/*
 * @file Matrix.cpp
 * @author PJ O Halloran
 * @date 20/12/2016
 */

#include "Matrix4.h"

namespace ember
{
	namespace math
	{
		const Matrix4 IdentityMatrix( 1.0f, 0.0f, 0.0f, 0.0f, \
		                              0.0f, 1.0f, 0.0f, 0.0f, \
		                              0.0f, 0.0f, 1.0f, 0.0f, \
		                              0.0f, 0.0f, 0.0f, 1.0f );
		const Matrix4 ZeroMatrix( 0.0f );
		
		Matrix4::Matrix4()
		{
			memset( _mat, 0, sizeof( F32 ) * NUMBER_ELEMENTS );
		}
		
		Matrix4::Matrix4( const F32 scaler )
		{
			for ( I32 i = 0; i < NUMBER_ELEMENTS; ++i )
			{
				_mat[i] = scaler;
			}
		}
		
		Matrix4::Matrix4( const F32 matrixArr[NUMBER_ELEMENTS] )
		{
			Set( matrixArr );
		}
		
		Matrix4::Matrix4( const F32 m00, const F32 m10, const F32 m20, const F32 m30, \
		                  const F32 m01, const F32 m11, const F32 m21, const F32 m31, \
		                  const F32 m02, const F32 m12, const F32 m22, const F32 m32, \
		                  const F32 m03, const F32 m13, const F32 m23, const F32 m33 )
		{
			_mat[M00] = m00;
			_mat[M10] = m10;
			_mat[M20] = m20;
			_mat[M30] = m30;
			_mat[M01] = m01;
			_mat[M11] = m11;
			_mat[M21] = m21;
			_mat[M31] = m31;
			_mat[M02] = m02;
			_mat[M12] = m12;
			_mat[M22] = m22;
			_mat[M32] = m32;
			_mat[M03] = m03;
			_mat[M13] = m13;
			_mat[M23] = m23;
			_mat[M33] = m33;
		}
		
		Matrix4::Matrix4( const Vector3 &xDir, const Vector3 &yDir, const Vector3 &zDir, const Point3 &location )
		{
			_mat[M00] = xDir.X();
			_mat[M10] = yDir.X();
			_mat[M20] = zDir.X();
			_mat[M30] = location.X();
			_mat[M01] = xDir.Y();
			_mat[M11] = yDir.Y();
			_mat[M21] = zDir.Y();
			_mat[M31] = location.Y();
			_mat[M02] = xDir.Z();
			_mat[M12] = yDir.Z();
			_mat[M22] = zDir.Z();
			_mat[M32] = location.Z();
			_mat[M03] = 0.0f;
			_mat[M13] = 0.0f;
			_mat[M23] = 0.0f;
			_mat[M33] = 1.0f;
		}
		
		Matrix4::Matrix4( const Matrix4 &matRef )
		{
			Set( matRef._mat );
		}
		
		void Matrix4::LoadIdentity()
		{
			Set( IdentityMatrix._mat );
		}
		
		void Matrix4::Zero()
		{
			Set( ZeroMatrix._mat );
		}
		
		void Matrix4::Transpose()
		{
			Matrix4 tmp;
			Transposed( tmp );
			Set( tmp._mat );
		}
		
		void Matrix4::Transposed( Matrix4 &outMatrix ) const
		{
			outMatrix._mat[M00] = _mat[M00];
			outMatrix._mat[M10] = _mat[M01];
			outMatrix._mat[M20] = _mat[M02];
			outMatrix._mat[M30] = _mat[M03];
			outMatrix._mat[M01] = _mat[M10];
			outMatrix._mat[M11] = _mat[M11];
			outMatrix._mat[M21] = _mat[M12];
			outMatrix._mat[M31] = _mat[M13];
			outMatrix._mat[M02] = _mat[M20];
			outMatrix._mat[M12] = _mat[M21];
			outMatrix._mat[M22] = _mat[M22];
			outMatrix._mat[M32] = _mat[M23];
			outMatrix._mat[M03] = _mat[M30];
			outMatrix._mat[M13] = _mat[M31];
			outMatrix._mat[M23] = _mat[M32];
			outMatrix._mat[M33] = _mat[M33];
		}
		
		F32 Matrix4::Det3x3( const I32 i, const I32 j ) const
		{
			I32 x, y;
			F32 ret, mat[3][3];
			
			// Create a 3x3 cofactor matrix (not including any elements from
			//  the i and j row and colums).
			x = 0;
			
			for ( I32 ii = 0; ii < 4; ++ii )
			{
				if ( ii != i )
				{
					y = 0;
					
					for ( I32 jj = 0; jj < 4; ++jj )
					{
						if ( jj != j )
						{
							mat[x][y] = _mat[( ii * 4 ) + jj];
							++y;
						}
					}
					
					++x;
				}
			}
			
			// See Fundamentals of Computer Graphics Third Edition,
			// Chapter 5 Linear Algebra for a full description of the
			// following formula.
			//
			// Briefly, the formula for calculating the determinant of
			// a 3x3 matrix:
			//      | a b c |
			// A =  | d e f |
			//      | g h i |
			// Cofactor matrices about the first row are:
			//      |e f|           |d f|           |d e|
			// aC = |h i|   bC =    |g i|   cC =    |g h|
			//
			// so the formula to get the determinant of A is (|A|)...
			// |A| = a.|aC| - b.|bC| + c.|cC|
			//
			// We know how to get the determinant of a 2x2 matrix from
			// the formula a.d - c.b where the 2x2 matrix is:
			//      |a b|
			//      |c d|
			// so it is easy to calculate the determinant of a 3x3 matrix.
			// and recursively matrices of higher dimensions may therefore
			// be calculated also using the same technique.  The algorithm
			// in this method only applies to 4x4 matrices as thats all
			// we need.
			//
			ret =  mat[0][0] * ( mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2] );
			ret -= mat[0][1] * ( mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2] );
			ret += mat[0][2] * ( mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1] );
			
			return ret;
		}
		
		F32 Matrix4::Determinant() const
		{
			F32 det = 0.0f;
			
			// calculate 4x4 determinant
			for ( I32 i = 0; i < 4; ++i )
			{
				det += ( i & 0x1 ) ? ( -_mat[i] * Det3x3( 0, i ) ) : ( _mat[i] * Det3x3( 0, i ) );
			}
			
			return det;
		}
		
		bool Matrix4::Inverse()
		{
			Matrix4 tmp;
			bool hasInverse = Inversed( tmp );
			
			if ( hasInverse )
			{
				*this = tmp;
			}
			
			return hasInverse;
		}
		
		bool Matrix4::Inversed( Matrix4 &outMatrix ) const
		{
			#ifdef EMBER_MATRIX_USE_CRAMER_INVERSE
		
			F32 tmp[12];
			F32 det = 0.0f;
			Matrix4 t( *this );
			t.Transpose();
			
			/* calculate pairs for first 8 elements (cofactors) */
			tmp[0] = t[10] * t[15];
			tmp[1] = t[11] * t[14];
			tmp[2] = t[9] * t[15];
			tmp[3] = t[11] * t[13];
			tmp[4] = t[9] * t[14];
			tmp[5] = t[10] * t[13];
			tmp[6] = t[8] * t[15];
			tmp[7] = t[11] * t[12];
			tmp[8] = t[8] * t[14];
			tmp[9] = t[10] * t[12];
			tmp[10] = t[8] * t[13];
			tmp[11] = t[9] * t[12];
			
			/* calculate first 8 elements (cofactors) */
			outMatrix[0] = tmp[0] * t[5] + tmp[3] * t[6] + tmp[4] * t[7];
			outMatrix[0] -= tmp[1] * t[5] + tmp[2] * t[6] + tmp[5] * t[7];
			outMatrix[1] = tmp[1] * t[4] + tmp[6] * t[6] + tmp[9] * t[7];
			outMatrix[1] -= tmp[0] * t[4] + tmp[7] * t[6] + tmp[8] * t[7];
			outMatrix[2] = tmp[2] * t[4] + tmp[7] * t[5] + tmp[10] * t[7];
			outMatrix[2] -= tmp[3] * t[4] + tmp[6] * t[5] + tmp[11] * t[7];
			outMatrix[3] = tmp[5] * t[4] + tmp[8] * t[5] + tmp[11] * t[6];
			outMatrix[3] -= tmp[4] * t[4] + tmp[9] * t[5] + tmp[10] * t[6];
			outMatrix[4] = tmp[1] * t[1] + tmp[2] * t[2] + tmp[5] * t[3];
			outMatrix[4] -= tmp[0] * t[1] + tmp[3] * t[2] + tmp[4] * t[3];
			outMatrix[5] = tmp[0] * t[0] + tmp[7] * t[2] + tmp[8] * t[3];
			outMatrix[5] -= tmp[1] * t[0] + tmp[6] * t[2] + tmp[9] * t[3];
			outMatrix[6] = tmp[3] * t[0] + tmp[6] * t[1] + tmp[11] * t[3];
			outMatrix[6] -= tmp[2] * t[0] + tmp[7] * t[1] + tmp[10] * t[3];
			outMatrix[7] = tmp[4] * t[0] + tmp[9] * t[1] + tmp[10] * t[2];
			outMatrix[7] -= tmp[5] * t[0] + tmp[8] * t[1] + tmp[11] * t[2];
			
			/* calculate pairs for second 8 elements (cofactors) */
			tmp[0] = t[2] * t[7];
			tmp[1] = t[3] * t[6];
			tmp[2] = t[1] * t[7];
			tmp[3] = t[3] * t[5];
			tmp[4] = t[1] * t[6];
			tmp[5] = t[2] * t[5];
			tmp[6] = t[0] * t[7];
			tmp[7] = t[3] * t[4];
			tmp[8] = t[0] * t[6];
			tmp[9] = t[2] * t[4];
			tmp[10] = t[0] * t[5];
			tmp[11] = t[1] * t[4];
			
			/* calculate second 8 elements (cofactors) */
			outMatrix[8] = tmp[0] * t[13] + tmp[3] * t[14] + tmp[4] * t[15];
			outMatrix[8] -= tmp[1] * t[13] + tmp[2] * t[14] + tmp[5] * t[15];
			outMatrix[9] = tmp[1] * t[12] + tmp[6] * t[14] + tmp[9] * t[15];
			outMatrix[9] -= tmp[0] * t[12] + tmp[7] * t[14] + tmp[8] * t[15];
			outMatrix[10] = tmp[2] * t[12] + tmp[7] * t[13] + tmp[10] * t[15];
			outMatrix[10] -= tmp[3] * t[12] + tmp[6] * t[13] + tmp[11] * t[15];
			outMatrix[11] = tmp[5] * t[12] + tmp[8] * t[13] + tmp[11] * t[14];
			outMatrix[11] -= tmp[4] * t[12] + tmp[9] * t[13] + tmp[10] * t[14];
			outMatrix[12] = tmp[2] * t[10] + tmp[5] * t[11] + tmp[1] * t[9];
			outMatrix[12] -= tmp[4] * t[11] + tmp[0] * t[9] + tmp[3] * t[10];
			outMatrix[13] = tmp[8] * t[11] + tmp[0] * t[8] + tmp[7] * t[10];
			outMatrix[13] -= tmp[6] * t[10] + tmp[9] * t[11] + tmp[1] * t[8];
			outMatrix[14] = tmp[6] * t[9] + tmp[11] * t[11] + tmp[3] * t[8];
			outMatrix[14] -= tmp[10] * t[11] + tmp[2] * t[8] + tmp[7] * t[9];
			outMatrix[15] = tmp[10] * t[10] + tmp[4] * t[8] + tmp[9] * t[9];
			outMatrix[15] -= tmp[8] * t[9] + tmp[11] * t[10] + tmp[5] * t[8];
			
			/* calculate determinant */
			det = t[0] * outMatrix[0] + t[1] * outMatrix[1] + t[2] * outMatrix[2] + t[3] * outMatrix[3];
			
			/* calculate matrix inverse */
			det = 1 / det;
			
			for ( I32 j = 0; j < 16; ++j )
			{
				outMatrix[j] *= det;
			}
			
			return true;
			
			#else
			
			F32 det = Determinant(), detij = 0.0f;
			bool hasInverse = !Compare( det, 0.0f );
			
			if ( hasInverse )
			{
				F32 oneDet = 1.0f / det;
			
				for ( I32 i = 0; i < 4; ++i )
				{
					for ( I32 j = 0; j < 4; ++j )
					{
						detij = Det3x3( j, i );
						outMatrix._mat[( i * 4 ) + j] = ( ( i + j ) & 0x1 ) ? ( -detij * oneDet ) : ( detij * oneDet );
					}
				}
			}
			
			return hasInverse;
			
			#endif
		}
		
		Matrix4 Matrix4::operator*( const Matrix4 &rhs ) const
		{
			Matrix4 outMatrix;
			outMatrix[M00] = ( _mat[M00] * rhs._mat[M00] ) + ( _mat[M10] * rhs._mat[M01] ) + ( _mat[M20] * rhs._mat[M02] ) + ( _mat[M30] * rhs._mat[M03] );
			outMatrix[M10] = ( _mat[M00] * rhs._mat[M10] ) + ( _mat[M10] * rhs._mat[M11] ) + ( _mat[M20] * rhs._mat[M12] ) + ( _mat[M30] * rhs._mat[M13] );
			outMatrix[M20] = ( _mat[M00] * rhs._mat[M20] ) + ( _mat[M10] * rhs._mat[M21] ) + ( _mat[M20] * rhs._mat[M22] ) + ( _mat[M30] * rhs._mat[M23] );
			outMatrix[M30] = ( _mat[M00] * rhs._mat[M30] ) + ( _mat[M10] * rhs._mat[M31] ) + ( _mat[M20] * rhs._mat[M32] ) + ( _mat[M30] * rhs._mat[M33] );
			
			outMatrix[M01] = ( _mat[M01] * rhs._mat[M00] ) + ( _mat[M11] * rhs._mat[M01] ) + ( _mat[M21] * rhs._mat[M02] ) + ( _mat[M31] * rhs._mat[M03] );
			outMatrix[M11] = ( _mat[M01] * rhs._mat[M10] ) + ( _mat[M11] * rhs._mat[M11] ) + ( _mat[M21] * rhs._mat[M12] ) + ( _mat[M31] * rhs._mat[M13] );
			outMatrix[M21] = ( _mat[M01] * rhs._mat[M20] ) + ( _mat[M11] * rhs._mat[M21] ) + ( _mat[M21] * rhs._mat[M22] ) + ( _mat[M31] * rhs._mat[M23] );
			outMatrix[M31] = ( _mat[M01] * rhs._mat[M30] ) + ( _mat[M11] * rhs._mat[M31] ) + ( _mat[M21] * rhs._mat[M32] ) + ( _mat[M31] * rhs._mat[M33] );
			
			outMatrix[M02] = ( _mat[M02] * rhs._mat[M00] ) + ( _mat[M12] * rhs._mat[M01] ) + ( _mat[M22] * rhs._mat[M02] ) + ( _mat[M32] * rhs._mat[M03] );
			outMatrix[M12] = ( _mat[M02] * rhs._mat[M10] ) + ( _mat[M12] * rhs._mat[M11] ) + ( _mat[M22] * rhs._mat[M12] ) + ( _mat[M32] * rhs._mat[M13] );
			outMatrix[M22] = ( _mat[M02] * rhs._mat[M20] ) + ( _mat[M12] * rhs._mat[M21] ) + ( _mat[M22] * rhs._mat[M22] ) + ( _mat[M32] * rhs._mat[M23] );
			outMatrix[M32] = ( _mat[M02] * rhs._mat[M30] ) + ( _mat[M12] * rhs._mat[M31] ) + ( _mat[M22] * rhs._mat[M32] ) + ( _mat[M32] * rhs._mat[M33] );
			
			outMatrix[M03] = ( _mat[M03] * rhs._mat[M00] ) + ( _mat[M13] * rhs._mat[M01] ) + ( _mat[M23] * rhs._mat[M02] ) + ( _mat[M33] * rhs._mat[M03] );
			outMatrix[M13] = ( _mat[M03] * rhs._mat[M10] ) + ( _mat[M13] * rhs._mat[M11] ) + ( _mat[M23] * rhs._mat[M12] ) + ( _mat[M33] * rhs._mat[M13] );
			outMatrix[M23] = ( _mat[M03] * rhs._mat[M20] ) + ( _mat[M13] * rhs._mat[M21] ) + ( _mat[M23] * rhs._mat[M22] ) + ( _mat[M33] * rhs._mat[M23] );
			outMatrix[M33] = ( _mat[M03] * rhs._mat[M30] ) + ( _mat[M13] * rhs._mat[M31] ) + ( _mat[M23] * rhs._mat[M32] ) + ( _mat[M33] * rhs._mat[M33] );
			
			return ( outMatrix );
		}
		
		Matrix4 &Matrix4::operator*=( const Matrix4 &rhs )
		{
			*this = *this * rhs;
			return *this;
		}
		
		Vector4 Matrix4::operator*( const Vector4 &rhs ) const
		{
			F32 x = _mat[M00] * rhs.X() + _mat[M10] * rhs.Y() + _mat[M20] * rhs.Z() + _mat[M30] * rhs.W();
			F32 y = _mat[M01] * rhs.X() + _mat[M11] * rhs.Y() + _mat[M21] * rhs.Z() + _mat[M31] * rhs.W();
			F32 z = _mat[M02] * rhs.X() + _mat[M12] * rhs.Y() + _mat[M22] * rhs.Z() + _mat[M32] * rhs.W();
			F32 w = _mat[M03] * rhs.X() + _mat[M13] * rhs.Y() + _mat[M23] * rhs.Z() + _mat[M33] * rhs.W();
			
			return Vector4( x, y, z, w );
		}
		
		Matrix4 &Matrix4::operator=( const Matrix4 &rhs )
		{
			Set( rhs._mat );
			return *this;
		}
		
		Matrix4 &BuildRotationArbitraryMatrix4( const F32 angle, const Vector3 &axis, Matrix4 &outMatrix )
		{
			Vector3 rotationVec( axis );
			
			if ( rotationVec.Magnitude() == 0.0f )
			{
				outMatrix.LoadIdentity();
				return outMatrix;
			}
			
			const F32 radians = F32( DegreesToRadians( angle ) );
			const F32 sinAngle = F32( sin( radians ) );
			const F32 cosAngle = F32( cos( radians ) );
			
			rotationVec.Normalize();
			
			// Build up the components used to assemble the rotation matrix.
			// For explanation of the formula used to generate this matrix,
			// please see Mathematics for Computer Graphics by John Vince,
			// Second Edition, Chapter 7 Transformations, pg 83.
			//
			const F32 xy = rotationVec.X() * rotationVec.Y();
			const F32 yz = rotationVec.Y() * rotationVec.Z();
			const F32 zx = rotationVec.Z() * rotationVec.X();
			const F32 xs = rotationVec.X() * sinAngle;
			const F32 ys = rotationVec.Y() * sinAngle;
			const F32 zs = rotationVec.Z() * sinAngle;
			const F32 one_c = 1.0f - cosAngle;
			const F32 m00 = ( one_c * ( rotationVec.X() * rotationVec.X() ) ) + cosAngle;
			const F32 m01 = ( one_c * xy ) + zs;
			const F32 m02 = ( one_c * zx ) - ys;
			const F32 m10 = ( one_c * xy ) - zs;
			const F32 m11 = ( one_c * ( rotationVec.Y() * rotationVec.Y() ) ) + cosAngle;
			const F32 m12 = ( one_c * yz ) + xs;
			const F32 m20 = ( one_c * zx ) + ys;
			const F32 m21 = ( one_c * yz ) - xs;
			const F32 m22 = ( one_c * ( rotationVec.Z() * rotationVec.Z() ) ) + cosAngle;
			
			outMatrix = Matrix4( m00,    m10,    m20,    0.0f, \
			                     m01,    m11,    m21,    0.0f, \
			                     m02,    m12,    m22,    0.0f, \
			                     0.0f,   0.0f,   0.0f,   1.0f );
			                     
			return outMatrix;
		}
		
		Matrix4 &BuildRotationXMatrix4( const F32 angle, Matrix4 &outMatrix )
		{
			const F32 radians = F32( DegreesToRadians( angle ) );
			const F32 sinAngle = F32( sin( radians ) );
			const F32 cosAngle = F32( cos( radians ) );
			
			outMatrix.LoadIdentity();
			
			outMatrix[Matrix4::M11] = cosAngle;
			outMatrix[Matrix4::M12] = sinAngle;
			outMatrix[Matrix4::M21] = -sinAngle;
			outMatrix[Matrix4::M22] = cosAngle;
			
			return outMatrix;
		}
		
		Matrix4 &BuildRotationYMatrix4( const F32 angle, Matrix4 &outMatrix )
		{
			const F32 radians = F32( DegreesToRadians( angle ) );
			const F32 sinAngle = F32( sin( radians ) );
			const F32 cosAngle = F32( cos( radians ) );
			
			outMatrix.LoadIdentity();
			
			outMatrix[Matrix4::M00] = cosAngle;
			outMatrix[Matrix4::M20] = sinAngle;
			outMatrix[Matrix4::M02] = -sinAngle;
			outMatrix[Matrix4::M22] = cosAngle;
			
			return outMatrix;
		}
		
		Matrix4 &BuildRotationZMatrix4( const F32 angle, Matrix4 &outMatrix )
		{
			const F32 radians = F32( DegreesToRadians( angle ) );
			const F32 sinAngle = F32( sin( radians ) );
			const F32 cosAngle = F32( cos( radians ) );
			
			outMatrix.LoadIdentity();
			
			outMatrix[Matrix4::M00] = cosAngle;
			outMatrix[Matrix4::M10] = -sinAngle;
			outMatrix[Matrix4::M01] = sinAngle;
			outMatrix[Matrix4::M11] = cosAngle;
			
			return ( outMatrix );
		}
		
		Matrix4 &BuildTranslationMatrix4( const Point3 &pos, Matrix4 &outMatrix )
		{
			outMatrix.LoadIdentity();
			
			outMatrix[Matrix4::M30] = pos.X();
			outMatrix[Matrix4::M31] = pos.Y();
			outMatrix[Matrix4::M32] = pos.Z();
			
			return outMatrix;
		}
		
		Matrix4 &BuildScaleMatrix4( const Vector3 &scale, Matrix4 &outMatrix )
		{
			outMatrix.LoadIdentity();
			
			outMatrix[Matrix4::M00] = scale.X();
			outMatrix[Matrix4::M11] = scale.Y();
			outMatrix[Matrix4::M22] = scale.Z();
			
			return outMatrix;
		}
		
		Matrix4 &BuildScaleArbitraryMatrix4( const Vector3 &scale, const Point3 &pos, Matrix4 &outMatrix )
		{
			outMatrix = BuildScaleMatrix4( scale, outMatrix );
			
			outMatrix[Matrix4::M30] = pos.X() * ( 1.0f - scale.X() );
			outMatrix[Matrix4::M31] = pos.Y() * ( 1.0f - scale.Y() );
			outMatrix[Matrix4::M32] = pos.Z() * ( 1.0f - scale.Z() );
			
			return outMatrix;
		}
		
		Matrix4 &BuildLookAt( const Point3 &eyePos, const Point3 &atPos, const Vector3 &upVec, Matrix4 &outMatrix )
		{
			// Get a vector pointing in the same direction as the camera.
			Vector3 dirVec = atPos - eyePos;
			dirVec.Normalize();
			
			// Ensure the UP vector is a normalized one.
			Vector3 upVecCopy( upVec );
			upVecCopy.Normalize();
			
			Vector3 s;
			dirVec.Cross( upVecCopy, s );
			Vector3 u;
			s.Cross( dirVec, u );
			
			// Row 1
			outMatrix[Matrix4::M00] = s.X();
			outMatrix[Matrix4::M01] = s.Y();
			outMatrix[Matrix4::M02] = s.Z();
			outMatrix[Matrix4::M03] = 0.0f;
			
			// Row 2
			outMatrix[Matrix4::M10] = u.X();
			outMatrix[Matrix4::M11] = u.Y();
			outMatrix[Matrix4::M12] = u.Z();
			outMatrix[Matrix4::M13] = 0.0f;
			
			// Row 3
			outMatrix[Matrix4::M20] = -dirVec.X();
			outMatrix[Matrix4::M21] = -dirVec.Y();
			outMatrix[Matrix4::M22] = -dirVec.Z();
			outMatrix[Matrix4::M23] = 0.0f;
			
			// Row 4
			outMatrix[Matrix4::M30] = eyePos.X();
			outMatrix[Matrix4::M31] = eyePos.Y();
			outMatrix[Matrix4::M32] = eyePos.Z();
			outMatrix[Matrix4::M33] = 1.0f;
			
			return outMatrix;
		}
		
		Matrix4 &BuildPerspectiveFov( const F32 fov, const F32 aspect, const F32 zNear, const F32 zFar, Matrix4 &outMatrix )
		{
			outMatrix.LoadIdentity();
			
			const F32 yMax = zNear * tanf( F32( DegreesToRadians( fov ) ) * 0.5f );
			const F32 yMin = -yMax;
			const F32 xMin = yMin * aspect;
			const F32 xMax = -xMin;
			
			// Perspective matrix settings taken from OpenGL Superbible math3d lib and Fundamentals
			// of Computer Graphics, Third Edition, Chapter 7 Perspective Projection, pg. 155.
			outMatrix[Matrix4::M00] = ( 2.0f * zNear ) / ( xMax - xMin );
			outMatrix[Matrix4::M11] = ( 2.0f * zNear ) / ( yMax - yMin );
			outMatrix[Matrix4::M20] = ( xMax + xMin ) / ( xMax - xMin );
			outMatrix[Matrix4::M21] = ( yMax + yMin ) / ( yMax - yMin );
			outMatrix[Matrix4::M22] = -( ( zFar + zNear ) / ( zFar - zNear ) );
			outMatrix[Matrix4::M23] = -1.0f;
			outMatrix[Matrix4::M32] = -( ( 2.0f * ( zFar * zNear ) ) / ( zFar - zNear ) );
			outMatrix[Matrix4::M33] = 0.0f;
			
			return outMatrix;
		}
		
		Matrix4 &BuildOrthographic( const F32 xMin, const F32 xMax, const F32 yMin, const F32 yMax, const F32 zMin, const F32 zMax, Matrix4 &outMatrix )
		{
			outMatrix.LoadIdentity();
			
			// Please see Fundamentals of Computer Graphics, 3rd Edition, Chapter 7
			//  Viewing Transformations, pg.144 for details on the orthographic projection
			//   matrix.
			
			outMatrix[Matrix4::M00] = 2.0f / ( xMax - xMin );
			outMatrix[Matrix4::M11] = 2.0f / ( yMax - yMin );
			outMatrix[Matrix4::M22] = 2.0f / ( zMax - zMin );
			outMatrix[Matrix4::M30] = -( ( xMax + xMin ) / ( xMax - xMin ) );
			outMatrix[Matrix4::M31] = -( ( yMax + yMin ) / ( yMax - yMin ) );
			outMatrix[Matrix4::M32] = -( ( zMax + zMin ) / ( zMax - zMin ) );
			
			return outMatrix;
		}
		
		void ExtractRotationMatrix( const Matrix4 &matrix, Matrix3x3 rotMatArr )
		{
			rotMatArr[0] = matrix[Matrix4::M00];
			rotMatArr[1] = matrix[Matrix4::M01];
			rotMatArr[2] = matrix[Matrix4::M02];
			rotMatArr[3] = matrix[Matrix4::M10];
			rotMatArr[4] = matrix[Matrix4::M11];
			rotMatArr[5] = matrix[Matrix4::M12];
			rotMatArr[6] = matrix[Matrix4::M20];
			rotMatArr[7] = matrix[Matrix4::M21];
			rotMatArr[8] = matrix[Matrix4::M22];
		}
	}
}
