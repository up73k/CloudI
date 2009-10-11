// -*- coding: utf-8; Mode: C++; tab-width: 4; c-basic-offset: 4; indent-tabs-mode: nil -*-
// ex: set softtabstop=4 tabstop=4 shiftwidth=4 expandtab fileencoding=utf-8:
//
// BSD LICENSE
// 
// Copyright (c) 2009, Michael Truog
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in
//       the documentation and/or other materials provided with the
//       distribution.
//     * All advertising materials mentioning features or use of this
//       software must display the following acknowledgment:
//         This product includes software developed by Michael Truog
//     * The name of the author may not be used to endorse or promote
//       products derived from this software without specific prior
//       written permission
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
// CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
#ifndef NODE_CONNECTIONS_HPP
#define NODE_CONNECTIONS_HPP

#include <stdint.h>
#include <string>

class WorkerController;

class NodeConnections
{
    public:
        static bool is_initialized() { return m_initialized; }
        static bool initialize(std::string const & nodeNamePrefix,
                               std::string const & domainName,
                               std::string const & cookie,
                               int32_t port, int16_t instance,
                               WorkerController & controller);
        static bool initialize(std::string const & nodeNamePrefix,
                               std::string const & cookie,
                               int32_t port, int16_t instance,
                               WorkerController & controller);
        static bool deinitialize();
        static int worker_loop(unsigned char * buffer,
                               WorkerController & controller);

        static std::string const & nodeName()
        {
            if (m_longName.empty())
                return m_shortName;
            else
                return m_longName;
        }
        static std::string const & parentProcessName()
        {
            return m_parentProcessName;
        }
    private:
        static bool m_initialized;
        static std::string m_hostName;
        static std::string m_parentProcessName;
        static std::string m_nodeNamePrefix;
        static std::string m_shortName;
        static std::string m_longName;
        static std::string m_cookie;
        static int32_t m_port;
        static int16_t m_instance; // incremented on restart to avoid old msgs
};

#endif // NODE_CONNECTIONS_HPP

