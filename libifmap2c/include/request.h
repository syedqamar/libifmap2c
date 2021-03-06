/*
 * COPYRIGHT AND PERMISSION NOTICE
 * 
 * Copyright (c) 2010-2011, Arne Welzel, <arne.welzel@googlemail.com>
 * 		 
 * All rights reserved.
 * 		 
 * Permission to use, copy, modify, and distribute this software for any purpose
 * with or without fee is hereby granted, provided that the above copyright
 * notice and this permission notice appear in all copies.
 * 	 
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 * 		 
 * Except as contained in this notice, the name of a copyright holder shall not
 * be used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization of the copyright holder.
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include <list>
#include <string>
#include <typeinfo>

#include "result.h"
#include "xmlmarshalable.h"
#include "xmlcommunicationerror.h"


namespace ifmap2c {

/**
 * Just a simple marker interface for requests...
 */
class Request {

protected:
	Request() { };
	virtual ~Request() { };
};

class RequestHandler {

public:
	virtual XmlMarshalable *toXml(Request *const req) const = 0;
	virtual Result *fromXml(XmlMarshalable *const xml) const = 0;
	virtual bool canHandle(Request *const req) const = 0;
	virtual ~RequestHandler() { }
};

class RequestHandlerError : public XmlCommunicationError {

public:
	RequestHandlerError(const std::string& msg) 
		: XmlCommunicationError("RequestHandlerError", msg)
	{ };

};

class RequestHandlerDispatch {

public:
	/**
	 * Get the appropiate RequestHandler for the given Request
	 */
	virtual RequestHandler *dispatch(Request *const req) const = 0;
	virtual ~RequestHandlerDispatch() { }
};

} // namespace

#endif /* REQUEST_H_*/
