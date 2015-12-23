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

#include <leaf3d/L3DTexture.h>
#include <leaf3d/L3DRenderer.h>

using namespace l3d;

L3DTexture::L3DTexture(
    L3DRenderer* renderer,
    const TextureType& type,
    const ImageFormat& format,
    unsigned char* data,
    unsigned int width,
    unsigned int height,
    unsigned int depth
) : L3DResource(L3D_TEXTURE, renderer),
    m_type(type),
    m_format(format),
    m_data(data),
    m_width(width),
    m_height(height),
    m_depth(depth)
{
    if (data)
    {
        unsigned int size = width * format * sizeof(unsigned char);
        if (height) size *= height;
        if (depth) size *= depth;
        m_data = (unsigned char*)memcpy(malloc(size), data, size);
    }

    if (renderer) renderer->addTexture(this);
}

L3DTexture::~L3DTexture()
{
    free(m_data);
}
