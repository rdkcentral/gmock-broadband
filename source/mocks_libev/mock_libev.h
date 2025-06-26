/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2024 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef MOCK_LIBEV_H
#define MOCK_LIBEV_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
	#include <ev.h>
}

class LibevInterface {
    public:
        virtual ~LibevInterface() {}
	virtual void ev_break (struct ev_loop *,int) = 0;
	virtual void ev_timer_stop (struct ev_loop *,ev_timer *) = 0;
	virtual void ev_loop_destroy(struct ev_loop *) = 0;
	virtual struct ev_loop * ev_loop_new(unsigned int) = 0;
	virtual void ev_io_start(struct ev_loop *,ev_io *) = 0;
	virtual void ev_timer_start(struct ev_loop *,ev_timer *) = 0;
	virtual int ev_run(struct ev_loop *,int) = 0;
	virtual void ev_io_stop(struct ev_loop *,ev_io *) = 0;
	virtual void ev_stat_start(struct ev_loop *,ev_stat *) = 0;
};

class LibevMock: public LibevInterface {
    public:
        virtual ~LibevMock() {}
        MOCK_METHOD2(ev_break, void(struct ev_loop *,int));
        MOCK_METHOD2(ev_timer_stop, void(struct ev_loop *,ev_timer *));
        MOCK_METHOD1(ev_loop_destroy, void(struct ev_loop *));
        MOCK_METHOD1(ev_loop_new, struct ev_loop * (unsigned int));
        MOCK_METHOD2(ev_io_start, void(struct ev_loop *,ev_io *));
        MOCK_METHOD2(ev_timer_start, void(struct ev_loop *,ev_timer *));
        MOCK_METHOD2(ev_run, int(struct ev_loop *,int));
        MOCK_METHOD2(ev_io_stop, void(struct ev_loop *,ev_io *));
        MOCK_METHOD2(ev_stat_start, void(struct ev_loop *,ev_stat *));

};

#endif //MOCK_LIBEV_H
