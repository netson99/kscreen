/*************************************************************************************
 *  Copyright (C) 2012 by Alejandro Fiestas Olivares <afiestas@kde.org>              *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/

#include "generator.h"

#include <kscreen/config.h>

KScreen::Config* Generator::idealConfig()
{
    KScreen::Config* config = KScreen::Config::current();
    KScreen::OutputList outputs = config->outputs();
    KScreen::OutputList connectedOutputs;

    Q_FOREACH(KScreen::Output* output, outputs) {
        if (!output->isConnected()) {
            continue;
        }

        connectedOutputs.insert(output->id(), output);
    }

    if (connectedOutputs.count() == 1) {
        KScreen::Output* output = connectedOutputs.take(connectedOutputs.keys().first());
        output->setCurrentMode(output->preferredMode());

        return config;
    }

    return new KScreen::Config();
}

KScreen::Config* Generator::laptop()
{
    return new KScreen::Config();
}

KScreen::Config* Generator::dockedLaptop()
{
    return new KScreen::Config();
}

KScreen::Config* Generator::desktop()
{
    return new KScreen::Config();
}