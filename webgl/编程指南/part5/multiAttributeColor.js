var VSHADER_SOURCE =
    'attribute vec4 a_Position;\n' +
    'attribute vec4 a_Color;\n' +
    'varying vec4 v_Color;\n' +
    'void main() {\n' +
    '  gl_Position = a_Position;\n' +
    '  gl_PointSize = 10.0;\n' +
    '  v_Color = a_Color;\n' +
    '}\n'

var FSHADER_SOURCE =
    'precision mediump float;\n' +
    'varying vec4 v_Color;\n' +
    'void main() {\n' +
    ' gl_FragColor = v_Color;\n' +
    '}\n';

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

    gl.clearColor(0.0, 0.0, 1.0, 1.0)
    gl.clear(gl.COLOR_BUFFER_BIT)
    gl.drawArrays(gl.POINTS, 0, n)
}

function initVertexBuffers(gl) {
    var verticesColors = new Float32Array([
        0.0, 0.5, 1.0, 0.0, 0.0,
        -0.5, -0.5, 0.0, 1.0, 0.0,
        0.5, -0.5, 0.0, 0.0, 1.0
    ])
    var n = 3

    var vertexColorBuffer = gl.createBuffer()
    if (!vertexColorBuffer) {
        console.log('Failed to create the buffer object')
        return -1
    }

    gl.bindBuffer(gl.ARRAY_BUFFER, vertexColorBuffer)
    gl.bufferData(gl.ARRAY_BUFFER, verticesColors, gl.STATIC_DRAW)

    var FSIZE = verticesColors.BYTES_PER_ELEMENT
    var a_Position = gl.getAttribLocation(gl.program, 'a_Position')
    gl.vertexAttribPointer(a_Position, 2, gl.FLOAT, false, FSIZE * 5, 0)
    gl.enableVertexAttribArray(a_Position)

    var a_Color = gl.getAttribLocation(gl.program, 'a_Color')
    gl.vertexAttribPointer(a_Color, 3, gl.FLOAT, false, FSIZE * 5, FSIZE * 2)
    gl.enableVertexAttribArray(a_Color)
    return n
}