/*
 * Copyright (C) 2014-2016 Fanout, Inc.
 *
 * This file is part of Pushpin.
 *
 * Pushpin is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Pushpin is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef WSCONTROLPACKET_H
#define WSCONTROLPACKET_H

#include <QByteArray>
#include <QList>
#include <QVariant>
#include <QUrl>

class WsControlPacket
{
public:
	class Item
	{
	public:
		enum Type
		{
			Here,
			KeepAlive,
			Gone,
			Grip,
			NeedKeepAlive,
			Cancel,
			Send,
			KeepAliveSetup,
			Close,
			Detach
		};

		QByteArray cid;
		Type type;
		QUrl uri;
		QByteArray contentType;
		QByteArray message;
		int code;
		QByteArray route;
		QByteArray channelPrefix;
		int ttl;
		int timeout;

		Item() :
			type((Type)-1),
			code(-1),
			ttl(-1),
			timeout(-1)
		{
		}
	};

	QList<Item> items;

	QVariant toVariant() const;
	bool fromVariant(const QVariant &in);
};

#endif
