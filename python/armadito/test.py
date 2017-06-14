from armadito import module as a6m

class TestModule(a6m.Module):
    def __init__(self):
        print('TestModule.__init__()')

    def scan(self, fd, path, mime_type):
        print('TestModule.scan(', fd, path, mime_type, ')')
        return (a6m.FileStatus.MALWARE.value, "hélo foobâr!")


