[Terra.js](http://sible777.github.io/Terra.js/)
========

##Javascript procedural terrain generator

Terra.js uses the diamond square algorithm to generate a height map that is rendered using Three.js.

Currently is is only possible to generate terrains that are just planes, and there are some issues with the distrubution
of the height map data to the vertices.

##Example
```html
  <html>
    <head>
      <title>Terra.js</title>
      <style>
        body { margin: 0; }
        canvas { width: 100%; height: 100% }
      </style>
      <script src='https://cdnjs.cloudflare.com/ajax/libs/three.js/r69/three.min.js'></script>
      <script src='http://threejs.org/examples/js/controls/FlyControls.js'></script>
    </head>
    <body id='container'>
      <script src='js/terra.js'></script>
    </body>
  </html>
```

##TODO:
1. Fix the issues posted
2. Fix the height application distribution
3. Implement sphere generation
4. Implement cube generation




