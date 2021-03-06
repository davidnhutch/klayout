
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


#include "dbOASISReader.h"
#include "dbTextWriter.h"
#include "tlLog.h"
#include "tlUnitTest.h"

#include <stdlib.h>

TEST(1_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t1.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(1_2)
{
  const char *expected = 
    "begin_lib 2\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t1.2.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(1_3)
{
  const char *expected = 
    "begin_lib 0.4\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t1.3.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(1_4)
{
  const char *expected = 
    "begin_lib 0.08\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t1.4.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(1_5)
{
  const char *expected = 
    "begin_lib 0.08\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t1.5.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(10_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {0 0} {10 20}\n"
    "box 1 2 {100 -100} {110 -80}\n"
    "box 1 2 {200 -200} {210 -180}\n"
    "box 1 2 {300 -300} {310 -280}\n"
    "text 2 1 0 0 {0 0} {A}\n"
    "text 2 1 0 0 {100 -100} {A}\n"
    "text 2 1 0 0 {200 -200} {A}\n"
    "text 2 1 0 0 {300 -300} {A}\n"
    "end_cell\n"
    "begin_cell {B}\n"
    "sref {A} 0 0 1 {0 0}\n"
    "sref {A} 0 0 1 {50 50}\n"
    "box 1 2 {0 0} {20 10}\n"
    "box 1 2 {100 100} {120 110}\n"
    "box 1 2 {200 200} {220 210}\n"
    "box 1 2 {300 300} {320 310}\n"
    "text 2 1 0 0 {0 0} {B}\n"
    "text 2 1 0 0 {100 100} {B}\n"
    "text 2 1 0 0 {200 200} {B}\n"
    "text 2 1 0 0 {300 300} {B}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "sref {B} 0 0 1 {0 0}\n"
    "box 1 2 {0 0} {50 5}\n"
    "text 2 1 0 0 {0 0} {TOP}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t10.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(11_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3000 0} {3000 100} {3100 100} {3100 50} {3150 50} {3150 0} {3000 0}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2000 0} {2150 0} {2150 50} {2100 50}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {0 0} {100 200}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {0 1000} {100 1200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {0 2000} {100 2200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 3000} {100 3200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 4000} {100 4200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1000 0} {A}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t11.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(11_2)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3000 0} {3000 100} {3100 100} {3100 50} {3150 50} {3150 0} {3000 0}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3300 0} {3300 100} {3400 100} {3400 50} {3450 50} {3450 0} {3300 0}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3600 0} {3600 100} {3700 100} {3700 50} {3750 50} {3750 0} {3600 0}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3000 320} {3000 420} {3100 420} {3100 370} {3150 370} {3150 320} {3000 320}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3300 320} {3300 420} {3400 420} {3400 370} {3450 370} {3450 320} {3300 320}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3600 320} {3600 420} {3700 420} {3700 370} {3750 370} {3750 320} {3600 320}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2000 0} {2150 0} {2150 50} {2100 50}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2300 0} {2450 0} {2450 50} {2400 50}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2600 0} {2750 0} {2750 50} {2700 50}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2000 320} {2150 320} {2150 370} {2100 370}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2300 320} {2450 320} {2450 370} {2400 370}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2600 320} {2750 320} {2750 370} {2700 370}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {0 0} {100 200}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {300 0} {400 200}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {600 0} {700 200}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {0 320} {100 520}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {300 320} {400 520}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {600 320} {700 520}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {0 1000} {100 1200}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {300 1000} {400 1200}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {600 1000} {700 1200}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {0 1320} {100 1520}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {300 1320} {400 1520}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {600 1320} {700 1520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {0 2000} {100 2200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {300 2000} {400 2200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {600 2000} {700 2200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {0 2320} {100 2520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {300 2320} {400 2520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {600 2320} {700 2520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 3000} {100 3200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {300 3000} {400 3200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {600 3000} {700 3200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 3320} {100 3520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {300 3320} {400 3520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {600 3320} {700 3520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 4000} {100 4200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {300 4000} {400 4200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {600 4000} {700 4200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 4320} {100 4520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {300 4320} {400 4520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {600 4320} {700 4520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1000 0} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1300 0} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1600 0} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1000 320} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1300 320} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1600 320} {A}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t11.2.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(11_3)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "boundaryp $props 1 2 {3000 0} {3000 100} {3100 100} {3100 50} {3150 50} {3150 0} {3000 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2000 0} {2150 0} {2150 50} {2100 50}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "boxp $props 1 2 {0 1000} {100 1200}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 2000} {100 2200}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 3000} {100 3200}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 4000} {100 4200}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 5000} {100 5200}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1000 0} {A}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t11.3.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(11_4)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 0 0 1 {-300 400}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "srefp $props {A} 0 0 1 {0 200}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "srefp $props {A} 0 0 1 {0 400}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "srefp $props {A} 0 0 1 {300 400}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "srefp $props {A} 0 1 1 {700 400}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 90 0 1 {700 1400}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 90 1 1 {700 2400}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 3 4 {2000 0} {2900 0} {2000 1200}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 3 4 {4000 0} {4900 0} {4000 1200}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 3 1 {6000 0} {6960 0} {6000 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 1 4 {8000 0} {8000 0} {8000 1240}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 270 1 1 {10000 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 270 1 1 {10320 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 270 1 1 {10650 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 270 1 1 {10990 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 3 4 {12000 0} {12930 960} {10680 1320}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t11.4.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(11_5)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3000 0} {3000 100} {3100 100} {3100 50} {3150 50} {3150 0} {3000 0}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3300 0} {3300 100} {3400 100} {3400 50} {3450 50} {3450 0} {3300 0}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3600 0} {3600 100} {3700 100} {3700 50} {3750 50} {3750 0} {3600 0}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3000 320} {3000 420} {3100 420} {3100 370} {3150 370} {3150 320} {3000 320}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3300 320} {3300 420} {3400 420} {3400 370} {3450 370} {3450 320} {3300 320}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "  {{PROP1} {nil}}\n"
    "}\n"
    "boundaryp $props 1 2 {3600 320} {3600 420} {3700 420} {3700 370} {3750 370} {3750 320} {3600 320}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2000 0} {2150 0} {2150 50} {2100 50}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2300 0} {2450 0} {2450 50} {2400 50}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2600 0} {2750 0} {2750 50} {2700 50}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2000 320} {2150 320} {2150 370} {2100 370}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2300 320} {2450 320} {2450 370} {2400 370}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "pathp $props 1 2 20 5 -5 {2600 320} {2750 320} {2750 370} {2700 370}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {0 0} {100 200}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {300 0} {400 200}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {600 0} {700 200}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {0 320} {100 520}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {300 320} {400 520}\n"
    "set props {\n"
    "  {{PROPX} {nil}}\n"
    "}\n"
    "boxp $props 1 2 {600 320} {700 520}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {0 1000} {100 1200}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {300 1000} {400 1200}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {600 1000} {700 1200}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {0 1320} {100 1520}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {300 1320} {400 1520}\n"
    "set props {\n"
    "  {{PROP0} {-5}}\n"
    "}\n"
    "boxp $props 1 2 {600 1320} {700 1520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {0 2000} {100 2200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {300 2000} {400 2200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {600 2000} {700 2200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {0 2320} {100 2520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {300 2320} {400 2520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,PROP_VALUE2,PropStringId12}}\n"
    "}\n"
    "boxp $props 1 2 {600 2320} {700 2520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 3000} {100 3200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {300 3000} {400 3200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {600 3000} {700 3200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 3320} {100 3520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {300 3320} {400 3520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {600 3320} {700 3520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 4000} {100 4200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {300 4000} {400 4200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {600 4000} {700 4200}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {0 4320} {100 4520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {300 4320} {400 4520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "boxp $props 1 2 {600 4320} {700 4520}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1000 0} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1300 0} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1600 0} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1000 320} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1300 320} {A}\n"
    "set props {\n"
    "  {{PROP0} {25,-124,Property string value for ID 13}}\n"
    "}\n"
    "textp $props 2 1 0 0 {1600 320} {A}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t11.5.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(11_6)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "  {26 {PROP_VALUE26}}\n"
    "}\n"
    "srefp $props {A} 0 0 1 {-300 400}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "srefp $props {A} 0 0 1 {0 400}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "srefp $props {A} 0 0 1 {0 400}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "srefp $props {A} 0 0 1 {300 400}\n"
    "set props {\n"
    "  {10 {Property string value for ID 13}}\n"
    "}\n"
    "srefp $props {A} 0 1 1 {700 400}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 90 0 1 {700 1400}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 90 1 1 {700 2400}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 3 4 {2000 0} {2900 0} {2000 1200}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 3 4 {4000 0} {4900 0} {4000 1200}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 3 1 {6000 0} {6960 0} {6000 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 1 4 {8000 0} {8000 0} {8000 1240}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 270 1 1 {10000 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 270 1 1 {10320 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 270 1 1 {10650 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "srefp $props {A} 270 1 1 {10990 0}\n"
    "set props {\n"
    "  {25 {PROP_VALUE2}}\n"
    "}\n"
    "arefp $props {A} 270 1 1 3 4 {12000 0} {12930 960} {10680 1320}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t11.6.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(11_7)
{
  const char *expected = 
    "set props {\n"
    "  {{FileProp1} {FileProp1Value}}\n"
    "  {{FileProp2} {FileProp1Value}}\n"
    "}\n"
    "begin_libp $props 0.001\n"
    "set props {\n"
    "  {{CellProp0} {CPValue0}}\n"
    "  {{CellProp1} {CPValue}}\n"
    "  {{CellProp2} {CPValue}}\n"
    "}\n"
    "begin_cellp $props {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t11.7.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(11_8)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t11.8.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: Modal variable accessed before being defined: last-value-list (position=96, cell=)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(11_9)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t11.9.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: Modal variable accessed before being defined: last-value-list (position=118, cell=)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(12_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "path 1 2 300 150 150 {-100 200}\n"
    "path 1 2 300 150 150 {-100 600}\n"
    "path 1 2 2 1 1 {-100 1400}\n"
    "path 1 2 12 6 6 {-100 1800}\n"
    "path 1 2 40 20 20 {-100 2200}\n"
    "path 1 2 200 100 100 {-100 2600}\n"
    "path 1 2 200 100 100 {300 2600}\n"
    "path 1 2 200 100 100 {700 2600}\n"
    "path 1 2 200 100 100 {-100 2900}\n"
    "path 1 2 200 100 100 {300 2900}\n"
    "path 1 2 200 100 100 {700 2900}\n"
    "path 1 2 200 100 100 {-100 3200}\n"
    "path 1 2 200 100 100 {300 3200}\n"
    "path 1 2 200 100 100 {700 3200}\n"
    "path 1 2 200 100 100 {-100 3500}\n"
    "path 1 2 200 100 100 {300 3500}\n"
    "path 1 2 200 100 100 {700 3500}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t12.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(13_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "path 1 2 300 150 150 {1000 2000}\n"
    "path 1 5 300 150 150 {1000 5000}\n"
    "path 1 6 300 150 150 {1000 6000}\n"
    "path 1 8 300 150 150 {1000 8000}\n"
    "path 5 2 300 150 150 {5000 2000}\n"
    "path 5 5 300 150 150 {5000 5000}\n"
    "path 5 6 300 150 150 {5000 6000}\n"
    "path 5 8 300 150 150 {5000 8000}\n"
    "path 6 2 300 150 150 {6000 2000}\n"
    "path 6 5 300 150 150 {6000 5000}\n"
    "path 6 6 300 150 150 {6000 6000}\n"
    "path 6 8 300 150 150 {6000 8000}\n"
    "path 7 2 300 150 150 {7000 2000}\n"
    "path 7 5 300 150 150 {7000 5000}\n"
    "path 7 6 300 150 150 {7000 6000}\n"
    "path 7 8 300 150 150 {7000 8000}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t13.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
    EXPECT_EQ (map.to_string (), "layer_map('1/2 : \\'AA;L5A\\' (1/2)';'1/5 : \\'AA;L5A\\' (1/5)';'1/6 : \\'AA;L5A\\' (1/6)';'1/8 : \\'AA;L5A\\' (1/8)';'5/2 : \\'AA;L5A;H5A;E5A;I56A;E5L4\\' (5/2)';'5/5 : \\'AA;L5A;H5A;E5A;I56A;E5H4;E5I47\\' (5/5)';'5/6 : \\'AA;L5A;H5A;E5A;I56A;E5H4;E5I47\\' (5/6)';'5/8 : \\'AA;L5A;H5A;E5A;I56A;E5H4\\' (5/8)';'6/2 : \\'AA;H5A;I56A\\' (6/2)';'6/5 : \\'AA;H5A;I56A\\' (6/5)';'6/6 : \\'AA;H5A;I56A\\' (6/6)';'6/8 : \\'AA;H5A;I56A\\' (6/8)';'7/2 : \\'AA;H5A\\' (7/2)';'7/5 : \\'AA;H5A\\' (7/5)';'7/6 : \\'AA;H5A\\' (7/6)';'7/8 : \\'AA;H5A\\' (7/8)')")
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(13_2)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "text 1 2 0 0 {1000 2000} {A}\n"
    "text 1 5 0 0 {1000 5000} {A}\n"
    "text 1 6 0 0 {1000 6000} {A}\n"
    "text 1 8 0 0 {1000 8000} {A}\n"
    "text 5 2 0 0 {5000 2000} {A}\n"
    "text 5 5 0 0 {5000 5000} {A}\n"
    "text 5 6 0 0 {5000 6000} {A}\n"
    "text 5 8 0 0 {5000 8000} {A}\n"
    "text 6 2 0 0 {6000 2000} {A}\n"
    "text 6 5 0 0 {6000 5000} {A}\n"
    "text 6 6 0 0 {6000 6000} {A}\n"
    "text 6 8 0 0 {6000 8000} {A}\n"
    "text 7 2 0 0 {7000 2000} {A}\n"
    "text 7 5 0 0 {7000 5000} {A}\n"
    "text 7 6 0 0 {7000 6000} {A}\n"
    "text 7 8 0 0 {7000 8000} {A}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t13.2.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
    EXPECT_EQ (map.to_string (), "layer_map('1/2 : \\'AA;L5A\\' (1/2)';'1/5 : \\'AA;L5A\\' (1/5)';'1/6 : \\'AA;L5A\\' (1/6)';'1/8 : \\'AA;L5A\\' (1/8)';'5/2 : \\'AA;L5A;H5A;E5A;I56A\\' (5/2)';'5/5 : \\'AA;L5A;H5A;E5A;I56A\\' (5/5)';'5/6 : \\'AA;L5A;H5A;E5A;I56A\\' (5/6)';'5/8 : \\'AA;L5A;H5A;E5A;I56A\\' (5/8)';'6/2 : \\'AA;H5A;I56A\\' (6/2)';'6/5 : \\'AA;H5A;I56A\\' (6/5)';'6/6 : \\'AA;H5A;I56A\\' (6/6)';'6/8 : \\'AA;H5A;I56A\\' (6/8)';'7/2 : \\'AA;H5A\\' (7/2)';'7/5 : \\'AA;H5A\\' (7/5)';'7/6 : \\'AA;H5A\\' (7/6)';'7/8 : \\'AA;H5A\\' (7/8)')");
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(13_3)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "path 1 2 300 150 150 {1000 2000}\n"
    "text 1 2 0 0 {1000 2000} {A}\n"
    "path 1 5 300 150 150 {1000 5000}\n"
    "text 1 5 0 0 {1000 5000} {A}\n"
    "path 1 6 300 150 150 {1000 6000}\n"
    "text 1 6 0 0 {1000 6000} {A}\n"
    "path 1 8 300 150 150 {1000 8000}\n"
    "text 1 8 0 0 {1000 8000} {A}\n"
    "path 5 2 300 150 150 {5000 2000}\n"
    "text 5 2 0 0 {5000 2000} {A}\n"
    "path 5 5 300 150 150 {5000 5000}\n"
    "text 5 5 0 0 {5000 5000} {A}\n"
    "path 5 6 300 150 150 {5000 6000}\n"
    "text 5 6 0 0 {5000 6000} {A}\n"
    "path 5 8 300 150 150 {5000 8000}\n"
    "text 5 8 0 0 {5000 8000} {A}\n"
    "path 6 2 300 150 150 {6000 2000}\n"
    "text 6 2 0 0 {6000 2000} {A}\n"
    "path 6 5 300 150 150 {6000 5000}\n"
    "text 6 5 0 0 {6000 5000} {A}\n"
    "path 6 6 300 150 150 {6000 6000}\n"
    "text 6 6 0 0 {6000 6000} {A}\n"
    "path 6 8 300 150 150 {6000 8000}\n"
    "text 6 8 0 0 {6000 8000} {A}\n"
    "path 7 2 300 150 150 {7000 2000}\n"
    "text 7 2 0 0 {7000 2000} {A}\n"
    "path 7 5 300 150 150 {7000 5000}\n"
    "text 7 5 0 0 {7000 5000} {A}\n"
    "path 7 6 300 150 150 {7000 6000}\n"
    "text 7 6 0 0 {7000 6000} {A}\n"
    "path 7 8 300 150 150 {7000 8000}\n"
    "text 7 8 0 0 {7000 8000} {A}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t13.3.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
    EXPECT_EQ (map.to_string (), "layer_map('1/2 : \\'TAA;TL5A;AA;L5A\\' (1/2)';'1/5 : \\'TAA;TL5A;AA;L5A\\' (1/5)';'1/6 : \\'TAA;TL5A;AA;L5A\\' (1/6)';'1/8 : \\'TAA;TL5A;AA;L5A\\' (1/8)';'5/2 : \\'TAA;TL5A;TH5A;TE5A;TI56A;AA;L5A;H5A;E5A;I56A\\' (5/2)';'5/5 : \\'TAA;TL5A;TH5A;TE5A;TI56A;AA;L5A;H5A;E5A;I56A\\' (5/5)';'5/6 : \\'TAA;TL5A;TH5A;TE5A;TI56A;AA;L5A;H5A;E5A;I56A\\' (5/6)';'5/8 : \\'TAA;TL5A;TH5A;TE5A;TI56A;AA;L5A;H5A;E5A;I56A\\' (5/8)';'6/2 : \\'TAA;TH5A;TI56A;AA;H5A;I56A\\' (6/2)';'6/5 : \\'TAA;TH5A;TI56A;AA;H5A;I56A\\' (6/5)';'6/6 : \\'TAA;TH5A;TI56A;AA;H5A;I56A\\' (6/6)';'6/8 : \\'TAA;TH5A;TI56A;AA;H5A;I56A\\' (6/8)';'7/2 : \\'TAA;TH5A;AA;H5A\\' (7/2)';'7/5 : \\'TAA;TH5A;AA;H5A\\' (7/5)';'7/6 : \\'TAA;TH5A;AA;H5A\\' (7/6)';'7/8 : \\'TAA;TH5A;AA;H5A\\' (7/8)')");
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(13_4)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "path 1 2 300 150 150 {1000 2000}\n"
    "text 1 2 0 0 {1000 2000} {A}\n"
    "path 1 5 300 150 150 {1000 5000}\n"
    "text 1 5 0 0 {1000 5000} {A}\n"
    "path 1 6 300 150 150 {1000 6000}\n"
    "text 1 6 0 0 {1000 6000} {A}\n"
    "path 1 8 300 150 150 {1000 8000}\n"
    "text 1 8 0 0 {1000 8000} {A}\n"
    "path 5 2 300 150 150 {5000 2000}\n"
    "text 5 2 0 0 {5000 2000} {A}\n"
    "path 5 5 300 150 150 {5000 5000}\n"
    "text 5 5 0 0 {5000 5000} {A}\n"
    "path 5 6 300 150 150 {5000 6000}\n"
    "text 5 6 0 0 {5000 6000} {A}\n"
    "path 5 8 300 150 150 {5000 8000}\n"
    "text 5 8 0 0 {5000 8000} {A}\n"
    "path 6 2 300 150 150 {6000 2000}\n"
    "text 6 2 0 0 {6000 2000} {A}\n"
    "path 6 5 300 150 150 {6000 5000}\n"
    "text 6 5 0 0 {6000 5000} {A}\n"
    "path 6 6 300 150 150 {6000 6000}\n"
    "text 6 6 0 0 {6000 6000} {A}\n"
    "path 6 8 300 150 150 {6000 8000}\n"
    "text 6 8 0 0 {6000 8000} {A}\n"
    "path 7 2 300 150 150 {7000 2000}\n"
    "text 7 2 0 0 {7000 2000} {A}\n"
    "path 7 5 300 150 150 {7000 5000}\n"
    "text 7 5 0 0 {7000 5000} {A}\n"
    "path 7 6 300 150 150 {7000 6000}\n"
    "text 7 6 0 0 {7000 6000} {A}\n"
    "path 7 8 300 150 150 {7000 8000}\n"
    "text 7 8 0 0 {7000 8000} {A}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t13.4.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
    EXPECT_EQ (map.to_string (), "layer_map('1/2 : \\'TAA;TL5A;AA;L5A\\' (1/2)';'1/5 : \\'TAA;TL5A;AA;L5A\\' (1/5)';'1/6 : \\'TAA;TL5A;AA;L5A\\' (1/6)';'1/8 : \\'TAA;TL5A;AA;L5A\\' (1/8)';'5/2 : \\'TAA;TL5A;TH5A;TE5A;TI56A;AA;L5A;H5A;E5A;I56A\\' (5/2)';'5/5 : \\'TAA;TL5A;TH5A;TE5A;TI56A;AA;L5A;H5A;E5A;I56A\\' (5/5)';'5/6 : \\'TAA;TL5A;TH5A;TE5A;TI56A;AA;L5A;H5A;E5A;I56A\\' (5/6)';'5/8 : \\'TAA;TL5A;TH5A;TE5A;TI56A;AA;L5A;H5A;E5A;I56A\\' (5/8)';'6/2 : \\'TAA;TH5A;TI56A;AA;H5A;I56A\\' (6/2)';'6/5 : \\'TAA;TH5A;TI56A;AA;H5A;I56A\\' (6/5)';'6/6 : \\'TAA;TH5A;TI56A;AA;H5A;I56A\\' (6/6)';'6/8 : \\'TAA;TH5A;TI56A;AA;H5A;I56A\\' (6/8)';'7/2 : \\'TAA;TH5A;AA;H5A\\' (7/2)';'7/5 : \\'TAA;TH5A;AA;H5A\\' (7/5)';'7/6 : \\'TAA;TH5A;AA;H5A\\' (7/6)';'7/8 : \\'TAA;TH5A;AA;H5A\\' (7/8)')");
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(14_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABCDH}\n"
    "box 0 0 {110 1270} {650 1800}\n"
    "boundary 1 0 {1970 1590} {1490 1640} {1520 2000} {2150 2020} {1970 1590}\n"
    "boundary 1 0 {120 680} {50 900} {-400 860} {-370 1260} {-400 2630} {940 2570} {900 1750} {690 1740} {690 1840} {80 1850} {80 1240} {700 1230} {680 1700} {1340 1700} {1320 2170} {2130 2160} {2120 2060} {1490 2040} {1440 1540} {870 1530} {870 870} {130 890} {120 680}\n"
    "boundary 1 0 {2220 610} {1730 660} {1690 1420} {2330 1410} {2220 610}\n"
    "boundary 1 0 {-210 -100} {-420 810} {-50 850} {90 470} {430 460} {460 360} {140 380} {270 -80} {-210 -100}\n"
    "boundary 1 0 {1620 640} {1560 780} {170 830} {180 860} {900 840} {920 860} {1610 860} {1600 1510} {1580 1540} {1490 1530} {1500 1600} {1970 1570} {1990 1450} {1670 1450} {1710 660} {1620 640}\n"
    "boundary 1 0 {1690 -80} {370 -40} {300 330} {610 300} {620 520} {870 480} {910 260} {1250 270} {1230 560} {160 580} {160 810} {1540 750} {1690 -80}\n"
    "boundary 1 0 {970 1740} {970 2590} {1900 2530} {1910 2200} {1290 2220} {1300 1740} {970 1740}\n"
    "boundary 1 0 {2030 1450} {2020 1590} {2160 2000} {2150 2190} {1940 2200} {1930 2530} {2430 2480} {2300 1450} {2030 1450}\n"
    "box 1 0 {900 890} {1580 1500}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t14.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(2_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {XYZ}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t2.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(2_2)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "end_cell\n"
    "begin_cell {XYZ}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t2.2.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(2_3)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t2.3.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: Explicit and implicit CELLNAME modes cannot be mixed (position=45, cell=)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(2_4)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "end_cell\n"
    "begin_cell {XYZ}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t2.4.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(2_5)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t2.5.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: No cellname declared for cell id 2 (position=305, cell=#2)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(2_6)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "end_cell\n"
    "begin_cell { XYZ}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t2.6.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(3_1)
{
  const char *expected;
  if (db::default_editable_mode ()) {
    expected = 
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "text 1 2 0 0 {100 -200} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -400} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -300} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -500} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -500} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -500} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -488} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -488} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -488} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -476} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -476} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -476} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -464} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -464} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -464} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -700} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -700} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -700} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -688} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -688} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -688} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -676} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -676} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -676} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -664} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -664} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -664} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -900} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -900} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -900} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1100} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1088} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1076} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1064} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1300} {TEXT_ABC}\n"
      "text 2 1 0 0 {312 -1300} {TEXT_ABC}\n"
      "text 2 1 0 0 {325 -1300} {TEXT_ABC}\n"
      "text 2 1 0 0 {339 -1300} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1500} {TEXT_ABC}\n"
      "text 2 1 0 0 {312 -1500} {TEXT_ABC}\n"
      "text 2 1 0 0 {327 -1500} {TEXT_ABC}\n"
      "text 2 1 0 0 {345 -1500} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1700} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1690} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1679} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1890} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1875} {TEXT_ABC}\n"
      "text 2 1 0 0 {200 -400} {TEXT_ABC}\n"
      "text 2 1 0 0 {267 -2136} {TEXT_ABC}\n"
      "text 2 1 0 0 {270 -2270} {TEXT_ABC}\n"
      "text 2 1 0 0 {270 -2670} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -2100} {TEXT_ABC}\n"
      "text 2 1 0 0 {289 -2112} {TEXT_ABC}\n"
      "text 2 1 0 0 {299 -2112} {TEXT_ABC}\n"
      "text 2 1 0 0 {309 -2112} {TEXT_ABC}\n"
      "text 2 1 0 0 {278 -2124} {TEXT_ABC}\n"
      "text 2 1 0 0 {288 -2124} {TEXT_ABC}\n"
      "text 2 1 0 0 {298 -2124} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1900} {TEXT_ABC}\n"
      "text 2 1 0 0 {277 -2136} {TEXT_ABC}\n"
      "text 2 1 0 0 {287 -2136} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2300} {TEXT_ABC}\n"
      "text 2 1 0 0 {311 -2288} {TEXT_ABC}\n"
      "text 2 1 0 0 {322 -2276} {TEXT_ABC}\n"
      "text 2 1 0 0 {290 -2290} {TEXT_ABC}\n"
      "text 2 1 0 0 {301 -2278} {TEXT_ABC}\n"
      "text 2 1 0 0 {312 -2266} {TEXT_ABC}\n"
      "text 2 1 0 0 {280 -2280} {TEXT_ABC}\n"
      "text 2 1 0 0 {291 -2268} {TEXT_ABC}\n"
      "text 2 1 0 0 {302 -2256} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2100} {TEXT_ABC}\n"
      "text 2 1 0 0 {281 -2258} {TEXT_ABC}\n"
      "text 2 1 0 0 {292 -2246} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2500} {TEXT_ABC}\n"
      "text 2 1 0 0 {311 -2488} {TEXT_ABC}\n"
      "text 2 1 0 0 {322 -2476} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2700} {TEXT_ABC}\n"
      "text 2 1 0 0 {290 -2690} {TEXT_ABC}\n"
      "text 2 1 0 0 {280 -2680} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2100} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2900} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2900} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2890} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2890} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2930} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2920} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2910} {TEXT_ABC}\n"
      "text 2 1 0 0 {290 -2920} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2940} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3100} {TEXT_ABC}\n"
      "text 2 1 0 0 {289 -3088} {TEXT_ABC}\n"
      "text 2 1 0 0 {299 -3098} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3300} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -3300} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -3290} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3290} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3330} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -3320} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3310} {TEXT_ABC}\n"
      "text 2 1 0 0 {290 -3320} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -3340} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3500} {TEXT_ABC}\n"
      "text 2 1 0 0 {288 -3488} {TEXT_ABC}\n"
      "text 2 1 0 0 {297 -3497} {TEXT_ABC}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  } else {
    expected = 
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "text 1 2 0 0 {100 -200} {TEXT_ABC}\n"
      "text 2 1 0 0 {200 -400} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -400} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -300} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -500} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -500} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -500} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -488} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -488} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -488} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -476} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -476} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -476} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -464} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -464} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -464} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -700} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -700} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -700} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -688} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -688} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -688} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -676} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -676} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -676} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -664} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -664} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -664} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -900} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -900} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -900} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1100} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1088} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1076} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1064} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1300} {TEXT_ABC}\n"
      "text 2 1 0 0 {312 -1300} {TEXT_ABC}\n"
      "text 2 1 0 0 {325 -1300} {TEXT_ABC}\n"
      "text 2 1 0 0 {339 -1300} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1500} {TEXT_ABC}\n"
      "text 2 1 0 0 {312 -1500} {TEXT_ABC}\n"
      "text 2 1 0 0 {327 -1500} {TEXT_ABC}\n"
      "text 2 1 0 0 {345 -1500} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1700} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1690} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1679} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1900} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1890} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -1875} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2100} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2100} {TEXT_ABC}\n"
      "text 2 1 0 0 {320 -2100} {TEXT_ABC}\n"
      "text 2 1 0 0 {289 -2112} {TEXT_ABC}\n"
      "text 2 1 0 0 {299 -2112} {TEXT_ABC}\n"
      "text 2 1 0 0 {309 -2112} {TEXT_ABC}\n"
      "text 2 1 0 0 {278 -2124} {TEXT_ABC}\n"
      "text 2 1 0 0 {288 -2124} {TEXT_ABC}\n"
      "text 2 1 0 0 {298 -2124} {TEXT_ABC}\n"
      "text 2 1 0 0 {267 -2136} {TEXT_ABC}\n"
      "text 2 1 0 0 {277 -2136} {TEXT_ABC}\n"
      "text 2 1 0 0 {287 -2136} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2300} {TEXT_ABC}\n"
      "text 2 1 0 0 {311 -2288} {TEXT_ABC}\n"
      "text 2 1 0 0 {322 -2276} {TEXT_ABC}\n"
      "text 2 1 0 0 {290 -2290} {TEXT_ABC}\n"
      "text 2 1 0 0 {301 -2278} {TEXT_ABC}\n"
      "text 2 1 0 0 {312 -2266} {TEXT_ABC}\n"
      "text 2 1 0 0 {280 -2280} {TEXT_ABC}\n"
      "text 2 1 0 0 {291 -2268} {TEXT_ABC}\n"
      "text 2 1 0 0 {302 -2256} {TEXT_ABC}\n"
      "text 2 1 0 0 {270 -2270} {TEXT_ABC}\n"
      "text 2 1 0 0 {281 -2258} {TEXT_ABC}\n"
      "text 2 1 0 0 {292 -2246} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2500} {TEXT_ABC}\n"
      "text 2 1 0 0 {311 -2488} {TEXT_ABC}\n"
      "text 2 1 0 0 {322 -2476} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2700} {TEXT_ABC}\n"
      "text 2 1 0 0 {290 -2690} {TEXT_ABC}\n"
      "text 2 1 0 0 {280 -2680} {TEXT_ABC}\n"
      "text 2 1 0 0 {270 -2670} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2900} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2900} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2890} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2890} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2930} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2920} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -2910} {TEXT_ABC}\n"
      "text 2 1 0 0 {290 -2920} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -2940} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3100} {TEXT_ABC}\n"
      "text 2 1 0 0 {289 -3088} {TEXT_ABC}\n"
      "text 2 1 0 0 {299 -3098} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3300} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -3300} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -3290} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3290} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3330} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -3320} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3310} {TEXT_ABC}\n"
      "text 2 1 0 0 {290 -3320} {TEXT_ABC}\n"
      "text 2 1 0 0 {310 -3340} {TEXT_ABC}\n"
      "text 2 1 0 0 {300 -3500} {TEXT_ABC}\n"
      "text 2 1 0 0 {288 -3488} {TEXT_ABC}\n"
      "text 2 1 0 0 {297 -3497} {TEXT_ABC}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  }

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(3_10)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "text 1 2 0 0 {100 0} {A}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.10.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(3_11)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.11.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: Modal variable accessed before being defined: text-string (position=50, cell=ABC)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(3_12)
{
  const char *expected;
  if (db::default_editable_mode ()) {
    expected = 
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "text 1 2 0 0 {100 -200} {A}\n"
      "text 2 1 0 0 {300 -400} {B}\n"
      "text 2 1 0 0 {300 -300} {B}\n"
      "text 2 1 0 0 {300 -500} {A}\n"
      "text 2 1 0 0 {310 -500} {A}\n"
      "text 2 1 0 0 {320 -500} {A}\n"
      "text 2 1 0 0 {300 -488} {A}\n"
      "text 2 1 0 0 {310 -488} {A}\n"
      "text 2 1 0 0 {320 -488} {A}\n"
      "text 2 1 0 0 {300 -476} {A}\n"
      "text 2 1 0 0 {310 -476} {A}\n"
      "text 2 1 0 0 {320 -476} {A}\n"
      "text 2 1 0 0 {300 -464} {A}\n"
      "text 2 1 0 0 {310 -464} {A}\n"
      "text 2 1 0 0 {320 -464} {A}\n"
      "text 2 1 0 0 {300 -700} {A}\n"
      "text 2 1 0 0 {310 -700} {A}\n"
      "text 2 1 0 0 {320 -700} {A}\n"
      "text 2 1 0 0 {300 -688} {A}\n"
      "text 2 1 0 0 {310 -688} {A}\n"
      "text 2 1 0 0 {320 -688} {A}\n"
      "text 2 1 0 0 {300 -676} {A}\n"
      "text 2 1 0 0 {310 -676} {A}\n"
      "text 2 1 0 0 {320 -676} {A}\n"
      "text 2 1 0 0 {300 -664} {A}\n"
      "text 2 1 0 0 {310 -664} {A}\n"
      "text 2 1 0 0 {320 -664} {A}\n"
      "text 2 1 0 0 {300 -900} {A}\n"
      "text 2 1 0 0 {310 -900} {A}\n"
      "text 2 1 0 0 {320 -900} {A}\n"
      "text 2 1 0 0 {300 -1100} {A}\n"
      "text 2 1 0 0 {300 -1088} {A}\n"
      "text 2 1 0 0 {300 -1076} {A}\n"
      "text 2 1 0 0 {300 -1064} {A}\n"
      "text 2 1 0 0 {300 -1300} {A}\n"
      "text 2 1 0 0 {312 -1300} {A}\n"
      "text 2 1 0 0 {325 -1300} {A}\n"
      "text 2 1 0 0 {339 -1300} {A}\n"
      "text 2 1 0 0 {300 -1500} {A}\n"
      "text 2 1 0 0 {312 -1500} {A}\n"
      "text 2 1 0 0 {327 -1500} {A}\n"
      "text 2 1 0 0 {345 -1500} {A}\n"
      "text 2 1 0 0 {300 -1700} {A}\n"
      "text 2 1 0 0 {300 -1690} {A}\n"
      "text 2 1 0 0 {300 -1679} {A}\n"
      "text 2 1 0 0 {300 -1890} {A}\n"
      "text 2 1 0 0 {300 -1875} {A}\n"
      "text 2 1 0 0 {200 -400} {B}\n"
      "text 2 1 0 0 {267 -2136} {A}\n"
      "text 2 1 0 0 {270 -2270} {A}\n"
      "text 2 1 0 0 {270 -2670} {A}\n"
      "text 2 1 0 0 {320 -2100} {A}\n"
      "text 2 1 0 0 {289 -2112} {A}\n"
      "text 2 1 0 0 {299 -2112} {A}\n"
      "text 2 1 0 0 {309 -2112} {A}\n"
      "text 2 1 0 0 {278 -2124} {A}\n"
      "text 2 1 0 0 {288 -2124} {A}\n"
      "text 2 1 0 0 {298 -2124} {A}\n"
      "text 2 1 0 0 {300 -1900} {A}\n"
      "text 2 1 0 0 {277 -2136} {A}\n"
      "text 2 1 0 0 {287 -2136} {A}\n"
      "text 2 1 0 0 {300 -2300} {A}\n"
      "text 2 1 0 0 {311 -2288} {A}\n"
      "text 2 1 0 0 {322 -2276} {A}\n"
      "text 2 1 0 0 {290 -2290} {A}\n"
      "text 2 1 0 0 {301 -2278} {A}\n"
      "text 2 1 0 0 {312 -2266} {A}\n"
      "text 2 1 0 0 {280 -2280} {A}\n"
      "text 2 1 0 0 {291 -2268} {A}\n"
      "text 2 1 0 0 {302 -2256} {A}\n"
      "text 2 1 0 0 {300 -2100} {A}\n"
      "text 2 1 0 0 {281 -2258} {A}\n"
      "text 2 1 0 0 {292 -2246} {A}\n"
      "text 2 1 0 0 {300 -2500} {A}\n"
      "text 2 1 0 0 {311 -2488} {A}\n"
      "text 2 1 0 0 {322 -2476} {A}\n"
      "text 2 1 0 0 {300 -2700} {A}\n"
      "text 2 1 0 0 {290 -2690} {A}\n"
      "text 2 1 0 0 {280 -2680} {A}\n"
      "text 2 1 0 0 {310 -2100} {A}\n"
      "text 2 1 0 0 {300 -2900} {A}\n"
      "text 2 1 0 0 {310 -2900} {A}\n"
      "text 2 1 0 0 {310 -2890} {A}\n"
      "text 2 1 0 0 {300 -2890} {A}\n"
      "text 2 1 0 0 {300 -2900} {A}\n"
      "text 2 1 0 0 {310 -2890} {A}\n"
      "text 2 1 0 0 {300 -2880} {A}\n"
      "text 2 1 0 0 {290 -2890} {A}\n"
      "text 2 1 0 0 {300 -2900} {A}\n"
      "text 2 1 0 0 {300 -3100} {A}\n"
      "text 2 1 0 0 {289 -3088} {A}\n"
      "text 2 1 0 0 {299 -3098} {A}\n"
      "text 2 1 0 0 {300 -3300} {A}\n"
      "text 2 1 0 0 {310 -3300} {A}\n"
      "text 2 1 0 0 {310 -3290} {A}\n"
      "text 2 1 0 0 {300 -3290} {A}\n"
      "text 2 1 0 0 {300 -3300} {A}\n"
      "text 2 1 0 0 {310 -3290} {A}\n"
      "text 2 1 0 0 {300 -3280} {A}\n"
      "text 2 1 0 0 {290 -3290} {A}\n"
      "text 2 1 0 0 {300 -3300} {A}\n"
      "text 2 1 0 0 {300 -3500} {A}\n"
      "text 2 1 0 0 {288 -3488} {A}\n"
      "text 2 1 0 0 {297 -3497} {A}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  } else {
    expected = 
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "text 1 2 0 0 {100 -200} {A}\n"
      "text 2 1 0 0 {200 -400} {B}\n"
      "text 2 1 0 0 {300 -400} {B}\n"
      "text 2 1 0 0 {300 -300} {B}\n"
      "text 2 1 0 0 {300 -500} {A}\n"
      "text 2 1 0 0 {310 -500} {A}\n"
      "text 2 1 0 0 {320 -500} {A}\n"
      "text 2 1 0 0 {300 -488} {A}\n"
      "text 2 1 0 0 {310 -488} {A}\n"
      "text 2 1 0 0 {320 -488} {A}\n"
      "text 2 1 0 0 {300 -476} {A}\n"
      "text 2 1 0 0 {310 -476} {A}\n"
      "text 2 1 0 0 {320 -476} {A}\n"
      "text 2 1 0 0 {300 -464} {A}\n"
      "text 2 1 0 0 {310 -464} {A}\n"
      "text 2 1 0 0 {320 -464} {A}\n"
      "text 2 1 0 0 {300 -700} {A}\n"
      "text 2 1 0 0 {310 -700} {A}\n"
      "text 2 1 0 0 {320 -700} {A}\n"
      "text 2 1 0 0 {300 -688} {A}\n"
      "text 2 1 0 0 {310 -688} {A}\n"
      "text 2 1 0 0 {320 -688} {A}\n"
      "text 2 1 0 0 {300 -676} {A}\n"
      "text 2 1 0 0 {310 -676} {A}\n"
      "text 2 1 0 0 {320 -676} {A}\n"
      "text 2 1 0 0 {300 -664} {A}\n"
      "text 2 1 0 0 {310 -664} {A}\n"
      "text 2 1 0 0 {320 -664} {A}\n"
      "text 2 1 0 0 {300 -900} {A}\n"
      "text 2 1 0 0 {310 -900} {A}\n"
      "text 2 1 0 0 {320 -900} {A}\n"
      "text 2 1 0 0 {300 -1100} {A}\n"
      "text 2 1 0 0 {300 -1088} {A}\n"
      "text 2 1 0 0 {300 -1076} {A}\n"
      "text 2 1 0 0 {300 -1064} {A}\n"
      "text 2 1 0 0 {300 -1300} {A}\n"
      "text 2 1 0 0 {312 -1300} {A}\n"
      "text 2 1 0 0 {325 -1300} {A}\n"
      "text 2 1 0 0 {339 -1300} {A}\n"
      "text 2 1 0 0 {300 -1500} {A}\n"
      "text 2 1 0 0 {312 -1500} {A}\n"
      "text 2 1 0 0 {327 -1500} {A}\n"
      "text 2 1 0 0 {345 -1500} {A}\n"
      "text 2 1 0 0 {300 -1700} {A}\n"
      "text 2 1 0 0 {300 -1690} {A}\n"
      "text 2 1 0 0 {300 -1679} {A}\n"
      "text 2 1 0 0 {300 -1900} {A}\n"
      "text 2 1 0 0 {300 -1890} {A}\n"
      "text 2 1 0 0 {300 -1875} {A}\n"
      "text 2 1 0 0 {300 -2100} {A}\n"
      "text 2 1 0 0 {310 -2100} {A}\n"
      "text 2 1 0 0 {320 -2100} {A}\n"
      "text 2 1 0 0 {289 -2112} {A}\n"
      "text 2 1 0 0 {299 -2112} {A}\n"
      "text 2 1 0 0 {309 -2112} {A}\n"
      "text 2 1 0 0 {278 -2124} {A}\n"
      "text 2 1 0 0 {288 -2124} {A}\n"
      "text 2 1 0 0 {298 -2124} {A}\n"
      "text 2 1 0 0 {267 -2136} {A}\n"
      "text 2 1 0 0 {277 -2136} {A}\n"
      "text 2 1 0 0 {287 -2136} {A}\n"
      "text 2 1 0 0 {300 -2300} {A}\n"
      "text 2 1 0 0 {311 -2288} {A}\n"
      "text 2 1 0 0 {322 -2276} {A}\n"
      "text 2 1 0 0 {290 -2290} {A}\n"
      "text 2 1 0 0 {301 -2278} {A}\n"
      "text 2 1 0 0 {312 -2266} {A}\n"
      "text 2 1 0 0 {280 -2280} {A}\n"
      "text 2 1 0 0 {291 -2268} {A}\n"
      "text 2 1 0 0 {302 -2256} {A}\n"
      "text 2 1 0 0 {270 -2270} {A}\n"
      "text 2 1 0 0 {281 -2258} {A}\n"
      "text 2 1 0 0 {292 -2246} {A}\n"
      "text 2 1 0 0 {300 -2500} {A}\n"
      "text 2 1 0 0 {311 -2488} {A}\n"
      "text 2 1 0 0 {322 -2476} {A}\n"
      "text 2 1 0 0 {300 -2700} {A}\n"
      "text 2 1 0 0 {290 -2690} {A}\n"
      "text 2 1 0 0 {280 -2680} {A}\n"
      "text 2 1 0 0 {270 -2670} {A}\n"
      "text 2 1 0 0 {300 -2900} {A}\n"
      "text 2 1 0 0 {310 -2900} {A}\n"
      "text 2 1 0 0 {310 -2890} {A}\n"
      "text 2 1 0 0 {300 -2890} {A}\n"
      "text 2 1 0 0 {300 -2900} {A}\n"
      "text 2 1 0 0 {310 -2890} {A}\n"
      "text 2 1 0 0 {300 -2880} {A}\n"
      "text 2 1 0 0 {290 -2890} {A}\n"
      "text 2 1 0 0 {300 -2900} {A}\n"
      "text 2 1 0 0 {300 -3100} {A}\n"
      "text 2 1 0 0 {289 -3088} {A}\n"
      "text 2 1 0 0 {299 -3098} {A}\n"
      "text 2 1 0 0 {300 -3300} {A}\n"
      "text 2 1 0 0 {310 -3300} {A}\n"
      "text 2 1 0 0 {310 -3290} {A}\n"
      "text 2 1 0 0 {300 -3290} {A}\n"
      "text 2 1 0 0 {300 -3300} {A}\n"
      "text 2 1 0 0 {310 -3290} {A}\n"
      "text 2 1 0 0 {300 -3280} {A}\n"
      "text 2 1 0 0 {290 -3290} {A}\n"
      "text 2 1 0 0 {300 -3300} {A}\n"
      "text 2 1 0 0 {300 -3500} {A}\n"
      "text 2 1 0 0 {288 -3488} {A}\n"
      "text 2 1 0 0 {297 -3497} {A}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  }

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.12.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(3_2)
{
  const char *expected;
  if (db::default_editable_mode ()) {
    expected = 
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "text 1 2 0 0 {100 -200} {A}\n"
      "text 2 1 0 0 {300 -400} {B}\n"
      "text 2 1 0 0 {300 -300} {B}\n"
      "text 2 1 0 0 {300 -500} {A}\n"
      "text 2 1 0 0 {310 -500} {A}\n"
      "text 2 1 0 0 {320 -500} {A}\n"
      "text 2 1 0 0 {300 -488} {A}\n"
      "text 2 1 0 0 {310 -488} {A}\n"
      "text 2 1 0 0 {320 -488} {A}\n"
      "text 2 1 0 0 {300 -476} {A}\n"
      "text 2 1 0 0 {310 -476} {A}\n"
      "text 2 1 0 0 {320 -476} {A}\n"
      "text 2 1 0 0 {300 -464} {A}\n"
      "text 2 1 0 0 {310 -464} {A}\n"
      "text 2 1 0 0 {320 -464} {A}\n"
      "text 2 1 0 0 {300 -700} {A}\n"
      "text 2 1 0 0 {310 -700} {A}\n"
      "text 2 1 0 0 {320 -700} {A}\n"
      "text 2 1 0 0 {300 -688} {A}\n"
      "text 2 1 0 0 {310 -688} {A}\n"
      "text 2 1 0 0 {320 -688} {A}\n"
      "text 2 1 0 0 {300 -676} {A}\n"
      "text 2 1 0 0 {310 -676} {A}\n"
      "text 2 1 0 0 {320 -676} {A}\n"
      "text 2 1 0 0 {300 -664} {A}\n"
      "text 2 1 0 0 {310 -664} {A}\n"
      "text 2 1 0 0 {320 -664} {A}\n"
      "text 2 1 0 0 {300 -900} {A}\n"
      "text 2 1 0 0 {310 -900} {A}\n"
      "text 2 1 0 0 {320 -900} {A}\n"
      "text 2 1 0 0 {300 -1100} {A}\n"
      "text 2 1 0 0 {300 -1088} {A}\n"
      "text 2 1 0 0 {300 -1076} {A}\n"
      "text 2 1 0 0 {300 -1064} {A}\n"
      "text 2 1 0 0 {300 -1300} {A}\n"
      "text 2 1 0 0 {312 -1300} {A}\n"
      "text 2 1 0 0 {325 -1300} {A}\n"
      "text 2 1 0 0 {339 -1300} {A}\n"
      "text 2 1 0 0 {300 -1500} {A}\n"
      "text 2 1 0 0 {312 -1500} {A}\n"
      "text 2 1 0 0 {327 -1500} {A}\n"
      "text 2 1 0 0 {345 -1500} {A}\n"
      "text 2 1 0 0 {300 -1700} {A}\n"
      "text 2 1 0 0 {300 -1690} {A}\n"
      "text 2 1 0 0 {300 -1679} {A}\n"
      "text 2 1 0 0 {300 -1890} {A}\n"
      "text 2 1 0 0 {300 -1875} {A}\n"
      "text 2 1 0 0 {200 -400} {B}\n"
      "text 2 1 0 0 {267 -2136} {A}\n"
      "text 2 1 0 0 {270 -2270} {A}\n"
      "text 2 1 0 0 {270 -2670} {A}\n"
      "text 2 1 0 0 {320 -2100} {A}\n"
      "text 2 1 0 0 {289 -2112} {A}\n"
      "text 2 1 0 0 {299 -2112} {A}\n"
      "text 2 1 0 0 {309 -2112} {A}\n"
      "text 2 1 0 0 {278 -2124} {A}\n"
      "text 2 1 0 0 {288 -2124} {A}\n"
      "text 2 1 0 0 {298 -2124} {A}\n"
      "text 2 1 0 0 {300 -1900} {A}\n"
      "text 2 1 0 0 {277 -2136} {A}\n"
      "text 2 1 0 0 {287 -2136} {A}\n"
      "text 2 1 0 0 {300 -2300} {A}\n"
      "text 2 1 0 0 {311 -2288} {A}\n"
      "text 2 1 0 0 {322 -2276} {A}\n"
      "text 2 1 0 0 {290 -2290} {A}\n"
      "text 2 1 0 0 {301 -2278} {A}\n"
      "text 2 1 0 0 {312 -2266} {A}\n"
      "text 2 1 0 0 {280 -2280} {A}\n"
      "text 2 1 0 0 {291 -2268} {A}\n"
      "text 2 1 0 0 {302 -2256} {A}\n"
      "text 2 1 0 0 {300 -2100} {A}\n"
      "text 2 1 0 0 {281 -2258} {A}\n"
      "text 2 1 0 0 {292 -2246} {A}\n"
      "text 2 1 0 0 {300 -2500} {A}\n"
      "text 2 1 0 0 {311 -2488} {A}\n"
      "text 2 1 0 0 {322 -2476} {A}\n"
      "text 2 1 0 0 {300 -2700} {A}\n"
      "text 2 1 0 0 {290 -2690} {A}\n"
      "text 2 1 0 0 {280 -2680} {A}\n"
      "text 2 1 0 0 {310 -2100} {A}\n"
      "text 2 1 0 0 {300 -2900} {A}\n"
      "text 2 1 0 0 {310 -2900} {A}\n"
      "text 2 1 0 0 {310 -2890} {A}\n"
      "text 2 1 0 0 {300 -2890} {A}\n"
      "text 2 1 0 0 {300 -2930} {A}\n"
      "text 2 1 0 0 {310 -2920} {A}\n"
      "text 2 1 0 0 {300 -2910} {A}\n"
      "text 2 1 0 0 {290 -2920} {A}\n"
      "text 2 1 0 0 {310 -2940} {A}\n"
      "text 2 1 0 0 {300 -3100} {A}\n"
      "text 2 1 0 0 {289 -3088} {A}\n"
      "text 2 1 0 0 {299 -3098} {A}\n"
      "text 2 1 0 0 {300 -3300} {A}\n"
      "text 2 1 0 0 {310 -3300} {A}\n"
      "text 2 1 0 0 {310 -3290} {A}\n"
      "text 2 1 0 0 {300 -3290} {A}\n"
      "text 2 1 0 0 {300 -3330} {A}\n"
      "text 2 1 0 0 {310 -3320} {A}\n"
      "text 2 1 0 0 {300 -3310} {A}\n"
      "text 2 1 0 0 {290 -3320} {A}\n"
      "text 2 1 0 0 {310 -3340} {A}\n"
      "text 2 1 0 0 {300 -3500} {A}\n"
      "text 2 1 0 0 {288 -3488} {A}\n"
      "text 2 1 0 0 {297 -3497} {A}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  } else {
    expected = 
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "text 1 2 0 0 {100 -200} {A}\n"
      "text 2 1 0 0 {200 -400} {B}\n"
      "text 2 1 0 0 {300 -400} {B}\n"
      "text 2 1 0 0 {300 -300} {B}\n"
      "text 2 1 0 0 {300 -500} {A}\n"
      "text 2 1 0 0 {310 -500} {A}\n"
      "text 2 1 0 0 {320 -500} {A}\n"
      "text 2 1 0 0 {300 -488} {A}\n"
      "text 2 1 0 0 {310 -488} {A}\n"
      "text 2 1 0 0 {320 -488} {A}\n"
      "text 2 1 0 0 {300 -476} {A}\n"
      "text 2 1 0 0 {310 -476} {A}\n"
      "text 2 1 0 0 {320 -476} {A}\n"
      "text 2 1 0 0 {300 -464} {A}\n"
      "text 2 1 0 0 {310 -464} {A}\n"
      "text 2 1 0 0 {320 -464} {A}\n"
      "text 2 1 0 0 {300 -700} {A}\n"
      "text 2 1 0 0 {310 -700} {A}\n"
      "text 2 1 0 0 {320 -700} {A}\n"
      "text 2 1 0 0 {300 -688} {A}\n"
      "text 2 1 0 0 {310 -688} {A}\n"
      "text 2 1 0 0 {320 -688} {A}\n"
      "text 2 1 0 0 {300 -676} {A}\n"
      "text 2 1 0 0 {310 -676} {A}\n"
      "text 2 1 0 0 {320 -676} {A}\n"
      "text 2 1 0 0 {300 -664} {A}\n"
      "text 2 1 0 0 {310 -664} {A}\n"
      "text 2 1 0 0 {320 -664} {A}\n"
      "text 2 1 0 0 {300 -900} {A}\n"
      "text 2 1 0 0 {310 -900} {A}\n"
      "text 2 1 0 0 {320 -900} {A}\n"
      "text 2 1 0 0 {300 -1100} {A}\n"
      "text 2 1 0 0 {300 -1088} {A}\n"
      "text 2 1 0 0 {300 -1076} {A}\n"
      "text 2 1 0 0 {300 -1064} {A}\n"
      "text 2 1 0 0 {300 -1300} {A}\n"
      "text 2 1 0 0 {312 -1300} {A}\n"
      "text 2 1 0 0 {325 -1300} {A}\n"
      "text 2 1 0 0 {339 -1300} {A}\n"
      "text 2 1 0 0 {300 -1500} {A}\n"
      "text 2 1 0 0 {312 -1500} {A}\n"
      "text 2 1 0 0 {327 -1500} {A}\n"
      "text 2 1 0 0 {345 -1500} {A}\n"
      "text 2 1 0 0 {300 -1700} {A}\n"
      "text 2 1 0 0 {300 -1690} {A}\n"
      "text 2 1 0 0 {300 -1679} {A}\n"
      "text 2 1 0 0 {300 -1900} {A}\n"
      "text 2 1 0 0 {300 -1890} {A}\n"
      "text 2 1 0 0 {300 -1875} {A}\n"
      "text 2 1 0 0 {300 -2100} {A}\n"
      "text 2 1 0 0 {310 -2100} {A}\n"
      "text 2 1 0 0 {320 -2100} {A}\n"
      "text 2 1 0 0 {289 -2112} {A}\n"
      "text 2 1 0 0 {299 -2112} {A}\n"
      "text 2 1 0 0 {309 -2112} {A}\n"
      "text 2 1 0 0 {278 -2124} {A}\n"
      "text 2 1 0 0 {288 -2124} {A}\n"
      "text 2 1 0 0 {298 -2124} {A}\n"
      "text 2 1 0 0 {267 -2136} {A}\n"
      "text 2 1 0 0 {277 -2136} {A}\n"
      "text 2 1 0 0 {287 -2136} {A}\n"
      "text 2 1 0 0 {300 -2300} {A}\n"
      "text 2 1 0 0 {311 -2288} {A}\n"
      "text 2 1 0 0 {322 -2276} {A}\n"
      "text 2 1 0 0 {290 -2290} {A}\n"
      "text 2 1 0 0 {301 -2278} {A}\n"
      "text 2 1 0 0 {312 -2266} {A}\n"
      "text 2 1 0 0 {280 -2280} {A}\n"
      "text 2 1 0 0 {291 -2268} {A}\n"
      "text 2 1 0 0 {302 -2256} {A}\n"
      "text 2 1 0 0 {270 -2270} {A}\n"
      "text 2 1 0 0 {281 -2258} {A}\n"
      "text 2 1 0 0 {292 -2246} {A}\n"
      "text 2 1 0 0 {300 -2500} {A}\n"
      "text 2 1 0 0 {311 -2488} {A}\n"
      "text 2 1 0 0 {322 -2476} {A}\n"
      "text 2 1 0 0 {300 -2700} {A}\n"
      "text 2 1 0 0 {290 -2690} {A}\n"
      "text 2 1 0 0 {280 -2680} {A}\n"
      "text 2 1 0 0 {270 -2670} {A}\n"
      "text 2 1 0 0 {300 -2900} {A}\n"
      "text 2 1 0 0 {310 -2900} {A}\n"
      "text 2 1 0 0 {310 -2890} {A}\n"
      "text 2 1 0 0 {300 -2890} {A}\n"
      "text 2 1 0 0 {300 -2930} {A}\n"
      "text 2 1 0 0 {310 -2920} {A}\n"
      "text 2 1 0 0 {300 -2910} {A}\n"
      "text 2 1 0 0 {290 -2920} {A}\n"
      "text 2 1 0 0 {310 -2940} {A}\n"
      "text 2 1 0 0 {300 -3100} {A}\n"
      "text 2 1 0 0 {289 -3088} {A}\n"
      "text 2 1 0 0 {299 -3098} {A}\n"
      "text 2 1 0 0 {300 -3300} {A}\n"
      "text 2 1 0 0 {310 -3300} {A}\n"
      "text 2 1 0 0 {310 -3290} {A}\n"
      "text 2 1 0 0 {300 -3290} {A}\n"
      "text 2 1 0 0 {300 -3330} {A}\n"
      "text 2 1 0 0 {310 -3320} {A}\n"
      "text 2 1 0 0 {300 -3310} {A}\n"
      "text 2 1 0 0 {290 -3320} {A}\n"
      "text 2 1 0 0 {310 -3340} {A}\n"
      "text 2 1 0 0 {300 -3500} {A}\n"
      "text 2 1 0 0 {288 -3488} {A}\n"
      "text 2 1 0 0 {297 -3497} {A}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  }

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.2.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(3_3)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.3.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: Explicit and implicit TEXTSTRING modes cannot be mixed (position=41, cell=)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(3_4)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.4.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: No text string defined for id 2 (must be declared before text is used) (position=48, cell=ABC)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(3_5)
{
  const char *expected;
  if (db::default_editable_mode ()) {
    expected = 
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "text 1 2 0 0 {100 -200} {B}\n"
      "text 2 1 0 0 {300 -400} {A}\n"
      "text 2 1 0 0 {300 -300} {A}\n"
      "text 2 1 0 0 {300 -500} {B}\n"
      "text 2 1 0 0 {310 -500} {B}\n"
      "text 2 1 0 0 {320 -500} {B}\n"
      "text 2 1 0 0 {300 -488} {B}\n"
      "text 2 1 0 0 {310 -488} {B}\n"
      "text 2 1 0 0 {320 -488} {B}\n"
      "text 2 1 0 0 {300 -476} {B}\n"
      "text 2 1 0 0 {310 -476} {B}\n"
      "text 2 1 0 0 {320 -476} {B}\n"
      "text 2 1 0 0 {300 -464} {B}\n"
      "text 2 1 0 0 {310 -464} {B}\n"
      "text 2 1 0 0 {320 -464} {B}\n"
      "text 2 1 0 0 {300 -700} {B}\n"
      "text 2 1 0 0 {310 -700} {B}\n"
      "text 2 1 0 0 {320 -700} {B}\n"
      "text 2 1 0 0 {300 -688} {B}\n"
      "text 2 1 0 0 {310 -688} {B}\n"
      "text 2 1 0 0 {320 -688} {B}\n"
      "text 2 1 0 0 {300 -676} {B}\n"
      "text 2 1 0 0 {310 -676} {B}\n"
      "text 2 1 0 0 {320 -676} {B}\n"
      "text 2 1 0 0 {300 -664} {B}\n"
      "text 2 1 0 0 {310 -664} {B}\n"
      "text 2 1 0 0 {320 -664} {B}\n"
      "text 2 1 0 0 {300 -900} {B}\n"
      "text 2 1 0 0 {310 -900} {B}\n"
      "text 2 1 0 0 {320 -900} {B}\n"
      "text 2 1 0 0 {300 -1100} {B}\n"
      "text 2 1 0 0 {300 -1088} {B}\n"
      "text 2 1 0 0 {300 -1076} {B}\n"
      "text 2 1 0 0 {300 -1064} {B}\n"
      "text 2 1 0 0 {300 -1300} {B}\n"
      "text 2 1 0 0 {312 -1300} {B}\n"
      "text 2 1 0 0 {325 -1300} {B}\n"
      "text 2 1 0 0 {339 -1300} {B}\n"
      "text 2 1 0 0 {300 -1500} {B}\n"
      "text 2 1 0 0 {312 -1500} {B}\n"
      "text 2 1 0 0 {327 -1500} {B}\n"
      "text 2 1 0 0 {345 -1500} {B}\n"
      "text 2 1 0 0 {300 -1700} {B}\n"
      "text 2 1 0 0 {300 -1690} {B}\n"
      "text 2 1 0 0 {300 -1679} {B}\n"
      "text 2 1 0 0 {300 -1890} {B}\n"
      "text 2 1 0 0 {300 -1875} {B}\n"
      "text 2 1 0 0 {200 -400} {A}\n"
      "text 2 1 0 0 {267 -2136} {B}\n"
      "text 2 1 0 0 {270 -2270} {B}\n"
      "text 2 1 0 0 {270 -2670} {B}\n"
      "text 2 1 0 0 {320 -2100} {B}\n"
      "text 2 1 0 0 {289 -2112} {B}\n"
      "text 2 1 0 0 {299 -2112} {B}\n"
      "text 2 1 0 0 {309 -2112} {B}\n"
      "text 2 1 0 0 {278 -2124} {B}\n"
      "text 2 1 0 0 {288 -2124} {B}\n"
      "text 2 1 0 0 {298 -2124} {B}\n"
      "text 2 1 0 0 {300 -1900} {B}\n"
      "text 2 1 0 0 {277 -2136} {B}\n"
      "text 2 1 0 0 {287 -2136} {B}\n"
      "text 2 1 0 0 {300 -2300} {B}\n"
      "text 2 1 0 0 {311 -2288} {B}\n"
      "text 2 1 0 0 {322 -2276} {B}\n"
      "text 2 1 0 0 {290 -2290} {B}\n"
      "text 2 1 0 0 {301 -2278} {B}\n"
      "text 2 1 0 0 {312 -2266} {B}\n"
      "text 2 1 0 0 {280 -2280} {B}\n"
      "text 2 1 0 0 {291 -2268} {B}\n"
      "text 2 1 0 0 {302 -2256} {B}\n"
      "text 2 1 0 0 {300 -2100} {B}\n"
      "text 2 1 0 0 {281 -2258} {B}\n"
      "text 2 1 0 0 {292 -2246} {B}\n"
      "text 2 1 0 0 {300 -2500} {B}\n"
      "text 2 1 0 0 {311 -2488} {B}\n"
      "text 2 1 0 0 {322 -2476} {B}\n"
      "text 2 1 0 0 {300 -2700} {B}\n"
      "text 2 1 0 0 {290 -2690} {B}\n"
      "text 2 1 0 0 {280 -2680} {B}\n"
      "text 2 1 0 0 {310 -2100} {B}\n"
      "text 2 1 0 0 {300 -2900} {B}\n"
      "text 2 1 0 0 {310 -2900} {B}\n"
      "text 2 1 0 0 {310 -2890} {B}\n"
      "text 2 1 0 0 {300 -2890} {B}\n"
      "text 2 1 0 0 {300 -2930} {B}\n"
      "text 2 1 0 0 {310 -2920} {B}\n"
      "text 2 1 0 0 {300 -2910} {B}\n"
      "text 2 1 0 0 {290 -2920} {B}\n"
      "text 2 1 0 0 {310 -2940} {B}\n"
      "text 2 1 0 0 {300 -3100} {B}\n"
      "text 2 1 0 0 {289 -3088} {B}\n"
      "text 2 1 0 0 {299 -3098} {B}\n"
      "text 2 1 0 0 {300 -3300} {B}\n"
      "text 2 1 0 0 {310 -3300} {B}\n"
      "text 2 1 0 0 {310 -3290} {B}\n"
      "text 2 1 0 0 {300 -3290} {B}\n"
      "text 2 1 0 0 {300 -3330} {B}\n"
      "text 2 1 0 0 {310 -3320} {B}\n"
      "text 2 1 0 0 {300 -3310} {B}\n"
      "text 2 1 0 0 {290 -3320} {B}\n"
      "text 2 1 0 0 {310 -3340} {B}\n"
      "text 2 1 0 0 {300 -3500} {B}\n"
      "text 2 1 0 0 {288 -3488} {B}\n"
      "text 2 1 0 0 {297 -3497} {B}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  } else {
    expected = 
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "text 1 2 0 0 {100 -200} {B}\n"
      "text 2 1 0 0 {200 -400} {A}\n"
      "text 2 1 0 0 {300 -400} {A}\n"
      "text 2 1 0 0 {300 -300} {A}\n"
      "text 2 1 0 0 {300 -500} {B}\n"
      "text 2 1 0 0 {310 -500} {B}\n"
      "text 2 1 0 0 {320 -500} {B}\n"
      "text 2 1 0 0 {300 -488} {B}\n"
      "text 2 1 0 0 {310 -488} {B}\n"
      "text 2 1 0 0 {320 -488} {B}\n"
      "text 2 1 0 0 {300 -476} {B}\n"
      "text 2 1 0 0 {310 -476} {B}\n"
      "text 2 1 0 0 {320 -476} {B}\n"
      "text 2 1 0 0 {300 -464} {B}\n"
      "text 2 1 0 0 {310 -464} {B}\n"
      "text 2 1 0 0 {320 -464} {B}\n"
      "text 2 1 0 0 {300 -700} {B}\n"
      "text 2 1 0 0 {310 -700} {B}\n"
      "text 2 1 0 0 {320 -700} {B}\n"
      "text 2 1 0 0 {300 -688} {B}\n"
      "text 2 1 0 0 {310 -688} {B}\n"
      "text 2 1 0 0 {320 -688} {B}\n"
      "text 2 1 0 0 {300 -676} {B}\n"
      "text 2 1 0 0 {310 -676} {B}\n"
      "text 2 1 0 0 {320 -676} {B}\n"
      "text 2 1 0 0 {300 -664} {B}\n"
      "text 2 1 0 0 {310 -664} {B}\n"
      "text 2 1 0 0 {320 -664} {B}\n"
      "text 2 1 0 0 {300 -900} {B}\n"
      "text 2 1 0 0 {310 -900} {B}\n"
      "text 2 1 0 0 {320 -900} {B}\n"
      "text 2 1 0 0 {300 -1100} {B}\n"
      "text 2 1 0 0 {300 -1088} {B}\n"
      "text 2 1 0 0 {300 -1076} {B}\n"
      "text 2 1 0 0 {300 -1064} {B}\n"
      "text 2 1 0 0 {300 -1300} {B}\n"
      "text 2 1 0 0 {312 -1300} {B}\n"
      "text 2 1 0 0 {325 -1300} {B}\n"
      "text 2 1 0 0 {339 -1300} {B}\n"
      "text 2 1 0 0 {300 -1500} {B}\n"
      "text 2 1 0 0 {312 -1500} {B}\n"
      "text 2 1 0 0 {327 -1500} {B}\n"
      "text 2 1 0 0 {345 -1500} {B}\n"
      "text 2 1 0 0 {300 -1700} {B}\n"
      "text 2 1 0 0 {300 -1690} {B}\n"
      "text 2 1 0 0 {300 -1679} {B}\n"
      "text 2 1 0 0 {300 -1900} {B}\n"
      "text 2 1 0 0 {300 -1890} {B}\n"
      "text 2 1 0 0 {300 -1875} {B}\n"
      "text 2 1 0 0 {300 -2100} {B}\n"
      "text 2 1 0 0 {310 -2100} {B}\n"
      "text 2 1 0 0 {320 -2100} {B}\n"
      "text 2 1 0 0 {289 -2112} {B}\n"
      "text 2 1 0 0 {299 -2112} {B}\n"
      "text 2 1 0 0 {309 -2112} {B}\n"
      "text 2 1 0 0 {278 -2124} {B}\n"
      "text 2 1 0 0 {288 -2124} {B}\n"
      "text 2 1 0 0 {298 -2124} {B}\n"
      "text 2 1 0 0 {267 -2136} {B}\n"
      "text 2 1 0 0 {277 -2136} {B}\n"
      "text 2 1 0 0 {287 -2136} {B}\n"
      "text 2 1 0 0 {300 -2300} {B}\n"
      "text 2 1 0 0 {311 -2288} {B}\n"
      "text 2 1 0 0 {322 -2276} {B}\n"
      "text 2 1 0 0 {290 -2290} {B}\n"
      "text 2 1 0 0 {301 -2278} {B}\n"
      "text 2 1 0 0 {312 -2266} {B}\n"
      "text 2 1 0 0 {280 -2280} {B}\n"
      "text 2 1 0 0 {291 -2268} {B}\n"
      "text 2 1 0 0 {302 -2256} {B}\n"
      "text 2 1 0 0 {270 -2270} {B}\n"
      "text 2 1 0 0 {281 -2258} {B}\n"
      "text 2 1 0 0 {292 -2246} {B}\n"
      "text 2 1 0 0 {300 -2500} {B}\n"
      "text 2 1 0 0 {311 -2488} {B}\n"
      "text 2 1 0 0 {322 -2476} {B}\n"
      "text 2 1 0 0 {300 -2700} {B}\n"
      "text 2 1 0 0 {290 -2690} {B}\n"
      "text 2 1 0 0 {280 -2680} {B}\n"
      "text 2 1 0 0 {270 -2670} {B}\n"
      "text 2 1 0 0 {300 -2900} {B}\n"
      "text 2 1 0 0 {310 -2900} {B}\n"
      "text 2 1 0 0 {310 -2890} {B}\n"
      "text 2 1 0 0 {300 -2890} {B}\n"
      "text 2 1 0 0 {300 -2930} {B}\n"
      "text 2 1 0 0 {310 -2920} {B}\n"
      "text 2 1 0 0 {300 -2910} {B}\n"
      "text 2 1 0 0 {290 -2920} {B}\n"
      "text 2 1 0 0 {310 -2940} {B}\n"
      "text 2 1 0 0 {300 -3100} {B}\n"
      "text 2 1 0 0 {289 -3088} {B}\n"
      "text 2 1 0 0 {299 -3098} {B}\n"
      "text 2 1 0 0 {300 -3300} {B}\n"
      "text 2 1 0 0 {310 -3300} {B}\n"
      "text 2 1 0 0 {310 -3290} {B}\n"
      "text 2 1 0 0 {300 -3290} {B}\n"
      "text 2 1 0 0 {300 -3330} {B}\n"
      "text 2 1 0 0 {310 -3320} {B}\n"
      "text 2 1 0 0 {300 -3310} {B}\n"
      "text 2 1 0 0 {290 -3320} {B}\n"
      "text 2 1 0 0 {310 -3340} {B}\n"
      "text 2 1 0 0 {300 -3500} {B}\n"
      "text 2 1 0 0 {288 -3488} {B}\n"
      "text 2 1 0 0 {297 -3497} {B}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  }

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.5.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(3_6)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.6.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: Modal variable accessed before being defined: repetition (position=52, cell=ABC)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(3_7)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.7.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: Modal variable accessed before being defined: textlayer (position=50, cell=ABC)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(3_8)
{
  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.8.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    /*
      *** ERROR: Modal variable accessed before being defined: texttype (position=50, cell=ABC)
    */
    error = true;
  }
  EXPECT_EQ (error, true)
}

TEST(3_9)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "text 1 2 0 0 {0 -200} {A}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t3.9.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(4_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "box 1 2 {400 -500} {500 -300}\n"
    "box 1 2 {600 -300} {700 -100}\n"
    "box 1 2 {800 -300} {900 -100}\n"
    "box 2 3 {800 -600} {900 -400}\n"
    "box 2 3 {800 -900} {900 -700}\n"
    "box 2 3 {800 -1200} {900 -1000}\n"
    "box 2 3 {800 -1500} {950 -1350}\n"
    "box 2 3 {800 -1800} {950 -1650}\n"
    "box 2 3 {800 500} {950 650}\n"
    "box 2 3 {1000 500} {1150 650}\n"
    "box 2 3 {1200 500} {1350 650}\n"
    "box 2 3 {800 800} {950 950}\n"
    "box 2 3 {1000 800} {1150 950}\n"
    "box 2 3 {1200 800} {1350 950}\n"
    "box 2 3 {800 1100} {950 1250}\n"
    "box 2 3 {1000 1100} {1150 1250}\n"
    "box 2 3 {1200 1100} {1350 1250}\n"
    "box 2 3 {800 1400} {950 1550}\n"
    "box 2 3 {1000 1400} {1150 1550}\n"
    "box 2 3 {1200 1400} {1350 1550}\n"
    "box 2 3 {800 2000} {950 2150}\n"
    "box 2 3 {1000 2000} {1150 2150}\n"
    "box 2 3 {1300 2000} {1450 2150}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t4.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(4_2)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 1 2 {300 -400} {400 -200}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 1 2 {400 -500} {500 -300}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 1 2 {600 -300} {700 -100}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 1 2 {800 -300} {900 -100}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 -600} {900 -400}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 -900} {900 -700}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 -1200} {900 -1000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 -1500} {950 -1350}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 -1800} {950 -1650}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 500} {950 650}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1000 500} {1150 650}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1200 500} {1350 650}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 800} {950 950}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1000 800} {1150 950}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1200 800} {1350 950}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 1100} {950 1250}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1000 1100} {1150 1250}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1200 1100} {1350 1250}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 1400} {950 1550}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1000 1400} {1150 1550}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1200 1400} {1350 1550}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {800 2000} {950 2150}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1000 2000} {1150 2150}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boxp $props 2 3 {1300 2000} {1450 2150}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t4.2.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(5_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "boundary 1 2 {0 100} {0 200} {100 200} {100 150} {150 150} {150 100} {0 100}\n"
    "boundary 1 2 {-200 400} {-200 500} {-100 500} {-100 450} {-50 450} {-50 400} {-200 400}\n"
    "boundary 2 3 {0 400} {0 500} {100 500} {100 450} {150 450} {150 400} {0 400}\n"
    "boundary 2 3 {0 1000} {0 1100} {100 1100} {100 1050} {150 1050} {150 1000} {0 1000}\n"
    "boundary 2 3 {200 1000} {200 1150} {250 1150} {250 1100} {300 1100} {300 1000} {200 1000}\n"
    "boundary 2 3 {400 1000} {400 1050} {450 1050} {450 1100} {500 1100} {500 1050} {550 1050} {550 1000} {400 1000}\n"
    "boundary 2 3 {675 1000} {625 1050} {625 1100} {675 1150} {725 1150} {775 1100} {775 1050} {725 1000} {700 1000} {675 1000}\n"
    "boundary 2 3 {860 1000} {835 1025} {825 1100} {875 1150} {925 1150} {975 1100} {975 1050} {925 1000} {900 1000} {860 1000}\n"
    "boundary 2 3 {1100 1000} {1095 1575} {1135 1575} {1200 1550} {1275 1450} {1300 1300} {1275 1150} {1200 1050} {1125 1000} {1100 1000}\n"
    "boundary 2 3 {0 2000} {0 2150} {50 2150} {50 2100} {100 2100} {100 2000} {0 2000}\n"
    "boundary 2 3 {200 2000} {200 2150} {250 2150} {250 2100} {300 2100} {300 2000} {200 2000}\n"
    "boundary 2 3 {400 2000} {400 2150} {450 2150} {450 2100} {500 2100} {500 2000} {400 2000}\n"
    "boundary 2 3 {0 2300} {0 2450} {50 2450} {50 2400} {100 2400} {100 2300} {0 2300}\n"
    "boundary 2 3 {200 2300} {200 2450} {250 2450} {250 2400} {300 2400} {300 2300} {200 2300}\n"
    "boundary 2 3 {400 2300} {400 2450} {450 2450} {450 2400} {500 2400} {500 2300} {400 2300}\n"
    "boundary 2 3 {0 2600} {0 2750} {50 2750} {50 2700} {100 2700} {100 2600} {0 2600}\n"
    "boundary 2 3 {200 2600} {200 2750} {250 2750} {250 2700} {300 2700} {300 2600} {200 2600}\n"
    "boundary 2 3 {400 2600} {400 2750} {450 2750} {450 2700} {500 2700} {500 2600} {400 2600}\n"
    "boundary 2 3 {0 2900} {0 3050} {50 3050} {50 3000} {100 3000} {100 2900} {0 2900}\n"
    "boundary 2 3 {200 2900} {200 3050} {250 3050} {250 3000} {300 3000} {300 2900} {200 2900}\n"
    "boundary 2 3 {400 2900} {400 3050} {450 3050} {450 3000} {500 3000} {500 2900} {400 2900}\n"
    "boundary 2 1 {1000 2000} {1000 2150} {1050 2150} {1050 2100} {1100 2100} {1100 2000} {1000 2000}\n"
    "boundary 2 1 {1200 2000} {1200 2150} {1250 2150} {1250 2100} {1300 2100} {1300 2000} {1200 2000}\n"
    "boundary 2 1 {1400 2000} {1400 2150} {1450 2150} {1450 2100} {1500 2100} {1500 2000} {1400 2000}\n"
    "boundary 2 1 {1000 2300} {1000 2450} {1050 2450} {1050 2400} {1100 2400} {1100 2300} {1000 2300}\n"
    "boundary 2 1 {1200 2300} {1200 2450} {1250 2450} {1250 2400} {1300 2400} {1300 2300} {1200 2300}\n"
    "boundary 2 1 {1400 2300} {1400 2450} {1450 2450} {1450 2400} {1500 2400} {1500 2300} {1400 2300}\n"
    "boundary 2 1 {1000 2600} {1000 2750} {1050 2750} {1050 2700} {1100 2700} {1100 2600} {1000 2600}\n"
    "boundary 2 1 {1200 2600} {1200 2750} {1250 2750} {1250 2700} {1300 2700} {1300 2600} {1200 2600}\n"
    "boundary 2 1 {1400 2600} {1400 2750} {1450 2750} {1450 2700} {1500 2700} {1500 2600} {1400 2600}\n"
    "boundary 2 1 {1000 2900} {1000 3050} {1050 3050} {1050 3000} {1100 3000} {1100 2900} {1000 2900}\n"
    "boundary 2 1 {1200 2900} {1200 3050} {1250 3050} {1250 3000} {1300 3000} {1300 2900} {1200 2900}\n"
    "boundary 2 1 {1400 2900} {1400 3050} {1450 3050} {1450 3000} {1500 3000} {1500 2900} {1400 2900}\n"
    "boundary 2 1 {2000 2000} {2000 2150} {2050 2150} {2050 2100} {2100 2100} {2100 2000} {2000 2000}\n"
    "boundary 2 1 {2000 2200} {2000 2350} {2050 2350} {2050 2300} {2100 2300} {2100 2200} {2000 2200}\n"
    "boundary 2 1 {2000 2500} {2000 2650} {2050 2650} {2050 2600} {2100 2600} {2100 2500} {2000 2500}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t5.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

#ifndef _MSC_VER // MSVC can't handle the long string

TEST(5_2)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "boundary 2 3 {-1000 0} {-990 20} {-1000 40} {-990 60} {-1000 80} {-990 100} {-1000 120} {-990 140} {-1000 160} {-990 180} {-1000 200} {-990 220} {-1000 240} {-990 260} {-1000 280} {-990 300} {-1000 320} {-990 340} {-1000 360} {-990 380} {-1000 400} {-990 420} {-1000 440} {-990 460} {-1000 480} {-990 500} {-1000 520} {-990 540} {-1000 560} {-990 580} {-1000 600} {-990 620} {-1000 640} {-990 660} {-1000 680} {-990 700} {-1000 720} {-990 740} {-1000 760} {-990 780} {-1000 800} {-990 820} {-1000 840} {-990 860} {-1000 880} {-990 900} {-1000 920} {-990 940} {-1000 960} {-990 980} {-1000 1000} {-990 1020} {-1000 1040} {-990 1060} {-1000 1080} {-990 1100} {-1000 1120} {-990 1140} {-1000 1160} {-990 1180} {-1000 1200} {-990 1220} {-1000 1240} {-990 1260} {-1000 1280} {-990 1300} {-1000 1320} {-990 1340} {-1000 1360} {-990 1380} {-1000 1400} {-990 1420} {-1000 1440} {-990 1460} {-1000 1480} {-990 1500} {-1000 1520} {-990 1540} {-1000 1560} {-990 1580} {-1000 1600} {-990 1620} {-1000 1640} {-990 1660} {-1000 1680} {-990 1700} {-1000 1720} {-990 1740} {-1000 1760} {-990 1780} {-1000 1800} {-990 1820} {-1000 1840} {-990 1860} {-1000 1880} {-990 1900} {-1000 1920} {-990 1940} {-1000 1960} {-990 1980} {-1000 2000} {-990 2020} {-1000 2040} {-990 2060} {-1000 2080} {-990 2100} {-1000 2120} {-990 2140} {-1000 2160} {-990 2180} {-1000 2200} {-990 2220} {-1000 2240} {-990 2260} {-1000 2280} {-990 2300} {-1000 2320} {-990 2340} {-1000 2360} {-990 2380} {-1000 2400} {-990 2420} {-1000 2440} {-990 2460} {-1000 2480} {-990 2500} {-1000 2520} {-990 2540} {-1000 2560} {-990 2580} {-1000 2600} {-990 2620} {-1000 2640} {-990 2660} {-1000 2680} {-990 2700} {-1000 2720} {-990 2740} {-1000 2760} {-990 2780} {-1000 2800} {-990 2820} {-1000 2840} {-990 2860} {-1000 2880} {-990 2900} {-1000 2920} {-990 2940} {-1000 2960} {-990 2980} {-1000 3000} {-990 3020} {-1000 3040} {-990 3060} {-1000 3080} {-990 3100} {-1000 3120} {-990 3140} {-1000 3160} {-990 3180} {-1000 3200} {-990 3220} {-1000 3240} {-990 3260} {-1000 3280} {-990 3300} {-1000 3320} {-990 3340} {-1000 3360} {-990 3380} {-1000 3400} {-990 3420} {-1000 3440} {-990 3460} {-1000 3480} {-990 3500} {-1000 3520} {-990 3540} {-1000 3560} {-990 3580} {-1000 3600} {-990 3620} {-1000 3640} {-990 3660} {-1000 3680} {-990 3700} {-1000 3720} {-990 3740} {-1000 3760} {-990 3780} {-1000 3800} {-990 3820} {-1000 3840} {-990 3860} {-1000 3880} {-990 3900} {-1000 3920} {-990 3940} {-1000 3960} {-990 3980} {-1000 4000} {-990 4020} {-1000 4040} {-990 4060} {-1000 4080} {-990 4100} {-1000 4120} {-990 4140} {-1000 4160} {-990 4180} {-1000 4200} {-990 4220} {-1000 4240} {-990 4260} {-1000 4280} {-990 4300} {-1000 4320} {-990 4340} {-1000 4360} {-990 4380} {-1000 4400} {-990 4420} {-1000 4440} {-990 4460} {-1000 4480} {-990 4500} {-1000 4520} {-990 4540} {-1000 4560} {-990 4580} {-1000 4600} {-990 4620} {-1000 4640} {-990 4660} {-1000 4680} {-990 4700} {-1000 4720} {-990 4740} {-1000 4760} {-990 4780} {-1000 4800} {-990 4820} {-1000 4840} {-990 4860} {-1000 4880} {-990 4900} {-1000 4920} {-990 4940} {-1000 4960} {-990 4980} {-1000 5000} {-990 5020} {-1000 5040} {-990 5060} {-1000 5080} {-990 5100} {-1000 5120} {-990 5140} {-1000 5160} {-990 5180} {-1000 5200} {-990 5220} {-1000 5240} {-990 5260} {-1000 5280} {-990 5300} {-1000 5320} {-990 5340} {-1000 5360} {-990 5380} {-1000 5400} {-990 5420} {-1000 5440} {-990 5460} {-1000 5480} {-990 5500} {-1000 5520} {-990 5540} {-1000 5560} {-990 5580} {-1000 5600} {-990 5620} {-1000 5640} {-990 5660} {-1000 5680} {-990 5700} {-1000 5720} {-990 5740} {-1000 5760} {-990 5780} {-1000 5800} {-990 5820} {-1000 5840} {-990 5860} {-1000 5880} {-990 5900} {-1000 5920} {-990 5940} {-1000 5960} {-990 5980} {-1000 6000} {-990 6020} {-1000 6040} {-990 6060} {-1000 6080} {-990 6100} {-1000 6120} {-990 6140} {-1000 6160} {-990 6180} {-1000 6200} {-990 6220} {-1000 6240} {-990 6260} {-1000 6280} {-990 6300} {-1000 6320} {-990 6340} {-1000 6360} {-990 6380} {-1000 6400} {-990 6420} {-1000 6440} {-990 6460} {-1000 6480} {-990 6500} {-1000 6520} {-990 6540} {-1000 6560} {-990 6580} {-1000 6600} {-990 6620} {-1000 6640} {-990 6660} {-1000 6680} {-990 6700} {-1000 6720} {-990 6740} {-1000 6760} {-990 6780} {-1000 6800} {-990 6820} {-1000 6840} {-990 6860} {-1000 6880} {-990 6900} {-1000 6920} {-990 6940} {-1000 6960} {-990 6980} {-1000 7000} {-990 7020} {-1000 7040} {-990 7060} {-1000 7080} {-990 7100} {-1000 7120} {-990 7140} {-1000 7160} {-990 7180} {-1000 7200} {-990 7220} {-1000 7240} {-990 7260} {-1000 7280} {-990 7300} {-1000 7320} {-990 7340} {-1000 7360} {-990 7380} {-1000 7400} {-990 7420} {-1000 7440} {-990 7460} {-1000 7480} {-990 7500} {-1000 7520} {-990 7540} {-1000 7560} {-990 7580} {-1000 7600} {-990 7620} {-1000 7640} {-990 7660} {-1000 7680} {-990 7700} {-1000 7720} {-990 7740} {-1000 7760} {-990 7780} {-1000 7800} {-990 7820} {-1000 7840} {-990 7860} {-1000 7880} {-990 7900} {-1000 7920} {-990 7940} {-1000 7960} {-990 7980} {-1000 8000} {-990 8020} {-1000 8040} {-990 8060} {-1000 8080} {-990 8100} {-1000 8120} {-990 8140} {-1000 8160} {-990 8180} {-1000 8200} {-990 8220} {-1000 8240} {-990 8260} {-1000 8280} {-990 8300} {-1000 8320} {-990 8340} {-1000 8360} {-990 8380} {-1000 8400} {-990 8420} {-1000 8440} {-990 8460} {-1000 8480} {-990 8500} {-1000 8520} {-990 8540} {-1000 8560} {-990 8580} {-1000 8600} {-990 8620} {-1000 8640} {-990 8660} {-1000 8680} {-990 8700} {-1000 8720} {-990 8740} {-1000 8760} {-990 8780} {-1000 8800} {-990 8820} {-1000 8840} {-990 8860} {-1000 8880} {-990 8900} {-1000 8920} {-990 8940} {-1000 8960} {-990 8980} {-1000 9000} {-990 9020} {-1000 9040} {-990 9060} {-1000 9080} {-990 9100} {-1000 9120} {-990 9140} {-1000 9160} {-990 9180} {-1000 9200} {-990 9220} {-1000 9240} {-990 9260} {-1000 9280} {-990 9300} {-1000 9320} {-990 9340} {-1000 9360} {-990 9380} {-1000 9400} {-990 9420} {-1000 9440} {-990 9460} {-1000 9480} {-990 9500} {-1000 9520} {-990 9540} {-1000 9560} {-990 9580} {-1000 9600} {-990 9620} {-1000 9640} {-990 9660} {-1000 9680} {-990 9700} {-1000 9720} {-990 9740} {-1000 9760} {-990 9780} {-1000 9800} {-990 9820} {-1000 9840} {-990 9860} {-1000 9880} {-990 9900} {-1000 9920} {-990 9940} {-1000 9960} {-990 9980} {-1000 10000} {-990 10020} {-1000 10040} {-990 10060} {-1000 10080} {-990 10100} {-1000 10120} {-990 10140} {-1000 10160} {-990 10180} {-1000 10200} {-990 10220} {-1000 10240} {-990 10260} {-1000 10280} {-990 10300} {-1000 10320} {-990 10340} {-1000 10360} {-990 10380} {-1000 10400} {-990 10420} {-1000 10440} {-990 10460} {-1000 10480} {-990 10500} {-1000 10520} {-990 10540} {-1000 10560} {-990 10580} {-1000 10600} {-990 10620} {-1000 10640} {-990 10660} {-1000 10680} {-990 10700} {-1000 10720} {-990 10740} {-1000 10760} {-990 10780} {-1000 10800} {-990 10820} {-1000 10840} {-990 10860} {-1000 10880} {-990 10900} {-1000 10920} {-990 10940} {-1000 10960} {-990 10980} {-1000 11000} {-990 11020} {-1000 11040} {-990 11060} {-1000 11080} {-990 11100} {-1000 11120} {-990 11140} {-1000 11160} {-990 11180} {-1000 11200} {-990 11220} {-1000 11240} {-990 11260} {-1000 11280} {-990 11300} {-1000 11320} {-990 11340} {-1000 11360} {-990 11380} {-1000 11400} {-990 11420} {-1000 11440} {-990 11460} {-1000 11480} {-990 11500} {-1000 11520} {-990 11540} {-1000 11560} {-990 11580} {-1000 11600} {-990 11620} {-1000 11640} {-990 11660} {-1000 11680} {-990 11700} {-1000 11720} {-990 11740} {-1000 11760} {-990 11780} {-1000 11800} {-990 11820} {-1000 11840} {-990 11860} {-1000 11880} {-990 11900} {-1000 11920} {-990 11940} {-1000 11960} {-990 11980} {-1000 12000} {-990 12020} {-1000 12040} {-990 12060} {-1000 12080} {-990 12100} {-1000 12120} {-990 12140} {-1000 12160} {-990 12180} {-1000 12200} {-990 12220} {-1000 12240} {-990 12260} {-1000 12280} {-990 12300} {-1000 12320} {-990 12340} {-1000 12360} {-990 12380} {-1000 12400} {-990 12420} {-1000 12440} {-990 12460} {-1000 12480} {-990 12500} {-1000 12520} {-990 12540} {-1000 12560} {-990 12580} {-1000 12600} {-990 12620} {-1000 12640} {-990 12660} {-1000 12680} {-990 12700} {-1000 12720} {-990 12740} {-1000 12760} {-990 12780} {-1000 12800} {-990 12820} {-1000 12840} {-990 12860} {-1000 12880} {-990 12900} {-1000 12920} {-990 12940} {-1000 12960} {-990 12980} {-1000 13000} {-990 13020} {-1000 13040} {-990 13060} {-1000 13080} {-990 13100} {-1000 13120} {-990 13140} {-1000 13160} {-990 13180} {-1000 13200} {-990 13220} {-1000 13240} {-990 13260} {-1000 13280} {-990 13300} {-1000 13320} {-990 13340} {-1000 13360} {-990 13380} {-1000 13400} {-990 13420} {-1000 13440} {-990 13460} {-1000 13480} {-990 13500} {-1000 13520} {-990 13540} {-1000 13560} {-990 13580} {-1000 13600} {-990 13620} {-1000 13640} {-990 13660} {-1000 13680} {-990 13700} {-1000 13720} {-990 13740} {-1000 13760} {-990 13780} {-1000 13800} {-990 13820} {-1000 13840} {-990 13860} {-1000 13880} {-990 13900} {-1000 13920} {-990 13940} {-1000 13960} {-990 13980} {-1000 14000} {-990 14020} {-1000 14040} {-990 14060} {-1000 14080} {-990 14100} {-1000 14120} {-990 14140} {-1000 14160} {-990 14180} {-1000 14200} {-990 14220} {-1000 14240} {-990 14260} {-1000 14280} {-990 14300} {-1000 14320} {-990 14340} {-1000 14360} {-990 14380} {-1000 14400} {-990 14420} {-1000 14440} {-990 14460} {-1000 14480} {-990 14500} {-1000 14520} {-990 14540} {-1000 14560} {-990 14580} {-1000 14600} {-990 14620} {-1000 14640} {-990 14660} {-1000 14680} {-990 14700} {-1000 14720} {-990 14740} {-1000 14760} {-990 14780} {-1000 14800} {-990 14820} {-1000 14840} {-990 14860} {-1000 14880} {-990 14900} {-1000 14920} {-990 14940} {-1000 14960} {-990 14980} {-1000 15000} {-990 15020} {-1000 15040} {-990 15060} {-1000 15080} {-990 15100} {-1000 15120} {-990 15140} {-1000 15160} {-990 15180} {-1000 15200} {-990 15220} {-1000 15240} {-990 15260} {-1000 15280} {-990 15300} {-1000 15320} {-990 15340} {-1000 15360} {-990 15380} {-1000 15400} {-990 15420} {-1000 15440} {-990 15460} {-1000 15480} {-990 15500} {-1000 15520} {-990 15540} {-1000 15560} {-990 15580} {-1000 15600} {-990 15620} {-1000 15640} {-990 15660} {-1000 15680} {-990 15700} {-1000 15720} {-990 15740} {-1000 15760} {-990 15780} {-1000 15800} {-990 15820} {-1000 15840} {-990 15860} {-1000 15880} {-990 15900} {-1000 15920} {-990 15940} {-1000 15960} {-990 15980} {-1000 16000} {-990 16020} {-1000 16040} {-990 16060} {-1000 16080} {-990 16100} {-1000 16120} {-990 16140} {-1000 16160} {-990 16180} {-1000 16200} {-990 16220} {-1000 16240} {-990 16260} {-1000 16280} {-990 16300} {-1000 16320} {-990 16340} {-1000 16360} {-990 16380} {-1000 16400} {-990 16420} {-1000 16440} {-990 16460} {-1000 16480} {-990 16500} {-1000 16520} {-990 16540} {-1000 16560} {-990 16580} {-1000 16600} {-990 16620} {-1000 16640} {-990 16660} {-1000 16680} {-990 16700} {-1000 16720} {-990 16740} {-1000 16760} {-990 16780} {-1000 16800} {-990 16820} {-1000 16840} {-990 16860} {-1000 16880} {-990 16900} {-1000 16920} {-990 16940} {-1000 16960} {-990 16980} {-1000 17000} {-990 17020} {-1000 17040} {-990 17060} {-1000 17080} {-990 17100} {-1000 17120} {-990 17140} {-1000 17160} {-990 17180} {-1000 17200} {-990 17220} {-1000 17240} {-990 17260} {-1000 17280} {-990 17300} {-1000 17320} {-990 17340} {-1000 17360} {-990 17380} {-1000 17400} {-990 17420} {-1000 17440} {-990 17460} {-1000 17480} {-990 17500} {-1000 17520} {-990 17540} {-1000 17560} {-990 17580} {-1000 17600} {-990 17620} {-1000 17640} {-990 17660} {-1000 17680} {-990 17700} {-1000 17720} {-990 17740} {-1000 17760} {-990 17780} {-1000 17800} {-990 17820} {-1000 17840} {-990 17860} {-1000 17880} {-990 17900} {-1000 17920} {-990 17940} {-1000 17960} {-990 17980} {-1000 18000} {-990 18020} {-1000 18040} {-990 18060} {-1000 18080} {-990 18100} {-1000 18120} {-990 18140} {-1000 18160} {-990 18180} {-1000 18200} {-990 18220} {-1000 18240} {-990 18260} {-1000 18280} {-990 18300} {-1000 18320} {-990 18340} {-1000 18360} {-990 18380} {-1000 18400} {-990 18420} {-1000 18440} {-990 18460} {-1000 18480} {-990 18500} {-1000 18520} {-990 18540} {-1000 18560} {-990 18580} {-1000 18600} {-990 18620} {-1000 18640} {-990 18660} {-1000 18680} {-990 18700} {-1000 18720} {-990 18740} {-1000 18760} {-990 18780} {-1000 18800} {-990 18820} {-1000 18840} {-990 18860} {-1000 18880} {-990 18900} {-1000 18920} {-990 18940} {-1000 18960} {-990 18980} {-1000 19000} {-990 19020} {-1000 19040} {-990 19060} {-1000 19080} {-990 19100} {-1000 19120} {-990 19140} {-1000 19160} {-990 19180} {-1000 19200} {-990 19220} {-1000 19240} {-990 19260} {-1000 19280} {-990 19300} {-1000 19320} {-990 19340} {-1000 19360} {-990 19380} {-1000 19400} {-990 19420} {-1000 19440} {-990 19460} {-1000 19480} {-990 19500} {-1000 19520} {-990 19540} {-1000 19560} {-990 19580} {-1000 19600} {-990 19620} {-1000 19640} {-990 19660} {-1000 19680} {-990 19700} {-1000 19720} {-990 19740} {-1000 19760} {-990 19780} {-1000 19800} {-990 19820} {-1000 19840} {-990 19860} {-1000 19880} {-990 19900} {-1000 19920} {-990 19940} {-1000 19960} {-990 19980} {-1000 20000} {-990 20020} {-1000 20040} {-990 20060} {-1000 20080} {-990 20100} {-1000 20120} {-990 20140} {-1000 20160} {-990 20180} {-1000 20200} {-990 20220} {-1000 20240} {-990 20260} {-1000 20280} {-990 20300} {-1000 20320} {-990 20340} {-1000 20360} {-990 20380} {-1000 20400} {-990 20420} {-1000 20440} {-990 20460} {-1000 20480} {-990 20500} {-1000 20520} {-990 20540} {-1000 20560} {-990 20580} {-1000 20600} {-990 20620} {-1000 20640} {-990 20660} {-1000 20680} {-990 20700} {-1000 20720} {-990 20740} {-1000 20760} {-990 20780} {-1000 20800} {-990 20820} {-1000 20840} {-990 20860} {-1000 20880} {-990 20900} {-1000 20920} {-990 20940} {-1000 20960} {-990 20980} {-1000 21000} {-990 21020} {-1000 21040} {-990 21060} {-1000 21080} {-990 21100} {-1000 21120} {-990 21140} {-1000 21160} {-990 21180} {-1000 21200} {-990 21220} {-1000 21240} {-990 21260} {-1000 21280} {-990 21300} {-1000 21320} {-990 21340} {-1000 21360} {-990 21380} {-1000 21400} {-990 21420} {-1000 21440} {-990 21460} {-1000 21480} {-990 21500} {-1000 21520} {-990 21540} {-1000 21560} {-990 21580} {-1000 21600} {-990 21620} {-1000 21640} {-990 21660} {-1000 21680} {-990 21700} {-1000 21720} {-990 21740} {-1000 21760} {-990 21780} {-1000 21800} {-990 21820} {-1000 21840} {-990 21860} {-1000 21880} {-990 21900} {-1000 21920} {-990 21940} {-1000 21960} {-990 21980} {-1000 22000} {-990 22020} {-1000 22040} {-990 22060} {-1000 22080} {-990 22100} {-1000 22120} {-990 22140} {-1000 22160} {-990 22180} {-1000 22200} {-990 22220} {-1000 22240} {-990 22260} {-1000 22280} {-990 22300} {-1000 22320} {-990 22340} {-1000 22360} {-990 22380} {-1000 22400} {-990 22420} {-1000 22440} {-990 22460} {-1000 22480} {-990 22500} {-1000 22520} {-990 22540} {-1000 22560} {-990 22580} {-1000 22600} {-990 22620} {-1000 22640} {-990 22660} {-1000 22680} {-990 22700} {-1000 22720} {-990 22740} {-1000 22760} {-990 22780} {-1000 22800} {-990 22820} {-1000 22840} {-990 22860} {-1000 22880} {-990 22900} {-1000 22920} {-990 22940} {-1000 22960} {-990 22980} {-1000 23000} {-990 23020} {-1000 23040} {-990 23060} {-1000 23080} {-990 23100} {-1000 23120} {-990 23140} {-1000 23160} {-990 23180} {-1000 23200} {-990 23220} {-1000 23240} {-990 23260} {-1000 23280} {-990 23300} {-1000 23320} {-990 23340} {-1000 23360} {-990 23380} {-1000 23400} {-990 23420} {-1000 23440} {-990 23460} {-1000 23480} {-990 23500} {-1000 23520} {-990 23540} {-1000 23560} {-990 23580} {-1000 23600} {-990 23620} {-1000 23640} {-990 23660} {-1000 23680} {-990 23700} {-1000 23720} {-990 23740} {-1000 23760} {-990 23780} {-1000 23800} {-990 23820} {-1000 23840} {-990 23860} {-1000 23880} {-990 23900} {-1000 23920} {-990 23940} {-1000 23960} {-990 23980} {-1000 24000} {-990 24020} {-1000 24040} {-990 24060} {-1000 24080} {-990 24100} {-1000 24120} {-990 24140} {-1000 24160} {-990 24180} {-1000 24200} {-990 24220} {-1000 24240} {-990 24260} {-1000 24280} {-990 24300} {-1000 24320} {-990 24340} {-1000 24360} {-990 24380} {-1000 24400} {-990 24420} {-1000 24440} {-990 24460} {-1000 24480} {-990 24500} {-1000 24520} {-990 24540} {-1000 24560} {-990 24580} {-1000 24600} {-990 24620} {-1000 24640} {-990 24660} {-1000 24680} {-990 24700} {-1000 24720} {-990 24740} {-1000 24760} {-990 24780} {-1000 24800} {-990 24820} {-1000 24840} {-990 24860} {-1000 24880} {-990 24900} {-1000 24920} {-990 24940} {-1000 24960} {-990 24980} {-1000 25000} {-990 25020} {-1000 25040} {-990 25060} {-1000 25080} {-990 25100} {-1000 25120} {-990 25140} {-1000 25160} {-990 25180} {-1000 25200} {-990 25220} {-1000 25240} {-990 25260} {-1000 25280} {-990 25300} {-1000 25320} {-990 25340} {-1000 25360} {-990 25380} {-1000 25400} {-990 25420} {-1000 25440} {-990 25460} {-1000 25480} {-990 25500} {-1000 25520} {-990 25540} {-1000 25560} {-990 25580} {-1000 25600} {-990 25620} {-1000 25640} {-990 25660} {-1000 25680} {-990 25700} {-1000 25720} {-990 25740} {-1000 25760} {-990 25780} {-1000 25800} {-990 25820} {-1000 25840} {-990 25860} {-1000 25880} {-990 25900} {-1000 25920} {-990 25940} {-1000 25960} {-990 25980} {-1000 26000} {-990 26020} {-1000 26040} {-990 26060} {-1000 26080} {-990 26100} {-1000 26120} {-990 26140} {-1000 26160} {-990 26180} {-1000 26200} {-990 26220} {-1000 26240} {-990 26260} {-1000 26280} {-990 26300} {-1000 26320} {-990 26340} {-1000 26360} {-990 26380} {-1000 26400} {-990 26420} {-1000 26440} {-990 26460} {-1000 26480} {-990 26500} {-1000 26520} {-990 26540} {-1000 26560} {-990 26580} {-1000 26600} {-990 26620} {-1000 26640} {-990 26660} {-1000 26680} {-990 26700} {-1000 26720} {-990 26740} {-1000 26760} {-990 26780} {-1000 26800} {-990 26820} {-1000 26840} {-990 26860} {-1000 26880} {-990 26900} {-1000 26920} {-990 26940} {-1000 26960} {-990 26980} {-1000 27000} {-990 27020} {-1000 27040} {-990 27060} {-1000 27080} {-990 27100} {-1000 27120} {-990 27140} {-1000 27160} {-990 27180} {-1000 27200} {-990 27220} {-1000 27240} {-990 27260} {-1000 27280} {-990 27300} {-1000 27320} {-990 27340} {-1000 27360} {-990 27380} {-1000 27400} {-990 27420} {-1000 27440} {-990 27460} {-1000 27480} {-990 27500} {-1000 27520} {-990 27540} {-1000 27560} {-990 27580} {-1000 27600} {-990 27620} {-1000 27640} {-990 27660} {-1000 27680} {-990 27700} {-1000 27720} {-990 27740} {-1000 27760} {-990 27780} {-1000 27800} {-990 27820} {-1000 27840} {-990 27860} {-1000 27880} {-990 27900} {-1000 27920} {-990 27940} {-1000 27960} {-990 27980} {-1000 28000} {-990 28020} {-1000 28040} {-990 28060} {-1000 28080} {-990 28100} {-1000 28120} {-990 28140} {-1000 28160} {-990 28180} {-1000 28200} {-990 28220} {-1000 28240} {-990 28260} {-1000 28280} {-990 28300} {-1000 28320} {-990 28340} {-1000 28360} {-990 28380} {-1000 28400} {-990 28420} {-1000 28440} {-990 28460} {-1000 28480} {-990 28500} {-1000 28520} {-990 28540} {-1000 28560} {-990 28580} {-1000 28600} {-990 28620} {-1000 28640} {-990 28660} {-1000 28680} {-990 28700} {-1000 28720} {-990 28740} {-1000 28760} {-990 28780} {-1000 28800} {-990 28820} {-1000 28840} {-990 28860} {-1000 28880} {-990 28900} {-1000 28920} {-990 28940} {-1000 28960} {-990 28980} {-1000 29000} {-990 29020} {-1000 29040} {-990 29060} {-1000 29080} {-990 29100} {-1000 29120} {-990 29140} {-1000 29160} {-990 29180} {-1000 29200} {-990 29220} {-1000 29240} {-990 29260} {-1000 29280} {-990 29300} {-1000 29320} {-990 29340} {-1000 29360} {-990 29380} {-1000 29400} {-990 29420} {-1000 29440} {-990 29460} {-1000 29480} {-990 29500} {-1000 29520} {-990 29540} {-1000 29560} {-990 29580} {-1000 29600} {-990 29620} {-1000 29640} {-990 29660} {-1000 29680} {-990 29700} {-1000 29720} {-990 29740} {-1000 29760} {-990 29780} {-1000 29800} {-990 29820} {-1000 29840} {-990 29860} {-1000 29880} {-990 29900} {-1000 29920} {-990 29940} {-1000 29960} {-990 29980} {-1000 30000} {-990 30020} {-1000 30040} {-990 30060} {-1000 30080} {-990 30100} {-1000 30120} {-990 30140} {-1000 30160} {-990 30180} {-1000 30200} {-990 30220} {-1000 30240} {-990 30260} {-1000 30280} {-990 30300} {-1000 30320} {-990 30340} {-1000 30360} {-990 30380} {-1000 30400} {-990 30420} {-1000 30440} {-990 30460} {-1000 30480} {-990 30500} {-1000 30520} {-990 30540} {-1000 30560} {-990 30580} {-1000 30600} {-990 30620} {-1000 30640} {-990 30660} {-1000 30680} {-990 30700} {-1000 30720} {-990 30740} {-1000 30760} {-990 30780} {-1000 30800} {-990 30820} {-1000 30840} {-990 30860} {-1000 30880} {-990 30900} {-1000 30920} {-990 30940} {-1000 30960} {-990 30980} {-1000 31000} {-990 31020} {-1000 31040} {-990 31060} {-1000 31080} {-990 31100} {-1000 31120} {-990 31140} {-1000 31160} {-990 31180} {-1000 31200} {-990 31220} {-1000 31240} {-990 31260} {-1000 31280} {-990 31300} {-1000 31320} {-990 31340} {-1000 31360} {-990 31380} {-1000 31400} {-990 31420} {-1000 31440} {-990 31460} {-1000 31480} {-990 31500} {-1000 31520} {-990 31540} {-1000 31560} {-990 31580} {-1000 31600} {-990 31620} {-1000 31640} {-990 31660} {-1000 31680} {-990 31700} {-1000 31720} {-990 31740} {-1000 31760} {-990 31780} {-1000 31800} {-990 31820} {-1000 31840} {-990 31860} {-1000 31880} {-990 31900} {-1000 31920} {-990 31940} {-1000 31960} {-990 31980} {-1000 32000} {-990 32020} {-1000 32040} {-990 32060} {-1000 32080} {-990 32100} {-1000 32120} {-990 32140} {-1000 32160} {-990 32180} {-1000 32200} {-990 32220} {-1000 32240} {-990 32260} {-1000 32280} {-990 32300} {-1000 32320} {-990 32340} {-1000 32360} {-990 32380} {-1000 32400} {-990 32420} {-1000 32440} {-990 32460} {-1000 32480} {-990 32500} {-1000 32520} {-990 32540} {-1000 32560} {-990 32580} {-1000 32600} {-990 32620} {-1000 32640} {-990 32660} {-1000 32680} {-990 32700} {-1000 32720} {-990 32740} {-1000 32760} {-990 32780} {-1000 32800} {-990 32820} {-1000 32840} {-990 32860} {-1000 32880} {-990 32900} {-1000 32920} {-990 32940} {-1000 32960} {-990 32980} {-1000 33000} {-990 33020} {-1000 33040} {-990 33060} {-1000 33080} {-990 33100} {-1000 33120} {-990 33140} {-1000 33160} {-990 33180} {-1000 33200} {-990 33220} {-1000 33240} {-990 33260} {-1000 33280} {-990 33300} {-1000 33320} {-990 33340} {-1000 33360} {-990 33380} {-1000 33400} {-990 33420} {-1000 33440} {-990 33460} {-1000 33480} {-990 33500} {-1000 33520} {-990 33540} {-1000 33560} {-990 33580} {-1000 33600} {-990 33620} {-1000 33640} {-990 33660} {-1000 33680} {-990 33700} {-1000 33720} {-990 33740} {-1000 33760} {-990 33780} {-1000 33800} {-990 33820} {-1000 33840} {-990 33860} {-1000 33880} {-990 33900} {-1000 33920} {-990 33940} {-1000 33960} {-990 33980} {-1000 34000} {-990 34020} {-1000 34040} {-990 34060} {-1000 34080} {-990 34100} {-1000 34120} {-990 34140} {-1000 34160} {-990 34180} {-1000 34200} {-990 34220} {-1000 34240} {-990 34260} {-1000 34280} {-990 34300} {-1000 34320} {-990 34340} {-1000 34360} {-990 34380} {-1000 34400} {-990 34420} {-1000 34440} {-990 34460} {-1000 34480} {-990 34500} {-1000 34520} {-990 34540} {-1000 34560} {-990 34580} {-1000 34600} {-990 34620} {-1000 34640} {-990 34660} {-1000 34680} {-990 34700} {-1000 34720} {-990 34740} {-1000 34760} {-990 34780} {-1000 34800} {-990 34820} {-1000 34840} {-990 34860} {-1000 34880} {-990 34900} {-1000 34920} {-990 34940} {-1000 34960} {-990 34980} {-1000 35000} {-990 35020} {-1000 35040} {-990 35060} {-1000 35080} {-990 35100} {-1000 35120} {-990 35140} {-1000 35160} {-990 35180} {-1000 35200} {-990 35220} {-1000 35240} {-990 35260} {-1000 35280} {-990 35300} {-1000 35320} {-990 35340} {-1000 35360} {-990 35380} {-1000 35400} {-990 35420} {-1000 35440} {-990 35460} {-1000 35480} {-990 35500} {-1000 35520} {-990 35540} {-1000 35560} {-990 35580} {-1000 35600} {-990 35620} {-1000 35640} {-990 35660} {-1000 35680} {-990 35700} {-1000 35720} {-990 35740} {-1000 35760} {-990 35780} {-1000 35800} {-990 35820} {-1000 35840} {-990 35860} {-1000 35880} {-990 35900} {-1000 35920} {-990 35940} {-1000 35960} {-990 35980} {-1000 36000} {-990 36020} {-1000 36040} {-990 36060} {-1000 36080} {-990 36100} {-1000 36120} {-990 36140} {-1000 36160} {-990 36180} {-1000 36200} {-990 36220} {-1000 36240} {-990 36260} {-1000 36280} {-990 36300} {-1000 36320} {-990 36340} {-1000 36360} {-990 36380} {-1000 36400} {-990 36420} {-1000 36440} {-990 36460} {-1000 36480} {-990 36500} {-1000 36520} {-990 36540} {-1000 36560} {-990 36580} {-1000 36600} {-990 36620} {-1000 36640} {-990 36660} {-1000 36680} {-990 36700} {-1000 36720} {-990 36740} {-1000 36760} {-990 36780} {-1000 36800} {-990 36820} {-1000 36840} {-990 36860} {-1000 36880} {-990 36900} {-1000 36920} {-990 36940} {-1000 36960} {-990 36980} {-1000 37000} {-990 37020} {-1000 37040} {-990 37060} {-1000 37080} {-990 37100} {-1000 37120} {-990 37140} {-1000 37160} {-990 37180} {-1000 37200} {-990 37220} {-1000 37240} {-990 37260} {-1000 37280} {-990 37300} {-1000 37320} {-990 37340} {-1000 37360} {-990 37380} {-1000 37400} {-990 37420} {-1000 37440} {-990 37460} {-1000 37480} {-990 37500} {-1000 37520} {-990 37540} {-1000 37560} {-990 37580} {-1000 37600} {-990 37620} {-1000 37640} {-990 37660} {-1000 37680} {-990 37700} {-1000 37720} {-990 37740} {-1000 37760} {-990 37780} {-1000 37800} {-990 37820} {-1000 37840} {-990 37860} {-1000 37880} {-990 37900} {-1000 37920} {-990 37940} {-1000 37960} {-990 37980} {-1000 38000} {-990 38020} {-1000 38040} {-990 38060} {-1000 38080} {-990 38100} {-1000 38120} {-990 38140} {-1000 38160} {-990 38180} {-1000 38200} {-990 38220} {-1000 38240} {-990 38260} {-1000 38280} {-990 38300} {-1000 38320} {-990 38340} {-1000 38360} {-990 38380} {-1000 38400} {-990 38420} {-1000 38440} {-990 38460} {-1000 38480} {-990 38500} {-1000 38520} {-990 38540} {-1000 38560} {-990 38580} {-1000 38600} {-990 38620} {-1000 38640} {-990 38660} {-1000 38680} {-990 38700} {-1000 38720} {-990 38740} {-1000 38760} {-990 38780} {-1000 38800} {-990 38820} {-1000 38840} {-990 38860} {-1000 38880} {-990 38900} {-1000 38920} {-990 38940} {-1000 38960} {-990 38980} {-1000 39000} {-990 39020} {-1000 39040} {-990 39060} {-1000 39080} {-990 39100} {-1000 39120} {-990 39140} {-1000 39160} {-990 39180} {-1000 39200} {-990 39220} {-1000 39240} {-990 39260} {-1000 39280} {-990 39300} {-1000 39320} {-990 39340} {-1000 39360} {-990 39380} {-1000 39400} {-990 39420} {-1000 39440} {-990 39460} {-1000 39480} {-990 39500} {-1000 39520} {-990 39540} {-1000 39560} {-990 39580} {-1000 39600} {-990 39620} {-1000 39640} {-990 39660} {-1000 39680} {-990 39700} {-1000 39720} {-990 39740} {-1000 39760} {-990 39780} {-1000 39800} {-990 39820} {-1000 39840} {-990 39860} {-1000 39880} {-990 39900} {-1000 39920} {-990 39940} {-1000 39960} {-990 39980} {-1000 40000} {-990 40020} {-1000 40040} {-990 40060} {-1000 40080} {-990 40100} {-1000 40120} {-990 40140} {-1000 40160} {-990 40180} {-1000 40200} {-990 40220} {-1000 40240} {-990 40260} {-1000 40280} {-990 40300} {-1000 40320} {-990 40340} {-1000 40360} {-990 40380} {-1000 40400} {-990 40420} {-1000 40440} {-990 40460} {-1000 40480} {-990 40500} {-1000 40520} {-990 40540} {-1000 40560} {-990 40580} {-1000 40600} {-990 40620} {-1000 40640} {-990 40660} {-1000 40680} {-990 40700} {-1000 40720} {-990 40740} {-1000 40760} {-990 40780} {-1000 40800} {-990 40820} {-1000 40840} {-990 40860} {-1000 40880} {-990 40900} {-1000 40920} {-990 40940} {-1000 40960} {-990 40980} {-1000 41000} {-990 41020} {-1000 41040} {-990 41060} {-1000 41080} {-990 41100} {-1000 41120} {-990 41140} {-1000 41160} {-990 41180} {-1000 41200} {-990 41220} {-1000 41240} {-990 41260} {-1000 41280} {-990 41300} {-1000 41320} {-990 41340} {-1000 41360} {-990 41380} {-1000 41400} {-990 41420} {-1000 41440} {-990 41460} {-1000 41480} {-990 41500} {-1000 41520} {-990 41540} {-1000 41560} {-990 41580} {-1000 41600} {-990 41620} {-1000 41640} {-990 41660} {-1000 41680} {-990 41700} {-1000 41720} {-990 41740} {-1000 41760} {-990 41780} {-1000 41800} {-990 41820} {-1000 41840} {-990 41860} {-1000 41880} {-990 41900} {-1000 41920} {-990 41940} {-1000 41960} {-990 41980} {-1000 42000} {-990 42020} {-1000 42040} {-990 42060} {-1000 42080} {-990 42100} {-1000 42120} {-990 42140} {-1000 42160} {-990 42180} {-1000 42200} {-990 42220} {-1000 42240} {-990 42260} {-1000 42280} {-990 42300} {-1000 42320} {-990 42340} {-1000 42360} {-990 42380} {-1000 42400} {-990 42420} {-1000 42440} {-990 42460} {-1000 42480} {-990 42500} {-1000 42520} {-990 42540} {-1000 42560} {-990 42580} {-1000 42600} {-990 42620} {-1000 42640} {-990 42660} {-1000 42680} {-990 42700} {-1000 42720} {-990 42740} {-1000 42760} {-990 42780} {-1000 42800} {-990 42820} {-1000 42840} {-990 42860} {-1000 42880} {-990 42900} {-1000 42920} {-990 42940} {-1000 42960} {-990 42980} {-1000 43000} {-990 43020} {-1000 43040} {-990 43060} {-1000 43080} {-990 43100} {-1000 43120} {-990 43140} {-1000 43160} {-990 43180} {-1000 43200} {-990 43220} {-1000 43240} {-990 43260} {-1000 43280} {-990 43300} {-1000 43320} {-990 43340} {-1000 43360} {-990 43380} {-1000 43400} {-990 43420} {-1000 43440} {-990 43460} {-1000 43480} {-990 43500} {-1000 43520} {-990 43540} {-1000 43560} {-990 43580} {-1000 43600} {-990 43620} {-1000 43640} {-990 43660} {-1000 43680} {-990 43700} {-1000 43720} {-990 43740} {-1000 43760} {-990 43780} {-1000 43800} {-990 43820} {-1000 43840} {-990 43860} {-1000 43880} {-990 43900} {-1000 43920} {-990 43940} {-1000 43960} {-990 43980} {-1000 44000} {-990 44020} {-1000 44040} {-990 44060} {-1000 44080} {-990 44100} {-1000 44120} {-990 44140} {-1000 44160} {-990 44180} {-1000 44200} {-990 44220} {-1000 44240} {-990 44260} {-1000 44280} {-990 44300} {-1000 44320} {-990 44340} {-1000 44360} {-990 44380} {-1000 44400} {-990 44420} {-1000 44440} {-990 44460} {-1000 44480} {-990 44500} {-1000 44520} {-990 44540} {-1000 44560} {-990 44580} {-1000 44600} {-990 44620} {-1000 44640} {-990 44660} {-1000 44680} {-990 44700} {-1000 44720} {-990 44740} {-1000 44760} {-990 44780} {-1000 44800} {-990 44820} {-1000 44840} {-990 44860} {-1000 44880} {-990 44900} {-1000 44920} {-990 44940} {-1000 44960} {-990 44980} {-1000 45000} {-990 45020} {-1000 45040} {-990 45060} {-1000 45080} {-990 45100} {-1000 45120} {-990 45140} {-1000 45160} {-990 45180} {-1000 45200} {-990 45220} {-1000 45240} {-990 45260} {-1000 45280} {-990 45300} {-1000 45320} {-990 45340} {-1000 45360} {-990 45380} {-1000 45400} {-990 45420} {-1000 45440} {-990 45460} {-1000 45480} {-990 45500} {-1000 45520} {-990 45540} {-1000 45560} {-990 45580} {-1000 45600} {-990 45620} {-1000 45640} {-990 45660} {-1000 45680} {-990 45700} {-1000 45720} {-990 45740} {-1000 45760} {-990 45780} {-1000 45800} {-990 45820} {-1000 45840} {-990 45860} {-1000 45880} {-990 45900} {-1000 45920} {-990 45940} {-1000 45960} {-990 45980} {-1000 46000} {-990 46020} {-1000 46040} {-990 46060} {-1000 46080} {-990 46100} {-1000 46120} {-990 46140} {-1000 46160} {-990 46180} {-1000 46200} {-990 46220} {-1000 46240} {-990 46260} {-1000 46280} {-990 46300} {-1000 46320} {-990 46340} {-1000 46360} {-990 46380} {-1000 46400} {-990 46420} {-1000 46440} {-990 46460} {-1000 46480} {-990 46500} {-1000 46520} {-990 46540} {-1000 46560} {-990 46580} {-1000 46600} {-990 46620} {-1000 46640} {-990 46660} {-1000 46680} {-990 46700} {-1000 46720} {-990 46740} {-1000 46760} {-990 46780} {-1000 46800} {-990 46820} {-1000 46840} {-990 46860} {-1000 46880} {-990 46900} {-1000 46920} {-990 46940} {-1000 46960} {-990 46980} {-1000 47000} {-990 47020} {-1000 47040} {-990 47060} {-1000 47080} {-990 47100} {-1000 47120} {-990 47140} {-1000 47160} {-990 47180} {-1000 47200} {-990 47220} {-1000 47240} {-990 47260} {-1000 47280} {-990 47300} {-1000 47320} {-990 47340} {-1000 47360} {-990 47380} {-1000 47400} {-990 47420} {-1000 47440} {-990 47460} {-1000 47480} {-990 47500} {-1000 47520} {-990 47540} {-1000 47560} {-990 47580} {-1000 47600} {-990 47620} {-1000 47640} {-990 47660} {-1000 47680} {-990 47700} {-1000 47720} {-990 47740} {-1000 47760} {-990 47780} {-1000 47800} {-990 47820} {-1000 47840} {-990 47860} {-1000 47880} {-990 47900} {-1000 47920} {-990 47940} {-1000 47960} {-990 47980} {-1000 48000} {-990 48020} {-1000 48040} {-990 48060} {-1000 48080} {-990 48100} {-1000 48120} {-990 48140} {-1000 48160} {-990 48180} {-1000 48200} {-990 48220} {-1000 48240} {-990 48260} {-1000 48280} {-990 48300} {-1000 48320} {-990 48340} {-1000 48360} {-990 48380} {-1000 48400} {-990 48420} {-1000 48440} {-990 48460} {-1000 48480} {-990 48500} {-1000 48520} {-990 48540} {-1000 48560} {-990 48580} {-1000 48600} {-990 48620} {-1000 48640} {-990 48660} {-1000 48680} {-990 48700} {-1000 48720} {-990 48740} {-1000 48760} {-990 48780} {-1000 48800} {-990 48820} {-1000 48840} {-990 48860} {-1000 48880} {-990 48900} {-1000 48920} {-990 48940} {-1000 48960} {-990 48980} {-1000 49000} {-990 49020} {-1000 49040} {-990 49060} {-1000 49080} {-990 49100} {-1000 49120} {-990 49140} {-1000 49160} {-990 49180} {-1000 49200} {-990 49220} {-1000 49240} {-990 49260} {-1000 49280} {-990 49300} {-1000 49320} {-990 49340} {-1000 49360} {-990 49380} {-1000 49400} {-990 49420} {-1000 49440} {-990 49460} {-1000 49480} {-990 49500} {-1000 49520} {-990 49540} {-1000 49560} {-990 49580} {-1000 49600} {-990 49620} {-1000 49640} {-990 49660} {-1000 49680} {-990 49700} {-1000 49720} {-990 49740} {-1000 49760} {-990 49780} {-1000 49800} {-990 49820} {-1000 49840} {-990 49860} {-1000 49880} {-990 49900} {-1000 49920} {-990 49940} {-1000 49960} {-990 49980} {-1000 50000} {-990 50020} {-1000 50040} {-990 50060} {-1000 50080} {-990 50100} {-1000 50120} {-990 50140} {-1000 50160} {-990 50180} {-1000 50200} {-990 50220} {-1000 50240} {-990 50260} {-1000 50280} {-990 50300} {-1000 50320} {-990 50340} {-1000 50360} {-990 50380} {-1000 50400} {-990 50420} {-1000 50440} {-990 50460} {-1000 50480} {-990 50500} {-1000 50520} {-990 50540} {-1000 50560} {-990 50580} {-1000 50600} {-990 50620} {-1000 50640} {-990 50660} {-1000 50680} {-990 50700} {-1000 50720} {-990 50740} {-1000 50760} {-990 50780} {-1000 50800} {-990 50820} {-1000 50840} {-990 50860} {-1000 50880} {-990 50900} {-1000 50920} {-990 50940} {-1000 50960} {-990 50980} {-1000 51000} {-990 51020} {-1000 51040} {-990 51060} {-1000 51080} {-990 51100} {-1000 51120} {-990 51140} {-1000 51160} {-990 51180} {-1000 51200} {-990 51220} {-1000 51240} {-990 51260} {-1000 51280} {-990 51300} {-1000 51320} {-990 51340} {-1000 51360} {-990 51380} {-1000 51400} {-990 51420} {-1000 51440} {-990 51460} {-1000 51480} {-990 51500} {-1000 51520} {-990 51540} {-1000 51560} {-990 51580} {-1000 51600} {-990 51620} {-1000 51640} {-990 51660} {-1000 51680} {-990 51700} {-1000 51720} {-990 51740} {-1000 51760} {-990 51780} {-1000 51800} {-990 51820} {-1000 51840} {-990 51860} {-1000 51880} {-990 51900} {-1000 51920} {-990 51940} {-1000 51960} {-990 51980} {-1000 52000} {-990 52020} {-1000 52040} {-990 52060} {-1000 52080} {-990 52100} {-1000 52120} {-990 52140} {-1000 52160} {-990 52180} {-1000 52200} {-990 52220} {-1000 52240} {-990 52260} {-1000 52280} {-990 52300} {-1000 52320} {-990 52340} {-1000 52360} {-990 52380} {-1000 52400} {-990 52420} {-1000 52440} {-990 52460} {-1000 52480} {-990 52500} {-1000 52520} {-990 52540} {-1000 52560} {-990 52580} {-1000 52600} {-990 52620} {-1000 52640} {-990 52660} {-1000 52680} {-990 52700} {-1000 52720} {-990 52740} {-1000 52760} {-990 52780} {-1000 52800} {-990 52820} {-1000 52840} {-990 52860} {-1000 52880} {-990 52900} {-1000 52920} {-990 52940} {-1000 52960} {-990 52980} {-1000 53000} {-990 53020} {-1000 53040} {-990 53060} {-1000 53080} {-990 53100} {-1000 53120} {-990 53140} {-1000 53160} {-990 53180} {-1000 53200} {-990 53220} {-1000 53240} {-990 53260} {-1000 53280} {-990 53300} {-1000 53320} {-990 53340} {-1000 53360} {-990 53380} {-1000 53400} {-990 53420} {-1000 53440} {-990 53460} {-1000 53480} {-990 53500} {-1000 53520} {-990 53540} {-1000 53560} {-990 53580} {-1000 53600} {-990 53620} {-1000 53640} {-990 53660} {-1000 53680} {-990 53700} {-1000 53720} {-990 53740} {-1000 53760} {-990 53780} {-1000 53800} {-990 53820} {-1000 53840} {-990 53860} {-1000 53880} {-990 53900} {-1000 53920} {-990 53940} {-1000 53960} {-990 53980} {-1000 54000} {-990 54020} {-1000 54040} {-990 54060} {-1000 54080} {-990 54100} {-1000 54120} {-990 54140} {-1000 54160} {-990 54180} {-1000 54200} {-990 54220} {-1000 54240} {-990 54260} {-1000 54280} {-990 54300} {-1000 54320} {-990 54340} {-1000 54360} {-990 54380} {-1000 54400} {-990 54420} {-1000 54440} {-990 54460} {-1000 54480} {-990 54500} {-1000 54520} {-990 54540} {-1000 54560} {-990 54580} {-1000 54600} {-990 54620} {-1000 54640} {-990 54660} {-1000 54680} {-990 54700} {-1000 54720} {-990 54740} {-1000 54760} {-990 54780} {-1000 54800} {-990 54820} {-1000 54840} {-990 54860} {-1000 54880} {-990 54900} {-1000 54920} {-990 54940} {-1000 54960} {-990 54980} {-1000 55000} {-990 55020} {-1000 55040} {-990 55060} {-1000 55080} {-990 55100} {-1000 55120} {-990 55140} {-1000 55160} {-990 55180} {-1000 55200} {-990 55220} {-1000 55240} {-990 55260} {-1000 55280} {-990 55300} {-1000 55320} {-990 55340} {-1000 55360} {-990 55380} {-1000 55400} {-990 55420} {-1000 55440} {-990 55460} {-1000 55480} {-990 55500} {-1000 55520} {-990 55540} {-1000 55560} {-990 55580} {-1000 55600} {-990 55620} {-1000 55640} {-990 55660} {-1000 55680} {-990 55700} {-1000 55720} {-990 55740} {-1000 55760} {-990 55780} {-1000 55800} {-990 55820} {-1000 55840} {-990 55860} {-1000 55880} {-990 55900} {-1000 55920} {-990 55940} {-1000 55960} {-990 55980} {-1000 56000} {-990 56020} {-1000 56040} {-990 56060} {-1000 56080} {-990 56100} {-1000 56120} {-990 56140} {-1000 56160} {-990 56180} {-1000 56200} {-990 56220} {-1000 56240} {-990 56260} {-1000 56280} {-990 56300} {-1000 56320} {-990 56340} {-1000 56360} {-990 56380} {-1000 56400} {-990 56420} {-1000 56440} {-990 56460} {-1000 56480} {-990 56500} {-1000 56520} {-990 56540} {-1000 56560} {-990 56580} {-1000 56600} {-990 56620} {-1000 56640} {-990 56660} {-1000 56680} {-990 56700} {-1000 56720} {-990 56740} {-1000 56760} {-990 56780} {-1000 56800} {-990 56820} {-1000 56840} {-990 56860} {-1000 56880} {-990 56900} {-1000 56920} {-990 56940} {-1000 56960} {-990 56980} {-1000 57000} {-990 57020} {-1000 57040} {-990 57060} {-1000 57080} {-990 57100} {-1000 57120} {-990 57140} {-1000 57160} {-990 57180} {-1000 57200} {-990 57220} {-1000 57240} {-990 57260} {-1000 57280} {-990 57300} {-1000 57320} {-990 57340} {-1000 57360} {-990 57380} {-1000 57400} {-990 57420} {-1000 57440} {-990 57460} {-1000 57480} {-990 57500} {-1000 57520} {-990 57540} {-1000 57560} {-990 57580} {-1000 57600} {-990 57620} {-1000 57640} {-990 57660} {-1000 57680} {-990 57700} {-1000 57720} {-990 57740} {-1000 57760} {-990 57780} {-1000 57800} {-990 57820} {-1000 57840} {-990 57860} {-1000 57880} {-990 57900} {-1000 57920} {-990 57940} {-1000 57960} {-990 57980} {-1000 58000} {-990 58020} {-1000 58040} {-990 58060} {-1000 58080} {-990 58100} {-1000 58120} {-990 58140} {-1000 58160} {-990 58180} {-1000 58200} {-990 58220} {-1000 58240} {-990 58260} {-1000 58280} {-990 58300} {-1000 58320} {-990 58340} {-1000 58360} {-990 58380} {-1000 58400} {-990 58420} {-1000 58440} {-990 58460} {-1000 58480} {-990 58500} {-1000 58520} {-990 58540} {-1000 58560} {-990 58580} {-1000 58600} {-990 58620} {-1000 58640} {-990 58660} {-1000 58680} {-990 58700} {-1000 58720} {-990 58740} {-1000 58760} {-990 58780} {-1000 58800} {-990 58820} {-1000 58840} {-990 58860} {-1000 58880} {-990 58900} {-1000 58920} {-990 58940} {-1000 58960} {-990 58980} {-1000 59000} {-990 59020} {-1000 59040} {-990 59060} {-1000 59080} {-990 59100} {-1000 59120} {-990 59140} {-1000 59160} {-990 59180} {-1000 59200} {-990 59220} {-1000 59240} {-990 59260} {-1000 59280} {-990 59300} {-1000 59320} {-990 59340} {-1000 59360} {-990 59380} {-1000 59400} {-990 59420} {-1000 59440} {-990 59460} {-1000 59480} {-990 59500} {-1000 59520} {-990 59540} {-1000 59560} {-990 59580} {-1000 59600} {-990 59620} {-1000 59640} {-990 59660} {-1000 59680} {-990 59700} {-1000 59720} {-990 59740} {-1000 59760} {-990 59780} {-1000 59800} {-990 59820} {-1000 59840} {-990 59860} {-1000 59880} {-990 59900} {-1000 59920} {-990 59940} {-1000 59960} {-990 59980} {-1000 60000} {-990 60020} {-1000 60040} {-990 60060} {-1000 60080} {-990 60100} {-1000 60120} {-990 60140} {-1000 60160} {-990 60180} {-1000 60200} {-990 60220} {-1000 60240} {-990 60260} {-1000 60280} {-990 60300} {-1000 60320} {-990 60340} {-1000 60360} {-990 60380} {-1000 60400} {-990 60420} {-1000 60440} {-990 60460} {-1000 60480} {-990 60500} {-1000 60520} {-990 60540} {-1000 60560} {-990 60580} {-1000 60600} {-990 60620} {-1000 60640} {-990 60660} {-1000 60680} {-990 60700} {-1000 60720} {-990 60740} {-1000 60760} {-990 60780} {-1000 60800} {-990 60820} {-1000 60840} {-990 60860} {-1000 60880} {-990 60900} {-1000 60920} {-990 60940} {-1000 60960} {-990 60980} {-1000 61000} {-990 61020} {-1000 61040} {-990 61060} {-1000 61080} {-990 61100} {-1000 61120} {-990 61140} {-1000 61160} {-990 61180} {-1000 61200} {-990 61220} {-1000 61240} {-990 61260} {-1000 61280} {-990 61300} {-1000 61320} {-990 61340} {-1000 61360} {-990 61380} {-1000 61400} {-990 61420} {-1000 61440} {-990 61460} {-1000 61480} {-990 61500} {-1000 61520} {-990 61540} {-1000 61560} {-990 61580} {-1000 61600} {-990 61620} {-1000 61640} {-990 61660} {-1000 61680} {-990 61700} {-1000 61720} {-990 61740} {-1000 61760} {-990 61780} {-1000 61800} {-990 61820} {-1000 61840} {-990 61860} {-1000 61880} {-990 61900} {-1000 61920} {-990 61940} {-1000 61960} {-990 61980} {-1000 62000} {-990 62020} {-1000 62040} {-990 62060} {-1000 62080} {-990 62100} {-1000 62120} {-990 62140} {-1000 62160} {-990 62180} {-1000 62200} {-990 62220} {-1000 62240} {-990 62260} {-1000 62280} {-990 62300} {-1000 62320} {-990 62340} {-1000 62360} {-990 62380} {-1000 62400} {-990 62420} {-1000 62440} {-990 62460} {-1000 62480} {-990 62500} {-1000 62520} {-990 62540} {-1000 62560} {-990 62580} {-1000 62600} {-990 62620} {-1000 62640} {-990 62660} {-1000 62680} {-990 62700} {-1000 62720} {-990 62740} {-1000 62760} {-990 62780} {-1000 62800} {-990 62820} {-1000 62840} {-990 62860} {-1000 62880} {-990 62900} {-1000 62920} {-990 62940} {-1000 62960} {-990 62980} {-1000 63000} {-990 63020} {-1000 63040} {-990 63060} {-1000 63080} {-990 63100} {-1000 63120} {-990 63140} {-1000 63160} {-990 63180} {-1000 63200} {-990 63220} {-1000 63240} {-990 63260} {-1000 63280} {-990 63300} {-1000 63320} {-990 63340} {-1000 63360} {-990 63380} {-1000 63400} {-990 63420} {-1000 63440} {-990 63460} {-1000 63480} {-990 63500} {-1000 63520} {-990 63540} {-1000 63560} {-990 63580} {-1000 63600} {-990 63620} {-1000 63640} {-990 63660} {-1000 63680} {-990 63700} {-1000 63720} {-990 63740} {-1000 63760} {-990 63780} {-1000 63800} {-990 63820} {-1000 63840} {-990 63860} {-1000 63880} {-990 63900} {-1000 63920} {-990 63940} {-1000 63960} {-990 63980} {-1000 64000} {-990 64020} {-1000 64040} {-990 64060} {-1000 64080} {-990 64100} {-1000 64120} {-990 64140} {-1000 64160} {-990 64180} {-1000 64200} {-990 64220} {-1000 64240} {-990 64260} {-1000 64280} {-990 64300} {-1000 64320} {-990 64340} {-1000 64360} {-990 64380} {-1000 64400} {-990 64420} {-1000 64440} {-990 64460} {-1000 64480} {-990 64500} {-1000 64520} {-990 64540} {-1000 64560} {-990 64580} {-1000 64600} {-990 64620} {-1000 64640} {-990 64660} {-1000 64680} {-990 64700} {-1000 64720} {-990 64740} {-1000 64760} {-990 64780} {-1000 64800} {-990 64820} {-1000 64840} {-990 64860} {-1000 64880} {-990 64900} {-1000 64920} {-990 64940} {-1000 64960} {-990 64980} {-1000 65000} {-990 65020} {-1000 65040} {-990 65060} {-1000 65080} {-990 65100} {-1000 65120} {-990 65140} {-1000 65160} {-990 65180} {-1000 65200} {-990 65220} {-1000 65240} {-990 65260} {-1000 65280} {-990 65300} {-1000 65320} {-990 65340} {-1000 65360} {-990 65380} {-1000 65400} {-990 65420} {-1000 65440} {-990 65460} {-1000 65480} {-990 65500} {-1000 65520} {-990 65540} {-1000 65560} {-990 65580} {-1000 65600} {-990 65620} {-1000 65640} {-990 65660} {-1000 65680} {-990 65700} {-1000 65720} {-990 65740} {-1000 65760} {-990 65780} {-1000 65800} {-990 65820} {-1000 65840} {-990 65860} {-1000 65880} {-990 65900} {-1000 65920} {-990 65940} {-1000 65960} {-990 65980} {-1000 66000} {-990 66020} {-1000 66040} {-990 66060} {-1000 66080} {-990 66100} {-1000 66120} {-990 66140} {-1000 66160} {-990 66180} {-1000 66200} {-990 66220} {-1000 66240} {-990 66260} {-1000 66280} {-990 66300} {-1000 66320} {-990 66340} {-1000 66360} {-990 66380} {-1000 66400} {-990 66420} {-1000 66440} {-990 66460} {-1000 66480} {-990 66500} {-1000 66520} {-990 66540} {-1000 66560} {-990 66580} {-1000 66600} {-990 66620} {-1000 66640} {-990 66660} {-1000 66680} {-990 66700} {-1000 66720} {-990 66740} {-1000 66760} {-990 66780} {-1000 66800} {-990 66820} {-1000 66840} {-990 66860} {-1000 66880} {-990 66900} {-1000 66920} {-990 66940} {-1000 66960} {-990 66980} {-1000 67000} {-990 67020} {-1000 67040} {-990 67060} {-1000 67080} {-990 67100} {-1000 67120} {-990 67140} {-1000 67160} {-990 67180} {-1000 67200} {-990 67220} {-1000 67240} {-990 67260} {-1000 67280} {-990 67300} {-1000 67320} {-990 67340} {-1000 67360} {-990 67380} {-1000 67400} {-990 67420} {-1000 67440} {-990 67460} {-1000 67480} {-990 67500} {-1000 67520} {-990 67540} {-1000 67560} {-990 67580} {-1000 67600} {-990 67620} {-1000 67640} {-990 67660} {-1000 67680} {-990 67700} {-1000 67720} {-990 67740} {-1000 67760} {-990 67780} {-1000 67800} {-990 67820} {-1000 67840} {-990 67860} {-1000 67880} {-990 67900} {-1000 67920} {-990 67940} {-1000 67960} {-990 67980} {-1000 68000} {-990 68020} {-1000 68040} {-990 68060} {-1000 68080} {-990 68100} {-1000 68120} {-990 68140} {-1000 68160} {-990 68180} {-1000 68200} {-990 68220} {-1000 68240} {-990 68260} {-1000 68280} {-990 68300} {-1000 68320} {-990 68340} {-1000 68360} {-990 68380} {-1000 68400} {-990 68420} {-1000 68440} {-990 68460} {-1000 68480} {-990 68500} {-1000 68520} {-990 68540} {-1000 68560} {-990 68580} {-1000 68600} {-990 68620} {-1000 68640} {-990 68660} {-1000 68680} {-990 68700} {-1000 68720} {-990 68740} {-1000 68760} {-990 68780} {-1000 68800} {-990 68820} {-1000 68840} {-990 68860} {-1000 68880} {-990 68900} {-1000 68920} {-990 68940} {-1000 68960} {-990 68980} {-1000 69000} {-990 69020} {-1000 69040} {-990 69060} {-1000 69080} {-990 69100} {-1000 69120} {-990 69140} {-1000 69160} {-990 69180} {-1000 69200} {-990 69220} {-1000 69240} {-990 69260} {-1000 69280} {-990 69300} {-1000 69320} {-990 69340} {-1000 69360} {-990 69380} {-1000 69400} {-990 69420} {-1000 69440} {-990 69460} {-1000 69480} {-990 69500} {-1000 69520} {-990 69540} {-1000 69560} {-990 69580} {-1000 69600} {-990 69620} {-1000 69640} {-990 69660} {-1000 69680} {-990 69700} {-1000 69720} {-990 69740} {-1000 69760} {-990 69780} {-1000 69800} {-990 69820} {-1000 69840} {-990 69860} {-1000 69880} {-990 69900} {-1000 69920} {-990 69940} {-1000 69960} {-990 69980} {-1000 70000} {-990 70020} {-1000 70040} {-990 70060} {-1000 70080} {-990 70100} {-1000 70120} {-990 70140} {-1000 70160} {-990 70180} {-1000 70200} {-990 70220} {-1000 70240} {-990 70260} {-1000 70280} {-990 70300} {-1000 70320} {-990 70340} {-1000 70360} {-990 70380} {-1000 70400} {-990 70420} {-1000 70440} {-990 70460} {-1000 70480} {-990 70500} {-1000 70520} {-990 70540} {-1000 70560} {-990 70580} {-1000 70600} {-990 70620} {-1000 70640} {-990 70660} {-1000 70680} {-990 70700} {-1000 70720} {-990 70740} {-1000 70760} {-990 70780} {-1000 70800} {-990 70820} {-1000 70840} {-990 70860} {-1000 70880} {-990 70900} {-1000 70920} {-990 70940} {-1000 70960} {-990 70980} {-1000 71000} {-990 71020} {-1000 71040} {-990 71060} {-1000 71080} {-990 71100} {-1000 71120} {-990 71140} {-1000 71160} {-990 71180} {-1000 71200} {-990 71220} {-1000 71240} {-990 71260} {-1000 71280} {-990 71300} {-1000 71320} {-990 71340} {-1000 71360} {-990 71380} {-1000 71400} {-990 71420} {-1000 71440} {-990 71460} {-1000 71480} {-990 71500} {-1000 71520} {-990 71540} {-1000 71560} {-990 71580} {-1000 71600} {-990 71620} {-1000 71640} {-990 71660} {-1000 71680} {-990 71700} {-1000 71720} {-990 71740} {-1000 71760} {-990 71780} {-1000 71800} {-990 71820} {-1000 71840} {-990 71860} {-1000 71880} {-990 71900} {-1000 71920} {-990 71940} {-1000 71960} {-990 71980} {-1000 72000} {-990 72020} {-1000 72040} {-990 72060} {-1000 72080} {-990 72100} {-1000 72120} {-990 72140} {-1000 72160} {-990 72180} {-1000 72200} {-990 72220} {-1000 72240} {-990 72260} {-1000 72280} {-990 72300} {-1000 72320} {-990 72340} {-1000 72360} {-990 72380} {-1000 72400} {-990 72420} {-1000 72440} {-990 72460} {-1000 72480} {-990 72500} {-1000 72520} {-990 72540} {-1000 72560} {-990 72580} {-1000 72600} {-990 72620} {-1000 72640} {-990 72660} {-1000 72680} {-990 72700} {-1000 72720} {-990 72740} {-1000 72760} {-990 72780} {-1000 72800} {-990 72820} {-1000 72840} {-990 72860} {-1000 72880} {-990 72900} {-1000 72920} {-990 72940} {-1000 72960} {-990 72980} {-1000 73000} {-990 73020} {-1000 73040} {-990 73060} {-1000 73080} {-990 73100} {-1000 73120} {-990 73140} {-1000 73160} {-990 73180} {-1000 73200} {-990 73220} {-1000 73240} {-990 73260} {-1000 73280} {-990 73300} {-1000 73320} {-990 73340} {-1000 73360} {-990 73380} {-1000 73400} {-990 73420} {-1000 73440} {-990 73460} {-1000 73480} {-990 73500} {-1000 73520} {-990 73540} {-1000 73560} {-990 73580} {-1000 73600} {-990 73620} {-1000 73640} {-990 73660} {-1000 73680} {-990 73700} {-1000 73720} {-990 73740} {-1000 73760} {-990 73780} {-1000 73800} {-990 73820} {-1000 73840} {-990 73860} {-1000 73880} {-990 73900} {-1000 73920} {-990 73940} {-1000 73960} {-990 73980} {-1000 74000} {-990 74020} {-1000 74040} {-990 74060} {-1000 74080} {-990 74100} {-1000 74120} {-990 74140} {-1000 74160} {-990 74180} {-1000 74200} {-990 74220} {-1000 74240} {-990 74260} {-1000 74280} {-990 74300} {-1000 74320} {-990 74340} {-1000 74360} {-990 74380} {-1000 74400} {-990 74420} {-1000 74440} {-990 74460} {-1000 74480} {-990 74500} {-1000 74520} {-990 74540} {-1000 74560} {-990 74580} {-1000 74600} {-990 74620} {-1000 74640} {-990 74660} {-1000 74680} {-990 74700} {-1000 74720} {-990 74740} {-1000 74760} {-990 74780} {-1000 74800} {-990 74820} {-1000 74840} {-990 74860} {-1000 74880} {-990 74900} {-1000 74920} {-990 74940} {-1000 74960} {-990 74980} {-1000 75000} {-990 75020} {-1000 75040} {-990 75060} {-1000 75080} {-990 75100} {-1000 75120} {-990 75140} {-1000 75160} {-990 75180} {-1000 75200} {-990 75220} {-1000 75240} {-990 75260} {-1000 75280} {-990 75300} {-1000 75320} {-990 75340} {-1000 75360} {-990 75380} {-1000 75400} {-990 75420} {-1000 75440} {-990 75460} {-1000 75480} {-990 75500} {-1000 75520} {-990 75540} {-1000 75560} {-990 75580} {-1000 75600} {-990 75620} {-1000 75640} {-990 75660} {-1000 75680} {-990 75700} {-1000 75720} {-990 75740} {-1000 75760} {-990 75780} {-1000 75800} {-990 75820} {-1000 75840} {-990 75860} {-1000 75880} {-990 75900} {-1000 75920} {-990 75940} {-1000 75960} {-990 75980} {-1000 76000} {-990 76020} {-1000 76040} {-990 76060} {-1000 76080} {-990 76100} {-1000 76120} {-990 76140} {-1000 76160} {-990 76180} {-1000 76200} {-990 76220} {-1000 76240} {-990 76260} {-1000 76280} {-990 76300} {-1000 76320} {-990 76340} {-1000 76360} {-990 76380} {-1000 76400} {-990 76420} {-1000 76440} {-990 76460} {-1000 76480} {-990 76500} {-1000 76520} {-990 76540} {-1000 76560} {-990 76580} {-1000 76600} {-990 76620} {-1000 76640} {-990 76660} {-1000 76680} {-990 76700} {-1000 76720} {-990 76740} {-1000 76760} {-990 76780} {-1000 76800} {-990 76820} {-1000 76840} {-990 76860} {-1000 76880} {-990 76900} {-1000 76920} {-990 76940} {-1000 76960} {-990 76980} {-1000 77000} {-990 77020} {-1000 77040} {-990 77060} {-1000 77080} {-990 77100} {-1000 77120} {-990 77140} {-1000 77160} {-990 77180} {-1000 77200} {-990 77220} {-1000 77240} {-990 77260} {-1000 77280} {-990 77300} {-1000 77320} {-990 77340} {-1000 77360} {-990 77380} {-1000 77400} {-990 77420} {-1000 77440} {-990 77460} {-1000 77480} {-990 77500} {-1000 77520} {-990 77540} {-1000 77560} {-990 77580} {-1000 77600} {-990 77620} {-1000 77640} {-990 77660} {-1000 77680} {-990 77700} {-1000 77720} {-990 77740} {-1000 77760} {-990 77780} {-1000 77800} {-990 77820} {-1000 77840} {-990 77860} {-1000 77880} {-990 77900} {-1000 77920} {-990 77940} {-1000 77960} {-990 77980} {-1000 78000} {-990 78020} {-1000 78040} {-990 78060} {-1000 78080} {-990 78100} {-1000 78120} {-990 78140} {-1000 78160} {-990 78180} {-1000 78200} {-990 78220} {-1000 78240} {-990 78260} {-1000 78280} {-990 78300} {-1000 78320} {-990 78340} {-1000 78360} {-990 78380} {-1000 78400} {-990 78420} {-1000 78440} {-990 78460} {-1000 78480} {-990 78500} {-1000 78520} {-990 78540} {-1000 78560} {-990 78580} {-1000 78600} {-990 78620} {-1000 78640} {-990 78660} {-1000 78680} {-990 78700} {-1000 78720} {-990 78740} {-1000 78760} {-990 78780} {-1000 78800} {-990 78820} {-1000 78840} {-990 78860} {-1000 78880} {-990 78900} {-1000 78920} {-990 78940} {-1000 78960} {-990 78980} {-1000 79000} {-990 79020} {-1000 79040} {-990 79060} {-1000 79080} {-990 79100} {-1000 79120} {-990 79140} {-1000 79160} {-990 79180} {-1000 79200} {-990 79220} {-1000 79240} {-990 79260} {-1000 79280} {-990 79300} {-1000 79320} {-990 79340} {-1000 79360} {-990 79380} {-1000 79400} {-990 79420} {-1000 79440} {-990 79460} {-1000 79480} {-990 79500} {-1000 79520} {-990 79540} {-1000 79560} {-990 79580} {-1000 79600} {-990 79620} {-1000 79640} {-990 79660} {-1000 79680} {-990 79700} {-1000 79720} {-990 79740} {-1000 79760} {-990 79780} {-1000 79800} {-990 79820} {-1000 79840} {-990 79860} {-1000 79880} {-990 79900} {-1000 79920} {-990 79940} {-1000 79960} {-990 79980} {-1000 80000} {-990 80020} {-1000 80040} {-990 80060} {-1000 80080} {-990 80100} {-1000 80120} {-990 80140} {-1000 80160} {-990 80180} {-1000 80200} {-990 80220} {-1000 80240} {-990 80260} {-1000 80280} {-990 80300} {-1000 80320} {-990 80340} {-1000 80360} {-990 80380} {-1000 80400} {-990 80420} {-1000 80440} {-990 80460} {-1000 80480} {-990 80500} {-1000 80520} {-990 80540} {-1000 80560} {-990 80580} {-1000 80600} {-990 80620} {-1000 80640} {-990 80660} {-1000 80680} {-990 80700} {-1000 80720} {-990 80740} {-1000 80760} {-990 80780} {-1000 80800} {-990 80820} {-1000 80840} {-990 80860} {-1000 80880} {-990 80900} {-1000 80920} {-990 80940} {-1000 80960} {-990 80980} {-1000 81000} {-990 81020} {-1000 81040} {-990 81060} {-1000 81080} {-990 81100} {-1000 81120} {-990 81140} {-1000 81160} {-990 81180} {-1000 81200} {-990 81220} {-1000 81240} {-990 81260} {-1000 81280} {-990 81300} {-1000 81320} {-990 81340} {-1000 81360} {-990 81380} {-1000 81400} {-990 81420} {-1000 81440} {-990 81460} {-1000 81480} {-990 81500} {-1000 81520} {-990 81540} {-1000 81560} {-990 81580} {-1000 81600} {-990 81620} {-1000 81640} {-990 81660} {-1000 81680} {-990 81700} {-1000 81720} {-990 81740} {-1000 81760} {-990 81780} {-1000 81800} {-990 81820} {-1000 81840} {-990 81860} {-1000 81880} {-990 81900} {-1000 81920} {-990 81940} {-1000 81960} {-990 81980} {-1000 82000} {-990 82020} {-1000 82040} {-990 82060} {-1000 82080} {-990 82100} {-1000 82120} {-990 82140} {-1000 82160} {-990 82180} {-1000 82200} {-990 82220} {-1000 82240} {-990 82260} {-1000 82280} {-990 82300} {-1000 82320} {-990 82340} {-1000 82360} {-990 82380} {-1000 82400} {-990 82420} {-1000 82440} {-990 82460} {-1000 82480} {-990 82500} {-1000 82520} {-990 82540} {-1000 82560} {-990 82580} {-1000 82600} {-990 82620} {-1000 82640} {-990 82660} {-1000 82680} {-990 82700} {-1000 82720} {-990 82740} {-1000 82760} {-990 82780} {-1000 82800} {-990 82820} {-1000 82840} {-990 82860} {-1000 82880} {-990 82900} {-1000 82920} {-990 82940} {-1000 82960} {-990 82980} {-1000 83000} {-990 83020} {-1000 83040} {-990 83060} {-1000 83080} {-990 83100} {-1000 83120} {-990 83140} {-1000 83160} {-990 83180} {-1000 83200} {-990 83220} {-1000 83240} {-990 83260} {-1000 83280} {-990 83300} {-1000 83320} {-990 83340} {-1000 83360} {-990 83380} {-1000 83400} {-990 83420} {-1000 83440} {-990 83460} {-1000 83480} {-990 83500} {-1000 83520} {-990 83540} {-1000 83560} {-990 83580} {-1000 83600} {-990 83620} {-1000 83640} {-990 83660} {-1000 83680} {-990 83700} {-1000 83720} {-990 83740} {-1000 83760} {-990 83780} {-1000 83800} {-990 83820} {-1000 83840} {-990 83860} {-1000 83880} {-990 83900} {-1000 83920} {-990 83940} {-1000 83960} {-990 83980} {-1000 84000} {-990 84020} {-1000 84040} {-990 84060} {-1000 84080} {-990 84100} {-1000 84120} {-990 84140} {-1000 84160} {-990 84180} {-1000 84200} {-990 84220} {-1000 84240} {-990 84260} {-1000 84280} {-990 84300} {-1000 84320} {-990 84340} {-1000 84360} {-990 84380} {-1000 84400} {-990 84420} {-1000 84440} {-990 84460} {-1000 84480} {-990 84500} {-1000 84520} {-990 84540} {-1000 84560} {-990 84580} {-1000 84600} {-990 84620} {-1000 84640} {-990 84660} {-1000 84680} {-990 84700} {-1000 84720} {-990 84740} {-1000 84760} {-990 84780} {-1000 84800} {-990 84820} {-1000 84840} {-990 84860} {-1000 84880} {-990 84900} {-1000 84920} {-990 84940} {-1000 84960} {-990 84980} {-1000 85000} {-990 85020} {-1000 85040} {-990 85060} {-1000 85080} {-990 85100} {-1000 85120} {-990 85140} {-1000 85160} {-990 85180} {-1000 85200} {-990 85220} {-1000 85240} {-990 85260} {-1000 85280} {-990 85300} {-1000 85320} {-990 85340} {-1000 85360} {-990 85380} {-1000 85400} {-990 85420} {-1000 85440} {-990 85460} {-1000 85480} {-990 85500} {-1000 85520} {-990 85540} {-1000 85560} {-990 85580} {-1000 85600} {-990 85620} {-1000 85640} {-990 85660} {-1000 85680} {-990 85700} {-1000 85720} {-990 85740} {-1000 85760} {-990 85780} {-1000 85800} {-990 85820} {-1000 85840} {-990 85860} {-1000 85880} {-990 85900} {-1000 85920} {-990 85940} {-1000 85960} {-990 85980} {-1000 86000} {-990 86020} {-1000 86040} {-990 86060} {-1000 86080} {-990 86100} {-1000 86120} {-990 86140} {-1000 86160} {-990 86180} {-1000 86200} {-990 86220} {-1000 86240} {-990 86260} {-1000 86280} {-990 86300} {-1000 86320} {-990 86340} {-1000 86360} {-990 86380} {-1000 86400} {-990 86420} {-1000 86440} {-990 86460} {-1000 86480} {-990 86500} {-1000 86520} {-990 86540} {-1000 86560} {-990 86580} {-1000 86600} {-990 86620} {-1000 86640} {-990 86660} {-1000 86680} {-990 86700} {-1000 86720} {-990 86740} {-1000 86760} {-990 86780} {-1000 86800} {-990 86820} {-1000 86840} {-990 86860} {-1000 86880} {-990 86900} {-1000 86920} {-990 86940} {-1000 86960} {-990 86980} {-1000 87000} {-990 87020} {-1000 87040} {-990 87060} {-1000 87080} {-990 87100} {-1000 87120} {-990 87140} {-1000 87160} {-990 87180} {-1000 87200} {-990 87220} {-1000 87240} {-990 87260} {-1000 87280} {-990 87300} {-1000 87320} {-990 87340} {-1000 87360} {-990 87380} {-1000 87400} {-990 87420} {-1000 87440} {-990 87460} {-1000 87480} {-990 87500} {-1000 87520} {-990 87540} {-1000 87560} {-990 87580} {-1000 87600} {-990 87620} {-1000 87640} {-990 87660} {-1000 87680} {-990 87700} {-1000 87720} {-990 87740} {-1000 87760} {-990 87780} {-1000 87800} {-990 87820} {-1000 87840} {-990 87860} {-1000 87880} {-990 87900} {-1000 87920} {-990 87940} {-1000 87960} {-990 87980} {-1000 88000} {-990 88020} {-1000 88040} {-990 88060} {-1000 88080} {-990 88100} {-1000 88120} {-990 88140} {-1000 88160} {-990 88180} {-1000 88200} {-990 88220} {-1000 88240} {-990 88260} {-1000 88280} {-990 88300} {-1000 88320} {-990 88340} {-1000 88360} {-990 88380} {-1000 88400} {-990 88420} {-1000 88440} {-990 88460} {-1000 88480} {-990 88500} {-1000 88520} {-990 88540} {-1000 88560} {-990 88580} {-1000 88600} {-990 88620} {-1000 88640} {-990 88660} {-1000 88680} {-990 88700} {-1000 88720} {-990 88740} {-1000 88760} {-990 88780} {-1000 88800} {-990 88820} {-1000 88840} {-990 88860} {-1000 88880} {-990 88900} {-1000 88920} {-990 88940} {-1000 88960} {-990 88980} {-1000 89000} {-990 89020} {-1000 89040} {-990 89060} {-1000 89080} {-990 89100} {-1000 89120} {-990 89140} {-1000 89160} {-990 89180} {-1000 89200} {-990 89220} {-1000 89240} {-990 89260} {-1000 89280} {-990 89300} {-1000 89320} {-990 89340} {-1000 89360} {-990 89380} {-1000 89400} {-990 89420} {-1000 89440} {-990 89460} {-1000 89480} {-990 89500} {-1000 89520} {-990 89540} {-1000 89560} {-990 89580} {-1000 89600} {-990 89620} {-1000 89640} {-990 89660} {-1000 89680} {-990 89700} {-1000 89720} {-990 89740} {-1000 89760} {-990 89780} {-1000 89800} {-990 89820} {-1000 89840} {-990 89860} {-1000 89880} {-990 89900} {-1000 89920} {-990 89940} {-1000 89960} {-990 89980} {-1000 90000} {-990 90020} {-1000 90040} {-990 90060} {-1000 90080} {-990 90100} {-1000 90120} {-990 90140} {-1000 90160} {-990 90180} {-1000 90200} {-990 90220} {-1000 90240} {-990 90260} {-1000 90280} {-990 90300} {-1000 90320} {-990 90340} {-1000 90360} {-990 90380} {-1000 90400} {-990 90420} {-1000 90440} {-990 90460} {-1000 90480} {-990 90500} {-1000 90520} {-990 90540} {-1000 90560} {-990 90580} {-1000 90600} {-990 90620} {-1000 90640} {-990 90660} {-1000 90680} {-990 90700} {-1000 90720} {-990 90740} {-1000 90760} {-990 90780} {-1000 90800} {-990 90820} {-1000 90840} {-990 90860} {-1000 90880} {-990 90900} {-1000 90920} {-990 90940} {-1000 90960} {-990 90980} {-1000 91000} {-990 91020} {-1000 91040} {-990 91060} {-1000 91080} {-990 91100} {-1000 91120} {-990 91140} {-1000 91160} {-990 91180} {-1000 91200} {-990 91220} {-1000 91240} {-990 91260} {-1000 91280} {-990 91300} {-1000 91320} {-990 91340} {-1000 91360} {-990 91380} {-1000 91400} {-990 91420} {-1000 91440} {-990 91460} {-1000 91480} {-990 91500} {-1000 91520} {-990 91540} {-1000 91560} {-990 91580} {-1000 91600} {-990 91620} {-1000 91640} {-990 91660} {-1000 91680} {-990 91700} {-1000 91720} {-990 91740} {-1000 91760} {-990 91780} {-1000 91800} {-990 91820} {-1000 91840} {-990 91860} {-1000 91880} {-990 91900} {-1000 91920} {-990 91940} {-1000 91960} {-990 91980} {-1000 92000} {-990 92020} {-1000 92040} {-990 92060} {-1000 92080} {-990 92100} {-1000 92120} {-990 92140} {-1000 92160} {-990 92180} {-1000 92200} {-990 92220} {-1000 92240} {-990 92260} {-1000 92280} {-990 92300} {-1000 92320} {-990 92340} {-1000 92360} {-990 92380} {-1000 92400} {-990 92420} {-1000 92440} {-990 92460} {-1000 92480} {-990 92500} {-1000 92520} {-990 92540} {-1000 92560} {-990 92580} {-1000 92600} {-990 92620} {-1000 92640} {-990 92660} {-1000 92680} {-990 92700} {-1000 92720} {-990 92740} {-1000 92760} {-990 92780} {-1000 92800} {-990 92820} {-1000 92840} {-990 92860} {-1000 92880} {-990 92900} {-1000 92920} {-990 92940} {-1000 92960} {-990 92980} {-1000 93000} {-990 93020} {-1000 93040} {-990 93060} {-1000 93080} {-990 93100} {-1000 93120} {-990 93140} {-1000 93160} {-990 93180} {-1000 93200} {-990 93220} {-1000 93240} {-990 93260} {-1000 93280} {-990 93300} {-1000 93320} {-990 93340} {-1000 93360} {-990 93380} {-1000 93400} {-990 93420} {-1000 93440} {-990 93460} {-1000 93480} {-990 93500} {-1000 93520} {-990 93540} {-1000 93560} {-990 93580} {-1000 93600} {-990 93620} {-1000 93640} {-990 93660} {-1000 93680} {-990 93700} {-1000 93720} {-990 93740} {-1000 93760} {-990 93780} {-1000 93800} {-990 93820} {-1000 93840} {-990 93860} {-1000 93880} {-990 93900} {-1000 93920} {-990 93940} {-1000 93960} {-990 93980} {-1000 94000} {-990 94020} {-1000 94040} {-990 94060} {-1000 94080} {-990 94100} {-1000 94120} {-990 94140} {-1000 94160} {-990 94180} {-1000 94200} {-990 94220} {-1000 94240} {-990 94260} {-1000 94280} {-990 94300} {-1000 94320} {-990 94340} {-1000 94360} {-990 94380} {-1000 94400} {-990 94420} {-1000 94440} {-990 94460} {-1000 94480} {-990 94500} {-1000 94520} {-990 94540} {-1000 94560} {-990 94580} {-1000 94600} {-990 94620} {-1000 94640} {-990 94660} {-1000 94680} {-990 94700} {-1000 94720} {-990 94740} {-1000 94760} {-990 94780} {-1000 94800} {-990 94820} {-1000 94840} {-990 94860} {-1000 94880} {-990 94900} {-1000 94920} {-990 94940} {-1000 94960} {-990 94980} {-1000 95000} {-990 95020} {-1000 95040} {-990 95060} {-1000 95080} {-990 95100} {-1000 95120} {-990 95140} {-1000 95160} {-990 95180} {-1000 95200} {-990 95220} {-1000 95240} {-990 95260} {-1000 95280} {-990 95300} {-1000 95320} {-990 95340} {-1000 95360} {-990 95380} {-1000 95400} {-990 95420} {-1000 95440} {-990 95460} {-1000 95480} {-990 95500} {-1000 95520} {-990 95540} {-1000 95560} {-990 95580} {-1000 95600} {-990 95620} {-1000 95640} {-990 95660} {-1000 95680} {-990 95700} {-1000 95720} {-990 95740} {-1000 95760} {-990 95780} {-1000 95800} {-990 95820} {-1000 95840} {-990 95860} {-1000 95880} {-990 95900} {-1000 95920} {-990 95940} {-1000 95960} {-990 95980} {-1000 96000} {-990 96020} {-1000 96040} {-990 96060} {-1000 96080} {-990 96100} {-1000 96120} {-990 96140} {-1000 96160} {-990 96180} {-1000 96200} {-990 96220} {-1000 96240} {-990 96260} {-1000 96280} {-990 96300} {-1000 96320} {-990 96340} {-1000 96360} {-990 96380} {-1000 96400} {-990 96420} {-1000 96440} {-990 96460} {-1000 96480} {-990 96500} {-1000 96520} {-990 96540} {-1000 96560} {-990 96580} {-1000 96600} {-990 96620} {-1000 96640} {-990 96660} {-1000 96680} {-990 96700} {-1000 96720} {-990 96740} {-1000 96760} {-990 96780} {-1000 96800} {-990 96820} {-1000 96840} {-990 96860} {-1000 96880} {-990 96900} {-1000 96920} {-990 96940} {-1000 96960} {-990 96980} {-1000 97000} {-990 97020} {-1000 97040} {-990 97060} {-1000 97080} {-990 97100} {-1000 97120} {-990 97140} {-1000 97160} {-990 97180} {-1000 97200} {-990 97220} {-1000 97240} {-990 97260} {-1000 97280} {-990 97300} {-1000 97320} {-990 97340} {-1000 97360} {-990 97380} {-1000 97400} {-990 97420} {-1000 97440} {-990 97460} {-1000 97480} {-990 97500} {-1000 97520} {-990 97540} {-1000 97560} {-990 97580} {-1000 97600} {-990 97620} {-1000 97640} {-990 97660} {-1000 97680} {-990 97700} {-1000 97720} {-990 97740} {-1000 97760} {-990 97780} {-1000 97800} {-990 97820} {-1000 97840} {-990 97860} {-1000 97880} {-990 97900} {-1000 97920} {-990 97940} {-1000 97960} {-990 97980} {-1000 98000} {-990 98020} {-1000 98040} {-990 98060} {-1000 98080} {-990 98100} {-1000 98120} {-990 98140} {-1000 98160} {-990 98180} {-1000 98200} {-990 98220} {-1000 98240} {-990 98260} {-1000 98280} {-990 98300} {-1000 98320} {-990 98340} {-1000 98360} {-990 98380} {-1000 98400} {-990 98420} {-1000 98440} {-990 98460} {-1000 98480} {-990 98500} {-1000 98520} {-990 98540} {-1000 98560} {-990 98580} {-1000 98600} {-990 98620} {-1000 98640} {-990 98660} {-1000 98680} {-990 98700} {-1000 98720} {-990 98740} {-1000 98760} {-990 98780} {-1000 98800} {-990 98820} {-1000 98840} {-990 98860} {-1000 98880} {-990 98900} {-1000 98920} {-990 98940} {-1000 98960} {-990 98980} {-1000 99000} {-990 99020} {-1000 99040} {-990 99060} {-1000 99080} {-990 99100} {-1000 99120} {-990 99140} {-1000 99160} {-990 99180} {-1000 99200} {-990 99220} {-1000 99240} {-990 99260} {-1000 99280} {-990 99300} {-1000 99320} {-990 99340} {-1000 99360} {-990 99380} {-1000 99400} {-990 99420} {-1000 99440} {-990 99460} {-1000 99480} {-990 99500} {-1000 99520} {-990 99540} {-1000 99560} {-990 99580} {-1000 99600} {-990 99620} {-1000 99640} {-990 99660} {-1000 99680} {-990 99700} {-1000 99720} {-990 99740} {-1000 99760} {-990 99780} {-1000 99800} {-990 99820} {-1000 99840} {-990 99860} {-1000 99880} {-990 99900} {-1000 99920} {-990 99940} {-1000 99960} {-990 99980} {-1000 100000} {-990 100020} {-1000 100040} {-990 100060} {-1000 100080} {-990 100100} {-1000 100120} {-990 100140} {-1000 100160} {-990 100180} {-1000 100200} {-990 100220} {-1000 100240} {-990 100260} {-1000 100280} {-990 100300} {-1000 100320} {-990 100340} {-1000 100360} {-990 100380} {-1000 100400} {-990 100420} {-1000 100440} {-990 100460} {-1000 100480} {-990 100500} {-1000 100520} {-990 100540} {-1000 100560} {-990 100580} {-1000 100600} {-990 100620} {-1000 100640} {-990 100660} {-1000 100680} {-990 100700} {-1000 100720} {-990 100740} {-1000 100760} {-990 100780} {-1000 100800} {-990 100820} {-1000 100840} {-990 100860} {-1000 100880} {-990 100900} {-1000 100920} {-990 100940} {-1000 100960} {-990 100980} {-1000 101000} {-990 101020} {-1000 101040} {-990 101060} {-1000 101080} {-990 101100} {-1000 101120} {-990 101140} {-1000 101160} {-990 101180} {-1000 101200} {-990 101220} {-1000 101240} {-990 101260} {-1000 101280} {-990 101300} {-1000 101320} {-990 101340} {-1000 101360} {-990 101380} {-1000 101400} {-990 101420} {-1000 101440} {-990 101460} {-1000 101480} {-990 101500} {-1000 101520} {-990 101540} {-1000 101560} {-990 101580} {-1000 101600} {-990 101620} {-1000 101640} {-990 101660} {-1000 101680} {-990 101700} {-1000 101720} {-990 101740} {-1000 101760} {-990 101780} {-1000 101800} {-990 101820} {-1000 101840} {-990 101860} {-1000 101880} {-990 101900} {-1000 101920} {-990 101940} {-1000 101960} {-990 101980} {-1000 102000} {-990 102020} {-1000 102040} {-990 102060} {-1000 102080} {-990 102100} {-1000 102120} {-990 102140} {-1000 102160} {-990 102180} {-1000 102200} {-990 102220} {-1000 102240} {-990 102260} {-1000 102280} {-990 102300} {-1000 102320} {-990 102340} {-1000 102360} {-990 102380} {-1000 102400} {-990 102420} {-1000 102440} {-990 102460} {-1000 102480} {-990 102500} {-1000 102520} {-990 102540} {-1000 102560} {-990 102580} {-1000 102600} {-990 102620} {-1000 102640} {-990 102660} {-1000 102680} {-990 102700} {-1000 102720} {-990 102740} {-1000 102760} {-990 102780} {-1000 102800} {-990 102820} {-1000 102840} {-990 102860} {-1000 102880} {-990 102900} {-1000 102920} {-990 102940} {-1000 102960} {-990 102980} {-1000 103000} {-990 103020} {-1000 103040} {-990 103060} {-1000 103080} {-990 103100} {-1000 103120} {-990 103140} {-1000 103160} {-990 103180} {-1000 103200} {-990 103220} {-1000 103240} {-990 103260} {-1000 103280} {-990 103300} {-1000 103320} {-990 103340} {-1000 103360} {-990 103380} {-1000 103400} {-990 103420} {-1000 103440} {-990 103460} {-1000 103480} {-990 103500} {-1000 103520} {-990 103540} {-1000 103560} {-990 103580} {-1000 103600} {-990 103620} {-1000 103640} {-990 103660} {-1000 103680} {-990 103700} {-1000 103720} {-990 103740} {-1000 103760} {-990 103780} {-1000 103800} {-990 103820} {-1000 103840} {-990 103860} {-1000 103880} {-990 103900} {-1000 103920} {-990 103940} {-1000 103960} {-990 103980} {-1000 104000} {-990 104020} {-1000 104040} {-990 104060} {-1000 104080} {-990 104100} {-1000 104120} {-990 104140} {-1000 104160} {-990 104180} {-1000 104200} {-990 104220} {-1000 104240} {-990 104260} {-1000 104280} {-990 104300} {-1000 104320} {-990 104340} {-1000 104360} {-990 104380} {-1000 104400} {-990 104420} {-1000 104440} {-990 104460} {-1000 104480} {-990 104500} {-1000 104520} {-990 104540} {-1000 104560} {-990 104580} {-1000 104600} {-990 104620} {-1000 104640} {-990 104660} {-1000 104680} {-990 104700} {-1000 104720} {-990 104740} {-1000 104760} {-990 104780} {-1000 104800} {-990 104820} {-1000 104840} {-990 104860} {-1000 104880} {-990 104900} {-1000 104920} {-990 104940} {-1000 104960} {-990 104980} {-1000 105000} {-990 105020} {-1000 105040} {-990 105060} {-1000 105080} {-990 105100} {-1000 105120} {-990 105140} {-1000 105160} {-990 105180} {-1000 105200} {-990 105220} {-1000 105240} {-990 105260} {-1000 105280} {-990 105300} {-1000 105320} {-990 105340} {-1000 105360} {-990 105380} {-1000 105400} {-990 105420} {-1000 105440} {-990 105460} {-1000 105480} {-990 105500} {-1000 105520} {-990 105540} {-1000 105560} {-990 105580} {-1000 105600} {-990 105620} {-1000 105640} {-990 105660} {-1000 105680} {-990 105700} {-1000 105720} {-990 105740} {-1000 105760} {-990 105780} {-1000 105800} {-990 105820} {-1000 105840} {-990 105860} {-1000 105880} {-990 105900} {-1000 105920} {-990 105940} {-1000 105960} {-990 105980} {-1000 106000} {-990 106020} {-1000 106040} {-990 106060} {-1000 106080} {-990 106100} {-1000 106120} {-990 106140} {-1000 106160} {-990 106180} {-1000 106200} {-990 106220} {-1000 106240} {-990 106260} {-1000 106280} {-990 106300} {-1000 106320} {-990 106340} {-1000 106360} {-990 106380} {-1000 106400} {-990 106420} {-1000 106440} {-990 106460} {-1000 106480} {-990 106500} {-1000 106520} {-990 106540} {-1000 106560} {-990 106580} {-1000 106600} {-990 106620} {-1000 106640} {-990 106660} {-1000 106680} {-990 106700} {-1000 106720} {-990 106740} {-1000 106760} {-990 106780} {-1000 106800} {-990 106820} {-1000 106840} {-990 106860} {-1000 106880} {-990 106900} {-1000 106920} {-990 106940} {-1000 106960} {-990 106980} {-1000 107000} {-990 107020} {-1000 107040} {-990 107060} {-1000 107080} {-990 107100} {-1000 107120} {-990 107140} {-1000 107160} {-990 107180} {-1000 107200} {-990 107220} {-1000 107240} {-990 107260} {-1000 107280} {-990 107300} {-1000 107320} {-990 107340} {-1000 107360} {-990 107380} {-1000 107400} {-990 107420} {-1000 107440} {-990 107460} {-1000 107480} {-990 107500} {-1000 107520} {-990 107540} {-1000 107560} {-990 107580} {-1000 107600} {-990 107620} {-1000 107640} {-990 107660} {-1000 107680} {-990 107700} {-1000 107720} {-990 107740} {-1000 107760} {-990 107780} {-1000 107800} {-990 107820} {-1000 107840} {-990 107860} {-1000 107880} {-990 107900} {-1000 107920} {-990 107940} {-1000 107960} {-990 107980} {-1000 108000} {-990 108020} {-1000 108040} {-990 108060} {-1000 108080} {-990 108100} {-1000 108120} {-990 108140} {-1000 108160} {-990 108180} {-1000 108200} {-990 108220} {-1000 108240} {-990 108260} {-1000 108280} {-990 108300} {-1000 108320} {-990 108340} {-1000 108360} {-990 108380} {-1000 108400} {-990 108420} {-1000 108440} {-990 108460} {-1000 108480} {-990 108500} {-1000 108520} {-990 108540} {-1000 108560} {-990 108580} {-1000 108600} {-990 108620} {-1000 108640} {-990 108660} {-1000 108680} {-990 108700} {-1000 108720} {-990 108740} {-1000 108760} {-990 108780} {-1000 108800} {-990 108820} {-1000 108840} {-990 108860} {-1000 108880} {-990 108900} {-1000 108920} {-990 108940} {-1000 108960} {-990 108980} {-1000 109000} {-990 109020} {-1000 109040} {-990 109060} {-1000 109080} {-990 109100} {-1000 109120} {-990 109140} {-1000 109160} {-990 109180} {-1000 109200} {-990 109220} {-1000 109240} {-990 109260} {-1000 109280} {-990 109300} {-1000 109320} {-990 109340} {-1000 109360} {-990 109380} {-1000 109400} {-990 109420} {-1000 109440} {-990 109460} {-1000 109480} {-990 109500} {-1000 109520} {-990 109540} {-1000 109560} {-990 109580} {-1000 109600} {-990 109620} {-1000 109640} {-990 109660} {-1000 109680} {-990 109700} {-1000 109720} {-990 109740} {-1000 109760} {-990 109780} {-1000 109800} {-990 109820} {-1000 109840} {-990 109860} {-1000 109880} {-990 109900} {-1000 109920} {-990 109940} {-1000 109960} {-990 109980} {-1000 110000} {-990 110020} {-1000 110040} {-990 110060} {-1000 110080} {-990 110100} {-1000 110120} {-990 110140} {-1000 110160} {-990 110180} {-1000 110200} {-990 110220} {-1000 110240} {-990 110260} {-1000 110280} {-990 110300} {-1000 110320} {-990 110340} {-1000 110360} {-990 110380} {-1000 110400} {-990 110420} {-1000 110440} {-990 110460} {-1000 110480} {-990 110500} {-1000 110520} {-990 110540} {-1000 110560} {-990 110580} {-1000 110600} {-990 110620} {-1000 110640} {-990 110660} {-1000 110680} {-990 110700} {-1000 110720} {-990 110740} {-1000 110760} {-990 110780} {-1000 110800} {-990 110820} {-1000 110840} {-990 110860} {-1000 110880} {-990 110900} {-1000 110920} {-990 110940} {-1000 110960} {-990 110980} {-1000 111000} {-990 111020} {-1000 111040} {-990 111060} {-1000 111080} {-990 111100} {-1000 111120} {-990 111140} {-1000 111160} {-990 111180} {-1000 111200} {-990 111220} {-1000 111240} {-990 111260} {-1000 111280} {-990 111300} {-1000 111320} {-990 111340} {-1000 111360} {-990 111380} {-1000 111400} {-990 111420} {-1000 111440} {-990 111460} {-1000 111480} {-990 111500} {-1000 111520} {-990 111540} {-1000 111560} {-990 111580} {-1000 111600} {-990 111620} {-1000 111640} {-990 111660} {-1000 111680} {-990 111700} {-1000 111720} {-990 111740} {-1000 111760} {-990 111780} {-1000 111800} {-990 111820} {-1000 111840} {-990 111860} {-1000 111880} {-990 111900} {-1000 111920} {-990 111940} {-1000 111960} {-990 111980} {-1000 112000} {-990 112020} {-1000 112040} {-990 112060} {-1000 112080} {-990 112100} {-1000 112120} {-990 112140} {-1000 112160} {-990 112180} {-1000 112200} {-990 112220} {-1000 112240} {-990 112260} {-1000 112280} {-990 112300} {-1000 112320} {-990 112340} {-1000 112360} {-990 112380} {-1000 112400} {-990 112420} {-1000 112440} {-990 112460} {-1000 112480} {-990 112500} {-1000 112520} {-990 112540} {-1000 112560} {-990 112580} {-1000 112600} {-990 112620} {-1000 112640} {-990 112660} {-1000 112680} {-990 112700} {-1000 112720} {-990 112740} {-1000 112760} {-990 112780} {-1000 112800} {-990 112820} {-1000 112840} {-990 112860} {-1000 112880} {-990 112900} {-1000 112920} {-990 112940} {-1000 112960} {-990 112980} {-1000 113000} {-990 113020} {-1000 113040} {-990 113060} {-1000 113080} {-990 113100} {-1000 113120} {-990 113140} {-1000 113160} {-990 113180} {-1000 113200} {-990 113220} {-1000 113240} {-990 113260} {-1000 113280} {-990 113300} {-1000 113320} {-990 113340} {-1000 113360} {-990 113380} {-1000 113400} {-990 113420} {-1000 113440} {-990 113460} {-1000 113480} {-990 113500} {-1000 113520} {-990 113540} {-1000 113560} {-990 113580} {-1000 113600} {-990 113620} {-1000 113640} {-990 113660} {-1000 113680} {-990 113700} {-1000 113720} {-990 113740} {-1000 113760} {-990 113780} {-1000 113800} {-990 113820} {-1000 113840} {-990 113860} {-1000 113880} {-990 113900} {-1000 113920} {-990 113940} {-1000 113960} {-990 113980} {-1000 114000} {-990 114020} {-1000 114040} {-990 114060} {-1000 114080} {-990 114100} {-1000 114120} {-990 114140} {-1000 114160} {-990 114180} {-1000 114200} {-990 114220} {-1000 114240} {-990 114260} {-1000 114280} {-990 114300} {-1000 114320} {-990 114340} {-1000 114360} {-990 114380} {-1000 114400} {-990 114420} {-1000 114440} {-990 114460} {-1000 114480} {-990 114500} {-1000 114520} {-990 114540} {-1000 114560} {-990 114580} {-1000 114600} {-990 114620} {-1000 114640} {-990 114660} {-1000 114680} {-990 114700} {-1000 114720} {-990 114740} {-1000 114760} {-990 114780} {-1000 114800} {-990 114820} {-1000 114840} {-990 114860} {-1000 114880} {-990 114900} {-1000 114920} {-990 114940} {-1000 114960} {-990 114980} {-1000 115000} {-990 115020} {-1000 115040} {-990 115060} {-1000 115080} {-990 115100} {-1000 115120} {-990 115140} {-1000 115160} {-990 115180} {-1000 115200} {-990 115220} {-1000 115240} {-990 115260} {-1000 115280} {-990 115300} {-1000 115320} {-990 115340} {-1000 115360} {-990 115380} {-1000 115400} {-990 115420} {-1000 115440} {-990 115460} {-1000 115480} {-990 115500} {-1000 115520} {-990 115540} {-1000 115560} {-990 115580} {-1000 115600} {-990 115620} {-1000 115640} {-990 115660} {-1000 115680} {-990 115700} {-1000 115720} {-990 115740} {-1000 115760} {-990 115780} {-1000 115800} {-990 115820} {-1000 115840} {-990 115860} {-1000 115880} {-990 115900} {-1000 115920} {-990 115940} {-1000 115960} {-990 115980} {-1000 116000} {-990 116020} {-1000 116040} {-990 116060} {-1000 116080} {-990 116100} {-1000 116120} {-990 116140} {-1000 116160} {-990 116180} {-1000 116200} {-990 116220} {-1000 116240} {-990 116260} {-1000 116280} {-990 116300} {-1000 116320} {-990 116340} {-1000 116360} {-990 116380} {-1000 116400} {-990 116420} {-1000 116440} {-990 116460} {-1000 116480} {-990 116500} {-1000 116520} {-990 116540} {-1000 116560} {-990 116580} {-1000 116600} {-990 116620} {-1000 116640} {-990 116660} {-1000 116680} {-990 116700} {-1000 116720} {-990 116740} {-1000 116760} {-990 116780} {-1000 116800} {-990 116820} {-1000 116840} {-990 116860} {-1000 116880} {-990 116900} {-1000 116920} {-990 116940} {-1000 116960} {-990 116980} {-1000 117000} {-990 117020} {-1000 117040} {-990 117060} {-1000 117080} {-990 117100} {-1000 117120} {-990 117140} {-1000 117160} {-990 117180} {-1000 117200} {-990 117220} {-1000 117240} {-990 117260} {-1000 117280} {-990 117300} {-1000 117320} {-990 117340} {-1000 117360} {-990 117380} {-1000 117400} {-990 117420} {-1000 117440} {-990 117460} {-1000 117480} {-990 117500} {-1000 117520} {-990 117540} {-1000 117560} {-990 117580} {-1000 117600} {-990 117620} {-1000 117640} {-990 117660} {-1000 117680} {-990 117700} {-1000 117720} {-990 117740} {-1000 117760} {-990 117780} {-1000 117800} {-990 117820} {-1000 117840} {-990 117860} {-1000 117880} {-990 117900} {-1000 117920} {-990 117940} {-1000 117960} {-990 117980} {-1000 118000} {-990 118020} {-1000 118040} {-990 118060} {-1000 118080} {-990 118100} {-1000 118120} {-990 118140} {-1000 118160} {-990 118180} {-1000 118200} {-990 118220} {-1000 118240} {-990 118260} {-1000 118280} {-990 118300} {-1000 118320} {-990 118340} {-1000 118360} {-990 118380} {-1000 118400} {-990 118420} {-1000 118440} {-990 118460} {-1000 118480} {-990 118500} {-1000 118520} {-990 118540} {-1000 118560} {-990 118580} {-1000 118600} {-990 118620} {-1000 118640} {-990 118660} {-1000 118680} {-990 118700} {-1000 118720} {-990 118740} {-1000 118760} {-990 118780} {-1000 118800} {-990 118820} {-1000 118840} {-990 118860} {-1000 118880} {-990 118900} {-1000 118920} {-990 118940} {-1000 118960} {-990 118980} {-1000 119000} {-990 119020} {-1000 119040} {-990 119060} {-1000 119080} {-990 119100} {-1000 119120} {-990 119140} {-1000 119160} {-990 119180} {-1000 119200} {-990 119220} {-1000 119240} {-990 119260} {-1000 119280} {-990 119300} {-1000 119320} {-990 119340} {-1000 119360} {-990 119380} {-1000 119400} {-990 119420} {-1000 119440} {-990 119460} {-1000 119480} {-990 119500} {-1000 119520} {-990 119540} {-1000 119560} {-990 119580} {-1000 119600} {-990 119620} {-1000 119640} {-990 119660} {-1000 119680} {-990 119700} {-1000 119720} {-990 119740} {-1000 119760} {-990 119780} {-1000 119800} {-990 119820} {-1000 119840} {-990 119860} {-1000 119880} {-990 119900} {-1000 119920} {-990 119940} {-1000 119960} {-990 119980} {-1000 120000} {-990 120020} {-1000 120040} {-990 120060} {-1000 120080} {-990 120100} {-1000 120120} {-990 120140} {-1000 120160} {-990 120180} {-1000 120200} {-990 120220} {-1000 120240} {-990 120260} {-1000 120280} {-990 120300} {-1000 120320} {-990 120340} {-1000 120360} {-990 120380} {-1000 120400} {-990 120420} {-1000 120440} {-990 120460} {-1000 120480} {-990 120500} {-1000 120520} {-990 120540} {-1000 120560} {-990 120580} {-1000 120600} {-990 120620} {-1000 120640} {-990 120660} {-1000 120680} {-990 120700} {-1000 120720} {-990 120740} {-1000 120760} {-990 120780} {-1000 120800} {-990 120820} {-1000 120840} {-990 120860} {-1000 120880} {-990 120900} {-1000 120920} {-990 120940} {-1000 120960} {-990 120980} {-1000 121000} {-990 121020} {-1000 121040} {-990 121060} {-1000 121080} {-990 121100} {-1000 121120} {-990 121140} {-1000 121160} {-990 121180} {-1000 121200} {-990 121220} {-1000 121240} {-990 121260} {-1000 121280} {-990 121300} {-1000 121320} {-990 121340} {-1000 121360} {-990 121380} {-1000 121400} {-990 121420} {-1000 121440} {-990 121460} {-1000 121480} {-990 121500} {-1000 121520} {-990 121540} {-1000 121560} {-990 121580} {-1000 121600} {-990 121620} {-1000 121640} {-990 121660} {-1000 121680} {-990 121700} {-1000 121720} {-990 121740} {-1000 121760} {-990 121780} {-1000 121800} {-990 121820} {-1000 121840} {-990 121860} {-1000 121880} {-990 121900} {-1000 121920} {-990 121940} {-1000 121960} {-990 121980} {-1000 122000} {-990 122020} {-1000 122040} {-990 122060} {-1000 122080} {-990 122100} {-1000 122120} {-990 122140} {-1000 122160} {-990 122180} {-1000 122200} {-990 122220} {-1000 122240} {-990 122260} {-1000 122280} {-990 122300} {-1000 122320} {-990 122340} {-1000 122360} {-990 122380} {-1000 122400} {-990 122420} {-1000 122440} {-990 122460} {-1000 122480} {-990 122500} {-1000 122520} {-990 122540} {-1000 122560} {-990 122580} {-1000 122600} {-990 122620} {-1000 122640} {-990 122660} {-1000 122680} {-990 122700} {-1000 122720} {-990 122740} {-1000 122760} {-990 122780} {-1000 122800} {-990 122820} {-1000 122840} {-990 122860} {-1000 122880} {-990 122900} {-1000 122920} {-990 122940} {-1000 122960} {-990 122980} {-1000 123000} {-990 123020} {-1000 123040} {-990 123060} {-1000 123080} {-990 123100} {-1000 123120} {-990 123140} {-1000 123160} {-990 123180} {-1000 123200} {-990 123220} {-1000 123240} {-990 123260} {-1000 123280} {-990 123300} {-1000 123320} {-990 123340} {-1000 123360} {-990 123380} {-1000 123400} {-990 123420} {-1000 123440} {-990 123460} {-1000 123480} {-990 123500} {-1000 123520} {-990 123540} {-1000 123560} {-990 123580} {-1000 123600} {-990 123620} {-1000 123640} {-990 123660} {-1000 123680} {-990 123700} {-1000 123720} {-990 123740} {-1000 123760} {-990 123780} {-1000 123800} {-990 123820} {-1000 123840} {-990 123860} {-1000 123880} {-990 123900} {-1000 123920} {-990 123940} {-1000 123960} {-990 123980} {-1000 124000} {-990 124020} {-1000 124040} {-990 124060} {-1000 124080} {-990 124100} {-1000 124120} {-990 124140} {-1000 124160} {-990 124180} {-1000 124200} {-990 124220} {-1000 124240} {-990 124260} {-1000 124280} {-990 124300} {-1000 124320} {-990 124340} {-1000 124360} {-990 124380} {-1000 124400} {-990 124420} {-1000 124440} {-990 124460} {-1000 124480} {-990 124500} {-1000 124520} {-990 124540} {-1000 124560} {-990 124580} {-1000 124600} {-990 124620} {-1000 124640} {-990 124660} {-1000 124680} {-990 124700} {-1000 124720} {-990 124740} {-1000 124760} {-990 124780} {-1000 124800} {-990 124820} {-1000 124840} {-990 124860} {-1000 124880} {-990 124900} {-1000 124920} {-990 124940} {-1000 124960} {-990 124980} {-1000 125000} {-990 125020} {-1000 125040} {-990 125060} {-1000 125080} {-990 125100} {-1000 125120} {-990 125140} {-1000 125160} {-990 125180} {-1000 125200} {-990 125220} {-1000 125240} {-990 125260} {-1000 125280} {-990 125300} {-1000 125320} {-990 125340} {-1000 125360} {-990 125380} {-1000 125400} {-990 125420} {-1000 125440} {-990 125460} {-1000 125480} {-990 125500} {-1000 125520} {-990 125540} {-1000 125560} {-990 125580} {-1000 125600} {-990 125620} {-1000 125640} {-990 125660} {-1000 125680} {-990 125700} {-1000 125720} {-990 125740} {-1000 125760} {-990 125780} {-1000 125800} {-990 125820} {-1000 125840} {-990 125860} {-1000 125880} {-990 125900} {-1000 125920} {-990 125940} {-1000 125960} {-990 125980} {-1000 126000} {-990 126020} {-1000 126040} {-990 126060} {-1000 126080} {-990 126100} {-1000 126120} {-990 126140} {-1000 126160} {-990 126180} {-1000 126200} {-990 126220} {-1000 126240} {-990 126260} {-1000 126280} {-990 126300} {-1000 126320} {-990 126340} {-1000 126360} {-990 126380} {-1000 126400} {-990 126420} {-1000 126440} {-990 126460} {-1000 126480} {-990 126500} {-1000 126520} {-990 126540} {-1000 126560} {-990 126580} {-1000 126600} {-990 126620} {-1000 126640} {-990 126660} {-1000 126680} {-990 126700} {-1000 126720} {-990 126740} {-1000 126760} {-990 126780} {-1000 126800} {-990 126820} {-1000 126840} {-990 126860} {-1000 126880} {-990 126900} {-1000 126920} {-990 126940} {-1000 126960} {-990 126980} {-1000 127000} {-990 127020} {-1000 127040} {-990 127060} {-1000 127080} {-990 127100} {-1000 127120} {-990 127140} {-1000 127160} {-990 127180} {-1000 127200} {-990 127220} {-1000 127240} {-990 127260} {-1000 127280} {-990 127300} {-1000 127320} {-990 127340} {-1000 127360} {-990 127380} {-1000 127400} {-990 127420} {-1000 127440} {-990 127460} {-1000 127480} {-990 127500} {-1000 127520} {-990 127540} {-1000 127560} {-990 127580} {-1000 127600} {-990 127620} {-1000 127640} {-990 127660} {-1000 127680} {-990 127700} {-1000 127720} {-990 127740} {-1000 127760} {-990 127780} {-1000 127800} {-990 127820} {-1000 127840} {-990 127860} {-1000 127880} {-990 127900} {-1000 127920} {-990 127940} {-1000 127960} {-990 127980} {-1000 128000} {-990 128020} {-1000 128040} {-990 128060} {-1000 128080} {-990 128100} {-1000 128120} {-990 128140} {-1000 128160} {-990 128180} {-1000 128200} {-990 128220} {-1000 128240} {-990 128260} {-1000 128280} {-990 128300} {-1000 128320} {-990 128340} {-1000 128360} {-990 128380} {-1000 128400} {-990 128420} {-1000 128440} {-990 128460} {-1000 128480} {-990 128500} {-1000 128520} {-990 128540} {-1000 128560} {-990 128580} {-1000 128600} {-990 128620} {-1000 128640} {-990 128660} {-1000 128680} {-990 128700} {-1000 128720} {-990 128740} {-1000 128760} {-990 128780} {-1000 128800} {-990 128820} {-1000 128840} {-990 128860} {-1000 128880} {-990 128900} {-1000 128920} {-990 128940} {-1000 128960} {-990 128980} {-1000 129000} {-990 129020} {-1000 129040} {-990 129060} {-1000 129080} {-990 129100} {-1000 129120} {-990 129140} {-1000 129160} {-990 129180} {-1000 129200} {-990 129220} {-1000 129240} {-990 129260} {-1000 129280} {-990 129300} {-1000 129320} {-990 129340} {-1000 129360} {-990 129380} {-1000 129400} {-990 129420} {-1000 129440} {-990 129460} {-1000 129480} {-990 129500} {-1000 129520} {-990 129540} {-1000 129560} {-990 129580} {-1000 129600} {-990 129620} {-1000 129640} {-990 129660} {-1000 129680} {-990 129700} {-1000 129720} {-990 129740} {-1000 129760} {-990 129780} {-1000 129800} {-990 129820} {-1000 129840} {-990 129860} {-1000 129880} {-990 129900} {-1000 129920} {-990 129940} {-1000 129960} {-990 129980} {-1000 130000} {-990 130020} {-1000 130040} {-990 130060} {-1000 130080} {-990 130100} {-1000 130120} {-990 130140} {-1000 130160} {-990 130180} {-1000 130200} {-990 130220} {-1000 130240} {-990 130260} {-1000 130280} {-990 130300} {-1000 130320} {-990 130340} {-1000 130360} {-990 130380} {-1000 130400} {-990 130420} {-1000 130440} {-990 130460} {-1000 130480} {-990 130500} {-1000 130520} {-990 130540} {-1000 130560} {-990 130580} {-1000 130600} {-990 130620} {-1000 130640} {-990 130660} {-1000 130680} {-990 130700} {-1000 130720} {-990 130740} {-1000 130760} {-990 130780} {-1000 130800} {-990 130820} {-1000 130840} {-990 130860} {-1000 130880} {-990 130900} {-1000 130920} {-990 130940} {-1000 130960} {-990 130980} {-1000 131000} {-990 131020} {-1000 131040} {-990 131060} {-1000 131080} {-990 131100} {-1000 131120} {-990 131140} {-1000 131160} {-990 131180} {-1000 131200} {-990 131220} {-1000 131240} {-990 131260} {-1000 131280} {-990 131300} {-1000 131320} {-990 131340} {-1000 131360} {-990 131380} {-1000 131400} {-990 131420} {-1000 131440} {-990 131460} {-1000 131480} {-990 131500} {-1000 131520} {-990 131540} {-1000 131560} {-990 131580} {-1000 131600} {-990 131620} {-1000 131640} {-990 131660} {-1000 131680} {-990 131700} {-1000 131720} {-990 131740} {-1000 131760} {-990 131780} {-1000 131800} {-990 131820} {-1000 131840} {-990 131860} {-1000 131880} {-990 131900} {-1000 131920} {-990 131940} {-1000 131960} {-990 131980} {-1000 132000} {-990 132020} {-1000 132040} {-990 132060} {-1000 132080} {-990 132100} {-1000 132120} {-990 132140} {-1000 132160} {-990 132180} {-1000 132200} {-990 132220} {-1000 132240} {-990 132260} {-1000 132280} {-990 132300} {-1000 132320} {-990 132340} {-1000 132360} {-990 132380} {-1000 132400} {-990 132420} {-1000 132440} {-990 132460} {-1000 132480} {-990 132500} {-1000 132520} {-990 132540} {-1000 132560} {-990 132580} {-1000 132600} {-990 132620} {-1000 132640} {-990 132660} {-1000 132680} {-990 132700} {-1000 132720} {-990 132740} {-1000 132760} {-990 132780} {-1000 132800} {-990 132820} {-1000 132840} {-990 132860} {-1000 132880} {-990 132900} {-1000 132920} {-990 132940} {-1000 132960} {-990 132980} {-1000 133000} {-990 133020} {-1000 133040} {-990 133060} {-1000 133080} {-990 133100} {-1000 133120} {-990 133140} {-1000 133160} {-990 133180} {-1000 133200} {-990 133220} {-1000 133240} {-990 133260} {-1000 133280} {-990 133300} {-1000 133320} {-990 133340} {-1000 133360} {-990 133380} {-1000 133400} {-990 133420} {-1000 133440} {-990 133460} {-1000 133480} {-990 133500} {-1000 133520} {-990 133540} {-1000 133560} {-990 133580} {-1000 133600} {-990 133620} {-1000 133640} {-990 133660} {-1000 133680} {-990 133700} {-1000 133720} {-990 133740} {-1000 133760} {-990 133780} {-1000 133800} {-990 133820} {-1000 133840} {-990 133860} {-1000 133880} {-990 133900} {-1000 133920} {-990 133940} {-1000 133960} {-990 133980} {-1000 134000} {-990 134020} {-1000 134040} {-990 134060} {-1000 134080} {-990 134100} {-1000 134120} {-990 134140} {-1000 134160} {-990 134180} {-1000 134200} {-990 134220} {-1000 134240} {-990 134260} {-1000 134280} {-990 134300} {-1000 134320} {-990 134340} {-1000 134360} {-990 134380} {-1000 134400} {-990 134420} {-1000 134440} {-990 134460} {-1000 134480} {-990 134500} {-1000 134520} {-990 134540} {-1000 134560} {-990 134580} {-1000 134600} {-990 134620} {-1000 134640} {-990 134660} {-1000 134680} {-990 134700} {-1000 134720} {-990 134740} {-1000 134760} {-990 134780} {-1000 134800} {-990 134820} {-1000 134840} {-990 134860} {-1000 134880} {-990 134900} {-1000 134920} {-990 134940} {-1000 134960} {-990 134980} {-1000 135000} {-990 135020} {-1000 135040} {-990 135060} {-1000 135080} {-990 135100} {-1000 135120} {-990 135140} {-1000 135160} {-990 135180} {-1000 135200} {-990 135220} {-1000 135240} {-990 135260} {-1000 135280} {-990 135300} {-1000 135320} {-990 135340} {-1000 135360} {-990 135380} {-1000 135400} {-990 135420} {-1000 135440} {-990 135460} {-1000 135480} {-990 135500} {-1000 135520} {-990 135540} {-1000 135560} {-990 135580} {-1000 135600} {-990 135620} {-1000 135640} {-990 135660} {-1000 135680} {-990 135700} {-1000 135720} {-990 135740} {-1000 135760} {-990 135780} {-1000 135800} {-990 135820} {-1000 135840} {-990 135860} {-1000 135880} {-990 135900} {-1000 135920} {-990 135940} {-1000 135960} {-990 135980} {-1000 136000} {-990 136020} {-1000 136040} {-990 136060} {-1000 136080} {-990 136100} {-1000 136120} {-990 136140} {-1000 136160} {-990 136180} {-1000 136200} {-990 136220} {-1000 136240} {-990 136260} {-1000 136280} {-990 136300} {-1000 136320} {-990 136340} {-1000 136360} {-990 136380} {-1000 136400} {-990 136420} {-1000 136440} {-990 136460} {-1000 136480} {-990 136500} {-1000 136520} {-990 136540} {-1000 136560} {-990 136580} {-1000 136600} {-990 136620} {-1000 136640} {-990 136660} {-1000 136680} {-990 136700} {-1000 136720} {-990 136740} {-1000 136760} {-990 136780} {-1000 136800} {-990 136820} {-1000 136840} {-990 136860} {-1000 136880} {-990 136900} {-1000 136920} {-990 136940} {-1000 136960} {-990 136980} {-1000 137000} {-990 137020} {-1000 137040} {-990 137060} {-1000 137080} {-990 137100} {-1000 137120} {-990 137140} {-1000 137160} {-990 137180} {-1000 137200} {-990 137220} {-1000 137240} {-990 137260} {-1000 137280} {-990 137300} {-1000 137320} {-990 137340} {-1000 137360} {-990 137380} {-1000 137400} {-990 137420} {-1000 137440} {-990 137460} {-1000 137480} {-990 137500} {-1000 137520} {-990 137540} {-1000 137560} {-990 137580} {-1000 137600} {-990 137620} {-1000 137640} {-990 137660} {-1000 137680} {-990 137700} {-1000 137720} {-990 137740} {-1000 137760} {-990 137780} {-1000 137800} {-990 137820} {-1000 137840} {-990 137860} {-1000 137880} {-990 137900} {-1000 137920} {-990 137940} {-1000 137960} {-990 137980} {-1000 138000} {-990 138020} {-1000 138040} {-990 138060} {-1000 138080} {-990 138100} {-1000 138120} {-990 138140} {-1000 138160} {-990 138180} {-1000 138200} {-990 138220} {-1000 138240} {-990 138260} {-1000 138280} {-990 138300} {-1000 138320} {-990 138340} {-1000 138360} {-990 138380} {-1000 138400} {-990 138420} {-1000 138440} {-990 138460} {-1000 138480} {-990 138500} {-1000 138520} {-990 138540} {-1000 138560} {-990 138580} {-1000 138600} {-990 138620} {-1000 138640} {-990 138660} {-1000 138680} {-990 138700} {-1000 138720} {-990 138740} {-1000 138760} {-990 138780} {-1000 138800} {-990 138820} {-1000 138840} {-990 138860} {-1000 138880} {-990 138900} {-1000 138920} {-990 138940} {-1000 138960} {-990 138980} {-1000 139000} {-990 139020} {-1000 139040} {-990 139060} {-1000 139080} {-990 139100} {-1000 139120} {-990 139140} {-1000 139160} {-990 139180} {-1000 139200} {-990 139220} {-1000 139240} {-990 139260} {-1000 139280} {-990 139300} {-1000 139320} {-990 139340} {-1000 139360} {-990 139380} {-1000 139400} {-990 139420} {-1000 139440} {-990 139460} {-1000 139480} {-990 139500} {-1000 139520} {-990 139540} {-1000 139560} {-990 139580} {-1000 139600} {-990 139620} {-1000 139640} {-990 139660} {-1000 139680} {-990 139700} {-1000 139720} {-990 139740} {-1000 139760} {-990 139780} {-1000 139800} {-990 139820} {-1000 139840} {-990 139860} {-1000 139880} {-990 139900} {-1000 139920} {-990 139940} {-1000 139960} {-990 139980} {-1000 140000} {-990 140020} {-1000 140040} {-990 140060} {-1000 140080} {-990 140100} {-1000 140120} {-990 140140} {-1000 140160} {-990 140180} {-1000 140200} {-990 140220} {-1000 140240} {-990 140260} {-1000 140280} {-990 140300} {-1000 140320} {-990 140340} {-1000 140360} {-990 140380} {-1000 140400} {-990 140420} {-1000 140440} {-990 140460} {-1000 140480} {-990 140500} {-1000 140520} {-990 140540} {-1000 140560} {-990 140580} {-1000 140600} {-990 140620} {-1000 140640} {-990 140660} {-1000 140680} {-990 140700} {-1000 140720} {-990 140740} {-1000 140760} {-990 140780} {-1000 140800} {-990 140820} {-1000 140840} {-990 140860} {-1000 140880} {-990 140900} {-1000 140920} {-990 140940} {-1000 140960} {-990 140980} {-1000 141000} {-990 141020} {-1000 141040} {-990 141060} {-1000 141080} {-990 141100} {-1000 141120} {-990 141140} {-1000 141160} {-990 141180} {-1000 141200} {-990 141220} {-1000 141240} {-990 141260} {-1000 141280} {-990 141300} {-1000 141320} {-990 141340} {-1000 141360} {-990 141380} {-1000 141400} {-990 141420} {-1000 141440} {-990 141460} {-1000 141480} {-990 141500} {-1000 141520} {-990 141540} {-1000 141560} {-990 141580} {-1000 141600} {-990 141620} {-1000 141640} {-990 141660} {-1000 141680} {-990 141700} {-1000 141720} {-990 141740} {-1000 141760} {-990 141780} {-1000 141800} {-990 141820} {-1000 141840} {-990 141860} {-1000 141880} {-990 141900} {-1000 141920} {-990 141940} {-1000 141960} {-990 141980} {-1000 142000} {-990 142020} {-1000 142040} {-990 142060} {-1000 142080} {-990 142100} {-1000 142120} {-990 142140} {-1000 142160} {-990 142180} {-1000 142200} {-990 142220} {-1000 142240} {-990 142260} {-1000 142280} {-990 142300} {-1000 142320} {-990 142340} {-1000 142360} {-990 142380} {-1000 142400} {-990 142420} {-1000 142440} {-990 142460} {-1000 142480} {-990 142500} {-1000 142520} {-990 142540} {-1000 142560} {-990 142580} {-1000 142600} {-990 142620} {-1000 142640} {-990 142660} {-1000 142680} {-990 142700} {-1000 142720} {-990 142740} {-1000 142760} {-990 142780} {-1000 142800} {-990 142820} {-1000 142840} {-990 142860} {-1000 142880} {-990 142900} {-1000 142920} {-990 142940} {-1000 142960} {-990 142980} {-1000 143000} {-990 143020} {-1000 143040} {-990 143060} {-1000 143080} {-990 143100} {-1000 143120} {-990 143140} {-1000 143160} {-990 143180} {-1000 143200} {-990 143220} {-1000 143240} {-990 143260} {-1000 143280} {-990 143300} {-1000 143320} {-990 143340} {-1000 143360} {-990 143380} {-1000 143400} {-990 143420} {-1000 143440} {-990 143460} {-1000 143480} {-990 143500} {-1000 143520} {-990 143540} {-1000 143560} {-990 143580} {-1000 143600} {-990 143620} {-1000 143640} {-990 143660} {-1000 143680} {-990 143700} {-1000 143720} {-990 143740} {-1000 143760} {-990 143780} {-1000 143800} {-990 143820} {-1000 143840} {-990 143860} {-1000 143880} {-990 143900} {-1000 143920} {-990 143940} {-1000 143960} {-990 143980} {-1000 144000} {-990 144020} {-1000 144040} {-990 144060} {-1000 144080} {-990 144100} {-1000 144120} {-990 144140} {-1000 144160} {-990 144180} {-1000 144200} {-990 144220} {-1000 144240} {-990 144260} {-1000 144280} {-990 144300} {-1000 144320} {-990 144340} {-1000 144360} {-990 144380} {-1000 144400} {-990 144420} {-1000 144440} {-990 144460} {-1000 144480} {-990 144500} {-1000 144520} {-990 144540} {-1000 144560} {-990 144580} {-1000 144600} {-990 144620} {-1000 144640} {-990 144660} {-1000 144680} {-990 144700} {-1000 144720} {-990 144740} {-1000 144760} {-990 144780} {-1000 144800} {-990 144820} {-1000 144840} {-990 144860} {-1000 144880} {-990 144900} {-1000 144920} {-990 144940} {-1000 144960} {-990 144980} {-1000 145000} {-990 145020} {-1000 145040} {-990 145060} {-1000 145080} {-990 145100} {-1000 145120} {-990 145140} {-1000 145160} {-990 145180} {-1000 145200} {-990 145220} {-1000 145240} {-990 145260} {-1000 145280} {-990 145300} {-1000 145320} {-990 145340} {-1000 145360} {-990 145380} {-1000 145400} {-990 145420} {-1000 145440} {-990 145460} {-1000 145480} {-990 145500} {-1000 145520} {-990 145540} {-1000 145560} {-990 145580} {-1000 145600} {-990 145620} {-1000 145640} {-990 145660} {-1000 145680} {-990 145700} {-1000 145720} {-990 145740} {-1000 145760} {-990 145780} {-1000 145800} {-990 145820} {-1000 145840} {-990 145860} {-1000 145880} {-990 145900} {-1000 145920} {-990 145940} {-1000 145960} {-990 145980} {-1000 146000} {-990 146020} {-1000 146040} {-990 146060} {-1000 146080} {-990 146100} {-1000 146120} {-990 146140} {-1000 146160} {-990 146180} {-1000 146200} {-990 146220} {-1000 146240} {-990 146260} {-1000 146280} {-990 146300} {-1000 146320} {-990 146340} {-1000 146360} {-990 146380} {-1000 146400} {-990 146420} {-1000 146440} {-990 146460} {-1000 146480} {-990 146500} {-1000 146520} {-990 146540} {-1000 146560} {-990 146580} {-1000 146600} {-990 146620} {-1000 146640} {-990 146660} {-1000 146680} {-990 146700} {-1000 146720} {-990 146740} {-1000 146760} {-990 146780} {-1000 146800} {-990 146820} {-1000 146840} {-990 146860} {-1000 146880} {-990 146900} {-1000 146920} {-990 146940} {-1000 146960} {-990 146980} {-1000 147000} {-990 147020} {-1000 147040} {-990 147060} {-1000 147080} {-990 147100} {-1000 147120} {-990 147140} {-1000 147160} {-990 147180} {-1000 147200} {-990 147220} {-1000 147240} {-990 147260} {-1000 147280} {-990 147300} {-1000 147320} {-990 147340} {-1000 147360} {-990 147380} {-1000 147400} {-990 147420} {-1000 147440} {-990 147460} {-1000 147480} {-990 147500} {-1000 147520} {-990 147540} {-1000 147560} {-990 147580} {-1000 147600} {-990 147620} {-1000 147640} {-990 147660} {-1000 147680} {-990 147700} {-1000 147720} {-990 147740} {-1000 147760} {-990 147780} {-1000 147800} {-990 147820} {-1000 147840} {-990 147860} {-1000 147880} {-990 147900} {-1000 147920} {-990 147940} {-1000 147960} {-990 147980} {-1000 148000} {-990 148020} {-1000 148040} {-990 148060} {-1000 148080} {-990 148100} {-1000 148120} {-990 148140} {-1000 148160} {-990 148180} {-1000 148200} {-990 148220} {-1000 148240} {-990 148260} {-1000 148280} {-990 148300} {-1000 148320} {-990 148340} {-1000 148360} {-990 148380} {-1000 148400} {-990 148420} {-1000 148440} {-990 148460} {-1000 148480} {-990 148500} {-1000 148520} {-990 148540} {-1000 148560} {-990 148580} {-1000 148600} {-990 148620} {-1000 148640} {-990 148660} {-1000 148680} {-990 148700} {-1000 148720} {-990 148740} {-1000 148760} {-990 148780} {-1000 148800} {-990 148820} {-1000 148840} {-990 148860} {-1000 148880} {-990 148900} {-1000 148920} {-990 148940} {-1000 148960} {-990 148980} {-1000 149000} {-990 149020} {-1000 149040} {-990 149060} {-1000 149080} {-990 149100} {-1000 149120} {-990 149140} {-1000 149160} {-990 149180} {-1000 149200} {-990 149220} {-1000 149240} {-990 149260} {-1000 149280} {-990 149300} {-1000 149320} {-990 149340} {-1000 149360} {-990 149380} {-1000 149400} {-990 149420} {-1000 149440} {-990 149460} {-1000 149480} {-990 149500} {-1000 149520} {-990 149540} {-1000 149560} {-990 149580} {-1000 149600} {-990 149620} {-1000 149640} {-990 149660} {-1000 149680} {-990 149700} {-1000 149720} {-990 149740} {-1000 149760} {-990 149780} {-1000 149800} {-990 149820} {-1000 149840} {-990 149860} {-1000 149880} {-990 149900} {-1000 149920} {-990 149940} {-1000 149960} {-990 149980} {-1000 150000} {-990 150020} {-1000 150040} {-990 150060} {-1000 150080} {-990 150100} {-1000 150120} {-990 150140} {-1000 150160} {-990 150180} {-1000 150200} {-990 150220} {-1000 150240} {-990 150260} {-1000 150280} {-990 150300} {-1000 150320} {-990 150340} {-1000 150360} {-990 150380} {-1000 150400} {-990 150420} {-1000 150440} {-990 150460} {-1000 150480} {-990 150500} {-1000 150520} {-990 150540} {-1000 150560} {-990 150580} {-1000 150600} {-990 150620} {-1000 150640} {-990 150660} {-1000 150680} {-990 150700} {-1000 150720} {-990 150740} {-1000 150760} {-990 150780} {-1000 150800} {-990 150820} {-1000 150840} {-990 150860} {-1000 150880} {-990 150900} {-1000 150920} {-990 150940} {-1000 150960} {-990 150980} {-1000 151000} {-990 151020} {-1000 151040} {-990 151060} {-1000 151080} {-990 151100} {-1000 151120} {-990 151140} {-1000 151160} {-990 151180} {-1000 151200} {-990 151220} {-1000 151240} {-990 151260} {-1000 151280} {-990 151300} {-1000 151320} {-990 151340} {-1000 151360} {-990 151380} {-1000 151400} {-990 151420} {-1000 151440} {-990 151460} {-1000 151480} {-990 151500} {-1000 151520} {-990 151540} {-1000 151560} {-990 151580} {-1000 151600} {-990 151620} {-1000 151640} {-990 151660} {-1000 151680} {-990 151700} {-1000 151720} {-990 151740} {-1000 151760} {-990 151780} {-1000 151800} {-990 151820} {-1000 151840} {-990 151860} {-1000 151880} {-990 151900} {-1000 151920} {-990 151940} {-1000 151960} {-990 151980} {-1000 152000} {-990 152020} {-1000 152040} {-990 152060} {-1000 152080} {-990 152100} {-1000 152120} {-990 152140} {-1000 152160} {-990 152180} {-1000 152200} {-990 152220} {-1000 152240} {-990 152260} {-1000 152280} {-990 152300} {-1000 152320} {-990 152340} {-1000 152360} {-990 152380} {-1000 152400} {-990 152420} {-1000 152440} {-990 152460} {-1000 152480} {-990 152500} {-1000 152520} {-990 152540} {-1000 152560} {-990 152580} {-1000 152600} {-990 152620} {-1000 152640} {-990 152660} {-1000 152680} {-990 152700} {-1000 152720} {-990 152740} {-1000 152760} {-990 152780} {-1000 152800} {-990 152820} {-1000 152840} {-990 152860} {-1000 152880} {-990 152900} {-1000 152920} {-990 152940} {-1000 152960} {-990 152980} {-1000 153000} {-990 153020} {-1000 153040} {-990 153060} {-1000 153080} {-990 153100} {-1000 153120} {-990 153140} {-1000 153160} {-990 153180} {-1000 153200} {-990 153220} {-1000 153240} {-990 153260} {-1000 153280} {-990 153300} {-1000 153320} {-990 153340} {-1000 153360} {-990 153380} {-1000 153400} {-990 153420} {-1000 153440} {-990 153460} {-1000 153480} {-990 153500} {-1000 153520} {-990 153540} {-1000 153560} {-990 153580} {-1000 153600} {-990 153620} {-1000 153640} {-990 153660} {-1000 153680} {-990 153700} {-1000 153720} {-990 153740} {-1000 153760} {-990 153780} {-1000 153800} {-990 153820} {-1000 153840} {-990 153860} {-1000 153880} {-990 153900} {-1000 153920} {-990 153940} {-1000 153960} {-990 153980} {-1000 154000} {-990 154020} {-1000 154040} {-990 154060} {-1000 154080} {-990 154100} {-1000 154120} {-990 154140} {-1000 154160} {-990 154180} {-1000 154200} {-990 154220} {-1000 154240} {-990 154260} {-1000 154280} {-990 154300} {-1000 154320} {-990 154340} {-1000 154360} {-990 154380} {-1000 154400} {-990 154420} {-1000 154440} {-990 154460} {-1000 154480} {-990 154500} {-1000 154520} {-990 154540} {-1000 154560} {-990 154580} {-1000 154600} {-990 154620} {-1000 154640} {-990 154660} {-1000 154680} {-990 154700} {-1000 154720} {-990 154740} {-1000 154760} {-990 154780} {-1000 154800} {-990 154820} {-1000 154840} {-990 154860} {-1000 154880} {-990 154900} {-1000 154920} {-990 154940} {-1000 154960} {-990 154980} {-1000 155000} {-990 155020} {-1000 155040} {-990 155060} {-1000 155080} {-990 155100} {-1000 155120} {-990 155140} {-1000 155160} {-990 155180} {-1000 155200} {-990 155220} {-1000 155240} {-990 155260} {-1000 155280} {-990 155300} {-1000 155320} {-990 155340} {-1000 155360} {-990 155380} {-1000 155400} {-990 155420} {-1000 155440} {-990 155460} {-1000 155480} {-990 155500} {-1000 155520} {-990 155540} {-1000 155560} {-990 155580} {-1000 155600} {-990 155620} {-1000 155640} {-990 155660} {-1000 155680} {-990 155700} {-1000 155720} {-990 155740} {-1000 155760} {-990 155780} {-1000 155800} {-990 155820} {-1000 155840} {-990 155860} {-1000 155880} {-990 155900} {-1000 155920} {-990 155940} {-1000 155960} {-990 155980} {-1000 156000} {-990 156020} {-1000 156040} {-990 156060} {-1000 156080} {-990 156100} {-1000 156120} {-990 156140} {-1000 156160} {-990 156180} {-1000 156200} {-990 156220} {-1000 156240} {-990 156260} {-1000 156280} {-990 156300} {-1000 156320} {-990 156340} {-1000 156360} {-990 156380} {-1000 156400} {-990 156420} {-1000 156440} {-990 156460} {-1000 156480} {-990 156500} {-1000 156520} {-990 156540} {-1000 156560} {-990 156580} {-1000 156600} {-990 156620} {-1000 156640} {-990 156660} {-1000 156680} {-990 156700} {-1000 156720} {-990 156740} {-1000 156760} {-990 156780} {-1000 156800} {-990 156820} {-1000 156840} {-990 156860} {-1000 156880} {-990 156900} {-1000 156920} {-990 156940} {-1000 156960} {-990 156980} {-1000 157000} {-990 157020} {-1000 157040} {-990 157060} {-1000 157080} {-990 157100} {-1000 157120} {-990 157140} {-1000 157160} {-990 157180} {-1000 157200} {-990 157220} {-1000 157240} {-990 157260} {-1000 157280} {-990 157300} {-1000 157320} {-990 157340} {-1000 157360} {-990 157380} {-1000 157400} {-990 157420} {-1000 157440} {-990 157460} {-1000 157480} {-990 157500} {-1000 157520} {-990 157540} {-1000 157560} {-990 157580} {-1000 157600} {-990 157620} {-1000 157640} {-990 157660} {-1000 157680} {-990 157700} {-1000 157720} {-990 157740} {-1000 157760} {-990 157780} {-1000 157800} {-990 157820} {-1000 157840} {-990 157860} {-1000 157880} {-990 157900} {-1000 157920} {-990 157940} {-1000 157960} {-990 157980} {-1000 158000} {-990 158020} {-1000 158040} {-990 158060} {-1000 158080} {-990 158100} {-1000 158120} {-990 158140} {-1000 158160} {-990 158180} {-1000 158200} {-990 158220} {-1000 158240} {-990 158260} {-1000 158280} {-990 158300} {-1000 158320} {-990 158340} {-1000 158360} {-990 158380} {-1000 158400} {-990 158420} {-1000 158440} {-990 158460} {-1000 158480} {-990 158500} {-1000 158520} {-990 158540} {-1000 158560} {-990 158580} {-1000 158600} {-990 158620} {-1000 158640} {-990 158660} {-1000 158680} {-990 158700} {-1000 158720} {-990 158740} {-1000 158760} {-990 158780} {-1000 158800} {-990 158820} {-1000 158840} {-990 158860} {-1000 158880} {-990 158900} {-1000 158920} {-990 158940} {-1000 158960} {-990 158980} {-1000 159000} {-990 159020} {-1000 159040} {-990 159060} {-1000 159080} {-990 159100} {-1000 159120} {-990 159140} {-1000 159160} {-990 159180} {-1000 159200} {-990 159220} {-1000 159240} {-990 159260} {-1000 159280} {-990 159300} {-1000 159320} {-990 159340} {-1000 159360} {-990 159380} {-1000 159400} {-990 159420} {-1000 159440} {-990 159460} {-1000 159480} {-990 159500} {-1000 159520} {-990 159540} {-1000 159560} {-990 159580} {-1000 159600} {-990 159620} {-1000 159640} {-990 159660} {-1000 159680} {-990 159700} {-1000 159720} {-990 159740} {-1000 159760} {-990 159780} {-1000 159800} {-990 159820} {-1000 159840} {-990 159860} {-1000 159880} {-990 159900} {-1000 159920} {-990 159940} {-1000 159960} {-990 159980} {-1000 160000} {0 160000} {0 0} {-1000 0}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t5.2.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}
#endif

TEST(5_3)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 1 2 {0 100} {0 200} {100 200} {100 150} {150 150} {150 100} {0 100}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 1 2 {-200 400} {-200 500} {-100 500} {-100 450} {-50 450} {-50 400} {-200 400}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {0 400} {0 500} {100 500} {100 450} {150 450} {150 400} {0 400}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {0 1000} {0 1100} {100 1100} {100 1050} {150 1050} {150 1000} {0 1000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {200 1000} {200 1150} {250 1150} {250 1100} {300 1100} {300 1000} {200 1000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {400 1000} {400 1050} {450 1050} {450 1100} {500 1100} {500 1050} {550 1050} {550 1000} {400 1000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {675 1000} {625 1050} {625 1100} {675 1150} {725 1150} {775 1100} {775 1050} {725 1000} {700 1000} {675 1000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {860 1000} {835 1025} {825 1100} {875 1150} {925 1150} {975 1100} {975 1050} {925 1000} {900 1000} {860 1000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {1100 1000} {1095 1575} {1135 1575} {1200 1550} {1275 1450} {1300 1300} {1275 1150} {1200 1050} {1125 1000} {1100 1000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {0 2000} {0 2150} {50 2150} {50 2100} {100 2100} {100 2000} {0 2000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {200 2000} {200 2150} {250 2150} {250 2100} {300 2100} {300 2000} {200 2000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {400 2000} {400 2150} {450 2150} {450 2100} {500 2100} {500 2000} {400 2000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {0 2300} {0 2450} {50 2450} {50 2400} {100 2400} {100 2300} {0 2300}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {200 2300} {200 2450} {250 2450} {250 2400} {300 2400} {300 2300} {200 2300}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {400 2300} {400 2450} {450 2450} {450 2400} {500 2400} {500 2300} {400 2300}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {0 2600} {0 2750} {50 2750} {50 2700} {100 2700} {100 2600} {0 2600}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {200 2600} {200 2750} {250 2750} {250 2700} {300 2700} {300 2600} {200 2600}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {400 2600} {400 2750} {450 2750} {450 2700} {500 2700} {500 2600} {400 2600}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {0 2900} {0 3050} {50 3050} {50 3000} {100 3000} {100 2900} {0 2900}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {200 2900} {200 3050} {250 3050} {250 3000} {300 3000} {300 2900} {200 2900}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 3 {400 2900} {400 3050} {450 3050} {450 3000} {500 3000} {500 2900} {400 2900}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1000 2000} {1000 2150} {1050 2150} {1050 2100} {1100 2100} {1100 2000} {1000 2000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1200 2000} {1200 2150} {1250 2150} {1250 2100} {1300 2100} {1300 2000} {1200 2000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1400 2000} {1400 2150} {1450 2150} {1450 2100} {1500 2100} {1500 2000} {1400 2000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1000 2300} {1000 2450} {1050 2450} {1050 2400} {1100 2400} {1100 2300} {1000 2300}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1200 2300} {1200 2450} {1250 2450} {1250 2400} {1300 2400} {1300 2300} {1200 2300}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1400 2300} {1400 2450} {1450 2450} {1450 2400} {1500 2400} {1500 2300} {1400 2300}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1000 2600} {1000 2750} {1050 2750} {1050 2700} {1100 2700} {1100 2600} {1000 2600}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1200 2600} {1200 2750} {1250 2750} {1250 2700} {1300 2700} {1300 2600} {1200 2600}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1400 2600} {1400 2750} {1450 2750} {1450 2700} {1500 2700} {1500 2600} {1400 2600}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1000 2900} {1000 3050} {1050 3050} {1050 3000} {1100 3000} {1100 2900} {1000 2900}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1200 2900} {1200 3050} {1250 3050} {1250 3000} {1300 3000} {1300 2900} {1200 2900}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {1400 2900} {1400 3050} {1450 3050} {1450 3000} {1500 3000} {1500 2900} {1400 2900}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {2000 2000} {2000 2150} {2050 2150} {2050 2100} {2100 2100} {2100 2000} {2000 2000}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {2000 2200} {2000 2350} {2050 2350} {2050 2300} {2100 2300} {2100 2200} {2000 2200}\n"
    "set props {\n"
    "  {{PROP0} {0.2}}\n"
    "}\n"
    "boundaryp $props 2 1 {2000 2500} {2000 2650} {2050 2650} {2050 2600} {2100 2600} {2100 2500} {2000 2500}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t5.3.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(6_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {ABC}\n"
    "path 1 2 20 5 -5 {0 100} {150 100} {150 150} {100 150}\n"
    "path 1 2 20 5 -5 {0 300} {150 300} {150 350} {100 350}\n"
    "path 1 2 20 0 -5 {0 500} {150 500} {150 550} {100 550}\n"
    "path 1 2 24 0 0 {0 700} {150 700} {150 750} {100 750}\n"
    "path 1 2 24 12 12 {0 900} {150 900} {150 950} {100 950}\n"
    "path 2 3 24 12 12 {0 1100} {150 1100} {150 1150} {100 1150}\n"
    "path 2 3 24 12 12 {0 1300} {150 1300} {150 1350} {100 1350}\n"
    "path 2 3 24 12 12 {200 1300} {350 1300} {350 1350} {300 1350}\n"
    "path 2 3 24 12 12 {400 1300} {550 1300} {550 1350} {500 1350}\n"
    "path 2 3 24 12 12 {0 1600} {150 1600} {150 1650} {100 1650}\n"
    "path 2 3 24 12 12 {200 1600} {350 1600} {350 1650} {300 1650}\n"
    "path 2 3 24 12 12 {400 1600} {550 1600} {550 1650} {500 1650}\n"
    "path 2 3 24 12 12 {0 1900} {150 1900} {150 1950} {100 1950}\n"
    "path 2 3 24 12 12 {200 1900} {350 1900} {350 1950} {300 1950}\n"
    "path 2 3 24 12 12 {400 1900} {550 1900} {550 1950} {500 1950}\n"
    "path 2 3 24 12 12 {0 2200} {150 2200} {150 2250} {100 2250}\n"
    "path 2 3 24 12 12 {200 2200} {350 2200} {350 2250} {300 2250}\n"
    "path 2 3 24 12 12 {400 2200} {550 2200} {550 2250} {500 2250}\n"
    "path 1 3 24 12 12 {1000 1300} {1150 1300} {1150 1350} {1100 1350}\n"
    "path 1 3 24 12 12 {1200 1300} {1350 1300} {1350 1350} {1300 1350}\n"
    "path 1 3 24 12 12 {1400 1300} {1550 1300} {1550 1350} {1500 1350}\n"
    "path 1 3 24 12 12 {1000 1600} {1150 1600} {1150 1650} {1100 1650}\n"
    "path 1 3 24 12 12 {1200 1600} {1350 1600} {1350 1650} {1300 1650}\n"
    "path 1 3 24 12 12 {1400 1600} {1550 1600} {1550 1650} {1500 1650}\n"
    "path 1 3 24 12 12 {1000 1900} {1150 1900} {1150 1950} {1100 1950}\n"
    "path 1 3 24 12 12 {1200 1900} {1350 1900} {1350 1950} {1300 1950}\n"
    "path 1 3 24 12 12 {1400 1900} {1550 1900} {1550 1950} {1500 1950}\n"
    "path 1 3 24 12 12 {1000 2200} {1150 2200} {1150 2250} {1100 2250}\n"
    "path 1 3 24 12 12 {1200 2200} {1350 2200} {1350 2250} {1300 2250}\n"
    "path 1 3 24 12 12 {1400 2200} {1550 2200} {1550 2250} {1500 2250}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t6.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(7_1)
{
  const char *expected; 

  if (db::default_editable_mode ()) {
    expected =
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "boundary 1 2 {20 100} {0 150} {100 150} {60 100} {20 100}\n"
      "boundary 1 2 {100 400} {0 420} {0 450} {100 410} {100 400}\n"
      "boundary 1 2 {150 700} {0 720} {0 730} {150 750} {150 700}\n"
      "boundary 1 2 {0 1000} {20 1050} {130 1050} {150 1000} {0 1000}\n"
      "boundary 1 2 {200 1000} {220 1050} {330 1050} {350 1000} {200 1000}\n"
      "boundary 1 2 {400 1000} {420 1050} {530 1050} {550 1000} {400 1000}\n"
      "boundary 1 2 {0 1300} {20 1350} {130 1350} {150 1300} {0 1300}\n"
      "boundary 1 2 {200 1300} {220 1350} {330 1350} {350 1300} {200 1300}\n"
      "boundary 1 2 {400 1300} {420 1350} {530 1350} {550 1300} {400 1300}\n"
      "boundary 1 2 {0 1600} {20 1650} {130 1650} {150 1600} {0 1600}\n"
      "boundary 1 2 {200 1600} {220 1650} {330 1650} {350 1600} {200 1600}\n"
      "boundary 1 2 {400 1600} {420 1650} {530 1650} {550 1600} {400 1600}\n"
      "boundary 1 2 {0 1900} {20 1950} {130 1950} {150 1900} {0 1900}\n"
      "boundary 1 2 {200 1900} {220 1950} {330 1950} {350 1900} {200 1900}\n"
      "boundary 1 2 {400 1900} {420 1950} {530 1950} {550 1900} {400 1900}\n"
      "boundary 1 2 {1020 100} {1000 150} {1100 150} {1100 100} {1020 100}\n"
      "boundary 1 2 {1100 400} {1000 420} {1000 450} {1100 450} {1100 400}\n"
      "boundary 1 2 {1150 700} {1000 720} {1000 750} {1150 750} {1150 700}\n"
      "boundary 1 2 {1000 1000} {1020 1050} {1150 1050} {1150 1000} {1000 1000}\n"
      "boundary 1 2 {1200 1000} {1220 1050} {1350 1050} {1350 1000} {1200 1000}\n"
      "boundary 1 2 {1400 1000} {1420 1050} {1550 1050} {1550 1000} {1400 1000}\n"
      "boundary 1 2 {1000 1300} {1020 1350} {1150 1350} {1150 1300} {1000 1300}\n"
      "boundary 1 2 {1200 1300} {1220 1350} {1350 1350} {1350 1300} {1200 1300}\n"
      "boundary 1 2 {1400 1300} {1420 1350} {1550 1350} {1550 1300} {1400 1300}\n"
      "boundary 1 2 {1000 1600} {1020 1650} {1150 1650} {1150 1600} {1000 1600}\n"
      "boundary 1 2 {1200 1600} {1220 1650} {1350 1650} {1350 1600} {1200 1600}\n"
      "boundary 1 2 {1400 1600} {1420 1650} {1550 1650} {1550 1600} {1400 1600}\n"
      "boundary 1 2 {1000 1900} {1020 1950} {1150 1950} {1150 1900} {1000 1900}\n"
      "boundary 1 2 {1200 1900} {1220 1950} {1350 1950} {1350 1900} {1200 1900}\n"
      "boundary 1 2 {1400 1900} {1420 1950} {1550 1950} {1550 1900} {1400 1900}\n"
      "boundary 1 2 {2000 100} {2000 150} {2100 150} {2060 100} {2000 100}\n"
      "boundary 1 2 {2000 400} {2000 450} {2100 410} {2100 400} {2000 400}\n"
      "boundary 1 2 {2000 700} {2000 730} {2150 750} {2150 700} {2000 700}\n"
      "boundary 1 2 {2000 1000} {2000 1050} {2130 1050} {2150 1000} {2000 1000}\n"
      "boundary 1 2 {2200 1000} {2200 1050} {2330 1050} {2350 1000} {2200 1000}\n"
      "boundary 1 2 {2400 1000} {2400 1050} {2530 1050} {2550 1000} {2400 1000}\n"
      "boundary 1 2 {2000 1300} {2000 1350} {2130 1350} {2150 1300} {2000 1300}\n"
      "boundary 1 2 {2200 1300} {2200 1350} {2330 1350} {2350 1300} {2200 1300}\n"
      "boundary 1 2 {2400 1300} {2400 1350} {2530 1350} {2550 1300} {2400 1300}\n"
      "boundary 1 2 {2000 1600} {2000 1650} {2130 1650} {2150 1600} {2000 1600}\n"
      "boundary 1 2 {2200 1600} {2200 1650} {2330 1650} {2350 1600} {2200 1600}\n"
      "boundary 1 2 {2400 1600} {2400 1650} {2530 1650} {2550 1600} {2400 1600}\n"
      "boundary 1 2 {2000 1900} {2000 1950} {2130 1950} {2150 1900} {2000 1900}\n"
      "boundary 1 2 {2200 1900} {2200 1950} {2330 1950} {2350 1900} {2200 1900}\n"
      "boundary 1 2 {2400 1900} {2400 1950} {2530 1950} {2550 1900} {2400 1900}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  } else {
    expected = 
      "begin_lib 0.001\n"
      "begin_cell {ABC}\n"
      "boundary 1 2 {20 100} {0 150} {100 150} {60 100} {20 100}\n"
      "boundary 1 2 {100 400} {0 420} {0 450} {100 410} {100 400}\n"
      "boundary 1 2 {150 700} {0 720} {0 730} {150 750} {150 700}\n"
      "boundary 1 2 {1020 100} {1000 150} {1100 150} {1100 100} {1020 100}\n"
      "boundary 1 2 {1100 400} {1000 420} {1000 450} {1100 450} {1100 400}\n"
      "boundary 1 2 {1150 700} {1000 720} {1000 750} {1150 750} {1150 700}\n"
      "boundary 1 2 {2000 100} {2000 150} {2100 150} {2060 100} {2000 100}\n"
      "boundary 1 2 {2000 400} {2000 450} {2100 410} {2100 400} {2000 400}\n"
      "boundary 1 2 {2000 700} {2000 730} {2150 750} {2150 700} {2000 700}\n"
      "boundary 1 2 {0 1000} {20 1050} {130 1050} {150 1000} {0 1000}\n"
      "boundary 1 2 {200 1000} {220 1050} {330 1050} {350 1000} {200 1000}\n"
      "boundary 1 2 {400 1000} {420 1050} {530 1050} {550 1000} {400 1000}\n"
      "boundary 1 2 {0 1300} {20 1350} {130 1350} {150 1300} {0 1300}\n"
      "boundary 1 2 {200 1300} {220 1350} {330 1350} {350 1300} {200 1300}\n"
      "boundary 1 2 {400 1300} {420 1350} {530 1350} {550 1300} {400 1300}\n"
      "boundary 1 2 {0 1600} {20 1650} {130 1650} {150 1600} {0 1600}\n"
      "boundary 1 2 {200 1600} {220 1650} {330 1650} {350 1600} {200 1600}\n"
      "boundary 1 2 {400 1600} {420 1650} {530 1650} {550 1600} {400 1600}\n"
      "boundary 1 2 {0 1900} {20 1950} {130 1950} {150 1900} {0 1900}\n"
      "boundary 1 2 {200 1900} {220 1950} {330 1950} {350 1900} {200 1900}\n"
      "boundary 1 2 {400 1900} {420 1950} {530 1950} {550 1900} {400 1900}\n"
      "boundary 1 2 {1000 1000} {1020 1050} {1150 1050} {1150 1000} {1000 1000}\n"
      "boundary 1 2 {1200 1000} {1220 1050} {1350 1050} {1350 1000} {1200 1000}\n"
      "boundary 1 2 {1400 1000} {1420 1050} {1550 1050} {1550 1000} {1400 1000}\n"
      "boundary 1 2 {1000 1300} {1020 1350} {1150 1350} {1150 1300} {1000 1300}\n"
      "boundary 1 2 {1200 1300} {1220 1350} {1350 1350} {1350 1300} {1200 1300}\n"
      "boundary 1 2 {1400 1300} {1420 1350} {1550 1350} {1550 1300} {1400 1300}\n"
      "boundary 1 2 {1000 1600} {1020 1650} {1150 1650} {1150 1600} {1000 1600}\n"
      "boundary 1 2 {1200 1600} {1220 1650} {1350 1650} {1350 1600} {1200 1600}\n"
      "boundary 1 2 {1400 1600} {1420 1650} {1550 1650} {1550 1600} {1400 1600}\n"
      "boundary 1 2 {1000 1900} {1020 1950} {1150 1950} {1150 1900} {1000 1900}\n"
      "boundary 1 2 {1200 1900} {1220 1950} {1350 1950} {1350 1900} {1200 1900}\n"
      "boundary 1 2 {1400 1900} {1420 1950} {1550 1950} {1550 1900} {1400 1900}\n"
      "boundary 1 2 {2000 1000} {2000 1050} {2130 1050} {2150 1000} {2000 1000}\n"
      "boundary 1 2 {2200 1000} {2200 1050} {2330 1050} {2350 1000} {2200 1000}\n"
      "boundary 1 2 {2400 1000} {2400 1050} {2530 1050} {2550 1000} {2400 1000}\n"
      "boundary 1 2 {2000 1300} {2000 1350} {2130 1350} {2150 1300} {2000 1300}\n"
      "boundary 1 2 {2200 1300} {2200 1350} {2330 1350} {2350 1300} {2200 1300}\n"
      "boundary 1 2 {2400 1300} {2400 1350} {2530 1350} {2550 1300} {2400 1300}\n"
      "boundary 1 2 {2000 1600} {2000 1650} {2130 1650} {2150 1600} {2000 1600}\n"
      "boundary 1 2 {2200 1600} {2200 1650} {2330 1650} {2350 1600} {2200 1600}\n"
      "boundary 1 2 {2400 1600} {2400 1650} {2530 1650} {2550 1600} {2400 1600}\n"
      "boundary 1 2 {2000 1900} {2000 1950} {2130 1950} {2150 1900} {2000 1900}\n"
      "boundary 1 2 {2200 1900} {2200 1950} {2330 1950} {2350 1900} {2200 1900}\n"
      "boundary 1 2 {2400 1900} {2400 1950} {2530 1950} {2550 1900} {2400 1900}\n"
      "end_cell\n"
      "end_lib\n"
    ;
  }

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t7.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(8_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "sref {A} 0 0 1 {-300 400}\n"
    "sref {A} 0 0 1 {-300 800}\n"
    "sref {A} 0 0 1 {-300 1200}\n"
    "sref {A} 0 0 1 {0 1200}\n"
    "sref {A} 0 1 1 {700 400}\n"
    "sref {A} 90 0 1 {700 1400}\n"
    "sref {A} 90 1 1 {700 2400}\n"
    "aref {A} 270 1 1 3 4 {2000 0} {2900 0} {2000 1200}\n"
    "aref {A} 270 1 1 3 4 {4000 0} {4900 0} {4000 1200}\n"
    "aref {A} 270 1 1 3 1 {6000 0} {6960 0} {6000 0}\n"
    "aref {A} 270 1 1 1 4 {8000 0} {8000 0} {8000 1240}\n"
    "sref {A} 270 1 1 {10000 0}\n"
    "sref {A} 270 1 1 {10320 0}\n"
    "sref {A} 270 1 1 {10650 0}\n"
    "sref {A} 270 1 1 {10990 0}\n"
    "aref {A} 270 1 1 3 4 {12000 0} {12930 960} {10680 1320}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t8.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(8_2)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "sref {A} 0 0 1 {-300 400}\n"
    "sref {A} 0 0 1 {-300 800}\n"
    "sref {A} 0 0 1 {-300 1200}\n"
    "sref {A} 0 0 1 {0 1200}\n"
    "sref {A} 0 1 1 {700 400}\n"
    "sref {A} 90 0 1 {700 1400}\n"
    "sref {A} 90 1 1 {700 2400}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t8.2.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(8_3)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "sref {A} 0 0 1 {-300 400}\n"
    "sref {A} 0 0 1 {-300 800}\n"
    "sref {A} 0 0 1 {-300 1200}\n"
    "sref {A} 0 0 1 {0 1200}\n"
    "sref {A} 0 1 1 {700 400}\n"
    "sref {A} 90 0 1 {700 1400}\n"
    "sref {A} 90 1 1 {700 2400}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t8.3.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(8_4)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "aref {A} 0 0 1 3 4 {-300 400} {-240 400} {-300 520}\n"
    "aref {A} 0 0 1 3 4 {-300 800} {-240 800} {-300 920}\n"
    "aref {A} 0 0 1 3 4 {-300 1200} {-240 1200} {-300 1320}\n"
    "aref {A} 0 0 1 3 4 {0 1200} {60 1200} {0 1320}\n"
    "aref {A} 0 1 1 3 4 {700 400} {760 400} {700 520}\n"
    "aref {A} 90 0 1 3 4 {700 1400} {760 1400} {700 1520}\n"
    "aref {A} 90 1 1 3 4 {700 2400} {760 2400} {700 2520}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t8.4.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(8_5)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "sref {A} 0 0 1 {-300 400}\n"
    "sref {A} 0 0 1 {-300 800}\n"
    "sref {A} 0 0 1 {-300 1200}\n"
    "sref {A} 0 0 1 {0 1200}\n"
    "sref {A} 0 1 1 {700 400}\n"
    "sref {A} 90 0 1 {700 1400}\n"
    "sref {A} 90 1 1 {700 2400}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t8.5.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(8_6)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "sref {A} 0 0 0.5 {-150 200}\n"
    "sref {A} 0 0 1 {-300 800}\n"
    "sref {A} 0 0 1 {-300 1200}\n"
    "sref {A} 0 0 1 {0 1200}\n"
    "sref {A} 0 1 1 {700 400}\n"
    "sref {A} 90 0 1 {700 1400}\n"
    "sref {A} 270 1 1 {700 2400}\n"
    "end_cell\n"
    "begin_cell {TOPTOP}\n"
    "sref {TOP} 90 0 0.5 {100 0}\n"
    "sref {TOP} 0 0 1 {200 1000}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t8.6.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(8_7)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "sref {A} 0 0 1 {-300 400}\n"
    "sref {A} 0 0 1 {-300 800}\n"
    "sref {A} 0 0 1 {-300 1200}\n"
    "sref {A} 0 0 1 {0 1200}\n"
    "sref {A} 0 1 1 {700 400}\n"
    "sref {A} 90 0 1 {700 1400}\n"
    "sref {A} 90 1 1 {700 2400}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t8.7.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(8_8)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "box 1 2 {30 -40} {130 160}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "sref {A} 0 0 2 {-100 100}\n"
    "sref {A} 45 0 1 {-150 1100}\n"
    "aref {A} 135 1 0.5 3 4 {-200 2100} {400 2100} {-200 3300}\n"
    "end_cell\n"
    "begin_cell {TOPTOP}\n"
    "sref {TOP} 22.5 0 0.5 {100 0}\n"
    "sref {TOP} 0 0 1 {1100 0}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t8.8.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(9_1)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "boundary 1 2 {-100 200} {-100 400} {0 400} {0 200} {-100 200}\n"
    "boundary 1 2 {-100 600} {-100 800} {0 800} {0 600} {-100 600}\n"
    "boundary 1 2 {-100 1000} {-100 1100} {50 1100} {150 1000} {-100 1000}\n"
    "boundary 1 2 {-100 1400} {-100 1500} {150 1500} {50 1400} {-100 1400}\n"
    "boundary 1 2 {-100 1800} {0 1900} {150 1900} {150 1800} {-100 1800}\n"
    "boundary 1 2 {0 2200} {-100 2300} {150 2300} {150 2200} {0 2200}\n"
    "boundary 1 2 {-100 2600} {0 2700} {50 2700} {150 2600} {-100 2600}\n"
    "boundary 1 2 {0 3000} {-100 3100} {150 3100} {50 3000} {0 3000}\n"
    "boundary 1 2 {-100 3400} {0 3500} {150 3500} {50 3400} {-100 3400}\n"
    "boundary 1 2 {0 3800} {-100 3900} {50 3900} {150 3800} {0 3800}\n"
    "boundary 1 2 {-100 4200} {-100 4450} {0 4350} {0 4200} {-100 4200}\n"
    "boundary 1 2 {-100 4600} {-100 4750} {0 4850} {0 4600} {-100 4600}\n"
    "boundary 1 2 {-100 5000} {-100 5250} {0 5250} {0 5100} {-100 5000}\n"
    "boundary 1 2 {0 5400} {-100 5500} {-100 5650} {0 5650} {0 5400}\n"
    "boundary 1 2 {-100 5800} {-100 6050} {0 5950} {0 5900} {-100 5800}\n"
    "boundary 1 2 {0 6200} {-100 6300} {-100 6350} {0 6450} {0 6200}\n"
    "boundary 1 2 {-100 6600} {-100 6750} {0 6850} {0 6700} {-100 6600}\n"
    "boundary 1 2 {0 7000} {-100 7100} {-100 7250} {0 7150} {0 7000}\n"
    "boundary 1 2 {-100 7400} {-100 7650} {150 7400} {-100 7400}\n"
    "boundary 1 2 {-100 7800} {-100 8050} {150 8050} {-100 7800}\n"
    "boundary 1 2 {-100 8200} {150 8450} {150 8200} {-100 8200}\n"
    "boundary 1 2 {150 8600} {-100 8850} {150 8850} {150 8600}\n"
    "boundary 1 2 {-100 9000} {0 9100} {100 9000} {-100 9000}\n"
    "boundary 1 2 {0 9400} {-100 9500} {100 9500} {0 9400}\n"
    "boundary 1 2 {-100 9800} {-100 10000} {0 9900} {-100 9800}\n"
    "boundary 1 2 {0 10200} {-100 10300} {0 10400} {0 10200}\n"
    "boundary 1 2 {-100 10600} {-100 10700} {150 10700} {150 10600} {-100 10600}\n"
    "boundary 1 2 {-100 11000} {-100 11250} {150 11250} {150 11000} {-100 11000}\n"
    "boundary 2 3 {-100 11400} {-100 11650} {150 11650} {150 11400} {-100 11400}\n"
    "boundary 2 3 {300 11400} {300 11650} {550 11650} {550 11400} {300 11400}\n"
    "boundary 2 3 {700 11400} {700 11650} {950 11650} {950 11400} {700 11400}\n"
    "boundary 2 3 {-100 11700} {-100 11950} {150 11950} {150 11700} {-100 11700}\n"
    "boundary 2 3 {300 11700} {300 11950} {550 11950} {550 11700} {300 11700}\n"
    "boundary 2 3 {700 11700} {700 11950} {950 11950} {950 11700} {700 11700}\n"
    "boundary 2 3 {-100 12000} {-100 12250} {150 12250} {150 12000} {-100 12000}\n"
    "boundary 2 3 {300 12000} {300 12250} {550 12250} {550 12000} {300 12000}\n"
    "boundary 2 3 {700 12000} {700 12250} {950 12250} {950 12000} {700 12000}\n"
    "boundary 2 3 {-100 12300} {-100 12550} {150 12550} {150 12300} {-100 12300}\n"
    "boundary 2 3 {300 12300} {300 12550} {550 12550} {550 12300} {300 12300}\n"
    "boundary 2 3 {700 12300} {700 12550} {950 12550} {950 12300} {700 12300}\n"
    "box 2 3 {-100 600} {0 800}\n"
    "box 2 3 {-100 1000} {150 1100}\n"
    "box 2 3 {-100 1400} {150 1500}\n"
    "box 2 3 {-100 1800} {150 1900}\n"
    "box 2 3 {-100 2200} {150 2300}\n"
    "box 2 3 {-100 2600} {150 2700}\n"
    "box 2 3 {-100 3000} {150 3100}\n"
    "box 2 3 {-100 3400} {150 3500}\n"
    "box 2 3 {-100 3800} {150 3900}\n"
    "box 2 3 {-100 4200} {0 4450}\n"
    "box 2 3 {-100 4600} {0 4850}\n"
    "box 2 3 {-100 5000} {0 5250}\n"
    "box 2 3 {-100 5400} {0 5650}\n"
    "box 2 3 {-100 5800} {0 6050}\n"
    "box 2 3 {-100 6200} {0 6450}\n"
    "box 2 3 {-100 6600} {0 6850}\n"
    "box 2 3 {-100 7000} {0 7250}\n"
    "box 2 3 {-100 7400} {150 7650}\n"
    "box 2 3 {-100 7800} {150 8050}\n"
    "box 2 3 {-100 8200} {150 8450}\n"
    "box 2 3 {-100 8600} {150 8850}\n"
    "box 2 3 {-100 9000} {100 9100}\n"
    "box 2 3 {-100 9400} {100 9500}\n"
    "box 2 3 {-100 9800} {0 10000}\n"
    "box 2 3 {-100 10200} {0 10400}\n"
    "box 2 3 {-100 10600} {150 10700}\n"
    "box 2 3 {-100 11000} {150 11250}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t9.1.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

TEST(9_2)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {B}\n"
    "boundary 1 2 {-100 200} {100 400} {300 200} {-100 200}\n"
    "boundary 1 2 {-100 600} {100 800} {300 600} {-100 600}\n"
    "end_cell\n"
    "begin_cell {A}\n"
    "boundary 1 2 {-100 200} {-100 400} {100 200} {-100 200}\n"
    "boundary 1 2 {-100 600} {-100 800} {100 600} {-100 600}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);
  std::string fn (tl::testsrc ());
  fn += "/testdata/oasis/t9.2.oas";
  tl::InputStream stream (fn);
  db::Reader reader (stream);
  reader.set_warnings_as_errors (true);
  
  bool error = false;
  try {
    db::LayerMap map = reader.read (layout);
  } catch (tl::Exception &ex) {
    tl::error << ex.msg ();
    error = true;
  }
  EXPECT_EQ (error, false)

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

//  Tests add-on reading 
TEST(99)
{
  const char *expected = 
    "begin_lib 0.001\n"
    "begin_cell {A}\n"
    "boundary 1 2 {-100 200} {-100 400} {100 200} {-100 200}\n"
    "boundary 1 2 {-100 600} {-100 800} {100 600} {-100 600}\n"
    "box 1 2 {300 -400} {400 -200}\n"
    "end_cell\n"
    "begin_cell {TOP}\n"
    "sref {A} 0 0 1 {-300 400}\n"
    "sref {A} 0 0 1 {-300 800}\n"
    "sref {A} 0 0 1 {-300 1200}\n"
    "sref {A} 0 0 1 {0 1200}\n"
    "sref {A} 0 1 1 {700 400}\n"
    "sref {A} 90 0 1 {700 1400}\n"
    "sref {A} 90 1 1 {700 2400}\n"
    "end_cell\n"
    "begin_cell {B}\n"
    "boundary 1 2 {-100 200} {100 400} {300 200} {-100 200}\n"
    "boundary 1 2 {-100 600} {100 800} {300 600} {-100 600}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);

  {
    std::string fn (tl::testsrc ());
    fn += "/testdata/oasis/t9.2.oas";
    tl::InputStream stream (fn);
    db::Reader reader (stream);
    reader.set_warnings_as_errors (true);
    
    bool error = false;
    try {
      db::LayerMap map = reader.read (layout);
    } catch (tl::Exception &ex) {
      tl::error << ex.msg ();
      error = true;
    }
    EXPECT_EQ (error, false)
  }

  {
    std::string fn (tl::testsrc ());
    fn += "/testdata/oasis/t8.7.oas";
    tl::InputStream stream (fn);
    db::Reader reader (stream);
    reader.set_warnings_as_errors (true);
    
    bool error = false;
    try {
      db::LayerMap map = reader.read (layout);
    } catch (tl::Exception &ex) {
      tl::error << ex.msg ();
      error = true;
    }
    EXPECT_EQ (error, false)
  }

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

//  XGEOMTRY tests (#773)
TEST(100)
{
  const char *expected = 
    "begin_lib 0.0001\n"
    "begin_cell {mask}\n"
    "boundary 7 1 {13237 5356} {13210 5490} {13192 5530} {13170 5563} {13130 5586} {13090 5583} {13070 5570} {13050 5551} {13037 5530} {13021 5490} {12988 5378} {12938 5390} {12963 5530} {12977 5570} {12998 5610} {13034 5650} {13051 5663} {13090 5678} {13130 5679} {13171 5667} {13210 5638} {13232 5611} {13253 5570} {13274 5490} {13291 5365} {13237 5356}\n"
    "boundary 4 0 {10772 1658} {10772 1744} {14510 1744} {14510 1658} {10772 1658}\n"
    "boundary 4 0 {14510 1658} {14510 1744} {15672 1744} {15672 1658} {14510 1658}\n"
    "boundary 4 0 {18157 647} {18157 676} {21642 676} {21642 647} {18157 647}\n"
    "boundary 6 0 {6743 2449} {6743 4230} {9061 4230} {9061 2449} {6743 2449}\n"
    "boundary 2 3 {21642 3613} {21642 4005} {19409 4005} {19409 6980} {21812 6980} {21812 4958} {21942 4958} {21942 4005} {21812 4005} {21812 3613} {21642 3613}\n"
    "boundary 2 4 {21642 4005} {21642 4958} {21812 4958} {21812 4005} {21642 4005}\n"
    "boundary 8 0 {21680 4106} {21640 4107} {21600 4118} {21574 4130} {21560 4138} {21520 4163} {21509 4170} {21480 4194} {21458 4210} {21440 4227} {21411 4250} {21400 4262} {21366 4290} {21360 4298} {21324 4330} {21320 4335} {21282 4370} {21280 4373} {21241 4410} {21240 4411} {21200 4450} {21160 4490} {21159 4490} {21039 4610} {21000 4650} {20960 4690} {20960 4691} {20921 4730} {20920 4732} {20896 4770} {20886 4810} {20882 4850} {20880 4930} {20880 5330} {20920 5370} {20960 5370} {21000 5340} {21013 5330} {21040 5325} {21080 5309} {21120 5291} {21121 5290} {21160 5276} {21200 5258} {21210 5250} {21240 5240} {21280 5222} {21295 5210} {21320 5202} {21360 5181} {21374 5170} {21400 5160} {21440 5136} {21447 5130} {21480 5112} {21510 5090} {21520 5086} {21560 5058} {21568 5050} {21600 5027} {21617 5010} {21640 4993} {21662 4970} {21680 4955} {21701 4930} {21720 4910} {21735 4890} {21760 4856} {21764 4850} {21786 4810} {21800 4781} {21805 4770} {21818 4730} {21828 4690} {21836 4650} {21840 4616} {21841 4610} {21845 4530} {21845 4450} {21844 4410} {21841 4370} {21840 4358} {21836 4330} {21829 4290} {21818 4250} {21803 4210} {21800 4205} {21778 4170} {21760 4148} {21738 4130} {21720 4118} {21680 4106}\n"
    "boundary 1 0 {17922 6288} {17922 6510} {18150 6510} {18150 6288} {17922 6288}\n"
    "boundary 1 0 {18157 647} {18157 676} {21630 676} {21630 647} {18157 647}\n"
    "boundary 1 0 {21956 0} {21956 89} {22047 89} {22047 0} {21956 0}\n"
    "boundary 3 0 {15392 1744} {15392 1774} {15672 1774} {15672 1744} {15392 1744}\n"
    "boundary 5 1 {15550 1658} {15550 1673} {15570 1673} {15570 1658} {15550 1658}\n"
    "boundary 5 1 {15661 1657} {15641 1659} {15642 1671} {15662 1669} {15661 1657}\n"
    "boundary 5 1 {18150 7440} {18150 7460} {18162 7460} {18162 7440} {18150 7440}\n"
    "boundary 5 1 {18150 8488} {18150 8508} {18162 8508} {18162 8488} {18150 8488}\n"
    "boundary 5 1 {18150 9480} {18150 9500} {18162 9500} {18162 9480} {18150 9480}\n"
    "boundary 5 1 {18670 3411} {18670 3468} {18690 3468} {18690 3411} {18670 3411}\n"
    "boundary 5 1 {19470 3411} {19470 3468} {19490 3468} {19490 3411} {19470 3411}\n"
    "boundary 5 1 {20217 3411} {20217 3468} {20237 3468} {20237 3411} {20217 3411}\n"
    "boundary 5 1 {21630 2048} {21630 2068} {21642 2068} {21642 2048} {21630 2048}\n"
    "boundary 5 1 {21630 2293} {21630 2313} {21642 2313} {21642 2293} {21630 2293}\n"
    "boundary 5 1 {21930 9308} {21930 9328} {21942 9328} {21942 9308} {21930 9308}\n"
    "boundary 5 1 {21930 9600} {21930 9620} {21942 9620} {21942 9600} {21930 9600}\n"
    "boundary 5 1 {23570 6128} {23570 6148} {23582 6148} {23582 6128} {23570 6128}\n"
    "boundary 5 1 {23570 6147} {23570 6167} {23582 6167} {23582 6147} {23570 6147}\n"
    "boundary 5 1 {25710 1978} {25710 1998} {25722 1998} {25722 1978} {25710 1978}\n"
    "boundary 5 1 {25710 2800} {25710 2820} {25722 2820} {25722 2800} {25710 2800}\n"
    "boundary 5 2 {18074 6408} {17971 6486} {17983 6502} {18086 6424} {18074 6408}\n"
    "end_cell\n"
    "end_lib\n"
  ;

  db::Manager m;
  db::Layout layout (&m);

  {
    std::string fn (tl::testsrc ());
    fn += "/testdata/oasis/xgeometry_test.oas";
    tl::InputStream stream (fn);
    db::Reader reader (stream);
    reader.set_warnings_as_errors (true);
    
    reader.read (layout);
  }

  tl::OutputStringStream os;
  tl::OutputStream ostream (os);
  db::TextWriter writer (ostream);
  writer.write (layout);
  EXPECT_EQ (std::string (os.string ()), std::string (expected))
}

