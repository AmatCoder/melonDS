#ifndef _WX_SOCKET_H_
#define _WX_SOCKET_H_

#include "wx/defs.h"
#include "wx/control.h"
#include <gtk/gtk.h>

extern WXDLLEXPORT_DATA(const wxChar) wxSocketNameStr[];

class WXDLLEXPORT wxSocketBase : public wxControl
{
public:
    wxSocketBase() {}

    virtual bool AcceptsFocus() const {return false;}
    virtual bool HasTransparentBackground() {return false;}

private:
    DECLARE_NO_COPY_CLASS(wxSocketBase)
};

class WXDLLIMPEXP_CORE wxSocket : public wxControl
{
public:
    wxSocket();

    wxSocket(wxWindow *parent,
             wxWindowID id,
             const wxPoint &pos = wxDefaultPosition,
             const wxSize &size = wxDefaultSize,
             long style = 0,
             const wxString &name = wxSocketNameStr);

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxPoint &pos = wxDefaultPosition,
                const wxSize &size = wxDefaultSize,
                long style = 0,
                const wxString &name = wxSocketNameStr);

    void setWindow(GdkNativeWindow test);

protected:
    virtual void DoSetSize(int x, int y,
                           int width, int height,
                           int sizeFlags = wxSIZE_AUTO);

    virtual wxSize DoGetBestSize() const;

    DECLARE_DYNAMIC_CLASS(wxSocket)
};

#endif // _WX_SOCKET_H_
