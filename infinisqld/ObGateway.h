/*
 * Copyright (c) 2013 Mark Travis <mtravis15432+src@gmail.com>
 * All rights reserved. No warranty, explicit or implicit, provided.
 *
 * This file is part of InfiniSQL(tm).
 
 * InfiniSQL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * InfiniSQL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with InfiniSQL. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file   ObGateway.h
 * @author Mark Travis <mtravis15432+src@gmail.com>
 * @date   Tue Dec 17 13:36:03 2013
 * 
 * @brief  Outbound Gateway actor. Counterpart to IbGateway. Receives messages
 * from actors on current node bound for remote nodes. Sends them over the
 * network to IbGateway.
 */

#ifndef INFINISQLOBGATEWAY_H
#define INFINISQLOBGATEWAY_H

#include "gch.h"
#include "Actor.h"

/** 
 * @brief execute Outbound Gateway actor
 *
 * @param myIdentityArg how to identify this
 */
class ObGateway : public Actor
{
public:
    ObGateway(Topology::actorIdentity *myIdentityArg);
    virtual ~ObGateway();
    void updateRemoteGateways();

    /*
    Topology::actorIdentity myIdentity;
    class Mboxes mboxes;
    class Topology myTopology;
    */

private:
    // remoteGateways[nodeid]=socket for corresponding ibgw's
    std::vector<int> remoteGateways;
    socklen_t optlen;
    int so_sndbuf;
    char *serstrsmall;
    char *cstrsmall;
    bool ismultinode;
};

/** 
 * @brief launch ObGateway actor
 *
 * @param identity how to identify actor instance
 *
 * @return 
 */
void *obGateway(void *identity);

#endif  /* INFINISQLOBGATEWAY_H */
