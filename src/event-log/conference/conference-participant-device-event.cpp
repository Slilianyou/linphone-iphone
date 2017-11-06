/*
 * conference-participant-device-event.cpp
 * Copyright (C) 2010-2017 Belledonne Communications SARL
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "conference-participant-device-event.h"
#include "conference-participant-event-p.h"

// =============================================================================

using namespace std;

LINPHONE_BEGIN_NAMESPACE

class ConferenceParticipantDeviceEventPrivate : public ConferenceParticipantEventPrivate {
public:
	Address gruuAddress;
};

// -----------------------------------------------------------------------------

ConferenceParticipantDeviceEvent::ConferenceParticipantDeviceEvent (
	Type type,
	time_t time,
	bool isFullState,
	const Address &conferenceAddress,
	unsigned int notifyId,
	const Address &participantAddress,
	const Address &gruuAddress
) : ConferenceParticipantEvent(
	*new ConferenceParticipantDeviceEventPrivate,
	type,
	time,
	isFullState,
	conferenceAddress,
	notifyId,
	participantAddress
) {
	L_D();
	L_ASSERT(
		type == Type::ConferenceParticipantDeviceAdded ||
		type == Type::ConferenceParticipantDeviceRemoved
	);
	d->gruuAddress = gruuAddress;
}

const Address &ConferenceParticipantDeviceEvent::getGruuAddress () const {
	L_D();
	return d->gruuAddress;
}

LINPHONE_END_NAMESPACE
