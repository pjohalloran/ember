/* WARNING: This file was automatically generated */
/* Do not edit. */

#include "flextGL.h"
#include "GLFW/glfw3.h"

#include <stdio.h>


#ifdef __cplusplus
extern "C" {
#endif


void flextLoadOpenGLFunctions( void );

int flextInit( GLFWwindow *window )
{

	int major = glfwGetWindowAttrib( window, GLFW_CONTEXT_VERSION_MAJOR );
	int minor = glfwGetWindowAttrib( window, GLFW_CONTEXT_VERSION_MINOR );
	
	flextLoadOpenGLFunctions();
	
	/* --- Check for minimal version and profile --- */
	
	if ( major * 10 + minor < 41 )
	{
		fprintf( stderr, "Error: OpenGL version 4.1 not supported.\n" );
		fprintf( stderr, "       Your version is %d.%d.\n", major, minor );
		fprintf( stderr, "       Try updating your graphics driver.\n" );
		return GL_FALSE;
	}
	
	
	/* --- Check for extensions --- */
	
	
	return GL_TRUE;
}



void flextLoadOpenGLFunctions( void )
{
	/* --- Function pointer loading --- */
	
	
	/* GL_VERSION_1_2 */
	
	glpfCopyTexSubImage3D = ( PFNGLCOPYTEXSUBIMAGE3D_PROC * )glfwGetProcAddress( "glCopyTexSubImage3D" );
	glpfDrawRangeElements = ( PFNGLDRAWRANGEELEMENTS_PROC * )glfwGetProcAddress( "glDrawRangeElements" );
	glpfTexImage3D = ( PFNGLTEXIMAGE3D_PROC * )glfwGetProcAddress( "glTexImage3D" );
	glpfTexSubImage3D = ( PFNGLTEXSUBIMAGE3D_PROC * )glfwGetProcAddress( "glTexSubImage3D" );
	
	
	/* GL_VERSION_1_3 */
	
	glpfActiveTexture = ( PFNGLACTIVETEXTURE_PROC * )glfwGetProcAddress( "glActiveTexture" );
	glpfCompressedTexImage1D = ( PFNGLCOMPRESSEDTEXIMAGE1D_PROC * )glfwGetProcAddress( "glCompressedTexImage1D" );
	glpfCompressedTexImage2D = ( PFNGLCOMPRESSEDTEXIMAGE2D_PROC * )glfwGetProcAddress( "glCompressedTexImage2D" );
	glpfCompressedTexImage3D = ( PFNGLCOMPRESSEDTEXIMAGE3D_PROC * )glfwGetProcAddress( "glCompressedTexImage3D" );
	glpfCompressedTexSubImage1D = ( PFNGLCOMPRESSEDTEXSUBIMAGE1D_PROC * )glfwGetProcAddress( "glCompressedTexSubImage1D" );
	glpfCompressedTexSubImage2D = ( PFNGLCOMPRESSEDTEXSUBIMAGE2D_PROC * )glfwGetProcAddress( "glCompressedTexSubImage2D" );
	glpfCompressedTexSubImage3D = ( PFNGLCOMPRESSEDTEXSUBIMAGE3D_PROC * )glfwGetProcAddress( "glCompressedTexSubImage3D" );
	glpfGetCompressedTexImage = ( PFNGLGETCOMPRESSEDTEXIMAGE_PROC * )glfwGetProcAddress( "glGetCompressedTexImage" );
	glpfSampleCoverage = ( PFNGLSAMPLECOVERAGE_PROC * )glfwGetProcAddress( "glSampleCoverage" );
	
	
	/* GL_VERSION_1_4 */
	
	glpfBlendColor = ( PFNGLBLENDCOLOR_PROC * )glfwGetProcAddress( "glBlendColor" );
	glpfBlendEquation = ( PFNGLBLENDEQUATION_PROC * )glfwGetProcAddress( "glBlendEquation" );
	glpfBlendFuncSeparate = ( PFNGLBLENDFUNCSEPARATE_PROC * )glfwGetProcAddress( "glBlendFuncSeparate" );
	glpfMultiDrawArrays = ( PFNGLMULTIDRAWARRAYS_PROC * )glfwGetProcAddress( "glMultiDrawArrays" );
	glpfMultiDrawElements = ( PFNGLMULTIDRAWELEMENTS_PROC * )glfwGetProcAddress( "glMultiDrawElements" );
	glpfPointParameterf = ( PFNGLPOINTPARAMETERF_PROC * )glfwGetProcAddress( "glPointParameterf" );
	glpfPointParameterfv = ( PFNGLPOINTPARAMETERFV_PROC * )glfwGetProcAddress( "glPointParameterfv" );
	glpfPointParameteri = ( PFNGLPOINTPARAMETERI_PROC * )glfwGetProcAddress( "glPointParameteri" );
	glpfPointParameteriv = ( PFNGLPOINTPARAMETERIV_PROC * )glfwGetProcAddress( "glPointParameteriv" );
	
	
	/* GL_VERSION_1_5 */
	
	glpfBeginQuery = ( PFNGLBEGINQUERY_PROC * )glfwGetProcAddress( "glBeginQuery" );
	glpfBindBuffer = ( PFNGLBINDBUFFER_PROC * )glfwGetProcAddress( "glBindBuffer" );
	glpfBufferData = ( PFNGLBUFFERDATA_PROC * )glfwGetProcAddress( "glBufferData" );
	glpfBufferSubData = ( PFNGLBUFFERSUBDATA_PROC * )glfwGetProcAddress( "glBufferSubData" );
	glpfDeleteBuffers = ( PFNGLDELETEBUFFERS_PROC * )glfwGetProcAddress( "glDeleteBuffers" );
	glpfDeleteQueries = ( PFNGLDELETEQUERIES_PROC * )glfwGetProcAddress( "glDeleteQueries" );
	glpfEndQuery = ( PFNGLENDQUERY_PROC * )glfwGetProcAddress( "glEndQuery" );
	glpfGenBuffers = ( PFNGLGENBUFFERS_PROC * )glfwGetProcAddress( "glGenBuffers" );
	glpfGenQueries = ( PFNGLGENQUERIES_PROC * )glfwGetProcAddress( "glGenQueries" );
	glpfGetBufferParameteriv = ( PFNGLGETBUFFERPARAMETERIV_PROC * )glfwGetProcAddress( "glGetBufferParameteriv" );
	glpfGetBufferPointerv = ( PFNGLGETBUFFERPOINTERV_PROC * )glfwGetProcAddress( "glGetBufferPointerv" );
	glpfGetBufferSubData = ( PFNGLGETBUFFERSUBDATA_PROC * )glfwGetProcAddress( "glGetBufferSubData" );
	glpfGetQueryObjectiv = ( PFNGLGETQUERYOBJECTIV_PROC * )glfwGetProcAddress( "glGetQueryObjectiv" );
	glpfGetQueryObjectuiv = ( PFNGLGETQUERYOBJECTUIV_PROC * )glfwGetProcAddress( "glGetQueryObjectuiv" );
	glpfGetQueryiv = ( PFNGLGETQUERYIV_PROC * )glfwGetProcAddress( "glGetQueryiv" );
	glpfIsBuffer = ( PFNGLISBUFFER_PROC * )glfwGetProcAddress( "glIsBuffer" );
	glpfIsQuery = ( PFNGLISQUERY_PROC * )glfwGetProcAddress( "glIsQuery" );
	glpfMapBuffer = ( PFNGLMAPBUFFER_PROC * )glfwGetProcAddress( "glMapBuffer" );
	glpfUnmapBuffer = ( PFNGLUNMAPBUFFER_PROC * )glfwGetProcAddress( "glUnmapBuffer" );
	
	
	/* GL_VERSION_2_0 */
	
	glpfAttachShader = ( PFNGLATTACHSHADER_PROC * )glfwGetProcAddress( "glAttachShader" );
	glpfBindAttribLocation = ( PFNGLBINDATTRIBLOCATION_PROC * )glfwGetProcAddress( "glBindAttribLocation" );
	glpfBlendEquationSeparate = ( PFNGLBLENDEQUATIONSEPARATE_PROC * )glfwGetProcAddress( "glBlendEquationSeparate" );
	glpfCompileShader = ( PFNGLCOMPILESHADER_PROC * )glfwGetProcAddress( "glCompileShader" );
	glpfCreateProgram = ( PFNGLCREATEPROGRAM_PROC * )glfwGetProcAddress( "glCreateProgram" );
	glpfCreateShader = ( PFNGLCREATESHADER_PROC * )glfwGetProcAddress( "glCreateShader" );
	glpfDeleteProgram = ( PFNGLDELETEPROGRAM_PROC * )glfwGetProcAddress( "glDeleteProgram" );
	glpfDeleteShader = ( PFNGLDELETESHADER_PROC * )glfwGetProcAddress( "glDeleteShader" );
	glpfDetachShader = ( PFNGLDETACHSHADER_PROC * )glfwGetProcAddress( "glDetachShader" );
	glpfDisableVertexAttribArray = ( PFNGLDISABLEVERTEXATTRIBARRAY_PROC * )glfwGetProcAddress( "glDisableVertexAttribArray" );
	glpfDrawBuffers = ( PFNGLDRAWBUFFERS_PROC * )glfwGetProcAddress( "glDrawBuffers" );
	glpfEnableVertexAttribArray = ( PFNGLENABLEVERTEXATTRIBARRAY_PROC * )glfwGetProcAddress( "glEnableVertexAttribArray" );
	glpfGetActiveAttrib = ( PFNGLGETACTIVEATTRIB_PROC * )glfwGetProcAddress( "glGetActiveAttrib" );
	glpfGetActiveUniform = ( PFNGLGETACTIVEUNIFORM_PROC * )glfwGetProcAddress( "glGetActiveUniform" );
	glpfGetAttachedShaders = ( PFNGLGETATTACHEDSHADERS_PROC * )glfwGetProcAddress( "glGetAttachedShaders" );
	glpfGetAttribLocation = ( PFNGLGETATTRIBLOCATION_PROC * )glfwGetProcAddress( "glGetAttribLocation" );
	glpfGetProgramInfoLog = ( PFNGLGETPROGRAMINFOLOG_PROC * )glfwGetProcAddress( "glGetProgramInfoLog" );
	glpfGetProgramiv = ( PFNGLGETPROGRAMIV_PROC * )glfwGetProcAddress( "glGetProgramiv" );
	glpfGetShaderInfoLog = ( PFNGLGETSHADERINFOLOG_PROC * )glfwGetProcAddress( "glGetShaderInfoLog" );
	glpfGetShaderSource = ( PFNGLGETSHADERSOURCE_PROC * )glfwGetProcAddress( "glGetShaderSource" );
	glpfGetShaderiv = ( PFNGLGETSHADERIV_PROC * )glfwGetProcAddress( "glGetShaderiv" );
	glpfGetUniformLocation = ( PFNGLGETUNIFORMLOCATION_PROC * )glfwGetProcAddress( "glGetUniformLocation" );
	glpfGetUniformfv = ( PFNGLGETUNIFORMFV_PROC * )glfwGetProcAddress( "glGetUniformfv" );
	glpfGetUniformiv = ( PFNGLGETUNIFORMIV_PROC * )glfwGetProcAddress( "glGetUniformiv" );
	glpfGetVertexAttribPointerv = ( PFNGLGETVERTEXATTRIBPOINTERV_PROC * )glfwGetProcAddress( "glGetVertexAttribPointerv" );
	glpfGetVertexAttribdv = ( PFNGLGETVERTEXATTRIBDV_PROC * )glfwGetProcAddress( "glGetVertexAttribdv" );
	glpfGetVertexAttribfv = ( PFNGLGETVERTEXATTRIBFV_PROC * )glfwGetProcAddress( "glGetVertexAttribfv" );
	glpfGetVertexAttribiv = ( PFNGLGETVERTEXATTRIBIV_PROC * )glfwGetProcAddress( "glGetVertexAttribiv" );
	glpfIsProgram = ( PFNGLISPROGRAM_PROC * )glfwGetProcAddress( "glIsProgram" );
	glpfIsShader = ( PFNGLISSHADER_PROC * )glfwGetProcAddress( "glIsShader" );
	glpfLinkProgram = ( PFNGLLINKPROGRAM_PROC * )glfwGetProcAddress( "glLinkProgram" );
	glpfShaderSource = ( PFNGLSHADERSOURCE_PROC * )glfwGetProcAddress( "glShaderSource" );
	glpfStencilFuncSeparate = ( PFNGLSTENCILFUNCSEPARATE_PROC * )glfwGetProcAddress( "glStencilFuncSeparate" );
	glpfStencilMaskSeparate = ( PFNGLSTENCILMASKSEPARATE_PROC * )glfwGetProcAddress( "glStencilMaskSeparate" );
	glpfStencilOpSeparate = ( PFNGLSTENCILOPSEPARATE_PROC * )glfwGetProcAddress( "glStencilOpSeparate" );
	glpfUniform1f = ( PFNGLUNIFORM1F_PROC * )glfwGetProcAddress( "glUniform1f" );
	glpfUniform1fv = ( PFNGLUNIFORM1FV_PROC * )glfwGetProcAddress( "glUniform1fv" );
	glpfUniform1i = ( PFNGLUNIFORM1I_PROC * )glfwGetProcAddress( "glUniform1i" );
	glpfUniform1iv = ( PFNGLUNIFORM1IV_PROC * )glfwGetProcAddress( "glUniform1iv" );
	glpfUniform2f = ( PFNGLUNIFORM2F_PROC * )glfwGetProcAddress( "glUniform2f" );
	glpfUniform2fv = ( PFNGLUNIFORM2FV_PROC * )glfwGetProcAddress( "glUniform2fv" );
	glpfUniform2i = ( PFNGLUNIFORM2I_PROC * )glfwGetProcAddress( "glUniform2i" );
	glpfUniform2iv = ( PFNGLUNIFORM2IV_PROC * )glfwGetProcAddress( "glUniform2iv" );
	glpfUniform3f = ( PFNGLUNIFORM3F_PROC * )glfwGetProcAddress( "glUniform3f" );
	glpfUniform3fv = ( PFNGLUNIFORM3FV_PROC * )glfwGetProcAddress( "glUniform3fv" );
	glpfUniform3i = ( PFNGLUNIFORM3I_PROC * )glfwGetProcAddress( "glUniform3i" );
	glpfUniform3iv = ( PFNGLUNIFORM3IV_PROC * )glfwGetProcAddress( "glUniform3iv" );
	glpfUniform4f = ( PFNGLUNIFORM4F_PROC * )glfwGetProcAddress( "glUniform4f" );
	glpfUniform4fv = ( PFNGLUNIFORM4FV_PROC * )glfwGetProcAddress( "glUniform4fv" );
	glpfUniform4i = ( PFNGLUNIFORM4I_PROC * )glfwGetProcAddress( "glUniform4i" );
	glpfUniform4iv = ( PFNGLUNIFORM4IV_PROC * )glfwGetProcAddress( "glUniform4iv" );
	glpfUniformMatrix2fv = ( PFNGLUNIFORMMATRIX2FV_PROC * )glfwGetProcAddress( "glUniformMatrix2fv" );
	glpfUniformMatrix3fv = ( PFNGLUNIFORMMATRIX3FV_PROC * )glfwGetProcAddress( "glUniformMatrix3fv" );
	glpfUniformMatrix4fv = ( PFNGLUNIFORMMATRIX4FV_PROC * )glfwGetProcAddress( "glUniformMatrix4fv" );
	glpfUseProgram = ( PFNGLUSEPROGRAM_PROC * )glfwGetProcAddress( "glUseProgram" );
	glpfValidateProgram = ( PFNGLVALIDATEPROGRAM_PROC * )glfwGetProcAddress( "glValidateProgram" );
	glpfVertexAttrib1d = ( PFNGLVERTEXATTRIB1D_PROC * )glfwGetProcAddress( "glVertexAttrib1d" );
	glpfVertexAttrib1dv = ( PFNGLVERTEXATTRIB1DV_PROC * )glfwGetProcAddress( "glVertexAttrib1dv" );
	glpfVertexAttrib1f = ( PFNGLVERTEXATTRIB1F_PROC * )glfwGetProcAddress( "glVertexAttrib1f" );
	glpfVertexAttrib1fv = ( PFNGLVERTEXATTRIB1FV_PROC * )glfwGetProcAddress( "glVertexAttrib1fv" );
	glpfVertexAttrib1s = ( PFNGLVERTEXATTRIB1S_PROC * )glfwGetProcAddress( "glVertexAttrib1s" );
	glpfVertexAttrib1sv = ( PFNGLVERTEXATTRIB1SV_PROC * )glfwGetProcAddress( "glVertexAttrib1sv" );
	glpfVertexAttrib2d = ( PFNGLVERTEXATTRIB2D_PROC * )glfwGetProcAddress( "glVertexAttrib2d" );
	glpfVertexAttrib2dv = ( PFNGLVERTEXATTRIB2DV_PROC * )glfwGetProcAddress( "glVertexAttrib2dv" );
	glpfVertexAttrib2f = ( PFNGLVERTEXATTRIB2F_PROC * )glfwGetProcAddress( "glVertexAttrib2f" );
	glpfVertexAttrib2fv = ( PFNGLVERTEXATTRIB2FV_PROC * )glfwGetProcAddress( "glVertexAttrib2fv" );
	glpfVertexAttrib2s = ( PFNGLVERTEXATTRIB2S_PROC * )glfwGetProcAddress( "glVertexAttrib2s" );
	glpfVertexAttrib2sv = ( PFNGLVERTEXATTRIB2SV_PROC * )glfwGetProcAddress( "glVertexAttrib2sv" );
	glpfVertexAttrib3d = ( PFNGLVERTEXATTRIB3D_PROC * )glfwGetProcAddress( "glVertexAttrib3d" );
	glpfVertexAttrib3dv = ( PFNGLVERTEXATTRIB3DV_PROC * )glfwGetProcAddress( "glVertexAttrib3dv" );
	glpfVertexAttrib3f = ( PFNGLVERTEXATTRIB3F_PROC * )glfwGetProcAddress( "glVertexAttrib3f" );
	glpfVertexAttrib3fv = ( PFNGLVERTEXATTRIB3FV_PROC * )glfwGetProcAddress( "glVertexAttrib3fv" );
	glpfVertexAttrib3s = ( PFNGLVERTEXATTRIB3S_PROC * )glfwGetProcAddress( "glVertexAttrib3s" );
	glpfVertexAttrib3sv = ( PFNGLVERTEXATTRIB3SV_PROC * )glfwGetProcAddress( "glVertexAttrib3sv" );
	glpfVertexAttrib4Nbv = ( PFNGLVERTEXATTRIB4NBV_PROC * )glfwGetProcAddress( "glVertexAttrib4Nbv" );
	glpfVertexAttrib4Niv = ( PFNGLVERTEXATTRIB4NIV_PROC * )glfwGetProcAddress( "glVertexAttrib4Niv" );
	glpfVertexAttrib4Nsv = ( PFNGLVERTEXATTRIB4NSV_PROC * )glfwGetProcAddress( "glVertexAttrib4Nsv" );
	glpfVertexAttrib4Nub = ( PFNGLVERTEXATTRIB4NUB_PROC * )glfwGetProcAddress( "glVertexAttrib4Nub" );
	glpfVertexAttrib4Nubv = ( PFNGLVERTEXATTRIB4NUBV_PROC * )glfwGetProcAddress( "glVertexAttrib4Nubv" );
	glpfVertexAttrib4Nuiv = ( PFNGLVERTEXATTRIB4NUIV_PROC * )glfwGetProcAddress( "glVertexAttrib4Nuiv" );
	glpfVertexAttrib4Nusv = ( PFNGLVERTEXATTRIB4NUSV_PROC * )glfwGetProcAddress( "glVertexAttrib4Nusv" );
	glpfVertexAttrib4bv = ( PFNGLVERTEXATTRIB4BV_PROC * )glfwGetProcAddress( "glVertexAttrib4bv" );
	glpfVertexAttrib4d = ( PFNGLVERTEXATTRIB4D_PROC * )glfwGetProcAddress( "glVertexAttrib4d" );
	glpfVertexAttrib4dv = ( PFNGLVERTEXATTRIB4DV_PROC * )glfwGetProcAddress( "glVertexAttrib4dv" );
	glpfVertexAttrib4f = ( PFNGLVERTEXATTRIB4F_PROC * )glfwGetProcAddress( "glVertexAttrib4f" );
	glpfVertexAttrib4fv = ( PFNGLVERTEXATTRIB4FV_PROC * )glfwGetProcAddress( "glVertexAttrib4fv" );
	glpfVertexAttrib4iv = ( PFNGLVERTEXATTRIB4IV_PROC * )glfwGetProcAddress( "glVertexAttrib4iv" );
	glpfVertexAttrib4s = ( PFNGLVERTEXATTRIB4S_PROC * )glfwGetProcAddress( "glVertexAttrib4s" );
	glpfVertexAttrib4sv = ( PFNGLVERTEXATTRIB4SV_PROC * )glfwGetProcAddress( "glVertexAttrib4sv" );
	glpfVertexAttrib4ubv = ( PFNGLVERTEXATTRIB4UBV_PROC * )glfwGetProcAddress( "glVertexAttrib4ubv" );
	glpfVertexAttrib4uiv = ( PFNGLVERTEXATTRIB4UIV_PROC * )glfwGetProcAddress( "glVertexAttrib4uiv" );
	glpfVertexAttrib4usv = ( PFNGLVERTEXATTRIB4USV_PROC * )glfwGetProcAddress( "glVertexAttrib4usv" );
	glpfVertexAttribPointer = ( PFNGLVERTEXATTRIBPOINTER_PROC * )glfwGetProcAddress( "glVertexAttribPointer" );
	
	
	/* GL_VERSION_2_1 */
	
	glpfUniformMatrix2x3fv = ( PFNGLUNIFORMMATRIX2X3FV_PROC * )glfwGetProcAddress( "glUniformMatrix2x3fv" );
	glpfUniformMatrix2x4fv = ( PFNGLUNIFORMMATRIX2X4FV_PROC * )glfwGetProcAddress( "glUniformMatrix2x4fv" );
	glpfUniformMatrix3x2fv = ( PFNGLUNIFORMMATRIX3X2FV_PROC * )glfwGetProcAddress( "glUniformMatrix3x2fv" );
	glpfUniformMatrix3x4fv = ( PFNGLUNIFORMMATRIX3X4FV_PROC * )glfwGetProcAddress( "glUniformMatrix3x4fv" );
	glpfUniformMatrix4x2fv = ( PFNGLUNIFORMMATRIX4X2FV_PROC * )glfwGetProcAddress( "glUniformMatrix4x2fv" );
	glpfUniformMatrix4x3fv = ( PFNGLUNIFORMMATRIX4X3FV_PROC * )glfwGetProcAddress( "glUniformMatrix4x3fv" );
	
	
	/* GL_VERSION_3_0 */
	
	glpfBeginConditionalRender = ( PFNGLBEGINCONDITIONALRENDER_PROC * )glfwGetProcAddress( "glBeginConditionalRender" );
	glpfBeginTransformFeedback = ( PFNGLBEGINTRANSFORMFEEDBACK_PROC * )glfwGetProcAddress( "glBeginTransformFeedback" );
	glpfBindBufferBase = ( PFNGLBINDBUFFERBASE_PROC * )glfwGetProcAddress( "glBindBufferBase" );
	glpfBindBufferRange = ( PFNGLBINDBUFFERRANGE_PROC * )glfwGetProcAddress( "glBindBufferRange" );
	glpfBindFragDataLocation = ( PFNGLBINDFRAGDATALOCATION_PROC * )glfwGetProcAddress( "glBindFragDataLocation" );
	glpfBindFramebuffer = ( PFNGLBINDFRAMEBUFFER_PROC * )glfwGetProcAddress( "glBindFramebuffer" );
	glpfBindRenderbuffer = ( PFNGLBINDRENDERBUFFER_PROC * )glfwGetProcAddress( "glBindRenderbuffer" );
	glpfBindVertexArray = ( PFNGLBINDVERTEXARRAY_PROC * )glfwGetProcAddress( "glBindVertexArray" );
	glpfBlitFramebuffer = ( PFNGLBLITFRAMEBUFFER_PROC * )glfwGetProcAddress( "glBlitFramebuffer" );
	glpfCheckFramebufferStatus = ( PFNGLCHECKFRAMEBUFFERSTATUS_PROC * )glfwGetProcAddress( "glCheckFramebufferStatus" );
	glpfClampColor = ( PFNGLCLAMPCOLOR_PROC * )glfwGetProcAddress( "glClampColor" );
	glpfClearBufferfi = ( PFNGLCLEARBUFFERFI_PROC * )glfwGetProcAddress( "glClearBufferfi" );
	glpfClearBufferfv = ( PFNGLCLEARBUFFERFV_PROC * )glfwGetProcAddress( "glClearBufferfv" );
	glpfClearBufferiv = ( PFNGLCLEARBUFFERIV_PROC * )glfwGetProcAddress( "glClearBufferiv" );
	glpfClearBufferuiv = ( PFNGLCLEARBUFFERUIV_PROC * )glfwGetProcAddress( "glClearBufferuiv" );
	glpfColorMaski = ( PFNGLCOLORMASKI_PROC * )glfwGetProcAddress( "glColorMaski" );
	glpfDeleteFramebuffers = ( PFNGLDELETEFRAMEBUFFERS_PROC * )glfwGetProcAddress( "glDeleteFramebuffers" );
	glpfDeleteRenderbuffers = ( PFNGLDELETERENDERBUFFERS_PROC * )glfwGetProcAddress( "glDeleteRenderbuffers" );
	glpfDeleteVertexArrays = ( PFNGLDELETEVERTEXARRAYS_PROC * )glfwGetProcAddress( "glDeleteVertexArrays" );
	glpfDisablei = ( PFNGLDISABLEI_PROC * )glfwGetProcAddress( "glDisablei" );
	glpfEnablei = ( PFNGLENABLEI_PROC * )glfwGetProcAddress( "glEnablei" );
	glpfEndConditionalRender = ( PFNGLENDCONDITIONALRENDER_PROC * )glfwGetProcAddress( "glEndConditionalRender" );
	glpfEndTransformFeedback = ( PFNGLENDTRANSFORMFEEDBACK_PROC * )glfwGetProcAddress( "glEndTransformFeedback" );
	glpfFlushMappedBufferRange = ( PFNGLFLUSHMAPPEDBUFFERRANGE_PROC * )glfwGetProcAddress( "glFlushMappedBufferRange" );
	glpfFramebufferRenderbuffer = ( PFNGLFRAMEBUFFERRENDERBUFFER_PROC * )glfwGetProcAddress( "glFramebufferRenderbuffer" );
	glpfFramebufferTexture1D = ( PFNGLFRAMEBUFFERTEXTURE1D_PROC * )glfwGetProcAddress( "glFramebufferTexture1D" );
	glpfFramebufferTexture2D = ( PFNGLFRAMEBUFFERTEXTURE2D_PROC * )glfwGetProcAddress( "glFramebufferTexture2D" );
	glpfFramebufferTexture3D = ( PFNGLFRAMEBUFFERTEXTURE3D_PROC * )glfwGetProcAddress( "glFramebufferTexture3D" );
	glpfFramebufferTextureLayer = ( PFNGLFRAMEBUFFERTEXTURELAYER_PROC * )glfwGetProcAddress( "glFramebufferTextureLayer" );
	glpfGenFramebuffers = ( PFNGLGENFRAMEBUFFERS_PROC * )glfwGetProcAddress( "glGenFramebuffers" );
	glpfGenRenderbuffers = ( PFNGLGENRENDERBUFFERS_PROC * )glfwGetProcAddress( "glGenRenderbuffers" );
	glpfGenVertexArrays = ( PFNGLGENVERTEXARRAYS_PROC * )glfwGetProcAddress( "glGenVertexArrays" );
	glpfGenerateMipmap = ( PFNGLGENERATEMIPMAP_PROC * )glfwGetProcAddress( "glGenerateMipmap" );
	glpfGetBooleani_v = ( PFNGLGETBOOLEANI_V_PROC * )glfwGetProcAddress( "glGetBooleani_v" );
	glpfGetFragDataLocation = ( PFNGLGETFRAGDATALOCATION_PROC * )glfwGetProcAddress( "glGetFragDataLocation" );
	glpfGetFramebufferAttachmentParameteriv = ( PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIV_PROC * )glfwGetProcAddress( "glGetFramebufferAttachmentParameteriv" );
	glpfGetIntegeri_v = ( PFNGLGETINTEGERI_V_PROC * )glfwGetProcAddress( "glGetIntegeri_v" );
	glpfGetRenderbufferParameteriv = ( PFNGLGETRENDERBUFFERPARAMETERIV_PROC * )glfwGetProcAddress( "glGetRenderbufferParameteriv" );
	glpfGetStringi = ( PFNGLGETSTRINGI_PROC * )glfwGetProcAddress( "glGetStringi" );
	glpfGetTexParameterIiv = ( PFNGLGETTEXPARAMETERIIV_PROC * )glfwGetProcAddress( "glGetTexParameterIiv" );
	glpfGetTexParameterIuiv = ( PFNGLGETTEXPARAMETERIUIV_PROC * )glfwGetProcAddress( "glGetTexParameterIuiv" );
	glpfGetTransformFeedbackVarying = ( PFNGLGETTRANSFORMFEEDBACKVARYING_PROC * )glfwGetProcAddress( "glGetTransformFeedbackVarying" );
	glpfGetUniformuiv = ( PFNGLGETUNIFORMUIV_PROC * )glfwGetProcAddress( "glGetUniformuiv" );
	glpfGetVertexAttribIiv = ( PFNGLGETVERTEXATTRIBIIV_PROC * )glfwGetProcAddress( "glGetVertexAttribIiv" );
	glpfGetVertexAttribIuiv = ( PFNGLGETVERTEXATTRIBIUIV_PROC * )glfwGetProcAddress( "glGetVertexAttribIuiv" );
	glpfIsEnabledi = ( PFNGLISENABLEDI_PROC * )glfwGetProcAddress( "glIsEnabledi" );
	glpfIsFramebuffer = ( PFNGLISFRAMEBUFFER_PROC * )glfwGetProcAddress( "glIsFramebuffer" );
	glpfIsRenderbuffer = ( PFNGLISRENDERBUFFER_PROC * )glfwGetProcAddress( "glIsRenderbuffer" );
	glpfIsVertexArray = ( PFNGLISVERTEXARRAY_PROC * )glfwGetProcAddress( "glIsVertexArray" );
	glpfMapBufferRange = ( PFNGLMAPBUFFERRANGE_PROC * )glfwGetProcAddress( "glMapBufferRange" );
	glpfRenderbufferStorage = ( PFNGLRENDERBUFFERSTORAGE_PROC * )glfwGetProcAddress( "glRenderbufferStorage" );
	glpfRenderbufferStorageMultisample = ( PFNGLRENDERBUFFERSTORAGEMULTISAMPLE_PROC * )glfwGetProcAddress( "glRenderbufferStorageMultisample" );
	glpfTexParameterIiv = ( PFNGLTEXPARAMETERIIV_PROC * )glfwGetProcAddress( "glTexParameterIiv" );
	glpfTexParameterIuiv = ( PFNGLTEXPARAMETERIUIV_PROC * )glfwGetProcAddress( "glTexParameterIuiv" );
	glpfTransformFeedbackVaryings = ( PFNGLTRANSFORMFEEDBACKVARYINGS_PROC * )glfwGetProcAddress( "glTransformFeedbackVaryings" );
	glpfUniform1ui = ( PFNGLUNIFORM1UI_PROC * )glfwGetProcAddress( "glUniform1ui" );
	glpfUniform1uiv = ( PFNGLUNIFORM1UIV_PROC * )glfwGetProcAddress( "glUniform1uiv" );
	glpfUniform2ui = ( PFNGLUNIFORM2UI_PROC * )glfwGetProcAddress( "glUniform2ui" );
	glpfUniform2uiv = ( PFNGLUNIFORM2UIV_PROC * )glfwGetProcAddress( "glUniform2uiv" );
	glpfUniform3ui = ( PFNGLUNIFORM3UI_PROC * )glfwGetProcAddress( "glUniform3ui" );
	glpfUniform3uiv = ( PFNGLUNIFORM3UIV_PROC * )glfwGetProcAddress( "glUniform3uiv" );
	glpfUniform4ui = ( PFNGLUNIFORM4UI_PROC * )glfwGetProcAddress( "glUniform4ui" );
	glpfUniform4uiv = ( PFNGLUNIFORM4UIV_PROC * )glfwGetProcAddress( "glUniform4uiv" );
	glpfVertexAttribI1i = ( PFNGLVERTEXATTRIBI1I_PROC * )glfwGetProcAddress( "glVertexAttribI1i" );
	glpfVertexAttribI1iv = ( PFNGLVERTEXATTRIBI1IV_PROC * )glfwGetProcAddress( "glVertexAttribI1iv" );
	glpfVertexAttribI1ui = ( PFNGLVERTEXATTRIBI1UI_PROC * )glfwGetProcAddress( "glVertexAttribI1ui" );
	glpfVertexAttribI1uiv = ( PFNGLVERTEXATTRIBI1UIV_PROC * )glfwGetProcAddress( "glVertexAttribI1uiv" );
	glpfVertexAttribI2i = ( PFNGLVERTEXATTRIBI2I_PROC * )glfwGetProcAddress( "glVertexAttribI2i" );
	glpfVertexAttribI2iv = ( PFNGLVERTEXATTRIBI2IV_PROC * )glfwGetProcAddress( "glVertexAttribI2iv" );
	glpfVertexAttribI2ui = ( PFNGLVERTEXATTRIBI2UI_PROC * )glfwGetProcAddress( "glVertexAttribI2ui" );
	glpfVertexAttribI2uiv = ( PFNGLVERTEXATTRIBI2UIV_PROC * )glfwGetProcAddress( "glVertexAttribI2uiv" );
	glpfVertexAttribI3i = ( PFNGLVERTEXATTRIBI3I_PROC * )glfwGetProcAddress( "glVertexAttribI3i" );
	glpfVertexAttribI3iv = ( PFNGLVERTEXATTRIBI3IV_PROC * )glfwGetProcAddress( "glVertexAttribI3iv" );
	glpfVertexAttribI3ui = ( PFNGLVERTEXATTRIBI3UI_PROC * )glfwGetProcAddress( "glVertexAttribI3ui" );
	glpfVertexAttribI3uiv = ( PFNGLVERTEXATTRIBI3UIV_PROC * )glfwGetProcAddress( "glVertexAttribI3uiv" );
	glpfVertexAttribI4bv = ( PFNGLVERTEXATTRIBI4BV_PROC * )glfwGetProcAddress( "glVertexAttribI4bv" );
	glpfVertexAttribI4i = ( PFNGLVERTEXATTRIBI4I_PROC * )glfwGetProcAddress( "glVertexAttribI4i" );
	glpfVertexAttribI4iv = ( PFNGLVERTEXATTRIBI4IV_PROC * )glfwGetProcAddress( "glVertexAttribI4iv" );
	glpfVertexAttribI4sv = ( PFNGLVERTEXATTRIBI4SV_PROC * )glfwGetProcAddress( "glVertexAttribI4sv" );
	glpfVertexAttribI4ubv = ( PFNGLVERTEXATTRIBI4UBV_PROC * )glfwGetProcAddress( "glVertexAttribI4ubv" );
	glpfVertexAttribI4ui = ( PFNGLVERTEXATTRIBI4UI_PROC * )glfwGetProcAddress( "glVertexAttribI4ui" );
	glpfVertexAttribI4uiv = ( PFNGLVERTEXATTRIBI4UIV_PROC * )glfwGetProcAddress( "glVertexAttribI4uiv" );
	glpfVertexAttribI4usv = ( PFNGLVERTEXATTRIBI4USV_PROC * )glfwGetProcAddress( "glVertexAttribI4usv" );
	glpfVertexAttribIPointer = ( PFNGLVERTEXATTRIBIPOINTER_PROC * )glfwGetProcAddress( "glVertexAttribIPointer" );
	
	
	/* GL_VERSION_3_1 */
	
	glpfCopyBufferSubData = ( PFNGLCOPYBUFFERSUBDATA_PROC * )glfwGetProcAddress( "glCopyBufferSubData" );
	glpfDrawArraysInstanced = ( PFNGLDRAWARRAYSINSTANCED_PROC * )glfwGetProcAddress( "glDrawArraysInstanced" );
	glpfDrawElementsInstanced = ( PFNGLDRAWELEMENTSINSTANCED_PROC * )glfwGetProcAddress( "glDrawElementsInstanced" );
	glpfGetActiveUniformBlockName = ( PFNGLGETACTIVEUNIFORMBLOCKNAME_PROC * )glfwGetProcAddress( "glGetActiveUniformBlockName" );
	glpfGetActiveUniformBlockiv = ( PFNGLGETACTIVEUNIFORMBLOCKIV_PROC * )glfwGetProcAddress( "glGetActiveUniformBlockiv" );
	glpfGetActiveUniformName = ( PFNGLGETACTIVEUNIFORMNAME_PROC * )glfwGetProcAddress( "glGetActiveUniformName" );
	glpfGetActiveUniformsiv = ( PFNGLGETACTIVEUNIFORMSIV_PROC * )glfwGetProcAddress( "glGetActiveUniformsiv" );
	glpfGetUniformBlockIndex = ( PFNGLGETUNIFORMBLOCKINDEX_PROC * )glfwGetProcAddress( "glGetUniformBlockIndex" );
	glpfGetUniformIndices = ( PFNGLGETUNIFORMINDICES_PROC * )glfwGetProcAddress( "glGetUniformIndices" );
	glpfPrimitiveRestartIndex = ( PFNGLPRIMITIVERESTARTINDEX_PROC * )glfwGetProcAddress( "glPrimitiveRestartIndex" );
	glpfTexBuffer = ( PFNGLTEXBUFFER_PROC * )glfwGetProcAddress( "glTexBuffer" );
	glpfUniformBlockBinding = ( PFNGLUNIFORMBLOCKBINDING_PROC * )glfwGetProcAddress( "glUniformBlockBinding" );
	
	
	/* GL_VERSION_3_2 */
	
	glpfClientWaitSync = ( PFNGLCLIENTWAITSYNC_PROC * )glfwGetProcAddress( "glClientWaitSync" );
	glpfDeleteSync = ( PFNGLDELETESYNC_PROC * )glfwGetProcAddress( "glDeleteSync" );
	glpfDrawElementsBaseVertex = ( PFNGLDRAWELEMENTSBASEVERTEX_PROC * )glfwGetProcAddress( "glDrawElementsBaseVertex" );
	glpfDrawElementsInstancedBaseVertex = ( PFNGLDRAWELEMENTSINSTANCEDBASEVERTEX_PROC * )glfwGetProcAddress( "glDrawElementsInstancedBaseVertex" );
	glpfDrawRangeElementsBaseVertex = ( PFNGLDRAWRANGEELEMENTSBASEVERTEX_PROC * )glfwGetProcAddress( "glDrawRangeElementsBaseVertex" );
	glpfFenceSync = ( PFNGLFENCESYNC_PROC * )glfwGetProcAddress( "glFenceSync" );
	glpfFramebufferTexture = ( PFNGLFRAMEBUFFERTEXTURE_PROC * )glfwGetProcAddress( "glFramebufferTexture" );
	glpfGetBufferParameteri64v = ( PFNGLGETBUFFERPARAMETERI64V_PROC * )glfwGetProcAddress( "glGetBufferParameteri64v" );
	glpfGetInteger64i_v = ( PFNGLGETINTEGER64I_V_PROC * )glfwGetProcAddress( "glGetInteger64i_v" );
	glpfGetInteger64v = ( PFNGLGETINTEGER64V_PROC * )glfwGetProcAddress( "glGetInteger64v" );
	glpfGetMultisamplefv = ( PFNGLGETMULTISAMPLEFV_PROC * )glfwGetProcAddress( "glGetMultisamplefv" );
	glpfGetSynciv = ( PFNGLGETSYNCIV_PROC * )glfwGetProcAddress( "glGetSynciv" );
	glpfIsSync = ( PFNGLISSYNC_PROC * )glfwGetProcAddress( "glIsSync" );
	glpfMultiDrawElementsBaseVertex = ( PFNGLMULTIDRAWELEMENTSBASEVERTEX_PROC * )glfwGetProcAddress( "glMultiDrawElementsBaseVertex" );
	glpfProvokingVertex = ( PFNGLPROVOKINGVERTEX_PROC * )glfwGetProcAddress( "glProvokingVertex" );
	glpfSampleMaski = ( PFNGLSAMPLEMASKI_PROC * )glfwGetProcAddress( "glSampleMaski" );
	glpfTexImage2DMultisample = ( PFNGLTEXIMAGE2DMULTISAMPLE_PROC * )glfwGetProcAddress( "glTexImage2DMultisample" );
	glpfTexImage3DMultisample = ( PFNGLTEXIMAGE3DMULTISAMPLE_PROC * )glfwGetProcAddress( "glTexImage3DMultisample" );
	glpfWaitSync = ( PFNGLWAITSYNC_PROC * )glfwGetProcAddress( "glWaitSync" );
	
	
	/* GL_VERSION_3_3 */
	
	glpfBindFragDataLocationIndexed = ( PFNGLBINDFRAGDATALOCATIONINDEXED_PROC * )glfwGetProcAddress( "glBindFragDataLocationIndexed" );
	glpfBindSampler = ( PFNGLBINDSAMPLER_PROC * )glfwGetProcAddress( "glBindSampler" );
	glpfDeleteSamplers = ( PFNGLDELETESAMPLERS_PROC * )glfwGetProcAddress( "glDeleteSamplers" );
	glpfGenSamplers = ( PFNGLGENSAMPLERS_PROC * )glfwGetProcAddress( "glGenSamplers" );
	glpfGetFragDataIndex = ( PFNGLGETFRAGDATAINDEX_PROC * )glfwGetProcAddress( "glGetFragDataIndex" );
	glpfGetQueryObjecti64v = ( PFNGLGETQUERYOBJECTI64V_PROC * )glfwGetProcAddress( "glGetQueryObjecti64v" );
	glpfGetQueryObjectui64v = ( PFNGLGETQUERYOBJECTUI64V_PROC * )glfwGetProcAddress( "glGetQueryObjectui64v" );
	glpfGetSamplerParameterIiv = ( PFNGLGETSAMPLERPARAMETERIIV_PROC * )glfwGetProcAddress( "glGetSamplerParameterIiv" );
	glpfGetSamplerParameterIuiv = ( PFNGLGETSAMPLERPARAMETERIUIV_PROC * )glfwGetProcAddress( "glGetSamplerParameterIuiv" );
	glpfGetSamplerParameterfv = ( PFNGLGETSAMPLERPARAMETERFV_PROC * )glfwGetProcAddress( "glGetSamplerParameterfv" );
	glpfGetSamplerParameteriv = ( PFNGLGETSAMPLERPARAMETERIV_PROC * )glfwGetProcAddress( "glGetSamplerParameteriv" );
	glpfIsSampler = ( PFNGLISSAMPLER_PROC * )glfwGetProcAddress( "glIsSampler" );
	glpfQueryCounter = ( PFNGLQUERYCOUNTER_PROC * )glfwGetProcAddress( "glQueryCounter" );
	glpfSamplerParameterIiv = ( PFNGLSAMPLERPARAMETERIIV_PROC * )glfwGetProcAddress( "glSamplerParameterIiv" );
	glpfSamplerParameterIuiv = ( PFNGLSAMPLERPARAMETERIUIV_PROC * )glfwGetProcAddress( "glSamplerParameterIuiv" );
	glpfSamplerParameterf = ( PFNGLSAMPLERPARAMETERF_PROC * )glfwGetProcAddress( "glSamplerParameterf" );
	glpfSamplerParameterfv = ( PFNGLSAMPLERPARAMETERFV_PROC * )glfwGetProcAddress( "glSamplerParameterfv" );
	glpfSamplerParameteri = ( PFNGLSAMPLERPARAMETERI_PROC * )glfwGetProcAddress( "glSamplerParameteri" );
	glpfSamplerParameteriv = ( PFNGLSAMPLERPARAMETERIV_PROC * )glfwGetProcAddress( "glSamplerParameteriv" );
	glpfVertexAttribDivisor = ( PFNGLVERTEXATTRIBDIVISOR_PROC * )glfwGetProcAddress( "glVertexAttribDivisor" );
	glpfVertexAttribP1ui = ( PFNGLVERTEXATTRIBP1UI_PROC * )glfwGetProcAddress( "glVertexAttribP1ui" );
	glpfVertexAttribP1uiv = ( PFNGLVERTEXATTRIBP1UIV_PROC * )glfwGetProcAddress( "glVertexAttribP1uiv" );
	glpfVertexAttribP2ui = ( PFNGLVERTEXATTRIBP2UI_PROC * )glfwGetProcAddress( "glVertexAttribP2ui" );
	glpfVertexAttribP2uiv = ( PFNGLVERTEXATTRIBP2UIV_PROC * )glfwGetProcAddress( "glVertexAttribP2uiv" );
	glpfVertexAttribP3ui = ( PFNGLVERTEXATTRIBP3UI_PROC * )glfwGetProcAddress( "glVertexAttribP3ui" );
	glpfVertexAttribP3uiv = ( PFNGLVERTEXATTRIBP3UIV_PROC * )glfwGetProcAddress( "glVertexAttribP3uiv" );
	glpfVertexAttribP4ui = ( PFNGLVERTEXATTRIBP4UI_PROC * )glfwGetProcAddress( "glVertexAttribP4ui" );
	glpfVertexAttribP4uiv = ( PFNGLVERTEXATTRIBP4UIV_PROC * )glfwGetProcAddress( "glVertexAttribP4uiv" );
	
	
	/* GL_VERSION_4_0 */
	
	glpfBeginQueryIndexed = ( PFNGLBEGINQUERYINDEXED_PROC * )glfwGetProcAddress( "glBeginQueryIndexed" );
	glpfBindTransformFeedback = ( PFNGLBINDTRANSFORMFEEDBACK_PROC * )glfwGetProcAddress( "glBindTransformFeedback" );
	glpfBlendEquationSeparatei = ( PFNGLBLENDEQUATIONSEPARATEI_PROC * )glfwGetProcAddress( "glBlendEquationSeparatei" );
	glpfBlendEquationi = ( PFNGLBLENDEQUATIONI_PROC * )glfwGetProcAddress( "glBlendEquationi" );
	glpfBlendFuncSeparatei = ( PFNGLBLENDFUNCSEPARATEI_PROC * )glfwGetProcAddress( "glBlendFuncSeparatei" );
	glpfBlendFunci = ( PFNGLBLENDFUNCI_PROC * )glfwGetProcAddress( "glBlendFunci" );
	glpfDeleteTransformFeedbacks = ( PFNGLDELETETRANSFORMFEEDBACKS_PROC * )glfwGetProcAddress( "glDeleteTransformFeedbacks" );
	glpfDrawArraysIndirect = ( PFNGLDRAWARRAYSINDIRECT_PROC * )glfwGetProcAddress( "glDrawArraysIndirect" );
	glpfDrawElementsIndirect = ( PFNGLDRAWELEMENTSINDIRECT_PROC * )glfwGetProcAddress( "glDrawElementsIndirect" );
	glpfDrawTransformFeedback = ( PFNGLDRAWTRANSFORMFEEDBACK_PROC * )glfwGetProcAddress( "glDrawTransformFeedback" );
	glpfDrawTransformFeedbackStream = ( PFNGLDRAWTRANSFORMFEEDBACKSTREAM_PROC * )glfwGetProcAddress( "glDrawTransformFeedbackStream" );
	glpfEndQueryIndexed = ( PFNGLENDQUERYINDEXED_PROC * )glfwGetProcAddress( "glEndQueryIndexed" );
	glpfGenTransformFeedbacks = ( PFNGLGENTRANSFORMFEEDBACKS_PROC * )glfwGetProcAddress( "glGenTransformFeedbacks" );
	glpfGetActiveSubroutineName = ( PFNGLGETACTIVESUBROUTINENAME_PROC * )glfwGetProcAddress( "glGetActiveSubroutineName" );
	glpfGetActiveSubroutineUniformName = ( PFNGLGETACTIVESUBROUTINEUNIFORMNAME_PROC * )glfwGetProcAddress( "glGetActiveSubroutineUniformName" );
	glpfGetActiveSubroutineUniformiv = ( PFNGLGETACTIVESUBROUTINEUNIFORMIV_PROC * )glfwGetProcAddress( "glGetActiveSubroutineUniformiv" );
	glpfGetProgramStageiv = ( PFNGLGETPROGRAMSTAGEIV_PROC * )glfwGetProcAddress( "glGetProgramStageiv" );
	glpfGetQueryIndexediv = ( PFNGLGETQUERYINDEXEDIV_PROC * )glfwGetProcAddress( "glGetQueryIndexediv" );
	glpfGetSubroutineIndex = ( PFNGLGETSUBROUTINEINDEX_PROC * )glfwGetProcAddress( "glGetSubroutineIndex" );
	glpfGetSubroutineUniformLocation = ( PFNGLGETSUBROUTINEUNIFORMLOCATION_PROC * )glfwGetProcAddress( "glGetSubroutineUniformLocation" );
	glpfGetUniformSubroutineuiv = ( PFNGLGETUNIFORMSUBROUTINEUIV_PROC * )glfwGetProcAddress( "glGetUniformSubroutineuiv" );
	glpfGetUniformdv = ( PFNGLGETUNIFORMDV_PROC * )glfwGetProcAddress( "glGetUniformdv" );
	glpfIsTransformFeedback = ( PFNGLISTRANSFORMFEEDBACK_PROC * )glfwGetProcAddress( "glIsTransformFeedback" );
	glpfMinSampleShading = ( PFNGLMINSAMPLESHADING_PROC * )glfwGetProcAddress( "glMinSampleShading" );
	glpfPatchParameterfv = ( PFNGLPATCHPARAMETERFV_PROC * )glfwGetProcAddress( "glPatchParameterfv" );
	glpfPatchParameteri = ( PFNGLPATCHPARAMETERI_PROC * )glfwGetProcAddress( "glPatchParameteri" );
	glpfPauseTransformFeedback = ( PFNGLPAUSETRANSFORMFEEDBACK_PROC * )glfwGetProcAddress( "glPauseTransformFeedback" );
	glpfResumeTransformFeedback = ( PFNGLRESUMETRANSFORMFEEDBACK_PROC * )glfwGetProcAddress( "glResumeTransformFeedback" );
	glpfUniform1d = ( PFNGLUNIFORM1D_PROC * )glfwGetProcAddress( "glUniform1d" );
	glpfUniform1dv = ( PFNGLUNIFORM1DV_PROC * )glfwGetProcAddress( "glUniform1dv" );
	glpfUniform2d = ( PFNGLUNIFORM2D_PROC * )glfwGetProcAddress( "glUniform2d" );
	glpfUniform2dv = ( PFNGLUNIFORM2DV_PROC * )glfwGetProcAddress( "glUniform2dv" );
	glpfUniform3d = ( PFNGLUNIFORM3D_PROC * )glfwGetProcAddress( "glUniform3d" );
	glpfUniform3dv = ( PFNGLUNIFORM3DV_PROC * )glfwGetProcAddress( "glUniform3dv" );
	glpfUniform4d = ( PFNGLUNIFORM4D_PROC * )glfwGetProcAddress( "glUniform4d" );
	glpfUniform4dv = ( PFNGLUNIFORM4DV_PROC * )glfwGetProcAddress( "glUniform4dv" );
	glpfUniformMatrix2dv = ( PFNGLUNIFORMMATRIX2DV_PROC * )glfwGetProcAddress( "glUniformMatrix2dv" );
	glpfUniformMatrix2x3dv = ( PFNGLUNIFORMMATRIX2X3DV_PROC * )glfwGetProcAddress( "glUniformMatrix2x3dv" );
	glpfUniformMatrix2x4dv = ( PFNGLUNIFORMMATRIX2X4DV_PROC * )glfwGetProcAddress( "glUniformMatrix2x4dv" );
	glpfUniformMatrix3dv = ( PFNGLUNIFORMMATRIX3DV_PROC * )glfwGetProcAddress( "glUniformMatrix3dv" );
	glpfUniformMatrix3x2dv = ( PFNGLUNIFORMMATRIX3X2DV_PROC * )glfwGetProcAddress( "glUniformMatrix3x2dv" );
	glpfUniformMatrix3x4dv = ( PFNGLUNIFORMMATRIX3X4DV_PROC * )glfwGetProcAddress( "glUniformMatrix3x4dv" );
	glpfUniformMatrix4dv = ( PFNGLUNIFORMMATRIX4DV_PROC * )glfwGetProcAddress( "glUniformMatrix4dv" );
	glpfUniformMatrix4x2dv = ( PFNGLUNIFORMMATRIX4X2DV_PROC * )glfwGetProcAddress( "glUniformMatrix4x2dv" );
	glpfUniformMatrix4x3dv = ( PFNGLUNIFORMMATRIX4X3DV_PROC * )glfwGetProcAddress( "glUniformMatrix4x3dv" );
	glpfUniformSubroutinesuiv = ( PFNGLUNIFORMSUBROUTINESUIV_PROC * )glfwGetProcAddress( "glUniformSubroutinesuiv" );
	
	
	/* GL_VERSION_4_1 */
	
	glpfActiveShaderProgram = ( PFNGLACTIVESHADERPROGRAM_PROC * )glfwGetProcAddress( "glActiveShaderProgram" );
	glpfBindProgramPipeline = ( PFNGLBINDPROGRAMPIPELINE_PROC * )glfwGetProcAddress( "glBindProgramPipeline" );
	glpfClearDepthf = ( PFNGLCLEARDEPTHF_PROC * )glfwGetProcAddress( "glClearDepthf" );
	glpfCreateShaderProgramv = ( PFNGLCREATESHADERPROGRAMV_PROC * )glfwGetProcAddress( "glCreateShaderProgramv" );
	glpfDeleteProgramPipelines = ( PFNGLDELETEPROGRAMPIPELINES_PROC * )glfwGetProcAddress( "glDeleteProgramPipelines" );
	glpfDepthRangeArrayv = ( PFNGLDEPTHRANGEARRAYV_PROC * )glfwGetProcAddress( "glDepthRangeArrayv" );
	glpfDepthRangeIndexed = ( PFNGLDEPTHRANGEINDEXED_PROC * )glfwGetProcAddress( "glDepthRangeIndexed" );
	glpfDepthRangef = ( PFNGLDEPTHRANGEF_PROC * )glfwGetProcAddress( "glDepthRangef" );
	glpfGenProgramPipelines = ( PFNGLGENPROGRAMPIPELINES_PROC * )glfwGetProcAddress( "glGenProgramPipelines" );
	glpfGetDoublei_v = ( PFNGLGETDOUBLEI_V_PROC * )glfwGetProcAddress( "glGetDoublei_v" );
	glpfGetFloati_v = ( PFNGLGETFLOATI_V_PROC * )glfwGetProcAddress( "glGetFloati_v" );
	glpfGetProgramBinary = ( PFNGLGETPROGRAMBINARY_PROC * )glfwGetProcAddress( "glGetProgramBinary" );
	glpfGetProgramPipelineInfoLog = ( PFNGLGETPROGRAMPIPELINEINFOLOG_PROC * )glfwGetProcAddress( "glGetProgramPipelineInfoLog" );
	glpfGetProgramPipelineiv = ( PFNGLGETPROGRAMPIPELINEIV_PROC * )glfwGetProcAddress( "glGetProgramPipelineiv" );
	glpfGetShaderPrecisionFormat = ( PFNGLGETSHADERPRECISIONFORMAT_PROC * )glfwGetProcAddress( "glGetShaderPrecisionFormat" );
	glpfGetVertexAttribLdv = ( PFNGLGETVERTEXATTRIBLDV_PROC * )glfwGetProcAddress( "glGetVertexAttribLdv" );
	glpfIsProgramPipeline = ( PFNGLISPROGRAMPIPELINE_PROC * )glfwGetProcAddress( "glIsProgramPipeline" );
	glpfProgramBinary = ( PFNGLPROGRAMBINARY_PROC * )glfwGetProcAddress( "glProgramBinary" );
	glpfProgramParameteri = ( PFNGLPROGRAMPARAMETERI_PROC * )glfwGetProcAddress( "glProgramParameteri" );
	glpfProgramUniform1d = ( PFNGLPROGRAMUNIFORM1D_PROC * )glfwGetProcAddress( "glProgramUniform1d" );
	glpfProgramUniform1dv = ( PFNGLPROGRAMUNIFORM1DV_PROC * )glfwGetProcAddress( "glProgramUniform1dv" );
	glpfProgramUniform1f = ( PFNGLPROGRAMUNIFORM1F_PROC * )glfwGetProcAddress( "glProgramUniform1f" );
	glpfProgramUniform1fv = ( PFNGLPROGRAMUNIFORM1FV_PROC * )glfwGetProcAddress( "glProgramUniform1fv" );
	glpfProgramUniform1i = ( PFNGLPROGRAMUNIFORM1I_PROC * )glfwGetProcAddress( "glProgramUniform1i" );
	glpfProgramUniform1iv = ( PFNGLPROGRAMUNIFORM1IV_PROC * )glfwGetProcAddress( "glProgramUniform1iv" );
	glpfProgramUniform1ui = ( PFNGLPROGRAMUNIFORM1UI_PROC * )glfwGetProcAddress( "glProgramUniform1ui" );
	glpfProgramUniform1uiv = ( PFNGLPROGRAMUNIFORM1UIV_PROC * )glfwGetProcAddress( "glProgramUniform1uiv" );
	glpfProgramUniform2d = ( PFNGLPROGRAMUNIFORM2D_PROC * )glfwGetProcAddress( "glProgramUniform2d" );
	glpfProgramUniform2dv = ( PFNGLPROGRAMUNIFORM2DV_PROC * )glfwGetProcAddress( "glProgramUniform2dv" );
	glpfProgramUniform2f = ( PFNGLPROGRAMUNIFORM2F_PROC * )glfwGetProcAddress( "glProgramUniform2f" );
	glpfProgramUniform2fv = ( PFNGLPROGRAMUNIFORM2FV_PROC * )glfwGetProcAddress( "glProgramUniform2fv" );
	glpfProgramUniform2i = ( PFNGLPROGRAMUNIFORM2I_PROC * )glfwGetProcAddress( "glProgramUniform2i" );
	glpfProgramUniform2iv = ( PFNGLPROGRAMUNIFORM2IV_PROC * )glfwGetProcAddress( "glProgramUniform2iv" );
	glpfProgramUniform2ui = ( PFNGLPROGRAMUNIFORM2UI_PROC * )glfwGetProcAddress( "glProgramUniform2ui" );
	glpfProgramUniform2uiv = ( PFNGLPROGRAMUNIFORM2UIV_PROC * )glfwGetProcAddress( "glProgramUniform2uiv" );
	glpfProgramUniform3d = ( PFNGLPROGRAMUNIFORM3D_PROC * )glfwGetProcAddress( "glProgramUniform3d" );
	glpfProgramUniform3dv = ( PFNGLPROGRAMUNIFORM3DV_PROC * )glfwGetProcAddress( "glProgramUniform3dv" );
	glpfProgramUniform3f = ( PFNGLPROGRAMUNIFORM3F_PROC * )glfwGetProcAddress( "glProgramUniform3f" );
	glpfProgramUniform3fv = ( PFNGLPROGRAMUNIFORM3FV_PROC * )glfwGetProcAddress( "glProgramUniform3fv" );
	glpfProgramUniform3i = ( PFNGLPROGRAMUNIFORM3I_PROC * )glfwGetProcAddress( "glProgramUniform3i" );
	glpfProgramUniform3iv = ( PFNGLPROGRAMUNIFORM3IV_PROC * )glfwGetProcAddress( "glProgramUniform3iv" );
	glpfProgramUniform3ui = ( PFNGLPROGRAMUNIFORM3UI_PROC * )glfwGetProcAddress( "glProgramUniform3ui" );
	glpfProgramUniform3uiv = ( PFNGLPROGRAMUNIFORM3UIV_PROC * )glfwGetProcAddress( "glProgramUniform3uiv" );
	glpfProgramUniform4d = ( PFNGLPROGRAMUNIFORM4D_PROC * )glfwGetProcAddress( "glProgramUniform4d" );
	glpfProgramUniform4dv = ( PFNGLPROGRAMUNIFORM4DV_PROC * )glfwGetProcAddress( "glProgramUniform4dv" );
	glpfProgramUniform4f = ( PFNGLPROGRAMUNIFORM4F_PROC * )glfwGetProcAddress( "glProgramUniform4f" );
	glpfProgramUniform4fv = ( PFNGLPROGRAMUNIFORM4FV_PROC * )glfwGetProcAddress( "glProgramUniform4fv" );
	glpfProgramUniform4i = ( PFNGLPROGRAMUNIFORM4I_PROC * )glfwGetProcAddress( "glProgramUniform4i" );
	glpfProgramUniform4iv = ( PFNGLPROGRAMUNIFORM4IV_PROC * )glfwGetProcAddress( "glProgramUniform4iv" );
	glpfProgramUniform4ui = ( PFNGLPROGRAMUNIFORM4UI_PROC * )glfwGetProcAddress( "glProgramUniform4ui" );
	glpfProgramUniform4uiv = ( PFNGLPROGRAMUNIFORM4UIV_PROC * )glfwGetProcAddress( "glProgramUniform4uiv" );
	glpfProgramUniformMatrix2dv = ( PFNGLPROGRAMUNIFORMMATRIX2DV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix2dv" );
	glpfProgramUniformMatrix2fv = ( PFNGLPROGRAMUNIFORMMATRIX2FV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix2fv" );
	glpfProgramUniformMatrix2x3dv = ( PFNGLPROGRAMUNIFORMMATRIX2X3DV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix2x3dv" );
	glpfProgramUniformMatrix2x3fv = ( PFNGLPROGRAMUNIFORMMATRIX2X3FV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix2x3fv" );
	glpfProgramUniformMatrix2x4dv = ( PFNGLPROGRAMUNIFORMMATRIX2X4DV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix2x4dv" );
	glpfProgramUniformMatrix2x4fv = ( PFNGLPROGRAMUNIFORMMATRIX2X4FV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix2x4fv" );
	glpfProgramUniformMatrix3dv = ( PFNGLPROGRAMUNIFORMMATRIX3DV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix3dv" );
	glpfProgramUniformMatrix3fv = ( PFNGLPROGRAMUNIFORMMATRIX3FV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix3fv" );
	glpfProgramUniformMatrix3x2dv = ( PFNGLPROGRAMUNIFORMMATRIX3X2DV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix3x2dv" );
	glpfProgramUniformMatrix3x2fv = ( PFNGLPROGRAMUNIFORMMATRIX3X2FV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix3x2fv" );
	glpfProgramUniformMatrix3x4dv = ( PFNGLPROGRAMUNIFORMMATRIX3X4DV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix3x4dv" );
	glpfProgramUniformMatrix3x4fv = ( PFNGLPROGRAMUNIFORMMATRIX3X4FV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix3x4fv" );
	glpfProgramUniformMatrix4dv = ( PFNGLPROGRAMUNIFORMMATRIX4DV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix4dv" );
	glpfProgramUniformMatrix4fv = ( PFNGLPROGRAMUNIFORMMATRIX4FV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix4fv" );
	glpfProgramUniformMatrix4x2dv = ( PFNGLPROGRAMUNIFORMMATRIX4X2DV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix4x2dv" );
	glpfProgramUniformMatrix4x2fv = ( PFNGLPROGRAMUNIFORMMATRIX4X2FV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix4x2fv" );
	glpfProgramUniformMatrix4x3dv = ( PFNGLPROGRAMUNIFORMMATRIX4X3DV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix4x3dv" );
	glpfProgramUniformMatrix4x3fv = ( PFNGLPROGRAMUNIFORMMATRIX4X3FV_PROC * )glfwGetProcAddress( "glProgramUniformMatrix4x3fv" );
	glpfReleaseShaderCompiler = ( PFNGLRELEASESHADERCOMPILER_PROC * )glfwGetProcAddress( "glReleaseShaderCompiler" );
	glpfScissorArrayv = ( PFNGLSCISSORARRAYV_PROC * )glfwGetProcAddress( "glScissorArrayv" );
	glpfScissorIndexed = ( PFNGLSCISSORINDEXED_PROC * )glfwGetProcAddress( "glScissorIndexed" );
	glpfScissorIndexedv = ( PFNGLSCISSORINDEXEDV_PROC * )glfwGetProcAddress( "glScissorIndexedv" );
	glpfShaderBinary = ( PFNGLSHADERBINARY_PROC * )glfwGetProcAddress( "glShaderBinary" );
	glpfUseProgramStages = ( PFNGLUSEPROGRAMSTAGES_PROC * )glfwGetProcAddress( "glUseProgramStages" );
	glpfValidateProgramPipeline = ( PFNGLVALIDATEPROGRAMPIPELINE_PROC * )glfwGetProcAddress( "glValidateProgramPipeline" );
	glpfVertexAttribL1d = ( PFNGLVERTEXATTRIBL1D_PROC * )glfwGetProcAddress( "glVertexAttribL1d" );
	glpfVertexAttribL1dv = ( PFNGLVERTEXATTRIBL1DV_PROC * )glfwGetProcAddress( "glVertexAttribL1dv" );
	glpfVertexAttribL2d = ( PFNGLVERTEXATTRIBL2D_PROC * )glfwGetProcAddress( "glVertexAttribL2d" );
	glpfVertexAttribL2dv = ( PFNGLVERTEXATTRIBL2DV_PROC * )glfwGetProcAddress( "glVertexAttribL2dv" );
	glpfVertexAttribL3d = ( PFNGLVERTEXATTRIBL3D_PROC * )glfwGetProcAddress( "glVertexAttribL3d" );
	glpfVertexAttribL3dv = ( PFNGLVERTEXATTRIBL3DV_PROC * )glfwGetProcAddress( "glVertexAttribL3dv" );
	glpfVertexAttribL4d = ( PFNGLVERTEXATTRIBL4D_PROC * )glfwGetProcAddress( "glVertexAttribL4d" );
	glpfVertexAttribL4dv = ( PFNGLVERTEXATTRIBL4DV_PROC * )glfwGetProcAddress( "glVertexAttribL4dv" );
	glpfVertexAttribLPointer = ( PFNGLVERTEXATTRIBLPOINTER_PROC * )glfwGetProcAddress( "glVertexAttribLPointer" );
	glpfViewportArrayv = ( PFNGLVIEWPORTARRAYV_PROC * )glfwGetProcAddress( "glViewportArrayv" );
	glpfViewportIndexedf = ( PFNGLVIEWPORTINDEXEDF_PROC * )glfwGetProcAddress( "glViewportIndexedf" );
	glpfViewportIndexedfv = ( PFNGLVIEWPORTINDEXEDFV_PROC * )glfwGetProcAddress( "glViewportIndexedfv" );
	
	
}

/* ----------------------- Extension flag definitions ---------------------- */

/* ---------------------- Function pointer definitions --------------------- */

/* GL_VERSION_1_2 */

PFNGLCOPYTEXSUBIMAGE3D_PROC *glpfCopyTexSubImage3D = NULL;
PFNGLDRAWRANGEELEMENTS_PROC *glpfDrawRangeElements = NULL;
PFNGLTEXIMAGE3D_PROC *glpfTexImage3D = NULL;
PFNGLTEXSUBIMAGE3D_PROC *glpfTexSubImage3D = NULL;

/* GL_VERSION_1_3 */

PFNGLACTIVETEXTURE_PROC *glpfActiveTexture = NULL;
PFNGLCOMPRESSEDTEXIMAGE1D_PROC *glpfCompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2D_PROC *glpfCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE3D_PROC *glpfCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1D_PROC *glpfCompressedTexSubImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2D_PROC *glpfCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3D_PROC *glpfCompressedTexSubImage3D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGE_PROC *glpfGetCompressedTexImage = NULL;
PFNGLSAMPLECOVERAGE_PROC *glpfSampleCoverage = NULL;

/* GL_VERSION_1_4 */

PFNGLBLENDCOLOR_PROC *glpfBlendColor = NULL;
PFNGLBLENDEQUATION_PROC *glpfBlendEquation = NULL;
PFNGLBLENDFUNCSEPARATE_PROC *glpfBlendFuncSeparate = NULL;
PFNGLMULTIDRAWARRAYS_PROC *glpfMultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTS_PROC *glpfMultiDrawElements = NULL;
PFNGLPOINTPARAMETERF_PROC *glpfPointParameterf = NULL;
PFNGLPOINTPARAMETERFV_PROC *glpfPointParameterfv = NULL;
PFNGLPOINTPARAMETERI_PROC *glpfPointParameteri = NULL;
PFNGLPOINTPARAMETERIV_PROC *glpfPointParameteriv = NULL;

/* GL_VERSION_1_5 */

PFNGLBEGINQUERY_PROC *glpfBeginQuery = NULL;
PFNGLBINDBUFFER_PROC *glpfBindBuffer = NULL;
PFNGLBUFFERDATA_PROC *glpfBufferData = NULL;
PFNGLBUFFERSUBDATA_PROC *glpfBufferSubData = NULL;
PFNGLDELETEBUFFERS_PROC *glpfDeleteBuffers = NULL;
PFNGLDELETEQUERIES_PROC *glpfDeleteQueries = NULL;
PFNGLENDQUERY_PROC *glpfEndQuery = NULL;
PFNGLGENBUFFERS_PROC *glpfGenBuffers = NULL;
PFNGLGENQUERIES_PROC *glpfGenQueries = NULL;
PFNGLGETBUFFERPARAMETERIV_PROC *glpfGetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERV_PROC *glpfGetBufferPointerv = NULL;
PFNGLGETBUFFERSUBDATA_PROC *glpfGetBufferSubData = NULL;
PFNGLGETQUERYOBJECTIV_PROC *glpfGetQueryObjectiv = NULL;
PFNGLGETQUERYOBJECTUIV_PROC *glpfGetQueryObjectuiv = NULL;
PFNGLGETQUERYIV_PROC *glpfGetQueryiv = NULL;
PFNGLISBUFFER_PROC *glpfIsBuffer = NULL;
PFNGLISQUERY_PROC *glpfIsQuery = NULL;
PFNGLMAPBUFFER_PROC *glpfMapBuffer = NULL;
PFNGLUNMAPBUFFER_PROC *glpfUnmapBuffer = NULL;

/* GL_VERSION_2_0 */

PFNGLATTACHSHADER_PROC *glpfAttachShader = NULL;
PFNGLBINDATTRIBLOCATION_PROC *glpfBindAttribLocation = NULL;
PFNGLBLENDEQUATIONSEPARATE_PROC *glpfBlendEquationSeparate = NULL;
PFNGLCOMPILESHADER_PROC *glpfCompileShader = NULL;
PFNGLCREATEPROGRAM_PROC *glpfCreateProgram = NULL;
PFNGLCREATESHADER_PROC *glpfCreateShader = NULL;
PFNGLDELETEPROGRAM_PROC *glpfDeleteProgram = NULL;
PFNGLDELETESHADER_PROC *glpfDeleteShader = NULL;
PFNGLDETACHSHADER_PROC *glpfDetachShader = NULL;
PFNGLDISABLEVERTEXATTRIBARRAY_PROC *glpfDisableVertexAttribArray = NULL;
PFNGLDRAWBUFFERS_PROC *glpfDrawBuffers = NULL;
PFNGLENABLEVERTEXATTRIBARRAY_PROC *glpfEnableVertexAttribArray = NULL;
PFNGLGETACTIVEATTRIB_PROC *glpfGetActiveAttrib = NULL;
PFNGLGETACTIVEUNIFORM_PROC *glpfGetActiveUniform = NULL;
PFNGLGETATTACHEDSHADERS_PROC *glpfGetAttachedShaders = NULL;
PFNGLGETATTRIBLOCATION_PROC *glpfGetAttribLocation = NULL;
PFNGLGETPROGRAMINFOLOG_PROC *glpfGetProgramInfoLog = NULL;
PFNGLGETPROGRAMIV_PROC *glpfGetProgramiv = NULL;
PFNGLGETSHADERINFOLOG_PROC *glpfGetShaderInfoLog = NULL;
PFNGLGETSHADERSOURCE_PROC *glpfGetShaderSource = NULL;
PFNGLGETSHADERIV_PROC *glpfGetShaderiv = NULL;
PFNGLGETUNIFORMLOCATION_PROC *glpfGetUniformLocation = NULL;
PFNGLGETUNIFORMFV_PROC *glpfGetUniformfv = NULL;
PFNGLGETUNIFORMIV_PROC *glpfGetUniformiv = NULL;
PFNGLGETVERTEXATTRIBPOINTERV_PROC *glpfGetVertexAttribPointerv = NULL;
PFNGLGETVERTEXATTRIBDV_PROC *glpfGetVertexAttribdv = NULL;
PFNGLGETVERTEXATTRIBFV_PROC *glpfGetVertexAttribfv = NULL;
PFNGLGETVERTEXATTRIBIV_PROC *glpfGetVertexAttribiv = NULL;
PFNGLISPROGRAM_PROC *glpfIsProgram = NULL;
PFNGLISSHADER_PROC *glpfIsShader = NULL;
PFNGLLINKPROGRAM_PROC *glpfLinkProgram = NULL;
PFNGLSHADERSOURCE_PROC *glpfShaderSource = NULL;
PFNGLSTENCILFUNCSEPARATE_PROC *glpfStencilFuncSeparate = NULL;
PFNGLSTENCILMASKSEPARATE_PROC *glpfStencilMaskSeparate = NULL;
PFNGLSTENCILOPSEPARATE_PROC *glpfStencilOpSeparate = NULL;
PFNGLUNIFORM1F_PROC *glpfUniform1f = NULL;
PFNGLUNIFORM1FV_PROC *glpfUniform1fv = NULL;
PFNGLUNIFORM1I_PROC *glpfUniform1i = NULL;
PFNGLUNIFORM1IV_PROC *glpfUniform1iv = NULL;
PFNGLUNIFORM2F_PROC *glpfUniform2f = NULL;
PFNGLUNIFORM2FV_PROC *glpfUniform2fv = NULL;
PFNGLUNIFORM2I_PROC *glpfUniform2i = NULL;
PFNGLUNIFORM2IV_PROC *glpfUniform2iv = NULL;
PFNGLUNIFORM3F_PROC *glpfUniform3f = NULL;
PFNGLUNIFORM3FV_PROC *glpfUniform3fv = NULL;
PFNGLUNIFORM3I_PROC *glpfUniform3i = NULL;
PFNGLUNIFORM3IV_PROC *glpfUniform3iv = NULL;
PFNGLUNIFORM4F_PROC *glpfUniform4f = NULL;
PFNGLUNIFORM4FV_PROC *glpfUniform4fv = NULL;
PFNGLUNIFORM4I_PROC *glpfUniform4i = NULL;
PFNGLUNIFORM4IV_PROC *glpfUniform4iv = NULL;
PFNGLUNIFORMMATRIX2FV_PROC *glpfUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FV_PROC *glpfUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FV_PROC *glpfUniformMatrix4fv = NULL;
PFNGLUSEPROGRAM_PROC *glpfUseProgram = NULL;
PFNGLVALIDATEPROGRAM_PROC *glpfValidateProgram = NULL;
PFNGLVERTEXATTRIB1D_PROC *glpfVertexAttrib1d = NULL;
PFNGLVERTEXATTRIB1DV_PROC *glpfVertexAttrib1dv = NULL;
PFNGLVERTEXATTRIB1F_PROC *glpfVertexAttrib1f = NULL;
PFNGLVERTEXATTRIB1FV_PROC *glpfVertexAttrib1fv = NULL;
PFNGLVERTEXATTRIB1S_PROC *glpfVertexAttrib1s = NULL;
PFNGLVERTEXATTRIB1SV_PROC *glpfVertexAttrib1sv = NULL;
PFNGLVERTEXATTRIB2D_PROC *glpfVertexAttrib2d = NULL;
PFNGLVERTEXATTRIB2DV_PROC *glpfVertexAttrib2dv = NULL;
PFNGLVERTEXATTRIB2F_PROC *glpfVertexAttrib2f = NULL;
PFNGLVERTEXATTRIB2FV_PROC *glpfVertexAttrib2fv = NULL;
PFNGLVERTEXATTRIB2S_PROC *glpfVertexAttrib2s = NULL;
PFNGLVERTEXATTRIB2SV_PROC *glpfVertexAttrib2sv = NULL;
PFNGLVERTEXATTRIB3D_PROC *glpfVertexAttrib3d = NULL;
PFNGLVERTEXATTRIB3DV_PROC *glpfVertexAttrib3dv = NULL;
PFNGLVERTEXATTRIB3F_PROC *glpfVertexAttrib3f = NULL;
PFNGLVERTEXATTRIB3FV_PROC *glpfVertexAttrib3fv = NULL;
PFNGLVERTEXATTRIB3S_PROC *glpfVertexAttrib3s = NULL;
PFNGLVERTEXATTRIB3SV_PROC *glpfVertexAttrib3sv = NULL;
PFNGLVERTEXATTRIB4NBV_PROC *glpfVertexAttrib4Nbv = NULL;
PFNGLVERTEXATTRIB4NIV_PROC *glpfVertexAttrib4Niv = NULL;
PFNGLVERTEXATTRIB4NSV_PROC *glpfVertexAttrib4Nsv = NULL;
PFNGLVERTEXATTRIB4NUB_PROC *glpfVertexAttrib4Nub = NULL;
PFNGLVERTEXATTRIB4NUBV_PROC *glpfVertexAttrib4Nubv = NULL;
PFNGLVERTEXATTRIB4NUIV_PROC *glpfVertexAttrib4Nuiv = NULL;
PFNGLVERTEXATTRIB4NUSV_PROC *glpfVertexAttrib4Nusv = NULL;
PFNGLVERTEXATTRIB4BV_PROC *glpfVertexAttrib4bv = NULL;
PFNGLVERTEXATTRIB4D_PROC *glpfVertexAttrib4d = NULL;
PFNGLVERTEXATTRIB4DV_PROC *glpfVertexAttrib4dv = NULL;
PFNGLVERTEXATTRIB4F_PROC *glpfVertexAttrib4f = NULL;
PFNGLVERTEXATTRIB4FV_PROC *glpfVertexAttrib4fv = NULL;
PFNGLVERTEXATTRIB4IV_PROC *glpfVertexAttrib4iv = NULL;
PFNGLVERTEXATTRIB4S_PROC *glpfVertexAttrib4s = NULL;
PFNGLVERTEXATTRIB4SV_PROC *glpfVertexAttrib4sv = NULL;
PFNGLVERTEXATTRIB4UBV_PROC *glpfVertexAttrib4ubv = NULL;
PFNGLVERTEXATTRIB4UIV_PROC *glpfVertexAttrib4uiv = NULL;
PFNGLVERTEXATTRIB4USV_PROC *glpfVertexAttrib4usv = NULL;
PFNGLVERTEXATTRIBPOINTER_PROC *glpfVertexAttribPointer = NULL;

/* GL_VERSION_2_1 */

PFNGLUNIFORMMATRIX2X3FV_PROC *glpfUniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX2X4FV_PROC *glpfUniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX3X2FV_PROC *glpfUniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FV_PROC *glpfUniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4X2FV_PROC *glpfUniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX4X3FV_PROC *glpfUniformMatrix4x3fv = NULL;

/* GL_VERSION_3_0 */

PFNGLBEGINCONDITIONALRENDER_PROC *glpfBeginConditionalRender = NULL;
PFNGLBEGINTRANSFORMFEEDBACK_PROC *glpfBeginTransformFeedback = NULL;
PFNGLBINDBUFFERBASE_PROC *glpfBindBufferBase = NULL;
PFNGLBINDBUFFERRANGE_PROC *glpfBindBufferRange = NULL;
PFNGLBINDFRAGDATALOCATION_PROC *glpfBindFragDataLocation = NULL;
PFNGLBINDFRAMEBUFFER_PROC *glpfBindFramebuffer = NULL;
PFNGLBINDRENDERBUFFER_PROC *glpfBindRenderbuffer = NULL;
PFNGLBINDVERTEXARRAY_PROC *glpfBindVertexArray = NULL;
PFNGLBLITFRAMEBUFFER_PROC *glpfBlitFramebuffer = NULL;
PFNGLCHECKFRAMEBUFFERSTATUS_PROC *glpfCheckFramebufferStatus = NULL;
PFNGLCLAMPCOLOR_PROC *glpfClampColor = NULL;
PFNGLCLEARBUFFERFI_PROC *glpfClearBufferfi = NULL;
PFNGLCLEARBUFFERFV_PROC *glpfClearBufferfv = NULL;
PFNGLCLEARBUFFERIV_PROC *glpfClearBufferiv = NULL;
PFNGLCLEARBUFFERUIV_PROC *glpfClearBufferuiv = NULL;
PFNGLCOLORMASKI_PROC *glpfColorMaski = NULL;
PFNGLDELETEFRAMEBUFFERS_PROC *glpfDeleteFramebuffers = NULL;
PFNGLDELETERENDERBUFFERS_PROC *glpfDeleteRenderbuffers = NULL;
PFNGLDELETEVERTEXARRAYS_PROC *glpfDeleteVertexArrays = NULL;
PFNGLDISABLEI_PROC *glpfDisablei = NULL;
PFNGLENABLEI_PROC *glpfEnablei = NULL;
PFNGLENDCONDITIONALRENDER_PROC *glpfEndConditionalRender = NULL;
PFNGLENDTRANSFORMFEEDBACK_PROC *glpfEndTransformFeedback = NULL;
PFNGLFLUSHMAPPEDBUFFERRANGE_PROC *glpfFlushMappedBufferRange = NULL;
PFNGLFRAMEBUFFERRENDERBUFFER_PROC *glpfFramebufferRenderbuffer = NULL;
PFNGLFRAMEBUFFERTEXTURE1D_PROC *glpfFramebufferTexture1D = NULL;
PFNGLFRAMEBUFFERTEXTURE2D_PROC *glpfFramebufferTexture2D = NULL;
PFNGLFRAMEBUFFERTEXTURE3D_PROC *glpfFramebufferTexture3D = NULL;
PFNGLFRAMEBUFFERTEXTURELAYER_PROC *glpfFramebufferTextureLayer = NULL;
PFNGLGENFRAMEBUFFERS_PROC *glpfGenFramebuffers = NULL;
PFNGLGENRENDERBUFFERS_PROC *glpfGenRenderbuffers = NULL;
PFNGLGENVERTEXARRAYS_PROC *glpfGenVertexArrays = NULL;
PFNGLGENERATEMIPMAP_PROC *glpfGenerateMipmap = NULL;
PFNGLGETBOOLEANI_V_PROC *glpfGetBooleani_v = NULL;
PFNGLGETFRAGDATALOCATION_PROC *glpfGetFragDataLocation = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIV_PROC *glpfGetFramebufferAttachmentParameteriv = NULL;
PFNGLGETINTEGERI_V_PROC *glpfGetIntegeri_v = NULL;
PFNGLGETRENDERBUFFERPARAMETERIV_PROC *glpfGetRenderbufferParameteriv = NULL;
PFNGLGETSTRINGI_PROC *glpfGetStringi = NULL;
PFNGLGETTEXPARAMETERIIV_PROC *glpfGetTexParameterIiv = NULL;
PFNGLGETTEXPARAMETERIUIV_PROC *glpfGetTexParameterIuiv = NULL;
PFNGLGETTRANSFORMFEEDBACKVARYING_PROC *glpfGetTransformFeedbackVarying = NULL;
PFNGLGETUNIFORMUIV_PROC *glpfGetUniformuiv = NULL;
PFNGLGETVERTEXATTRIBIIV_PROC *glpfGetVertexAttribIiv = NULL;
PFNGLGETVERTEXATTRIBIUIV_PROC *glpfGetVertexAttribIuiv = NULL;
PFNGLISENABLEDI_PROC *glpfIsEnabledi = NULL;
PFNGLISFRAMEBUFFER_PROC *glpfIsFramebuffer = NULL;
PFNGLISRENDERBUFFER_PROC *glpfIsRenderbuffer = NULL;
PFNGLISVERTEXARRAY_PROC *glpfIsVertexArray = NULL;
PFNGLMAPBUFFERRANGE_PROC *glpfMapBufferRange = NULL;
PFNGLRENDERBUFFERSTORAGE_PROC *glpfRenderbufferStorage = NULL;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLE_PROC *glpfRenderbufferStorageMultisample = NULL;
PFNGLTEXPARAMETERIIV_PROC *glpfTexParameterIiv = NULL;
PFNGLTEXPARAMETERIUIV_PROC *glpfTexParameterIuiv = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGS_PROC *glpfTransformFeedbackVaryings = NULL;
PFNGLUNIFORM1UI_PROC *glpfUniform1ui = NULL;
PFNGLUNIFORM1UIV_PROC *glpfUniform1uiv = NULL;
PFNGLUNIFORM2UI_PROC *glpfUniform2ui = NULL;
PFNGLUNIFORM2UIV_PROC *glpfUniform2uiv = NULL;
PFNGLUNIFORM3UI_PROC *glpfUniform3ui = NULL;
PFNGLUNIFORM3UIV_PROC *glpfUniform3uiv = NULL;
PFNGLUNIFORM4UI_PROC *glpfUniform4ui = NULL;
PFNGLUNIFORM4UIV_PROC *glpfUniform4uiv = NULL;
PFNGLVERTEXATTRIBI1I_PROC *glpfVertexAttribI1i = NULL;
PFNGLVERTEXATTRIBI1IV_PROC *glpfVertexAttribI1iv = NULL;
PFNGLVERTEXATTRIBI1UI_PROC *glpfVertexAttribI1ui = NULL;
PFNGLVERTEXATTRIBI1UIV_PROC *glpfVertexAttribI1uiv = NULL;
PFNGLVERTEXATTRIBI2I_PROC *glpfVertexAttribI2i = NULL;
PFNGLVERTEXATTRIBI2IV_PROC *glpfVertexAttribI2iv = NULL;
PFNGLVERTEXATTRIBI2UI_PROC *glpfVertexAttribI2ui = NULL;
PFNGLVERTEXATTRIBI2UIV_PROC *glpfVertexAttribI2uiv = NULL;
PFNGLVERTEXATTRIBI3I_PROC *glpfVertexAttribI3i = NULL;
PFNGLVERTEXATTRIBI3IV_PROC *glpfVertexAttribI3iv = NULL;
PFNGLVERTEXATTRIBI3UI_PROC *glpfVertexAttribI3ui = NULL;
PFNGLVERTEXATTRIBI3UIV_PROC *glpfVertexAttribI3uiv = NULL;
PFNGLVERTEXATTRIBI4BV_PROC *glpfVertexAttribI4bv = NULL;
PFNGLVERTEXATTRIBI4I_PROC *glpfVertexAttribI4i = NULL;
PFNGLVERTEXATTRIBI4IV_PROC *glpfVertexAttribI4iv = NULL;
PFNGLVERTEXATTRIBI4SV_PROC *glpfVertexAttribI4sv = NULL;
PFNGLVERTEXATTRIBI4UBV_PROC *glpfVertexAttribI4ubv = NULL;
PFNGLVERTEXATTRIBI4UI_PROC *glpfVertexAttribI4ui = NULL;
PFNGLVERTEXATTRIBI4UIV_PROC *glpfVertexAttribI4uiv = NULL;
PFNGLVERTEXATTRIBI4USV_PROC *glpfVertexAttribI4usv = NULL;
PFNGLVERTEXATTRIBIPOINTER_PROC *glpfVertexAttribIPointer = NULL;

/* GL_VERSION_3_1 */

PFNGLCOPYBUFFERSUBDATA_PROC *glpfCopyBufferSubData = NULL;
PFNGLDRAWARRAYSINSTANCED_PROC *glpfDrawArraysInstanced = NULL;
PFNGLDRAWELEMENTSINSTANCED_PROC *glpfDrawElementsInstanced = NULL;
PFNGLGETACTIVEUNIFORMBLOCKNAME_PROC *glpfGetActiveUniformBlockName = NULL;
PFNGLGETACTIVEUNIFORMBLOCKIV_PROC *glpfGetActiveUniformBlockiv = NULL;
PFNGLGETACTIVEUNIFORMNAME_PROC *glpfGetActiveUniformName = NULL;
PFNGLGETACTIVEUNIFORMSIV_PROC *glpfGetActiveUniformsiv = NULL;
PFNGLGETUNIFORMBLOCKINDEX_PROC *glpfGetUniformBlockIndex = NULL;
PFNGLGETUNIFORMINDICES_PROC *glpfGetUniformIndices = NULL;
PFNGLPRIMITIVERESTARTINDEX_PROC *glpfPrimitiveRestartIndex = NULL;
PFNGLTEXBUFFER_PROC *glpfTexBuffer = NULL;
PFNGLUNIFORMBLOCKBINDING_PROC *glpfUniformBlockBinding = NULL;

/* GL_VERSION_3_2 */

PFNGLCLIENTWAITSYNC_PROC *glpfClientWaitSync = NULL;
PFNGLDELETESYNC_PROC *glpfDeleteSync = NULL;
PFNGLDRAWELEMENTSBASEVERTEX_PROC *glpfDrawElementsBaseVertex = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEX_PROC *glpfDrawElementsInstancedBaseVertex = NULL;
PFNGLDRAWRANGEELEMENTSBASEVERTEX_PROC *glpfDrawRangeElementsBaseVertex = NULL;
PFNGLFENCESYNC_PROC *glpfFenceSync = NULL;
PFNGLFRAMEBUFFERTEXTURE_PROC *glpfFramebufferTexture = NULL;
PFNGLGETBUFFERPARAMETERI64V_PROC *glpfGetBufferParameteri64v = NULL;
PFNGLGETINTEGER64I_V_PROC *glpfGetInteger64i_v = NULL;
PFNGLGETINTEGER64V_PROC *glpfGetInteger64v = NULL;
PFNGLGETMULTISAMPLEFV_PROC *glpfGetMultisamplefv = NULL;
PFNGLGETSYNCIV_PROC *glpfGetSynciv = NULL;
PFNGLISSYNC_PROC *glpfIsSync = NULL;
PFNGLMULTIDRAWELEMENTSBASEVERTEX_PROC *glpfMultiDrawElementsBaseVertex = NULL;
PFNGLPROVOKINGVERTEX_PROC *glpfProvokingVertex = NULL;
PFNGLSAMPLEMASKI_PROC *glpfSampleMaski = NULL;
PFNGLTEXIMAGE2DMULTISAMPLE_PROC *glpfTexImage2DMultisample = NULL;
PFNGLTEXIMAGE3DMULTISAMPLE_PROC *glpfTexImage3DMultisample = NULL;
PFNGLWAITSYNC_PROC *glpfWaitSync = NULL;

/* GL_VERSION_3_3 */

PFNGLBINDFRAGDATALOCATIONINDEXED_PROC *glpfBindFragDataLocationIndexed = NULL;
PFNGLBINDSAMPLER_PROC *glpfBindSampler = NULL;
PFNGLDELETESAMPLERS_PROC *glpfDeleteSamplers = NULL;
PFNGLGENSAMPLERS_PROC *glpfGenSamplers = NULL;
PFNGLGETFRAGDATAINDEX_PROC *glpfGetFragDataIndex = NULL;
PFNGLGETQUERYOBJECTI64V_PROC *glpfGetQueryObjecti64v = NULL;
PFNGLGETQUERYOBJECTUI64V_PROC *glpfGetQueryObjectui64v = NULL;
PFNGLGETSAMPLERPARAMETERIIV_PROC *glpfGetSamplerParameterIiv = NULL;
PFNGLGETSAMPLERPARAMETERIUIV_PROC *glpfGetSamplerParameterIuiv = NULL;
PFNGLGETSAMPLERPARAMETERFV_PROC *glpfGetSamplerParameterfv = NULL;
PFNGLGETSAMPLERPARAMETERIV_PROC *glpfGetSamplerParameteriv = NULL;
PFNGLISSAMPLER_PROC *glpfIsSampler = NULL;
PFNGLQUERYCOUNTER_PROC *glpfQueryCounter = NULL;
PFNGLSAMPLERPARAMETERIIV_PROC *glpfSamplerParameterIiv = NULL;
PFNGLSAMPLERPARAMETERIUIV_PROC *glpfSamplerParameterIuiv = NULL;
PFNGLSAMPLERPARAMETERF_PROC *glpfSamplerParameterf = NULL;
PFNGLSAMPLERPARAMETERFV_PROC *glpfSamplerParameterfv = NULL;
PFNGLSAMPLERPARAMETERI_PROC *glpfSamplerParameteri = NULL;
PFNGLSAMPLERPARAMETERIV_PROC *glpfSamplerParameteriv = NULL;
PFNGLVERTEXATTRIBDIVISOR_PROC *glpfVertexAttribDivisor = NULL;
PFNGLVERTEXATTRIBP1UI_PROC *glpfVertexAttribP1ui = NULL;
PFNGLVERTEXATTRIBP1UIV_PROC *glpfVertexAttribP1uiv = NULL;
PFNGLVERTEXATTRIBP2UI_PROC *glpfVertexAttribP2ui = NULL;
PFNGLVERTEXATTRIBP2UIV_PROC *glpfVertexAttribP2uiv = NULL;
PFNGLVERTEXATTRIBP3UI_PROC *glpfVertexAttribP3ui = NULL;
PFNGLVERTEXATTRIBP3UIV_PROC *glpfVertexAttribP3uiv = NULL;
PFNGLVERTEXATTRIBP4UI_PROC *glpfVertexAttribP4ui = NULL;
PFNGLVERTEXATTRIBP4UIV_PROC *glpfVertexAttribP4uiv = NULL;

/* GL_VERSION_4_0 */

PFNGLBEGINQUERYINDEXED_PROC *glpfBeginQueryIndexed = NULL;
PFNGLBINDTRANSFORMFEEDBACK_PROC *glpfBindTransformFeedback = NULL;
PFNGLBLENDEQUATIONSEPARATEI_PROC *glpfBlendEquationSeparatei = NULL;
PFNGLBLENDEQUATIONI_PROC *glpfBlendEquationi = NULL;
PFNGLBLENDFUNCSEPARATEI_PROC *glpfBlendFuncSeparatei = NULL;
PFNGLBLENDFUNCI_PROC *glpfBlendFunci = NULL;
PFNGLDELETETRANSFORMFEEDBACKS_PROC *glpfDeleteTransformFeedbacks = NULL;
PFNGLDRAWARRAYSINDIRECT_PROC *glpfDrawArraysIndirect = NULL;
PFNGLDRAWELEMENTSINDIRECT_PROC *glpfDrawElementsIndirect = NULL;
PFNGLDRAWTRANSFORMFEEDBACK_PROC *glpfDrawTransformFeedback = NULL;
PFNGLDRAWTRANSFORMFEEDBACKSTREAM_PROC *glpfDrawTransformFeedbackStream = NULL;
PFNGLENDQUERYINDEXED_PROC *glpfEndQueryIndexed = NULL;
PFNGLGENTRANSFORMFEEDBACKS_PROC *glpfGenTransformFeedbacks = NULL;
PFNGLGETACTIVESUBROUTINENAME_PROC *glpfGetActiveSubroutineName = NULL;
PFNGLGETACTIVESUBROUTINEUNIFORMNAME_PROC *glpfGetActiveSubroutineUniformName = NULL;
PFNGLGETACTIVESUBROUTINEUNIFORMIV_PROC *glpfGetActiveSubroutineUniformiv = NULL;
PFNGLGETPROGRAMSTAGEIV_PROC *glpfGetProgramStageiv = NULL;
PFNGLGETQUERYINDEXEDIV_PROC *glpfGetQueryIndexediv = NULL;
PFNGLGETSUBROUTINEINDEX_PROC *glpfGetSubroutineIndex = NULL;
PFNGLGETSUBROUTINEUNIFORMLOCATION_PROC *glpfGetSubroutineUniformLocation = NULL;
PFNGLGETUNIFORMSUBROUTINEUIV_PROC *glpfGetUniformSubroutineuiv = NULL;
PFNGLGETUNIFORMDV_PROC *glpfGetUniformdv = NULL;
PFNGLISTRANSFORMFEEDBACK_PROC *glpfIsTransformFeedback = NULL;
PFNGLMINSAMPLESHADING_PROC *glpfMinSampleShading = NULL;
PFNGLPATCHPARAMETERFV_PROC *glpfPatchParameterfv = NULL;
PFNGLPATCHPARAMETERI_PROC *glpfPatchParameteri = NULL;
PFNGLPAUSETRANSFORMFEEDBACK_PROC *glpfPauseTransformFeedback = NULL;
PFNGLRESUMETRANSFORMFEEDBACK_PROC *glpfResumeTransformFeedback = NULL;
PFNGLUNIFORM1D_PROC *glpfUniform1d = NULL;
PFNGLUNIFORM1DV_PROC *glpfUniform1dv = NULL;
PFNGLUNIFORM2D_PROC *glpfUniform2d = NULL;
PFNGLUNIFORM2DV_PROC *glpfUniform2dv = NULL;
PFNGLUNIFORM3D_PROC *glpfUniform3d = NULL;
PFNGLUNIFORM3DV_PROC *glpfUniform3dv = NULL;
PFNGLUNIFORM4D_PROC *glpfUniform4d = NULL;
PFNGLUNIFORM4DV_PROC *glpfUniform4dv = NULL;
PFNGLUNIFORMMATRIX2DV_PROC *glpfUniformMatrix2dv = NULL;
PFNGLUNIFORMMATRIX2X3DV_PROC *glpfUniformMatrix2x3dv = NULL;
PFNGLUNIFORMMATRIX2X4DV_PROC *glpfUniformMatrix2x4dv = NULL;
PFNGLUNIFORMMATRIX3DV_PROC *glpfUniformMatrix3dv = NULL;
PFNGLUNIFORMMATRIX3X2DV_PROC *glpfUniformMatrix3x2dv = NULL;
PFNGLUNIFORMMATRIX3X4DV_PROC *glpfUniformMatrix3x4dv = NULL;
PFNGLUNIFORMMATRIX4DV_PROC *glpfUniformMatrix4dv = NULL;
PFNGLUNIFORMMATRIX4X2DV_PROC *glpfUniformMatrix4x2dv = NULL;
PFNGLUNIFORMMATRIX4X3DV_PROC *glpfUniformMatrix4x3dv = NULL;
PFNGLUNIFORMSUBROUTINESUIV_PROC *glpfUniformSubroutinesuiv = NULL;

/* GL_VERSION_4_1 */

PFNGLACTIVESHADERPROGRAM_PROC *glpfActiveShaderProgram = NULL;
PFNGLBINDPROGRAMPIPELINE_PROC *glpfBindProgramPipeline = NULL;
PFNGLCLEARDEPTHF_PROC *glpfClearDepthf = NULL;
PFNGLCREATESHADERPROGRAMV_PROC *glpfCreateShaderProgramv = NULL;
PFNGLDELETEPROGRAMPIPELINES_PROC *glpfDeleteProgramPipelines = NULL;
PFNGLDEPTHRANGEARRAYV_PROC *glpfDepthRangeArrayv = NULL;
PFNGLDEPTHRANGEINDEXED_PROC *glpfDepthRangeIndexed = NULL;
PFNGLDEPTHRANGEF_PROC *glpfDepthRangef = NULL;
PFNGLGENPROGRAMPIPELINES_PROC *glpfGenProgramPipelines = NULL;
PFNGLGETDOUBLEI_V_PROC *glpfGetDoublei_v = NULL;
PFNGLGETFLOATI_V_PROC *glpfGetFloati_v = NULL;
PFNGLGETPROGRAMBINARY_PROC *glpfGetProgramBinary = NULL;
PFNGLGETPROGRAMPIPELINEINFOLOG_PROC *glpfGetProgramPipelineInfoLog = NULL;
PFNGLGETPROGRAMPIPELINEIV_PROC *glpfGetProgramPipelineiv = NULL;
PFNGLGETSHADERPRECISIONFORMAT_PROC *glpfGetShaderPrecisionFormat = NULL;
PFNGLGETVERTEXATTRIBLDV_PROC *glpfGetVertexAttribLdv = NULL;
PFNGLISPROGRAMPIPELINE_PROC *glpfIsProgramPipeline = NULL;
PFNGLPROGRAMBINARY_PROC *glpfProgramBinary = NULL;
PFNGLPROGRAMPARAMETERI_PROC *glpfProgramParameteri = NULL;
PFNGLPROGRAMUNIFORM1D_PROC *glpfProgramUniform1d = NULL;
PFNGLPROGRAMUNIFORM1DV_PROC *glpfProgramUniform1dv = NULL;
PFNGLPROGRAMUNIFORM1F_PROC *glpfProgramUniform1f = NULL;
PFNGLPROGRAMUNIFORM1FV_PROC *glpfProgramUniform1fv = NULL;
PFNGLPROGRAMUNIFORM1I_PROC *glpfProgramUniform1i = NULL;
PFNGLPROGRAMUNIFORM1IV_PROC *glpfProgramUniform1iv = NULL;
PFNGLPROGRAMUNIFORM1UI_PROC *glpfProgramUniform1ui = NULL;
PFNGLPROGRAMUNIFORM1UIV_PROC *glpfProgramUniform1uiv = NULL;
PFNGLPROGRAMUNIFORM2D_PROC *glpfProgramUniform2d = NULL;
PFNGLPROGRAMUNIFORM2DV_PROC *glpfProgramUniform2dv = NULL;
PFNGLPROGRAMUNIFORM2F_PROC *glpfProgramUniform2f = NULL;
PFNGLPROGRAMUNIFORM2FV_PROC *glpfProgramUniform2fv = NULL;
PFNGLPROGRAMUNIFORM2I_PROC *glpfProgramUniform2i = NULL;
PFNGLPROGRAMUNIFORM2IV_PROC *glpfProgramUniform2iv = NULL;
PFNGLPROGRAMUNIFORM2UI_PROC *glpfProgramUniform2ui = NULL;
PFNGLPROGRAMUNIFORM2UIV_PROC *glpfProgramUniform2uiv = NULL;
PFNGLPROGRAMUNIFORM3D_PROC *glpfProgramUniform3d = NULL;
PFNGLPROGRAMUNIFORM3DV_PROC *glpfProgramUniform3dv = NULL;
PFNGLPROGRAMUNIFORM3F_PROC *glpfProgramUniform3f = NULL;
PFNGLPROGRAMUNIFORM3FV_PROC *glpfProgramUniform3fv = NULL;
PFNGLPROGRAMUNIFORM3I_PROC *glpfProgramUniform3i = NULL;
PFNGLPROGRAMUNIFORM3IV_PROC *glpfProgramUniform3iv = NULL;
PFNGLPROGRAMUNIFORM3UI_PROC *glpfProgramUniform3ui = NULL;
PFNGLPROGRAMUNIFORM3UIV_PROC *glpfProgramUniform3uiv = NULL;
PFNGLPROGRAMUNIFORM4D_PROC *glpfProgramUniform4d = NULL;
PFNGLPROGRAMUNIFORM4DV_PROC *glpfProgramUniform4dv = NULL;
PFNGLPROGRAMUNIFORM4F_PROC *glpfProgramUniform4f = NULL;
PFNGLPROGRAMUNIFORM4FV_PROC *glpfProgramUniform4fv = NULL;
PFNGLPROGRAMUNIFORM4I_PROC *glpfProgramUniform4i = NULL;
PFNGLPROGRAMUNIFORM4IV_PROC *glpfProgramUniform4iv = NULL;
PFNGLPROGRAMUNIFORM4UI_PROC *glpfProgramUniform4ui = NULL;
PFNGLPROGRAMUNIFORM4UIV_PROC *glpfProgramUniform4uiv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2DV_PROC *glpfProgramUniformMatrix2dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2FV_PROC *glpfProgramUniformMatrix2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X3DV_PROC *glpfProgramUniformMatrix2x3dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X3FV_PROC *glpfProgramUniformMatrix2x3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X4DV_PROC *glpfProgramUniformMatrix2x4dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX2X4FV_PROC *glpfProgramUniformMatrix2x4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3DV_PROC *glpfProgramUniformMatrix3dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3FV_PROC *glpfProgramUniformMatrix3fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X2DV_PROC *glpfProgramUniformMatrix3x2dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X2FV_PROC *glpfProgramUniformMatrix3x2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X4DV_PROC *glpfProgramUniformMatrix3x4dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX3X4FV_PROC *glpfProgramUniformMatrix3x4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4DV_PROC *glpfProgramUniformMatrix4dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4FV_PROC *glpfProgramUniformMatrix4fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X2DV_PROC *glpfProgramUniformMatrix4x2dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X2FV_PROC *glpfProgramUniformMatrix4x2fv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X3DV_PROC *glpfProgramUniformMatrix4x3dv = NULL;
PFNGLPROGRAMUNIFORMMATRIX4X3FV_PROC *glpfProgramUniformMatrix4x3fv = NULL;
PFNGLRELEASESHADERCOMPILER_PROC *glpfReleaseShaderCompiler = NULL;
PFNGLSCISSORARRAYV_PROC *glpfScissorArrayv = NULL;
PFNGLSCISSORINDEXED_PROC *glpfScissorIndexed = NULL;
PFNGLSCISSORINDEXEDV_PROC *glpfScissorIndexedv = NULL;
PFNGLSHADERBINARY_PROC *glpfShaderBinary = NULL;
PFNGLUSEPROGRAMSTAGES_PROC *glpfUseProgramStages = NULL;
PFNGLVALIDATEPROGRAMPIPELINE_PROC *glpfValidateProgramPipeline = NULL;
PFNGLVERTEXATTRIBL1D_PROC *glpfVertexAttribL1d = NULL;
PFNGLVERTEXATTRIBL1DV_PROC *glpfVertexAttribL1dv = NULL;
PFNGLVERTEXATTRIBL2D_PROC *glpfVertexAttribL2d = NULL;
PFNGLVERTEXATTRIBL2DV_PROC *glpfVertexAttribL2dv = NULL;
PFNGLVERTEXATTRIBL3D_PROC *glpfVertexAttribL3d = NULL;
PFNGLVERTEXATTRIBL3DV_PROC *glpfVertexAttribL3dv = NULL;
PFNGLVERTEXATTRIBL4D_PROC *glpfVertexAttribL4d = NULL;
PFNGLVERTEXATTRIBL4DV_PROC *glpfVertexAttribL4dv = NULL;
PFNGLVERTEXATTRIBLPOINTER_PROC *glpfVertexAttribLPointer = NULL;
PFNGLVIEWPORTARRAYV_PROC *glpfViewportArrayv = NULL;
PFNGLVIEWPORTINDEXEDF_PROC *glpfViewportIndexedf = NULL;
PFNGLVIEWPORTINDEXEDFV_PROC *glpfViewportIndexedfv = NULL;



#ifdef __cplusplus
}
#endif
