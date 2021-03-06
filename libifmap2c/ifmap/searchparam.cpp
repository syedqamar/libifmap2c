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

#include "searchparam.h"

namespace ifmap2c {

SearchParam::SearchParam(const char *const matchLinksFilter,
		const int maxDepth,
		const char *const resultFilter,
		const int maxResultSize,
		const char *const terminalIdent,
		Identifier *const start) :
	_matchLinksFilter(matchLinksFilter),
	_maxDepth(maxDepth),
	_resultFilter(resultFilter),
	_maxResultSize(maxResultSize),
	_terminalIdentifiers(terminalIdent),
	_startIdentifier(start)
{ }

SearchParam::~SearchParam()
{
	if (_startIdentifier)
		delete _startIdentifier;
}

const char *SearchParam::getMatchLinksFilter(void) const
{
	return _matchLinksFilter;
}

int SearchParam::getMaxDepth(void) const
{
	return _maxDepth;
}

const char *SearchParam::getResultFilter(void) const
{
	return _resultFilter;
}

int SearchParam::getMaxResultSize(void) const
{
	return _maxResultSize;
}

const char *SearchParam::getTerminalIdentifiers(void) const
{
	return _terminalIdentifiers;
}

Identifier *SearchParam::getStartIdentifier(void) const
{
	return _startIdentifier;
}

} // namespace
