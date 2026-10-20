##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Assignment1
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :="/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1"
ProjectPath            :="/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/Assignment1"
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Assignment1
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=kaito
Date                   :=20/10/2026
CodeLitePath           :=/Users/kaito/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -O0 -Wall -Wextra -std=c++17 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/RowListDS.cpp$(ObjectSuffix) $(IntermediateDirectory)/QueueDS.cpp$(ObjectSuffix) $(IntermediateDirectory)/Core.cpp$(ObjectSuffix) $(IntermediateDirectory)/StackDS.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImageListDS.cpp$(ObjectSuffix) $(IntermediateDirectory)/Pixel.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(ObjectSuffix): peque-image-manager/TinyImageJM.cpp $(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/Assignment1/peque-image-manager/TinyImageJM.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(DependSuffix): peque-image-manager/TinyImageJM.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(DependSuffix) -MM peque-image-manager/TinyImageJM.cpp

$(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(PreprocessSuffix): peque-image-manager/TinyImageJM.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/peque-image-manager_TinyImageJM.cpp$(PreprocessSuffix) peque-image-manager/TinyImageJM.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/Assignment1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/RowListDS.cpp$(ObjectSuffix): RowListDS.cpp $(IntermediateDirectory)/RowListDS.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/Assignment1/RowListDS.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RowListDS.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RowListDS.cpp$(DependSuffix): RowListDS.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RowListDS.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RowListDS.cpp$(DependSuffix) -MM RowListDS.cpp

$(IntermediateDirectory)/RowListDS.cpp$(PreprocessSuffix): RowListDS.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RowListDS.cpp$(PreprocessSuffix) RowListDS.cpp

$(IntermediateDirectory)/QueueDS.cpp$(ObjectSuffix): QueueDS.cpp $(IntermediateDirectory)/QueueDS.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/Assignment1/QueueDS.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/QueueDS.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/QueueDS.cpp$(DependSuffix): QueueDS.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/QueueDS.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/QueueDS.cpp$(DependSuffix) -MM QueueDS.cpp

$(IntermediateDirectory)/QueueDS.cpp$(PreprocessSuffix): QueueDS.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/QueueDS.cpp$(PreprocessSuffix) QueueDS.cpp

$(IntermediateDirectory)/Core.cpp$(ObjectSuffix): Core.cpp $(IntermediateDirectory)/Core.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/Assignment1/Core.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Core.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Core.cpp$(DependSuffix): Core.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Core.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Core.cpp$(DependSuffix) -MM Core.cpp

$(IntermediateDirectory)/Core.cpp$(PreprocessSuffix): Core.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Core.cpp$(PreprocessSuffix) Core.cpp

$(IntermediateDirectory)/StackDS.cpp$(ObjectSuffix): StackDS.cpp $(IntermediateDirectory)/StackDS.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/Assignment1/StackDS.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/StackDS.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/StackDS.cpp$(DependSuffix): StackDS.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/StackDS.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/StackDS.cpp$(DependSuffix) -MM StackDS.cpp

$(IntermediateDirectory)/StackDS.cpp$(PreprocessSuffix): StackDS.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/StackDS.cpp$(PreprocessSuffix) StackDS.cpp

$(IntermediateDirectory)/ImageListDS.cpp$(ObjectSuffix): ImageListDS.cpp $(IntermediateDirectory)/ImageListDS.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/Assignment1/ImageListDS.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImageListDS.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImageListDS.cpp$(DependSuffix): ImageListDS.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ImageListDS.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ImageListDS.cpp$(DependSuffix) -MM ImageListDS.cpp

$(IntermediateDirectory)/ImageListDS.cpp$(PreprocessSuffix): ImageListDS.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImageListDS.cpp$(PreprocessSuffix) ImageListDS.cpp

$(IntermediateDirectory)/Pixel.cpp$(ObjectSuffix): Pixel.cpp $(IntermediateDirectory)/Pixel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/kaito/FH-JOANNEUM/sem_5/data-structures /lab-assignment-BIG1/LAB_EXERSIZE_1/Assignment1/Pixel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pixel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pixel.cpp$(DependSuffix): Pixel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Pixel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Pixel.cpp$(DependSuffix) -MM Pixel.cpp

$(IntermediateDirectory)/Pixel.cpp$(PreprocessSuffix): Pixel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pixel.cpp$(PreprocessSuffix) Pixel.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


