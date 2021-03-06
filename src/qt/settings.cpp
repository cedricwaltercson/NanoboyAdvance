/**
  * Copyright (C) 2017 flerovium^-^ (Frederic Meyer)
  *
  * This file is part of NanoboyAdvance.
  *
  * NanoboyAdvance is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * NanoboyAdvance is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with NanoboyAdvance. If not, see <http://www.gnu.org/licenses/>.
  */

#include <QTabWidget>

#include "settings.hpp"

using namespace Util;

SettingsDialog::SettingsDialog(INI& ini, QWidget* parent) : QMainWindow(parent), ini(ini) {
    tab_widget.addTab(&tab_emulation, "Emulation");
    tab_widget.addTab(&tab_video,     "Video");
    tab_widget.addTab(&tab_audio,     "Audio");
    tab_widget.addTab(&tab_keymap,    "Keymap");

    setWindowTitle(tr("Settings"));
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
    setCentralWidget(&tab_widget);
}

SettingsDialog::~SettingsDialog() {
}

/*SettingsDialog::setupEmulationTab() {

}*/
