/*
 * This file is part of the leaf3d project.
 *
 * Copyright 2014-2015 Emanuele Bertoldi. All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * You should have received a copy of the modified BSD License along with this
 * program. If not, see <http://www.opensource.org/licenses/bsd-license.php>
 */

#ifndef L3D_L3DSHADERPROGRAM_H
#define L3D_L3DSHADERPROGRAM_H
#pragma once

#include <map>
#include "leaf3d/L3DResource.h"

namespace l3d
{
    class L3DShader;

    typedef union
    {
        float valueF;
        int valueI;
        float valueMat4[16];
    } L3DUniformValue;

    typedef std::map<const char*,L3DUniformValue> L3DUniformMap;

    class L3DShaderProgram : public L3DResource
    {
    protected:
        L3DShader*      m_vertexShader;
        L3DShader*      m_fragmentShader;
        L3DShader*      m_geometryShader;
        L3DUniformMap   m_uniforms;

    public:
        L3DShaderProgram(
            L3DRenderer* renderer,
            L3DShader* vertexShader,
            L3DShader* fragmentShader,
            L3DShader* geometryShader = L3D_NULLPTR,
            const L3DUniformMap& uniforms = L3DUniformMap()
        );
        ~L3DShaderProgram() {}

        L3DShader* vertexShader() const { return m_vertexShader; }
        L3DShader* fragmentShader() const { return m_fragmentShader; }
        L3DShader* geometryShader() const { return m_geometryShader; }
        L3DUniformMap uniforms() const { return m_uniforms; }
        unsigned int uniformCount() const { return m_uniforms.size(); }

        void setUniform(const char* name, int value);
        void setUniform(const char* name, float value);
        void setUniform(const char* name, const L3DMat4& value);
    };
}

#endif // L3D_L3DSHADERPROGRAM_H
