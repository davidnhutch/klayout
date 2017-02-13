
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

/**
*  @file gsiDeclQResizeEvent.cc 
*
*  DO NOT EDIT THIS FILE. 
*  This file has been created automatically
*/

#include <QResizeEvent>
#include <QEvent>
#include <QSize>
#include "gsiQt.h"
#include "gsiQtCommon.h"
#include "gsiDeclQtTypeTraits.h"
#include <memory>

// -----------------------------------------------------------------------
// class QResizeEvent

// const QSize &QResizeEvent::oldSize()


static void _init_f_oldSize_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QSize & > ();
}

static void _call_f_oldSize_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<const QSize & > ((const QSize &)((QResizeEvent *)cls)->oldSize ());
}


// const QSize &QResizeEvent::size()


static void _init_f_size_c0 (qt_gsi::GenericMethod *decl)
{
  decl->set_return<const QSize & > ();
}

static void _call_f_size_c0 (const qt_gsi::GenericMethod * /*decl*/, void *cls, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  ret.write<const QSize & > ((const QSize &)((QResizeEvent *)cls)->size ());
}


namespace gsi
{

static gsi::Methods methods_QResizeEvent () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericMethod ("oldSize", "@brief Method const QSize &QResizeEvent::oldSize()\n", true, &_init_f_oldSize_c0, &_call_f_oldSize_c0);
  methods += new qt_gsi::GenericMethod ("size", "@brief Method const QSize &QResizeEvent::size()\n", true, &_init_f_size_c0, &_call_f_size_c0);
  return methods;
}

gsi::Class<QEvent> &qtdecl_QEvent ();

gsi::Class<QResizeEvent> decl_QResizeEvent (qtdecl_QEvent (), "QResizeEvent_Native",
  methods_QResizeEvent (),
  "@hide\n@alias QResizeEvent");

GSIQT_PUBLIC gsi::Class<QResizeEvent> &qtdecl_QResizeEvent () { return decl_QResizeEvent; }

}


class QResizeEvent_Adaptor : public QResizeEvent, public qt_gsi::QtObjectBase
{
public:

  virtual ~QResizeEvent_Adaptor();

  //  [adaptor ctor] QResizeEvent::QResizeEvent(const QSize &size, const QSize &oldSize)
  QResizeEvent_Adaptor(const QSize &size, const QSize &oldSize) : QResizeEvent(size, oldSize)
  {
    qt_gsi::QtObjectBase::init (this);
  }

  
};

QResizeEvent_Adaptor::~QResizeEvent_Adaptor() { }

//  Constructor QResizeEvent::QResizeEvent(const QSize &size, const QSize &oldSize) (adaptor class)

static void _init_ctor_QResizeEvent_Adaptor_3502 (qt_gsi::GenericStaticMethod *decl)
{
  static gsi::ArgSpecBase argspec_0 ("size");
  decl->add_arg<const QSize & > (argspec_0);
  static gsi::ArgSpecBase argspec_1 ("oldSize");
  decl->add_arg<const QSize & > (argspec_1);
  decl->set_return_new<QResizeEvent_Adaptor> ();
}

static void _call_ctor_QResizeEvent_Adaptor_3502 (const qt_gsi::GenericStaticMethod * /*decl*/, gsi::SerialArgs &args, gsi::SerialArgs &ret) 
{
  __SUPPRESS_UNUSED_WARNING(args);
  tl::Heap heap;
  const QSize &arg1 = args.read<const QSize & > (heap);
  const QSize &arg2 = args.read<const QSize & > (heap);
  ret.write<QResizeEvent_Adaptor *> (new QResizeEvent_Adaptor (arg1, arg2));
}


namespace gsi
{

gsi::Class<QResizeEvent> &qtdecl_QResizeEvent ();

static gsi::Methods methods_QResizeEvent_Adaptor () {
  gsi::Methods methods;
  methods += new qt_gsi::GenericStaticMethod ("new", "@brief Constructor QResizeEvent::QResizeEvent(const QSize &size, const QSize &oldSize)\nThis method creates an object of class QResizeEvent.", &_init_ctor_QResizeEvent_Adaptor_3502, &_call_ctor_QResizeEvent_Adaptor_3502);
  return methods;
}

gsi::Class<QResizeEvent_Adaptor> decl_QResizeEvent_Adaptor (qtdecl_QResizeEvent (), "QResizeEvent",
  methods_QResizeEvent_Adaptor (),
  "@qt\n@brief Binding of QResizeEvent");

}
