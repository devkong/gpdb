/*
 * xlogutils.h
 *
 * PostgreSQL transaction log manager utility routines
 *
 * Portions Copyright (c) 1996-2009, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/access/xlogutils.h,v 1.28 2009/01/01 17:23:56 momjian Exp $
 */
#ifndef XLOG_UTILS_H
#define XLOG_UTILS_H

#include "storage/buf.h"
#include "storage/bufmgr.h"
#include "storage/relfilenode.h"
#include "storage/block.h"
#include "utils/relcache.h"


extern void XLogCheckInvalidPages(void);

extern void XLogDropRelation(RelFileNode rnode, ForkNumber forknum);
extern void XLogDropDatabase(Oid tblspc, Oid dbid);
extern void XLogTruncateRelation(RelFileNode rnode, ForkNumber forkNum,
								 BlockNumber nblocks);

extern Buffer XLogReadBuffer(RelFileNode rnode, BlockNumber blkno, bool init);
extern Buffer XLogReadBufferExtended(RelFileNode rnode, ForkNumber forknum,
									 BlockNumber blkno, ReadBufferMode mode);

extern Relation CreateFakeRelcacheEntry(RelFileNode rnode);
extern void FreeFakeRelcacheEntry(Relation fakerel);

#ifdef USE_SEGWALREP
extern void XLogAOSegmentFile(RelFileNode rnode, uint32 segmentFileNum);
extern void XLogAODropSegmentFile(RelFileNode rnode, uint32 segmentFileNum);
#endif

#endif
