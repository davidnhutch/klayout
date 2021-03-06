
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2017 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/


#ifndef HDR_tlStream
#define HDR_tlStream

#include "tlCommon.h"

#include "tlException.h"
#include "tlString.h"

#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <zlib.h>


namespace tl
{

class InflateFilter;
class DeflateFilter;
class OutputStream;

// ---------------------------------------------------------------------------------

/**
 *  @brief An utility method to match a file name against a given format
 */
extern TL_PUBLIC bool match_filename_to_format (const std::string &fn, const std::string &fmt);

// ---------------------------------------------------------------------------------

/**
 *  @brief The input stream delegate base class
 *
 *  This class provides the basic input stream functionality.
 *  The actual implementation is provided through InputFile, InputPipe and InputZLibFile.
 */

class TL_PUBLIC InputStreamBase
{
public:
  InputStreamBase () { }
  virtual ~InputStreamBase () { }

  /** 
   *  @brief Read a block of n bytes
   *
   *  Read the requested number of bytes or less.
   *  May throw an exception if a read error occures.
   *  
   *  @param b The buffer where to write to
   *  @param n The number of bytes to read (or less)
   *
   *  @return The number of bytes read. Should report 0 on EOF
   */
  virtual size_t read (char *b, size_t n) = 0;

  /**
   *  @brief Seek to the beginning
   */
  virtual void reset () = 0;

  /**
   *  @brief Get the source specification (i.e. the file name)
   */
  virtual std::string source () const = 0;

  /**
   *  @brief Gets the absolute path of the source
   */
  virtual std::string absolute_path () const = 0;

  /**
   *  @brief Gets the filename part of the source
   */
  virtual std::string filename () const = 0;
};

// ---------------------------------------------------------------------------------
//  InputStreamBase implementations

/**
 *  @brief An in-memory input file delegate
 */
class TL_PUBLIC InputMemoryStream
  : public InputStreamBase
{
public:
  /**
   *  @brief Create a stream reading from the given memory block
   *
   *  @param data The memory block where to read from
   *  @param length The length of the block
   */
  InputMemoryStream (const char *data, size_t length)
    : mp_data (data), m_length (length), m_pos (0)
  {
    //  .. nothing yet ..
  }

  virtual size_t read (char *b, size_t n)
  {
    if (m_pos + n > m_length) {
      n = m_length - m_pos;
    }
    memcpy (b, mp_data + m_pos, n);
    m_pos += n;
    return n;
  }

  virtual void reset ()
  {
    m_pos = 0;
  }

  virtual std::string source () const
  {
    return "data";
  }

  virtual std::string absolute_path () const
  {
    return "data";
  }

  virtual std::string filename () const
  {
    return "data";
  }

private:
  const char *mp_data;
  size_t m_length, m_pos;
};

// ---------------------------------------------------------------------------------

/**
 *  @brief An input stream abstraction class
 *
 *  The basic objective of this interface is to provide
 *  the capability to read a block of n bytes into a buffer.
 *  This object provides unget capabilities and buffering.
 *  The actual stream access is delegated to another object.
 */

class TL_PUBLIC InputStream
{
public:
  /**
   *  @brief Default constructor
   *
   *  This constructor takes a delegate object. 
   */
  InputStream (InputStreamBase &delegate);

  /**
   *  @brief Opens a stream from a abstract path
   *
   *  This will automatically create the approriate delegate and 
   *  delete it later.
   */
  InputStream (const std::string &abstract_path);

  /**
   *  @brief Destructor
   */
  virtual ~InputStream ();

  /** 
   *  @brief This is the outer write method to call
   *  
   *  This implementation writes data through the 
   *  protected write call.
   */
  void put (const char *b, size_t n);

  /** 
   *  @brief This is the outer read method to call
   *  
   *  This implementation obtains data through the 
   *  protected read call and buffers the data accordingly so
   *  a contigous memory block can be returned.
   *  If inline deflating is enabled, the method will return
   *  inflate data unless "bypass_inflate" is set to true.
   *
   *  @return 0 if not enough data can be obtained
   */
  const char *get (size_t n, bool bypass_inflate = false);

  /** 
   *  @brief Undo a previous get call
   *  
   *  This call puts back the bytes read by a previous get call.
   *  Only one call can be made undone.
   */
  void unget (size_t n);

  /**
   *  @brief Reads all remaining bytes into the string
   */
  std::string read_all ();

  /**
   *  @brief Reads all remaining bytes into the string 
   *
   *  This function reads all remaining of max_count bytes.
   */
  std::string read_all (size_t max_count);

  /**
   *  @brief Copies the content of the stream to the output stream
   */
  void copy_to (tl::OutputStream &os);

  /**
   *  @brief Enable uncompression of the following DEFLATE-compressed block
   *
   *  This call will enable uncompression of the next block
   *  of DEFLATE (RFC1951) compressed data. Subsequence get() calls will deliver
   *  the uncompressed data rather than the raw data, until the
   *  compressed block is finished.
   *  The stream must not be in inflate state yet.
   */
  void inflate ();

  /**
   *  @brief Obtain the current file position
   */
  size_t pos () const 
  {
    return m_pos;
  }

  /**
   *  @brief Obtain the available number of bytes
   *
   *  This is the number of bytes that can be delivered on the next get, not
   *  the total file size.
   */
  size_t blen () const
  {
    return m_blen;
  }

  /**
   *  @brief Get the source specification (the file name)
   *
   *  Returns an empty string if no file name is available.
   */
  std::string source () const
  {
    return mp_delegate->source ();
  }

  /**
   *  @brief Get the filename specification (the file name part of the path)
   *
   *  Returns an empty string if no file name is available.
   */
  std::string filename () const
  {
    return mp_delegate->filename ();
  }

  /**
   *  @brief Get the absolute path 
   *
   *  Returns an empty string if no absolute path is available.
   */
  std::string absolute_path () const
  {
    return mp_delegate->absolute_path ();
  }

  /**
   *  @brief Reset to the initial position
   */
  virtual void reset ();

  /**
   *  @brief Gets the absolute path for a given URL
   */
  static std::string absolute_path (const std::string &path);
    
protected:
  void reset_pos ()
  {
    m_pos = 0;
  }

private:
  size_t m_pos;
  char *mp_buffer;
  size_t m_bcap;
  size_t m_blen;
  char *mp_bptr;
  InputStreamBase *mp_delegate;
  bool m_owns_delegate;

  //  inflate support 
  InflateFilter *mp_inflate;

  //  No copying currently
  InputStream (const InputStream &);
  InputStream &operator= (const InputStream &);
};

// ---------------------------------------------------------------------------------

/**
 *  @brief An ASCII input stream
 *
 *  This class is put in front of a InputStream to format the input as text input stream.
 */
class TL_PUBLIC TextInputStream 
{
public:
  /**
   *  @brief Default constructor
   *
   *  This constructor takes a delegate object. 
   */
  TextInputStream (InputStream &stream);

  /**
   *  @brief Gets the raw stream
   */
  InputStream &raw_stream ()
  {
    return m_stream;
  }

  /**
   *  @brief Get a single line (presumably UTF8 encoded)
   */
  const std::string &get_line ();

  /**
   *  @brief Get a single character
   */
  char get_char ();

  /**
   *  @brief Peek a single character
   */
  char peek_char ();

  /**
   *  @brief Skip blanks, newlines etc.
   *
   *  Returns the following character without getting it.
   */
  char skip ();

  /**
   *  @brief Get the source specification
   */
  std::string source () const
  {
    return m_stream.source ();
  }

  /**
   *  @brief Get the current line number
   */
  size_t line_number ()
  {
    return m_line;
  }

  /**
   *  @brief Return false, if no more characters can be obtained
   */
  bool at_end () const 
  {
    return m_at_end;
  }

  /**
   *  @brief Reset to the initial position
   */
  void reset ();

private:
  size_t m_line, m_next_line;
  bool m_at_end;
  std::string m_line_buffer;
  InputStream &m_stream;

  //  no copying
  TextInputStream (const TextInputStream &);
  TextInputStream &operator= (const TextInputStream &);
};

// ---------------------------------------------------------------------------------

/**
 *  @brief The output stream delegate base class
 *
 *  This class provides the basic output stream functionality.
 *  The actual implementation is provided through OutputFile, OutputPipe and OutputZLibFile.
 */

class TL_PUBLIC OutputStreamBase
{
public:
  OutputStreamBase () { }
  virtual ~OutputStreamBase () { }

  /**
   *  @brief Write a block a n bytes
   *
   *  May throw an exception if a write error occures.
   *
   *  @param b What to write
   *  @param n The number of bytes to write 
   */
  virtual void write (const char *b, size_t n) = 0;

  /**
   *  @brief Seek to the specified position 
   *
   *  Writing continues at that position after a seek.
   */
  virtual void seek (size_t /*s*/) 
  {
    //  .. the default implementation does nothing ..
  }

  /**
   *  @brief Returns a value indicating whether that stream supports seek
   */
  virtual bool supports_seek () 
  {
    return false;
  }
};

/**
 *  @brief A string output delegate
 *
 *  Implements the writer to a memory buffer
 */
class TL_PUBLIC OutputMemoryStream
  : public OutputStreamBase
{
public:
  /**
   *  @brief Create a string writer
   */
  OutputMemoryStream ()
  {
    m_buffer.reserve (65336);
  }

  /**
   *  @brief Write to a string 
   *
   *  Implements the basic write method. 
   */
  virtual void write (const char *b, size_t n)
  {
    m_buffer.insert (m_buffer.end (), b, b + n);
  }

  /**
   *  @brief Get the address pointing to the data
   */
  const char *data () const
  {
    return & m_buffer.front ();
  }

  /**
   *  @brief Gets the size of the data stored
   */
  size_t size () const
  {
    return m_buffer.size ();
  }

  /**
   *  @brief Clears the buffer
   */
  void clear ()
  {
    m_buffer.clear ();
  }

private:
  std::vector<char> m_buffer;
};

/**
 *  @brief A string output delegate
 *
 *  Implements the writer to a string
 */
class TL_PUBLIC OutputStringStream
  : public OutputStreamBase
{
public:
  /**
   *  @brief Create a string writer
   */
  OutputStringStream ()
  {
    m_stream.imbue (std::locale ("C"));
  }

  /**
   *  @brief Write to a string 
   *
   *  Implements the basic write method. 
   */
  virtual void write (const char *b, size_t n)
  {
    m_stream.write (b, n);
  }

  /**
   *  @brief Seek to the specified position 
   *
   *  Writing continues at that position after a seek.
   */
  void seek (size_t s)
  {
    m_stream.seekp (s);
  }

  /**
   *  @brief Returns a value indicating whether that stream supports seek
   */
  bool supports_seek () 
  {
    return true;
  }

  /**
   *  @brief Get the content as a STL string
   *
   *  This method will return an char pointer containing the data written. 
   */
  std::string string () 
  {
    return m_stream.str ();
  }

private:
  std::ostringstream m_stream;
};

// ---------------------------------------------------------------------------------

/**
 *  @brief An output stream abstraction class
 *
 *  The basic objective of this interface is to provide
 *  the capability to write a block of n bytes into a buffer.
 *  The actual stream access is delegated to another object.
 */

class TL_PUBLIC OutputStream
{
public:
  /**
   *  @brief Definitions of the output options
   */
  enum OutputStreamMode
  {
    /**
     *  @brief Without compression
     */
    OM_Plain = 0,

    /**
     *  @brief With zlib compression
     */
    OM_Zlib = 1,

    /**
     *  @brief Determine from path (.gz -> zlib compression)
     */
    OM_Auto = 2
  };

  /**
   *  @brief Determine the output mode from the filename and a given mode
   *
   *  This method will replace OM_Auto by the appropriate mode given by the 
   *  file name.
   */
  static OutputStreamMode output_mode_from_filename (const std::string &abstract_path, OutputStreamMode om = OM_Auto);

  /**
   *  @brief Default constructor
   *
   *  This constructor takes a delegate object. 
   */
  OutputStream (OutputStreamBase &delegate);

  /**
   *  @brief Open an output stream with the given path and stream mode
   *
   *  This will automatically create a delegate object and delete it later.
   */
  OutputStream (const std::string &abstract_path, OutputStreamMode om = OM_Auto);

  /**
   *  @brief Destructor
   *
   *  This will delete the delegate object passed in the constructor.
   */
  virtual ~OutputStream ();

  /** 
   *  @brief This is the outer write method to call
   *  
   *  This implementation writes data through the 
   *  protected write call.
   */
  void put (const char *b, size_t n);

  /**
   *  @brief Puts a C string (UTF-8) to the output
   */
  void put (const char *s)
  {
    put (s, strlen (s));
  }

  /**
   *  @brief Puts a STL string (UTF-8) to the output
   */
  void put (const std::string &s)
  {
    put (s.c_str (), s.size ());
  }

  /**
   *  @brief << operator
   */
  OutputStream &operator<< (char s)
  {
    put (&s, 1);
    return *this;
  }

  /**
   *  @brief << operator
   */
  OutputStream &operator<< (unsigned char s)
  {
    put ((const char *) &s, 1);
    return *this;
  }

  /**
   *  @brief << operator
   */
  OutputStream &operator<< (const char *s)
  {
    put (s);
    return *this;
  }

  /**
   *  @brief << operator
   */
  OutputStream &operator<< (const std::string &s)
  {
    put (s);
    return *this;
  }

  /**
   *  @brief << operator
   */
  template <class T>
  OutputStream &operator<< (const T &t)
  {
    put (tl::to_string (t));
    return *this;
  }

  /**
   *  @brief Returns a value indicating whether that stream supports seek
   */
  bool supports_seek () const
  {
    return mp_delegate->supports_seek ();
  }

  /**
   *  @brief Seek to the specified position 
   *
   *  Writing continues at that position after a seek.
   *  Seek is not supported while in deflate mode.
   */
  void seek (size_t s);

  /**
   *  @brief Obtain the current file position
   */
  size_t pos () const 
  {
    return m_pos;
  }
    
  /**
   *  @brief Flush buffered data
   */
  void flush ();

protected:
  void reset_pos ()
  {
    m_pos = 0;
  }

private:
  size_t m_pos;
  OutputStreamBase *mp_delegate;
  bool m_owns_delegate;
  char *mp_buffer;
  size_t m_buffer_capacity, m_buffer_pos;

  //  No copying currently
  OutputStream (const OutputStream &);
  OutputStream &operator= (const OutputStream &);
};

}

#endif

