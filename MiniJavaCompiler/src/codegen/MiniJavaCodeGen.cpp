#include "codegen/MiniJavaCodeGen.h"

using namespace std;

MiniJavaCodeGen::MiniJavaCodeGen(CodeStruct* codeStruct, MiniJavaParser::ProgContext* progCtx)
{
	this->codeStruct = codeStruct;
	this->progCtx = progCtx;
}

void MiniJavaCodeGen::generateCode()
{
	cout << "MiniJavaCodeGen::generateCode()" << endl;
	CodeGenVisitor codeGenVisitor(codeStruct->astProgram, codeStruct->programInfo);
	AsmFile* asmFile = codeGenVisitor.visitProgram(progCtx);

	AsmFileWriter asmFileWriter(asmFile);
	asmFileWriter.saveFile("output.asm");
}