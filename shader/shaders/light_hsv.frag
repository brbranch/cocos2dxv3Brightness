const GLchar* LightHsvShaderFrag =
STRINGIFY(
                                           
\n#ifdef GL_ES\n
precision mediump float;
\n#endif\n

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;
uniform vec3 u_color;
          
vec3 rgb2hsv(vec3 c)
{
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));

    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

void main(void)
{
    vec4 col = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);
    vec3 hsv = rgb2hsv(col.rgb);
    hsv.x = hsv.x + u_color.x;
    if(hsv.x > 1.0){
        hsv.x = hsv.x - 1.0;
    }
    hsv.y = clamp(hsv.y + u_color.y, 0.0, 1.0);
    hsv.z = clamp(hsv.z + u_color.z, 0.0, 1.0);
    
    vec3 nrgb = hsv2rgb(hsv);
    vec4 c = vec4(nrgb.x, nrgb.y, nrgb.z, col.a);
    
    c.r = c.r * c.a;
    c.g = c.g * c.a;
    c.b = c.b * c.a;
    
    gl_FragColor = c;
}
);