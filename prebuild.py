import os, importlib.util, sys

def Check_Modules_Configure():
    for moduleType in os.listdir("Modules"):
        for module in os.listdir("Modules/" + moduleType):
            runFile = "Modules/" + moduleType + "/" + module + "/configure.py"
            if os.path.exists(runFile):
                spec = importlib.util.spec_from_file_location(runFile, runFile)
                import_module = importlib.util.module_from_spec(spec)
                spec.loader.exec_module(import_module)
                import_module.configure(os.getcwd())
        

if __name__ == "__main__":
    abspath = os.path.abspath(__file__)
    dname = os.path.dirname(abspath)
    os.chdir(dname)

    Check_Modules_Configure()