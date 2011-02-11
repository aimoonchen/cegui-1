/************************************************************************
    filename:   Win32CEGuiRendererSelector.cpp
    created:    24/9/2004
    author:     Paul D Turner
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://www.cegui.org.uk)
    Copyright (C)2004 - 2005 Paul D Turner (paul@cegui.org.uk)
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.
 
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#include "Win32CEGuiRendererSelector.h"
#include <TCHAR.H>


/*************************************************************************
    Constructor
*************************************************************************/
Win32CEGuiRendererSelector::Win32CEGuiRendererSelector() :
        d_template(createDialogTemplate())
{}


/*************************************************************************
    Destructor
*************************************************************************/
Win32CEGuiRendererSelector::~Win32CEGuiRendererSelector()
{
    if (d_template)
    {
        LocalFree(d_template);
    }
}


/*************************************************************************
    Display the dialog and wait for user
*************************************************************************/
bool Win32CEGuiRendererSelector::inkokeDialog()
{
    if (d_template)
    {
        // show dialog & return result
        return (1 == DialogBoxIndirectParam(GetModuleHandle(0), d_template, 0, Win32CEGuiRendererSelector::dialogProcedure, reinterpret_cast<LPARAM>(this)));
    }

    return false;
}


/*************************************************************************
    Create Win32 dialog template
*************************************************************************/
LPDLGTEMPLATE Win32CEGuiRendererSelector::createDialogTemplate()
{
    SIZE_T  templateBufferSize = 1024;

    // allocate memory to hold the template we're going to construct
    LPDLGTEMPLATE dialogTemplate = static_cast<LPDLGTEMPLATE>(LocalAlloc(LPTR, templateBufferSize));

    // if allocation was successful
    if (dialogTemplate)
    {
        LPDLGITEMTEMPLATE item;
        LPBYTE buffer = reinterpret_cast<LPBYTE>(dialogTemplate);

        //
        // build template header
        //
        LPDLGTEMPLATE header    = reinterpret_cast<LPDLGTEMPLATE>(buffer);
        header->style           = DS_MODALFRAME|WS_CAPTION|WS_VISIBLE;
        header->dwExtendedStyle = 0;
        header->cdit            = 6;
        header->x               = (short)0x8000;
        header->y               = (short)0x8000;
        header->cx              = 150;
        header->cy              = 75;

        // advance buffer pointer
        buffer += sizeof(DLGTEMPLATE);

        //
        // Write null menu and class names
        //
        *reinterpret_cast<LPWORD>(buffer) = 0;
        buffer += sizeof(WORD);

        *reinterpret_cast<LPWORD>(buffer) = 0;
        buffer += sizeof(WORD);

        //
        // Write dialog title
        //
        int charCount = copyAnsiToWideChar(buffer, TEXT("CEGui - Renderer Selection"));
        buffer += charCount * sizeof(WORD);

        // align pointer for first item
        buffer = alignPointer(buffer);

        //
        // Buttons area static frame
        //
        item = reinterpret_cast<LPDLGITEMTEMPLATE>(buffer);
        item->style             = BS_GROUPBOX|WS_VISIBLE|WS_CHILD;
        item->dwExtendedStyle   = 0;
        item->x                 = 5;
        item->y                 = 48;
        item->cx                = 140;
        item->cy                = 22;
        item->id                = 0;

        // advance buffer pointer
        buffer += sizeof(DLGITEMTEMPLATE);

        // write class information
        *reinterpret_cast<LPWORD>(buffer) = 0xFFFF;
        buffer += sizeof(WORD);

        *reinterpret_cast<LPWORD>(buffer) = 0x0080;
        buffer += sizeof(WORD);

        // write caption
        charCount = copyAnsiToWideChar(buffer, TEXT(""));
        buffer += charCount * sizeof(WORD);

        // no creation data
        *reinterpret_cast<LPWORD>(buffer) = 0x0000;
        buffer += sizeof(WORD);

        // align pointer for next item
        buffer = alignPointer(buffer);

        //
        // Selection area static frame
        //
        item = reinterpret_cast<LPDLGITEMTEMPLATE>(buffer);
        item->style             = BS_GROUPBOX|WS_VISIBLE|WS_CHILD;
        item->dwExtendedStyle   = 0;
        item->x                 = 5;
        item->y                 = 0;
        item->cx                = 140;
        item->cy                = 50;
        item->id                = 0;

        // advance buffer pointer
        buffer += sizeof(DLGITEMTEMPLATE);

        // write class information
        *reinterpret_cast<LPWORD>(buffer) = 0xFFFF;
        buffer += sizeof(WORD);

        *reinterpret_cast<LPWORD>(buffer) = 0x0080;
        buffer += sizeof(WORD);

        // write caption
        charCount = copyAnsiToWideChar(buffer, TEXT(""));
        buffer += charCount * sizeof(WORD);

        // no creation data
        *reinterpret_cast<LPWORD>(buffer) = 0x0000;
        buffer += sizeof(WORD);

        // align pointer for next item
        buffer = alignPointer(buffer);

        //
        // Okay button
        //
        item = reinterpret_cast<LPDLGITEMTEMPLATE>(buffer);
        item->style             = BS_DEFPUSHBUTTON|WS_VISIBLE|WS_CHILD|WS_TABSTOP;
        item->dwExtendedStyle   = 0;
        item->x                 = 9;
        item->y                 = 55;
        item->cx                = 40;
        item->cy                = 12;
        item->id                = IDOK;

        // advance buffer pointer
        buffer += sizeof(DLGITEMTEMPLATE);

        // write class information
        *reinterpret_cast<LPWORD>(buffer) = 0xFFFF;
        buffer += sizeof(WORD);

        *reinterpret_cast<LPWORD>(buffer) = 0x0080;
        buffer += sizeof(WORD);

        // write caption
        charCount = copyAnsiToWideChar(buffer, TEXT("Go!"));
        buffer += charCount * sizeof(WORD);

        // no creation data
        *reinterpret_cast<LPWORD>(buffer) = 0x0000;
        buffer += sizeof(WORD);

        // align pointer for next item
        buffer = alignPointer(buffer);

        //
        // Cancel button
        //
        item = reinterpret_cast<LPDLGITEMTEMPLATE>(buffer);
        item->style             = BS_PUSHBUTTON|WS_VISIBLE|WS_CHILD|WS_TABSTOP;
        item->dwExtendedStyle   = 0;
        item->x                 = 101;
        item->y                 = 55;
        item->cx                = 40;
        item->cy                = 12;
        item->id                = IDCANCEL;

        // advance buffer pointer
        buffer += sizeof(DLGITEMTEMPLATE);

        // write class information
        *reinterpret_cast<LPWORD>(buffer) = 0xFFFF;
        buffer += sizeof(WORD);

        *reinterpret_cast<LPWORD>(buffer) = 0x0080;
        buffer += sizeof(WORD);

        // write caption
        charCount = copyAnsiToWideChar(buffer, TEXT("Cancel"));
        buffer += charCount * sizeof(WORD);

        // no creation data
        *reinterpret_cast<LPWORD>(buffer) = 0x0000;
        buffer += sizeof(WORD);

        // align pointer for next item
        buffer = alignPointer(buffer);

        //
        // Combo label
        //
        item = reinterpret_cast<LPDLGITEMTEMPLATE>(buffer);
        item->style             = SS_LEFT|WS_VISIBLE|WS_CHILD|WS_GROUP;
        item->dwExtendedStyle   = 0;
        item->x                 = 8;
        item->y                 = 7;
        item->cx                = 130;
        item->cy                = 12;
        item->id                = 0;

        // advance buffer pointer
        buffer += sizeof(DLGITEMTEMPLATE);

        // write class information
        *reinterpret_cast<LPWORD>(buffer) = 0xFFFF;
        buffer += sizeof(WORD);

        *reinterpret_cast<LPWORD>(buffer) = 0x0082;
        buffer += sizeof(WORD);

        // write caption
        charCount = copyAnsiToWideChar(buffer, TEXT("Select Renderer to Use:"));
        buffer += charCount * sizeof(WORD);

        // no creation data
        *reinterpret_cast<LPWORD>(buffer) = 0x0000;
        buffer += sizeof(WORD);

        // align pointer for next item
        buffer = alignPointer(buffer);

        //
        // Combobox
        //
        item = reinterpret_cast<LPDLGITEMTEMPLATE>(buffer);
        item->style             = CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD;
        item->dwExtendedStyle   = 0;
        item->x                 = 8;
        item->y                 = 19;
        item->cx                = 130;
        item->cy                = 100;
        item->id                = 1000;

        // advance buffer pointer
        buffer += sizeof(DLGITEMTEMPLATE);

        // write class information
        *reinterpret_cast<LPWORD>(buffer) = 0xFFFF;
        buffer += sizeof(WORD);

        *reinterpret_cast<LPWORD>(buffer) = 0x0085;
        buffer += sizeof(WORD);

        // write caption
        charCount = copyAnsiToWideChar(buffer, TEXT(""));
        buffer += charCount * sizeof(WORD);

        // no creation data
        *reinterpret_cast<LPWORD>(buffer) = 0x0000;
        buffer += sizeof(WORD);

        // align pointer for next item
        buffer = alignPointer(buffer);

        return dialogTemplate;
    }

    return 0;
}


/*************************************************************************
    Win32 dialog procedure function
*************************************************************************/
INT_PTR CALLBACK Win32CEGuiRendererSelector::dialogProcedure(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_INITDIALOG:
        {
            // get the 'this' ptr we were passed
            Win32CEGuiRendererSelector* obj = reinterpret_cast<Win32CEGuiRendererSelector*>(lParam);

            // set as window long for future use
            SetWindowLong(hDlg, DWL_USER, static_cast<LONG>(lParam));

            //
            // Set-up combo box list
            //
            // get combo control
            HWND combo = GetDlgItem(hDlg, 1000);

            if (combo)
            {
                // basic control setup
                int idx;

                // clear old data
                SendMessage(combo, CB_RESETCONTENT, 0, 0);

                // add new stings according to if item is enabled or not
                if (obj->d_rendererAvailability[OgreGuiRendererType])
                {
                    idx = static_cast<int>(SendMessage(combo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(_TEXT("Ogre Engine Renderer"))));
                    SendMessage(combo, CB_SETITEMDATA, idx, OgreGuiRendererType);
                }

                if (obj->d_rendererAvailability[Direct3D81GuiRendererType])
                {
                    idx = static_cast<int>(SendMessage(combo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(_TEXT("Microsoft Direct3D 8.1 Renderer"))));
                    SendMessage(combo, CB_SETITEMDATA, idx, Direct3D81GuiRendererType);
                }

                if (obj->d_rendererAvailability[Direct3D9GuiRendererType])
                {
                    idx = static_cast<int>(SendMessage(combo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(_TEXT("Microsoft Direct3D 9 Renderer"))));
                    SendMessage(combo, CB_SETITEMDATA, idx, Direct3D9GuiRendererType);
                }

                if (obj->d_rendererAvailability[OpenGLGuiRendererType])
                {
                    idx = static_cast<int>(SendMessage(combo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(_TEXT("OpenGL Renderer"))));
                    SendMessage(combo, CB_SETITEMDATA, idx, OpenGLGuiRendererType);
                }

                if (obj->d_rendererAvailability[IrrlichtGuiRendererType])
                {
                    idx = static_cast<int>(SendMessage(combo, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(_TEXT("Irrlicht Engine Renderer"))));
                    SendMessage(combo, CB_SETITEMDATA, idx, IrrlichtGuiRendererType);
                }

            }

            return FALSE;
        }

    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
        case IDOK:
            EndDialog(hDlg, 1);
            return TRUE;

        case IDCANCEL:
            EndDialog(hDlg, 0);
            return TRUE;

            // Combo-box
        case 1000:
            switch(HIWORD(wParam))
            {
            case CBN_SELENDOK:
                {
                    HWND combo = reinterpret_cast<HWND>(lParam);

                    // get the 'this' ptr for the object we were created by
                    Win32CEGuiRendererSelector* obj = reinterpret_cast<Win32CEGuiRendererSelector*>(GetWindowLong(hDlg, DWL_USER));

                    int idx = static_cast<int>(SendMessage(combo, CB_GETCURSEL, 0, 0));

                    if (idx != CB_ERR)
                    {
                        // set last selected renderer type
                        obj->d_lastSelected = static_cast<CEGuiRendererType>(SendMessage(combo, CB_GETITEMDATA, idx, 0));
                    }

                    return TRUE;
                }
            }
        }

        break;
    }

    return FALSE;
}


/*************************************************************************
    Take an input pointer, return closest pointer that is aligned on a
    DWORD (4 byte) boundary.
*************************************************************************/
LPBYTE Win32CEGuiRendererSelector::alignPointer(LPBYTE buff)
{
    DWORD_PTR ul = reinterpret_cast<DWORD_PTR>(buff);
    ul +=3;
    ul >>=2;
    ul <<=2;
    return reinterpret_cast<LPBYTE>(ul);
}


/*************************************************************************
    Converts the Ansi string in 'pAnsiIn' into wide characters and
    copies the result into the WORD array at 'pWCStr'.
*************************************************************************/
int Win32CEGuiRendererSelector::copyAnsiToWideChar(LPBYTE outBuff, PTSTR ansiString)
{
    LPWSTR pWCStr = reinterpret_cast<LPWSTR>(outBuff);

#   ifdef UNICODE
    return lstrlen(lstrcpy(pWCStr, ansiString)) + 1;
#   else
    int cchAnsi = lstrlen(ansiString);
    return MultiByteToWideChar(GetACP(), MB_PRECOMPOSED, ansiString, cchAnsi, pWCStr, cchAnsi) + 1;
#   endif
}