#pragma once
#ifndef __EMBER_MATRIX4_H
#define __EMBER_MATRIX4_H

/*
 * @file Matrix4.h
 * @author PJ O Halloran
 * @date 20/12/2016
 */

#include "core/EmberTypes.h"
#include "EmberMathUtils.h"
#include "Vector4.h"
#include "Vector3.h"
#include "Point3.h"

namespace ember
{
	namespace math
	{
		/*
		 * @class Matrix4
		 * @author PJ O Halloran
		 *
		 * This class represents a 4x4 Matrix stored in column major order.
		 *
		 * e.g. The matrix, M:
		 *  |m00    m10     m20     m30|
		 *  |m01    m11     m21     m31|
		 *  |m02    m12     m22     m32|
		 *  |m03    m13     m23     m33|
		 *
		 * is stored in a continuous area of memory as follows:
		 *  index   element
		 *  0       m00
		 *  1       m01
		 *  2       m02
		 *  3       m03
		 *  4       m10
		 *  5       m11
		 *  6       m12
		 *  7       m13
		 *  8       m20
		 *  9       m21
		 *  10      m22
		 *  11      m23
		 *  12      m30
		 *  13      m31
		 *  14      m32
		 *  15      m33
		 *
		 * To get the matrix in row major order for libraries other than OpenGL
		 * then you must get the transpose of the matrix.
		 */
		class Matrix4
		{
			public:
			
				/*
				 * @enum INDEX
				 *
				 * The index where a particular element may be found in the 1D array.
				 *
				 * Each entry has the naming convention Mcr where c is the index of
				 * the column and r is the index of the row (e.g. M00 refers to the
				 * element in the first column and first row).
				 *
				 * The NUMBER_ELEMENTS entry is the size of the array. Any index
				 * greater than NUMBER_ELEMENTS-1 will cause a runtime memory index
				 * access error.
				 */
				enum INDEX
				{
					M00 = 0,
					M01,
					M02,
					M03,
					M10,
					M11,
					M12,
					M13,
					M20,
					M21,
					M22,
					M23,
					M30,
					M31,
					M32,
					M33,
					NUMBER_ELEMENTS
				};
				
			private:
			
				F32 _mat[NUMBER_ELEMENTS];
				
				inline void GetColumnVectors( Vector4 &one, Vector4 &two, Vector4 &three, Vector4 &four ) const
				{
					one.Set( _mat[M00], _mat[M01], _mat[M02], _mat[M03] );
					two.Set( _mat[M10], _mat[M11], _mat[M12], _mat[M13] );
					three.Set( _mat[M20], _mat[M21], _mat[M22], _mat[M23] );
					four.Set( _mat[M30], _mat[M31], _mat[M32], _mat[M33] );
				}
				
				inline void GetRowVectors( Vector4 &one, Vector4 &two, Vector4 &three, Vector4 &four ) const
				{
					one.Set( _mat[M00], _mat[M10], _mat[M20], _mat[M30] );
					two.Set( _mat[M01], _mat[M11], _mat[M21], _mat[M31] );
					three.Set( _mat[M02], _mat[M12], _mat[M22], _mat[M32] );
					four.Set( _mat[M03], _mat[M13], _mat[M23], _mat[M33] );
				};
				
				/*
				 * Get a component of the determinant (Determinant helper function).
				 *
				 * N.B.
				 * This method was copied from the m3dInvertMatrix44 method from the
				 * OpenGL Superbible, 5th edition.
				 */
				F32 Det3x3( const I32 i, const I32 j ) const;
				
			public:
			
				explicit Matrix4();
				
				explicit Matrix4( const F32 scaler );
				
				explicit Matrix4( F32 matrixArr[NUMBER_ELEMENTS] );
				
				explicit Matrix4( const F32 m00, const F32 m10, const F32 m20, const F32 m30, \
				                  const F32 m01, const F32 m11, const F32 m21, const F32 m31, \
				                  const F32 m02, const F32 m12, const F32 m22, const F32 m32, \
				                  const F32 m03, const F32 m13, const F32 m23, const F32 m33 );
				                  
				/*
				 * Sets the elements according to the x, y and z direction vectors
				 * and the translation/location point.
				 *
				 * @param xDir Orientation of the x axis with respect to the eye
				 *              coordinate system.
				 * @param yDir Orientation of the y axis with respect to the eye
				 *              coordinate system.
				 * @param zDir Orientation of the z axis with respect to the eye
				 *              coordinate system.
				 * @param location The position with respect to the eye
				 *              coordinate system.
				 */
				explicit Matrix4( const Vector3 &xDir, const Vector3 &yDir, const Vector3 &zDir, const Point3 &location );
				
				Matrix4( const Matrix4 &matRef );
				
				~Matrix4() {};
				
				void LoadIdentity();
				
				void Zero();
				
				void Transpose();
				
				void Transposed( Matrix4 &outMatrix ) const;
				
				/*
				 * Return the determinant of this matrix.
				 * Uses Laplaces' expansion.
				 */
				F32 Determinant() const;
				
				/*
				 * Inverse this matrix.
				 * Method used depends on the define flags used to compile
				 * the lib (laplace or cramer).
				 *
				 * @return bool Some matrices do not have an inverse. A simple way of
				 *              detemining this is that the matrix has an inverse if
				 *              its determinant is not equal to 0.  As a result we will
				 *              return true if the matrix has an inverse and false if
				 *              not.
				 */
				bool Inverse();
				
				/*
				 * Return the inverse of this matrix.
				 * Method used depends on the define flags used to compile
				 * the lib (laplace or cramer).
				 *
				 * @return bool Some matrices do not have an inverse. A simple way of
				 *              detemining this is that the matrix has an inverse if
				 *              its determinant is not equal to 0.  As a result we will
				 *              return true if the matrix has an inverse and false if
				 *              not.
				 */
				bool Inversed( Matrix4 &outMatrix ) const;
				
				Matrix4 operator*( const Matrix4 &rhs ) const;
				
				Matrix4 &operator*=( const Matrix4 &rhs );
				
				Vector4 operator*( const Vector4 &rhs ) const;
				
				Matrix4 &operator=( const Matrix4 &rhs );
				
				inline F32 &operator []( const I32 index )
				{
					return _mat[index];
				};
				
				inline F32 operator []( I32 index ) const
				{
					return _mat[index];
				};
				
				#ifdef EMBER_MATH_TO_STRING
				inline std::string ToString() const
				{
					std::stringstream conv;
					conv << "|\t" << _mat[M00] << "\t" << _mat[M10] << "\t" << _mat[M20] << "\t" << _mat[M30] << "\t|\n";
					conv << "|\t" << _mat[M01] << "\t" << _mat[M11] << "\t" << _mat[M21] << "\t" << _mat[M31] << "\t|\n";
					conv << "|\t" << _mat[M02] << "\t" << _mat[M12] << "\t" << _mat[M22] << "\t" << _mat[M32] << "\t|\n";
					conv << "|\t" << _mat[M03] << "\t" << _mat[M13] << "\t" << _mat[M23] << "\t" << _mat[M33] << "\t|";
					return conv.str();
				};
				#else
				inline const char *ToString() const
				{
					return "";
				};
				#endif
				
				inline const F32 *const GetComponentsConst() const
				{
					return _mat;
				};
				
				inline void GetPosition( Vector4 &pos ) const
				{
					pos.Set( _mat[M30], _mat[M31], _mat[M32], _mat[M33] );
				};
				
				inline void SetPosition( const Vector4 &pos )
				{
					_mat[M30] = pos.X();
					_mat[M31] = pos.Y();
					_mat[M32] = pos.Z();
					_mat[M33] = pos.W();
				};
				
				inline void GetPosition( Point3 &pos ) const
				{
					Vector4 pos4;
					GetPosition( pos4 );
					
					if ( !Compare( pos4.W(), 0.0f ) )
					{
						pos.SetX( pos4.X() / pos4.W() );
						pos.SetY( pos4.Y() / pos4.W() );
						pos.SetZ( pos4.Z() / pos4.W() );
					}
					else
					{
						pos.SetX( pos4.X() );
						pos.SetY( pos4.Y() );
						pos.SetZ( pos4.Z() );
					}
				};
				
				inline void SetPosition( const Point3 &pos )
				{
					_mat[M30] = pos.X();
					_mat[M31] = pos.Y();
					_mat[M32] = pos.Z();
					_mat[M33] = 1.0f;
				};
				
				inline void XDir( Vector4 &xDir ) const
				{
					xDir.Set( _mat[M00], _mat[M01], _mat[M02], _mat[M03] );
				};
				
				inline void SetXDir( const Vector4 &xDir )
				{
					_mat[M00] = xDir.X();
					_mat[M01] = xDir.Y();
					_mat[M02] = xDir.Z();
					_mat[M03] = xDir.W();
				};
				
				inline void YDir( Vector4 &yDir ) const
				{
					yDir.Set( _mat[M10], _mat[M11], _mat[M12], _mat[M13] );
				};
				
				inline void SetYDir( const Vector4 &yDir )
				{
					_mat[M10] = yDir.X();
					_mat[M11] = yDir.Y();
					_mat[M12] = yDir.Z();
					_mat[M13] = yDir.W();
				};
				
				inline void ZDir( Vector4 &zDir ) const
				{
					zDir.Set( _mat[M20], _mat[M21], _mat[M22], _mat[M23] );
				};
				
				inline void SetZDir( const Vector4 &zDir )
				{
					_mat[M20] = zDir.X();
					_mat[M21] = zDir.Y();
					_mat[M22] = zDir.Z();
					_mat[M23] = zDir.W();
				};
				
				inline void Set( const F32 *elementsArr )
				{
					memcpy( _mat, elementsArr, sizeof( F32 ) * NUMBER_ELEMENTS );
				};
				
				inline bool operator==( const Matrix4 &rhs ) const
				{
					// Optimization for when you compare a matrix to itself.
					if ( this == &rhs )
					{
						return true;
					}
					
					for ( U32 i = 0; i < NUMBER_ELEMENTS; ++i )
					{
						if ( !Compare( _mat[i], rhs._mat[i] ) )
						{
							return false;
						}
					}
					
					return true;
				};
				
				inline bool operator !=( const Matrix4 &rhs ) const
				{
					return !( *this == rhs );
				};
				
		};
		
		extern const Matrix4 IdentityMatrix;
		extern const Matrix4 ZeroMatrix;
		
		/*
		 * Build a rotation MOVE matrix.
		 *
		 * This may be used to rotate about an arbitrary axis.
		 *
		 * Please note that this method assumes a RIGHT hand coordinate
		 * system.
		 *
		 * @param angle The angle in degrees to rotate by.
		 * @param axis The axis to rotate around.
		 * @param outMatrix The matrix to store the result in.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildRotationArbitraryMatrix4( const F32 angle, const Vector3 &axis, Matrix4 &outMatrix );
		
		/*
		 * Build a rotation MOVE matrix about the X axis.
		 *
		 * Runs faster than calling the arbituary version with an X unit
		 * vector as only the absolutely required calculations to determine
		 * the rotation matrix are performed.  The XYZ rotation matrices are
		 * well known.
		 *
		 * Please note that this method assumes a RIGHT hand coordinate
		 * system.
		 *
		 * @param angle The angle in degrees to rotate by.
		 * @param outMatrix The matrix to store the result in.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildRotationXMatrix4( const F32 angle, Matrix4 &outMatrix );
		
		/*
		 * Build a rotation MOVE matrix about the Y axis.
		 *
		 * Runs faster than calling the arbituary version with an Y unit
		 * vector as only the absolutely required calculations to determine
		 * the rotation matrix are performed.  The XYZ rotation matrices are
		 * well known.
		 *
		 * Please note that this method assumes a RIGHT hand coordinate
		 * system.
		 *
		 * @param angle The angle in degrees to rotate by.
		 * @param outMatrix The matrix to store the result in.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildRotationYMatrix4( const F32 angle, Matrix4 &outMatrix );
		
		/*
		 * Build a rotation MOVE matrix about the Z axis.
		 *
		 * Runs faster than calling the arbituary version with an Z unit
		 * vector as only the absolutely required calculations to determine
		 * the rotation matrix are performed.  The XYZ rotation matrices are
		 * well known.
		 *
		 * Please note that this method assumes a RIGHT hand coordinate
		 * system.
		 *
		 * @param angle The angle in degrees to rotate by.
		 * @param outMatrix The matrix to store the result in.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildRotationZMatrix4( const F32 angle, Matrix4 &outMatrix );
		
		/*
		 * Build a translation MOVE matrix.
		 *
		 * @param pos The new position.
		 * @param outMatrix The matrix to store the result in.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildTranslationMatrix4( const Point3 &pos, Matrix4 &outMatrix );
		
		/*
		 * Build a scale MOVE matrix.
		 *
		 * The scale is performed with respect to the origin.
		 *
		 * @param scale The scale.
		 * @param outMatrix The matrix to store the result in.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildScaleMatrix4( const Vector3 &scale, Matrix4 &outMatrix );
		
		/*
		 * Build a scale MOVE matrix.
		 *
		 * The scale is performed with respect to some arbitrary point.
		 *
		 * @param scale The scale.
		 * @param pt The point in 3D space with which the scale operation
		 *              should be relative to.
		 * @param outMatrix The matrix to store the result in.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildScaleArbitraryMatrix4( const Vector3 &scale, const Point3 &pos, Matrix4 &outMatrix );
		
		/*
		 * Build a look at VIEW matrix.
		 *
		 * This look at VIEW matrix assumes a right-hand coordinate
		 * system.  That is the positive X axis to the right, the positive Y
		 * axis going up and the positive Z axis coming towards the screen
		 * (i.e. We are looking down the negative Z axis).
		 *
		 * @param eyePos The position in world space of the lens/eye.
		 * @param atPos The position in world space for the eye/lens to focus upon.
		 * @param upVec The direction of UP in the world (e.g. sometimes its the y axis or unit vector on the Y axis).
		 * @param outMatrix The matrix to store the result in.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildLookAt( const Point3 &eyePos, const Point3 &atPos, const Vector3 &upVec, Matrix4 &outMatrix );
		
		/*
		 * Build a perspective PROJECTION matrix.
		 *
		 * This perspective projection matrix assumes a right-hand coordinate
		 * system.  That is the positive X axis to the right, the positive Y
		 * axis going up and the positive Z axis coming towards the screen
		 * (i.e. We are looking down the negative Z axis).
		 *
		 * @param outMatrix The matrix to store the result in.
		 * @param fov The angle or field of view.
		 * @param aspect The screen aspect ratio.
		 * @param zNear The location of the near clipping plane.
		 * @param zFar The location of the far clipping plane.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildPerspectiveFov( const F32 fov, const F32 aspect, const F32 zNear, const F32 zFar, Matrix4 &outMatrix );
		
		/*
		 * Build an orthographic PROJECTION matrix.
		 *
		 * This orthographic projection matrix assumes a right-hand coordinate
		 * system.  That is the positive X axis to the right, the positive Y
		 * axis going up and the positive Z axis coming towards the screen
		 * (i.e. We are looking down the negative Z axis).
		 *
		 * @param xMin The minimum X plane.
		 * @param xMax The maximum X plane.
		 * @param yMin Minimum Y plane.
		 * @param yMax Maximum Y plane.
		 * @param zMin Minimum Z plane.
		 * @param zMax Maximum Z plane.
		 * @param outMatrix The matrix to store the result in.
		 *
		 * @return Matrix4& The output matrix.
		 */
		Matrix4 &BuildOrthographic( const F32 xMin, const F32 xMax, const F32 yMin, const F32 yMax, const F32 zMin, const F32 zMax, Matrix4 &outMatrix );
		
		/*
		 * Extract the rotation matrix from a Matrix4.
		 *
		 */
		void ExtractRotationMatrix( const Matrix4 &matrix, Matrix3x3 rotMatArr );
	}
}

#endif
