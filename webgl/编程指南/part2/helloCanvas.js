function main() {
    var canvas = document.getElementById('webgl')
    var gl = canvas.getContext('webgl')
    console.log(1)
    if (!gl) {
        console.log('Failed to get the rendering context for webgl')
    }
    console.log(2)

    gl.clearColor(0.0, 0.0, 1.0, 1.0)
    gl.clear(gl.COLOR_BUFFER_BIT)
}