var VSHADER_SOURCE =
    'attribute vec4 a_Position;\n' +
    'attribute vec2 a_TextCoord;\n' +
    'varying vec2 v_TextCoord;\n' +
    'void main() {\n' +
    '  gl_Position = a_Position;\n' +
    '  v_TextCoord = a_TextCoord;\n' +
    '}\n'

var FSHADER_SOURCE = `
    precision mediump float;
    uniform sampler2D u_Sampler;
    varying vec2 v_TextCoord;
    void main() {
      gl_FragColor = texture2D(u_Sampler, v_TextCoord);
    }`;

function main() {
    var canvas = document.getElementById('webgl')
    var gl = canvas.getContext('webgl')

    if (!gl) {
        console.log('Failed to get the rendering context for WebGL')
        return
    }

    if (!initShaders(gl, VSHADER_SOURCE, FSHADER_SOURCE)) {
        console.log('Failed to initialize shaders')
        return
    }

    var n = initVertexBuffers(gl)
    if (n < 0) {
        console.log('Failed to set the positions of the vertices')
        return
    }

    if (!initTextures(gl, n)) {
        console.log('Failed to init texture')
        return
    }

    gl.clearColor(0.0, 0.0, 1.0, 1.0)
    gl.clear(gl.COLOR_BUFFER_BIT)
    gl.drawArrays(gl.POINTS, 0, n)
}

function initVertexBuffers(gl) {
    var verticesTexCoords = new Float32Array([
        -0.5, 0.5, -0.3, 1.7,
        -0.5, -0.5, -0.3, -0.2,
        0.5, 0.5, 1.7, 1.7,
        0.5, -0.5, 1.7, -0.2
    ])
    var n = 4


    var vertexTexCoordBuffer = gl.createBuffer()
    if (!vertexTexCoordBuffer) {
        console.log('Failed to create the buffer object')
        return -1
    }

    gl.bindBuffer(gl.ARRAY_BUFFER, vertexTexCoordBuffer)
    gl.bufferData(gl.ARRAY_BUFFER, verticesTexCoords, gl.STATIC_DRAW)
    var FSIZE = verticesTexCoords.BYTES_PER_ELEMENT

    var a_Position = gl.getAttribLocation(gl.program, 'a_Position')
    gl.vertexAttribPointer(a_Position, 2, gl.FLOAT, false, 0, 0)
    gl.enableVertexAttribArray(a_Position)

    var a_TextCoord = gl.getAttribLocation(gl.program, 'a_TextCoord')
    gl.vertexAttribPointer(a_TextCoord, 2, gl.FLOAT, false, FSIZE * 4, FSIZE * 2)
    gl.enableVertexAttribArray(a_TextCoord)
    return n
}

function initTextures(gl, n) {
    var texture = gl.createTexture()

    var u_Sampler = gl.getUniformLocation(gl.program, 'u_Sampler')
    var image = new Image()
    image.onload = function () { loadTexture(gl, n, texture, u_Sampler, image) }
    image.src = '../images/sky.jpg'
    return true
}

function loadTexture(gl, n, texture, u_Sampler, image) {
    gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, 1)
    gl.activeTexture(gl.TEXTURE0)
    gl.bindTexture(gl.TEXTURE_2D, texture)

    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR)
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGB, gl.RGB, gl.UNSIGNED_BYTE, image)
    gl.uniform1i(u_Sampler, 0)

    gl.drawArrays(gl.TRIANGLE_STRIP, 0, n)
}