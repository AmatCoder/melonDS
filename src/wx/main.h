/*
    Copyright 2016-2017 StapleButter

    This file is part of melonDS.

    melonDS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS. If not, see http://www.gnu.org/licenses/.
*/

#ifndef WX_MAIN_H
#define WX_MAIN_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <SDL2/SDL.h>
#include <wx/evtloop.h>

#ifdef __WXGTK__
#include <SDL2/SDL_syswm.h>
#include "socket.h"
#endif // __WXGTK__

enum
{
    ID_OPENROM = 1,
    ID_EXIT,

    ID_RUN,
    ID_PAUSE,
    ID_RESET,

    ID_EMUCONFIG,
    ID_INPUTCONFIG,
};

class MainFrame : public wxFrame
{
public:
    MainFrame();

    void Start(wxEventLoopBase *loop);

    void EmuRun() { emustatus = 1; emupaused = false; }
    void EmuPause() { emustatus = 2; }
    void EmuExit() { emustatus = 0; }

    bool EmuIsRunning() { return (emustatus == 1) || (emustatus == 2); }
    bool EmuIsPaused() { return (emustatus == 2) && emupaused; }

    SDL_Joystick* joy;
    SDL_JoystickID joyid;

    wxString rompath;

    SDL_Window* sdlwin;
    bool MainLoopIsRunning;

#ifdef __WXGTK__
    wxSocket *socket;
#endif // __WXGTK__

protected:
    void ProcessEvents();

    SDL_Renderer* sdlrend;
    SDL_Texture* sdltex;

    SDL_Rect topsrc, topdst;
    SDL_Rect botsrc, botdst;

    SDL_AudioDeviceID audio;

    bool Touching;
    int txoffset, tyoffset;

    void* texpixels;
    int texstride;

    u32 axismask;

    int emustatus;
    volatile bool emupaused;
    bool limitfps;

private:
    wxDECLARE_EVENT_TABLE();

    void OnClose(wxCloseEvent& event);
    void OnCloseFromMenu(wxCommandEvent& event);
    void OnOpenROM(wxCommandEvent& event);

    void OnRun(wxCommandEvent& event);
    void OnPause(wxCommandEvent& event);
    void OnReset(wxCommandEvent& event);

    void OnEmuConfig(wxCommandEvent& event);
    void OnInputConfig(wxCommandEvent& event);

    void ProcessSDLEvents();
};

class wxApp_melonDS : public wxApp
{
public:
    virtual bool OnInit();
    virtual void OnEventLoopEnter(wxEventLoopBase *loop);
    virtual int OnExit();

    MainFrame *melon;
};

#endif // WX_MAIN_H
