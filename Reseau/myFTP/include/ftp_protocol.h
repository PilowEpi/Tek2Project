/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#ifndef FTP_PROTOCOL_H
#define FTP_PROTOCOL_H

#define FTP_110 "Restart marker reply."
#define FTP_120 "Service ready in %d minutes."
#define FTP_125 "Data connection already open; transfer starting."
#define FTP_159 "File status okay; about to open data connection."

#define FTP_200 "Command okay."
#define FTP_202 "Command not implemented, superfluous at this site."
#define FTP_211 "System status, or system help reply."
#define FTP_212 "Directory status."
#define FTP_213 "File status."
#define FTP_214 "Help message." //TO DO
#define FTP_215 "%s system type."
#define FTP_220 "Service ready for new user."
#define FTP_221 "Service closing control connection."
#define FTP_225 "Data connection open; no transfer in progress."
#define FTP_226 "Closing data connection."
#define FTP_227 "Entering Passive Mode (%d,%d,%d,%d,%d,%d)."
#define FTP_230 "User logged in, proceed."
#define FTP_250 "Requested file action okay, completed."
#define FTP_257 "\"%s\" created."

#define FTP_331 "User name okay, need password."
#define FTP_332 "Need account for login."
#define FTP_350 "Requested file action pending further information."

#define FTP_421 "Service not available, closing control connection."
#define FTP_425 "Can't open data connection."
#define FTP_426 "Connection closed; transfer aborted."
#define FTP_450 "Requested file action not taken."
#define FTP_451 "Requested action aborted: local error in processing."
#define FTP_452 "Requested action not taken."

#define FTP_500 "Syntax error, command unrecognized."
#define FTP_501 "Syntax error in parameters or arguments."
#define FTP_502 "Command not implemented."
#define FTP_503 "Bad sequence of commands."
#define FTP_504 "Command not implemented for that parameter."
#define FTP_530 "Not logged in."
#define FTP_532 "Need account for storing files."
#define FTP_550 "Requested action not taken."
#define FTP_551 "Requested action aborted: page type unknown."
#define FTP_552 "Requested file action aborted."
#define FTP_553 "Requested action not taken."

#endif /* ftp_protocol */
