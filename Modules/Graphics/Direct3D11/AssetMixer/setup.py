import sys, os

sys.path.insert(0, os.path.dirname(__file__))

import Setup.spirv_cross


def setup():
    if not Setup.spirv_cross.check():
        Setup.spirv_cross.grab()