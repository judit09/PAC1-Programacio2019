##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=UOCFlixMain
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/MARLO/Documents/LOL
ProjectPath            :=C:/Users/MARLO/Documents/LOL/UOCFlixMain
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=MARLO
Date                   :=21/10/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../bin/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UOCFlixMain.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)./test/include $(IncludeSwitch)../UOCFlix/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UOCFlix 
ArLibs                 :=  "UOCFlix" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/test_src_utils.c$(ObjectSuffix) $(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) $(IntermediateDirectory)/test_src_test_suit.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/test_src_utils.c$(ObjectSuffix): test/src/utils.c $(IntermediateDirectory)/test_src_utils.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/MARLO/Documents/LOL/UOCFlixMain/test/src/utils.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_utils.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_utils.c$(DependSuffix): test/src/utils.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_utils.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_utils.c$(DependSuffix) -MM test/src/utils.c

$(IntermediateDirectory)/test_src_utils.c$(PreprocessSuffix): test/src/utils.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_utils.c$(PreprocessSuffix) test/src/utils.c

$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/MARLO/Documents/LOL/UOCFlixMain/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix): test/src/test_pr1.c $(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/MARLO/Documents/LOL/UOCFlixMain/test/src/test_pr1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix): test/src/test_pr1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_pr1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_pr1.c$(DependSuffix) -MM test/src/test_pr1.c

$(IntermediateDirectory)/test_src_test_pr1.c$(PreprocessSuffix): test/src/test_pr1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_pr1.c$(PreprocessSuffix) test/src/test_pr1.c

$(IntermediateDirectory)/test_src_test_suit.c$(ObjectSuffix): test/src/test_suit.c $(IntermediateDirectory)/test_src_test_suit.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/MARLO/Documents/LOL/UOCFlixMain/test/src/test_suit.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_src_test_suit.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_src_test_suit.c$(DependSuffix): test/src/test_suit.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_src_test_suit.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_src_test_suit.c$(DependSuffix) -MM test/src/test_suit.c

$(IntermediateDirectory)/test_src_test_suit.c$(PreprocessSuffix): test/src/test_suit.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_src_test_suit.c$(PreprocessSuffix) test/src/test_suit.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


