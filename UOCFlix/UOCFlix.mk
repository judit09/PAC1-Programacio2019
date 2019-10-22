##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=UOCFlix
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/MARLO/Documents/LOL
ProjectPath            :=C:/Users/MARLO/Documents/LOL/UOCFlix
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
OutputFile             :=../lib/$(ProjectName).lib
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UOCFlix.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=   $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_view.c$(ObjectSuffix) $(IntermediateDirectory)/src_film.c$(ObjectSuffix) $(IntermediateDirectory)/src_series.c$(ObjectSuffix) $(IntermediateDirectory)/src_user.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Users\MARLO\Documents\LOL/.build-release"
	@echo rebuilt > "C:\Users\MARLO\Documents\LOL/.build-release/UOCFlix"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


./Release:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_view.c$(ObjectSuffix): src/view.c $(IntermediateDirectory)/src_view.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/MARLO/Documents/LOL/UOCFlix/src/view.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_view.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_view.c$(DependSuffix): src/view.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_view.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_view.c$(DependSuffix) -MM src/view.c

$(IntermediateDirectory)/src_view.c$(PreprocessSuffix): src/view.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_view.c$(PreprocessSuffix) src/view.c

$(IntermediateDirectory)/src_film.c$(ObjectSuffix): src/film.c $(IntermediateDirectory)/src_film.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/MARLO/Documents/LOL/UOCFlix/src/film.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_film.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_film.c$(DependSuffix): src/film.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_film.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_film.c$(DependSuffix) -MM src/film.c

$(IntermediateDirectory)/src_film.c$(PreprocessSuffix): src/film.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_film.c$(PreprocessSuffix) src/film.c

$(IntermediateDirectory)/src_series.c$(ObjectSuffix): src/series.c $(IntermediateDirectory)/src_series.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/MARLO/Documents/LOL/UOCFlix/src/series.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_series.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_series.c$(DependSuffix): src/series.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_series.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_series.c$(DependSuffix) -MM src/series.c

$(IntermediateDirectory)/src_series.c$(PreprocessSuffix): src/series.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_series.c$(PreprocessSuffix) src/series.c

$(IntermediateDirectory)/src_user.c$(ObjectSuffix): src/user.c $(IntermediateDirectory)/src_user.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/MARLO/Documents/LOL/UOCFlix/src/user.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_user.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_user.c$(DependSuffix): src/user.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_user.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_user.c$(DependSuffix) -MM src/user.c

$(IntermediateDirectory)/src_user.c$(PreprocessSuffix): src/user.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_user.c$(PreprocessSuffix) src/user.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


