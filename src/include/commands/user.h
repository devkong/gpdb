/*-------------------------------------------------------------------------
 *
 * user.h
 *	  Commands for manipulating roles (formerly called users).
 *
 *
 * $PostgreSQL: pgsql/src/include/commands/user.h,v 1.30 2006/10/04 00:30:08 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef USER_H
#define USER_H

#include "nodes/parsenodes.h"


/* Hook to check passwords in CreateRole and AlterRole */
#define PASSWORD_TYPE_PLAINTEXT     0
#define PASSWORD_TYPE_MD5           1

typedef void (*check_password_hook_type) (const char *username, const char *password, int password_type, Datum validunitl_time, bool validutil_null);

extern PGDLLIMPORT check_password_hook_type check_password_hook;

extern void CreateRole(CreateRoleStmt *stmt);
extern void AlterRole(AlterRoleStmt *stmt);
extern void AlterRoleSet(AlterRoleSetStmt *stmt);
extern void DropRole(DropRoleStmt *stmt);
extern void GrantRole(GrantRoleStmt *stmt);
extern void RenameRole(const char *oldname, const char *newname);
extern void DropOwnedObjects(DropOwnedStmt *stmt);
extern void ReassignOwnedObjects(ReassignOwnedStmt *stmt);

#endif   /* USER_H */
