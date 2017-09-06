#include "socket.h"

extern "C"
void wxgtk_window_size_request_callback(GtkWidget *widget,
                                        GtkRequisition *requisition,
                                        wxWindow *win);

wxSocket::wxSocket()
{
}

wxSocket::wxSocket(wxWindow *parent,
                   wxWindowID id,
                   const wxPoint &pos,
                   const wxSize &size,
                   long style,
                   const wxString &name)
{
    Create(parent, id, pos, size, style, name);
}

bool wxSocket::Create(wxWindow *parent,
                      wxWindowID id,
                      const wxPoint &pos,
                      const wxSize &size,
                      long style,
                      const wxString &name)
{

    if (!PreCreation(parent, pos, size) ||
        !CreateBase(parent, id, pos, size, style, wxDefaultValidator, name))
    {
        wxFAIL_MSG(wxT("wxSocket creation failed"));
        return FALSE;
    }

    m_widget = gtk_socket_new();
    g_object_ref(m_widget);

    m_parent->DoAddChild(this);

    PostCreation(size);

    return TRUE;
}

void wxSocket::setWindow(GdkNativeWindow XID)
{
    gtk_socket_add_id(GTK_SOCKET(m_widget), XID);
}

void wxSocket::DoSetSize(int x, int y,
                         int width, int height,
                         int sizeFlags)
{
    wxControl::DoSetSize(x, y, width, height, sizeFlags);
}

wxSize wxSocket::DoGetBestSize() const
{
    wxASSERT_MSG(m_widget, wxT("wxSocket::DoGetBestSize called before creation"));

    GtkRequisition req;
    req.width = -1;
    req.height = -1;
    (* GTK_WIDGET_CLASS(GTK_OBJECT_GET_CLASS(m_widget))->size_request)
        (m_widget, &req);

    return wxSize(req.width, req.height);
}
