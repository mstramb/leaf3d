include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../External)

set(LEAF3D_SOURCES
    leaf3d/platform.h
    leaf3d/types.h
    leaf3d/L3DResource.h
    leaf3d/L3DBuffer.h
    leaf3d/L3DTexture.h
    leaf3d/L3DShader.h
    leaf3d/L3DShaderProgram.h
    leaf3d/L3DMaterial.h
    leaf3d/L3DCamera.h
    leaf3d/L3DLight.h
    leaf3d/L3DMesh.h
    leaf3d/L3DRenderer.h
    leaf3d/leaf3d.h
    L3DResource.cpp
    L3DBuffer.cpp
    L3DTexture.cpp
    L3DShader.cpp
    L3DShaderProgram.cpp
    L3DMaterial.cpp
    L3DCamera.cpp
    L3DLight.cpp
    L3DMesh.cpp
    L3DRenderer.cpp
    main.cpp
)

add_library(leaf3d SHARED ${LEAF3D_SOURCES})