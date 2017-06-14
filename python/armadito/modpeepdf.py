from armadito import module as a6m
from PDFCore import PDFParser, vulnsDict

class PeePDFModule(a6m.Module):
    def __init__(self):
        pass

    def scan(self, fd, path, mime_type):
        pdfParser = PDFParser()
        ret, pdf = pdfParser.parse(path, True, True, True)
        statsDict = pdf.getStats()
        stats = ''
        status = a6m.FileStatus.CLEAN
        for statsVersion in statsDict['Versions']:
            actions = statsVersion['Actions']
            events = statsVersion['Events']
            vulns = statsVersion['Vulns']
            elements = statsVersion['Elements']
            if events is not None or actions is not None or vulns is not None or elements is not None:
                status = a6m.FileStatus.SUSPICIOUS
                if events is not None:
                    stats += ' '.join(events)
                if actions is not None:
                    stats += ' ' + ' '.join(actions)
                if vulns is not None:
                    for vuln in vulns:
                        if vulnsDict.has_key(vuln):
                            vulnName = vulnsDict[vuln][0]
                            vulnCVEList = vulnsDict[vuln][1]
                            stats += ' ' + vulnName + ' (' + ' '.join(vulnCVEList) + ')'
                        else:
                            stats += ' ' + vuln
                if elements is not None:
                    for element in elements:
                        if vulnsDict.has_key(element):
                            vulnName = vulnsDict[element][0]
                            vulnCVEList = vulnsDict[element][1]
                            stats += ' ' + vulnName + ' (' + ' '.join(vulnCVEList) +')'
                        else:
                            stats += ' ' + element
            return (status.value, stats)
