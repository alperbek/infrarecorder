/*
 * Copyright (C) 2006-2008 Christian Kindahl, christian dot kindahl at gmail dot com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#pragma once

class CActionManager
{
private:
	static DWORD WINAPI BurnCompilationThread(LPVOID lpThreadParameter);
	static DWORD WINAPI CreateImageThread(LPVOID lpThreadParameter);
	static DWORD WINAPI CreateImageThread42(LPVOID lpThreadParameter);
	static DWORD WINAPI CopyDiscOnFlyThread(LPVOID lpThreadParameter);
	static DWORD WINAPI CopyDiscThread(LPVOID lpThreadParameter);
	static DWORD WINAPI EraseThread(LPVOID lpThreadParameter);

public:
	CActionManager();
	~CActionManager();

	INT_PTR BurnCompilation(HWND hWndParent,bool bAppMode);
	INT_PTR CreateImage(HWND hWndParent,bool bAppMode);
	INT_PTR BurnImage(HWND hWndParent,bool bAppMode);
	INT_PTR BurnImageEx(HWND hWndParent,bool bAppMode,const TCHAR *szFilePath);
	INT_PTR CopyDisc(HWND hWndParent,bool bAppMode);
	INT_PTR CopyImage(HWND hWndParent,bool bAppMode);
	INT_PTR ManageTracks(bool bAppMode);
	INT_PTR Erase(HWND hWndParent,bool bAppMode);
	INT_PTR Fixate(HWND hWndParent,bool bAppMode);

	// For testing purposes only.
	//int VerifyCompilation(HWND hWndParent);
};

extern CActionManager g_ActionManager;