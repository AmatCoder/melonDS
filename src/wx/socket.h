#ifndef _WX_SOCKET_H_
#define _WX_SOCKET_H_

#include "wx/control.h"
#include <gtk/gtk.h>

class wxSocket : public wxControl
{
public:
    wxSocket();

    wxSocket(wxWindow *parent,
             wxWindowID id,
             const wxPoint &pos = wxDefaultPosition,
             const wxSize &size = wxDefaultSize,
             long style = 0,
             const wxString &name = wxT("socket"));

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxPoint &pos = wxDefaultPosition,
                const wxSize &size = wxDefaultSize,
                long style = 0,
                const wxString &name = wxT("socket"));

    void setWindow(GdkNativeWindow XID);

protected:
    virtual void DoSetSize(int x, int y,
                           int width, int height,
                           int sizeFlags = wxSIZE_AUTO);

    virtual wxSize DoGetBestSize() const;
};

#endif // _WX_SOCKET_H_
