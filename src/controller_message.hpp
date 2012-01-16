/*
**  Xbox360 USB Gamepad Userspace Driver
**  Copyright (C) 2011 Ingo Ruhnke <grumbel@gmx.de>
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HEADER_XBOXDRV_CONTROLLER_MESSAGE_HPP
#define HEADER_XBOXDRV_CONTROLLER_MESSAGE_HPP

#include <boost/array.hpp>
#include <bitset>
#include <linux/input.h>

#include "xboxmsg.hpp"

class ControllerMessageDescriptor;

class ControllerMessage
{
private:
  boost::array<int, 256> m_abs_state;
  boost::array<int, 256> m_rel_state;
  std::bitset<256>       m_key_state;

public:
  ControllerMessage();
 
  void clear();

  bool get_key(int key) const;
  void set_key(int key, bool v);

  const std::bitset<256>& get_key_state() const { return m_key_state; }

  int  get_abs(int abs) const;
  void set_abs(int abs, int v);

  int get_rel(int rel) const;
  void set_rel(int rel, int v);

  float get_abs_float(int abs) const;
  void  set_abs_float(int abs, float v);

  static int get_abs_min(int abs);
  static int get_abs_max(int abs);

  bool operator==(const ControllerMessage& rhs) const;
  bool operator!=(const ControllerMessage& rhs) const;
};

std::ostream& operator<<(std::ostream& out, const ControllerMessage& msg);

std::ostream& format_playstation3(std::ostream& out, const ControllerMessage& msg);
std::ostream& format_xbox360(std::ostream& out, const ControllerMessage& msg);
std::ostream& format_xbox(std::ostream& out, const ControllerMessage& msg);
std::ostream& format_generic(std::ostream& out, const ControllerMessage& msg, const ControllerMessageDescriptor& desc);

#endif

/* EOF */
