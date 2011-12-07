// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/load_handler_cpptoc.h"
#include "libcef_dll/ctocpp/browser_ctocpp.h"
#include "libcef_dll/ctocpp/frame_ctocpp.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK load_handler_on_load_start(struct _cef_load_handler_t* self,
    cef_browser_t* browser, cef_frame_t* frame)
{
  DCHECK(self);
  DCHECK(browser);
  DCHECK(frame);
  if (!self || !browser || !frame)
    return;

  CefLoadHandlerCppToC::Get(self)->OnLoadStart(
      CefBrowserCToCpp::Wrap(browser), CefFrameCToCpp::Wrap(frame));
}

void CEF_CALLBACK load_handler_on_load_end(struct _cef_load_handler_t* self,
    cef_browser_t* browser, cef_frame_t* frame, int httpStatusCode)
{
  DCHECK(self);
  DCHECK(browser);
  DCHECK(frame);
  if (!self || !browser || !frame)
    return;

  CefLoadHandlerCppToC::Get(self)->OnLoadEnd(
      CefBrowserCToCpp::Wrap(browser), CefFrameCToCpp::Wrap(frame),
      httpStatusCode);
}

int CEF_CALLBACK load_handler_on_load_error(struct _cef_load_handler_t* self,
    cef_browser_t* browser, cef_frame_t* frame,
    enum cef_handler_errorcode_t errorCode, const cef_string_t* failedUrl,
    cef_string_t* errorText)
{
  DCHECK(self);
  DCHECK(browser);
  DCHECK(frame);
  DCHECK(failedUrl);
  DCHECK(errorText);
  if (!self || !browser || !frame || !failedUrl || !errorText)
    return 0;

  CefString errorTextStr(errorText);
  return CefLoadHandlerCppToC::Get(self)->OnLoadError(
      CefBrowserCToCpp::Wrap(browser), CefFrameCToCpp::Wrap(frame), errorCode,
      CefString(failedUrl), errorTextStr);
}


// CONSTRUCTOR - Do not edit by hand.

CefLoadHandlerCppToC::CefLoadHandlerCppToC(CefLoadHandler* cls)
    : CefCppToC<CefLoadHandlerCppToC, CefLoadHandler, cef_load_handler_t>(cls)
{
  struct_.struct_.on_load_start = load_handler_on_load_start;
  struct_.struct_.on_load_end = load_handler_on_load_end;
  struct_.struct_.on_load_error = load_handler_on_load_error;
}

#ifndef NDEBUG
template<> long CefCppToC<CefLoadHandlerCppToC, CefLoadHandler,
    cef_load_handler_t>::DebugObjCt = 0;
#endif
