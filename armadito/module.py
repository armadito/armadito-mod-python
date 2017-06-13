from enum import Enum

class FileStatus(Enum):
    UNDECIDED = 1          # not yet decided by scan
    CLEAN = 2              # file is clean and does not contain a malware
    UNKNOWN_TYPE = 3       # file type is not handled by any module
    EINVAL = 4             # an invalid value was passed to scan functions
    IERROR = 5             # an internal error occured during file scan
    SUSPICIOUS = 6         # file is suspicious: not malware but not clean also
    WHITE_LISTED = 7       # file is while listed, i.e. guaranteed clean
    MALWARE = 8            # file contains a malware

class Module(object):

    def scan(fd = -1, path = None):
        raise NotImplementedError()
