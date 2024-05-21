f32 cmm_camera_zoom_table[][2] = {
    {900.0f,50.0f},
    {900.0f,400.0f},
    {1500.0f,800.0f},
    {2000.0f,900.0f},
    {2100.0f,1500.0f},
};

void* cmm_theme_segments[][4] = {
    {_group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd}, //CMM_GAME_VANILLA
    {_group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd}, //CMM_GAME_BTCM
};
LevelScript * cmm_theme_model_scripts[] = {
    script_func_cmm_theme_vanilla,
    script_func_cmm_theme_btcm,
};


// lookup table for rotating blocks
u8 cmm_rotated_dirs[4][6] = {
    {CMM_DIRECTION_UP, CMM_DIRECTION_DOWN, CMM_DIRECTION_POS_X, CMM_DIRECTION_NEG_X, CMM_DIRECTION_POS_Z, CMM_DIRECTION_NEG_Z},
    {CMM_DIRECTION_UP, CMM_DIRECTION_DOWN, CMM_DIRECTION_NEG_Z, CMM_DIRECTION_POS_Z, CMM_DIRECTION_POS_X, CMM_DIRECTION_NEG_X},
    {CMM_DIRECTION_UP, CMM_DIRECTION_DOWN, CMM_DIRECTION_NEG_X, CMM_DIRECTION_POS_X, CMM_DIRECTION_NEG_Z, CMM_DIRECTION_POS_Z},
    {CMM_DIRECTION_UP, CMM_DIRECTION_DOWN, CMM_DIRECTION_POS_Z, CMM_DIRECTION_NEG_Z, CMM_DIRECTION_NEG_X, CMM_DIRECTION_POS_X},
};

struct cmm_terrain_poly cmm_terrain_fullblock_quads[] = {
    {{{16, 16, 16}, {16, 16, 0}, {0, 16, 16},  {0, 16, 0}},  CMM_DIRECTION_UP,    CMM_FACESHAPE_FULL, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 0, 16},  {0, 0, 16},  {16, 0, 0},   {0, 0, 0}},   CMM_DIRECTION_DOWN,  CMM_FACESHAPE_FULL, 0, NULL}, // BOTTOM
    {{{16, 16, 16}, {16, 0, 16}, {16, 16, 0},  {16, 0, 0}},  CMM_DIRECTION_POS_X, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // LEFT
    {{{0, 16, 0},   {0, 0, 0},   {0, 16, 16},  {0, 0, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
    {{{0, 16, 16},  {0, 0, 16},  {16, 16, 16}, {16, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // FRONT
    {{{16, 16, 0},  {16, 0, 0},  {0, 16, 0},   {0, 0, 0}},   CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
};
struct cmm_terrain cmm_terrain_fullblock = {
    6,
    0,
    cmm_terrain_fullblock_quads,
    NULL
};

s8 slope_decal_uvs1[3][2] = {{0, 0}, {0, 16}, {16, 16}};
s8 slope_decal_uvs2[3][2] = {{16, 16}, {16, 0}, {0, 16}};

struct cmm_terrain_poly cmm_terrain_slope_quads[] = {
    {{{16, 0, 16}, {16, 16, 0}, {0, 0, 16}, {0, 16, 0}}, CMM_DIRECTION_UP,    CMM_FACESHAPE_EMPTY, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 0, 16}, {0, 0, 16},  {16, 0, 0}, {0, 0, 0}},  CMM_DIRECTION_DOWN,  CMM_FACESHAPE_FULL, 0, NULL}, // BOTTOM
    {{{16, 16, 0}, {16, 0, 0},  {0, 16, 0}, {0, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
};

struct cmm_terrain_poly cmm_terrain_slope_tris[] = {
    {{{16, 0, 0}, {16, 16, 0}, {16, 0, 16}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_TRI_1, CMM_GROWTH_SLOPE_SIDE_L, &slope_decal_uvs1}, // LEFT
    {{{0, 16, 0}, {0, 0, 0},   {0, 0, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_TRI_2, CMM_GROWTH_SLOPE_SIDE_R, &slope_decal_uvs2}, // RIGHT
};

struct cmm_terrain cmm_terrain_slope = {
    3,
    2,
    cmm_terrain_slope_quads,
    cmm_terrain_slope_tris,
};

struct cmm_terrain_poly cmm_terrain_corner_quads[] = {
    {{{16, 0, 16}, {0, 0, 16}, {16, 0, 0}, {0, 0, 0}}, CMM_DIRECTION_DOWN, CMM_FACESHAPE_FULL, 0, NULL}, // BOTTOM
};

struct cmm_terrain_poly cmm_terrain_corner_tris[] = {
    {{{0, 0, 16}, {16, 0, 16}, {0, 16, 0}},  CMM_DIRECTION_UP,    CMM_FACESHAPE_EMPTY, CMM_GROWTH_FULL, NULL}, // TOP-FRONT
    {{{0, 16, 0}, {16, 0, 16}, {16, 0, 0}},  CMM_DIRECTION_UP,    CMM_FACESHAPE_EMPTY, CMM_GROWTH_FULL, NULL}, // TOP-LEFT 
    {{{0, 16, 0}, {0, 0, 0},   {0, 0, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_TRI_2, CMM_GROWTH_SLOPE_SIDE_R, &slope_decal_uvs2}, // RIGHT
    {{{0, 0, 0},  {0, 16, 0},  {16, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_TRI_1, CMM_GROWTH_SLOPE_SIDE_L, &slope_decal_uvs1}, // BACK
};

struct cmm_terrain cmm_terrain_corner = {
    1,
    4,
    cmm_terrain_corner_quads,
    cmm_terrain_corner_tris,
};

struct cmm_terrain_poly cmm_terrain_dcorner_quads[] = {
    {{{16, 16, 16}, {16, 16, 0}, {0, 16, 16}, {0, 16, 0}}, CMM_DIRECTION_UP, CMM_FACESHAPE_FULL, CMM_GROWTH_FULL, NULL}, // TOP
};

struct cmm_terrain_poly cmm_terrain_dcorner_tris[] = {
    {{{16, 16, 16}, {0, 16, 16}, {0, 0, 0}},    CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, CMM_GROWTH_NORMAL_SIDE, NULL}, // BOTTOM-FRONT
    {{{0, 0, 0},    {16, 16, 0}, {16, 16, 16}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_EMPTY, CMM_GROWTH_NORMAL_SIDE, NULL}, // BOTTOM-LEFT 
    {{{0, 0, 0},    {0, 16, 16}, {0, 16, 0}},   CMM_DIRECTION_NEG_X, CMM_FACESHAPE_DOWNTRI_2, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
    {{{0, 0, 0},    {0, 16, 0},  {16, 16, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_DOWNTRI_1, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
};

struct cmm_terrain cmm_terrain_dcorner = {
    1,
    4,
    cmm_terrain_dcorner_quads,
    cmm_terrain_dcorner_tris,
};


struct cmm_terrain_poly cmm_terrain_icorner_quads[] = {
    {{{16, 0, 16}, {0, 0, 16}, {16, 0, 0},  {0, 0, 0}},  CMM_DIRECTION_DOWN,  CMM_FACESHAPE_FULL, 0, NULL}, // BOTTOM
    {{{16, 16, 0}, {16, 0, 0}, {0, 16, 0},  {0, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
    {{{0, 16, 0},  {0, 0, 0},  {0, 16, 16}, {0, 0, 16}}, CMM_DIRECTION_NEG_X, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
};

struct cmm_terrain_poly cmm_terrain_icorner_tris[] = {
    {{{0, 16, 16}, {16, 0, 16}, {0, 16, 0}},  CMM_DIRECTION_UP,    CMM_FACESHAPE_EMPTY, CMM_GROWTH_FULL, NULL}, // TOP-FRONT
    {{{0, 16, 0},  {16, 0, 16}, {16, 16, 0}}, CMM_DIRECTION_UP,    CMM_FACESHAPE_EMPTY, CMM_GROWTH_FULL, NULL}, // TOP-LEFT
    {{{16, 0, 0},  {16, 16, 0}, {16, 0, 16}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_TRI_1, CMM_GROWTH_SLOPE_SIDE_L, &slope_decal_uvs1}, // LEFT
    {{{0, 16, 16}, {0, 0, 16},  {16, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_TRI_2, CMM_GROWTH_SLOPE_SIDE_R, &slope_decal_uvs2}, // FRONT
};

struct cmm_terrain cmm_terrain_icorner = {
    3,
    4,
    cmm_terrain_icorner_quads,
    cmm_terrain_icorner_tris,
};

struct cmm_terrain_poly cmm_terrain_dicorner_quads[] = {
    {{{16, 16, 16}, {16, 16, 0}, {0, 16, 16}, {0, 16, 0}}, CMM_DIRECTION_UP,    CMM_FACESHAPE_FULL, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 16, 0},  {16, 0, 0},  {0, 16, 0},  {0, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
    {{{0, 16, 0},   {0, 0, 0},   {0, 16, 16}, {0, 0, 16}}, CMM_DIRECTION_NEG_X, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
};

struct cmm_terrain_poly cmm_terrain_dicorner_tris[] = {
    {{{16, 0, 0},   {16, 16, 0}, {16, 16, 16}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_DOWNTRI_1, CMM_GROWTH_NORMAL_SIDE, NULL}, // LEFT
    {{{0, 16, 16},  {0, 0, 16},  {16, 16, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_DOWNTRI_2, CMM_GROWTH_NORMAL_SIDE, NULL}, // FRONT
    {{{16, 16, 16}, {0, 0, 16},  {0, 0, 0}},    CMM_DIRECTION_POS_X, CMM_FACESHAPE_EMPTY, CMM_GROWTH_UNDERSLOPE_CORNER, NULL}, // BOTTOM-FRONT
    {{{16, 16, 16}, {0, 0, 0},   {16, 0, 0}},   CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, CMM_GROWTH_UNDERSLOPE_CORNER, NULL}, // BOTTOM-LEFT
};

struct cmm_terrain cmm_terrain_dicorner = {
    3,
    4,
    cmm_terrain_dicorner_quads,
    cmm_terrain_dicorner_tris,
};

struct cmm_terrain_poly cmm_terrain_dslope_quads[] = {
    {{{16, 16, 16}, {16, 16, 0}, {0, 16, 16}, {0, 16, 0}}, CMM_DIRECTION_UP,    CMM_FACESHAPE_FULL, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 16, 0},  {16, 0, 0},  {0, 16, 0},  {0, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
    {{{16, 16, 16}, {0, 16, 16}, {16, 0, 0},  {0, 0, 0}},  CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, CMM_GROWTH_NORMAL_SIDE, NULL}, // BOTTOM
};

struct cmm_terrain_poly cmm_terrain_dslope_tris[] = {
    {{{16, 0, 0}, {16, 16, 0}, {16, 16, 16}},  CMM_DIRECTION_POS_X, CMM_FACESHAPE_DOWNTRI_1, CMM_GROWTH_NORMAL_SIDE, NULL}, // LEFT
    {{{0, 16, 0}, {0, 0, 0},   {0, 16, 16}},   CMM_DIRECTION_NEG_X, CMM_FACESHAPE_DOWNTRI_2, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
};

struct cmm_terrain cmm_terrain_dslope = {
    3,
    2,
    cmm_terrain_dslope_quads,
    cmm_terrain_dslope_tris,
};

struct cmm_terrain_poly cmm_terrain_sslope_quads[] = {
    {{{16, 16, 0}, {16, 0, 0},  {0, 16, 0},  {0, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
    {{{0, 16, 0},  {0, 0, 0},   {0, 16, 16}, {0, 0, 16}}, CMM_DIRECTION_NEG_X, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
    {{{16, 16, 0}, {0, 16, 16}, {16, 0, 0},  {0, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, CMM_GROWTH_DIAGONAL_SIDE, NULL}, // DIAGONAL
};

struct cmm_terrain_poly cmm_terrain_sslope_tris[] = {
    {{{0, 16, 16}, {16, 16, 0}, {0, 16, 0}}, CMM_DIRECTION_UP,   CMM_FACESHAPE_TOPTRI, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 0, 0},  {0, 0, 16},  {0, 0, 0}},  CMM_DIRECTION_DOWN, CMM_FACESHAPE_TOPTRI, 0, NULL}, // BOTTOM
};

struct cmm_terrain cmm_terrain_sslope = {
    3,
    2,
    cmm_terrain_sslope_quads,
    cmm_terrain_sslope_tris,
};

struct cmm_terrain_poly cmm_terrain_scorner_tris[] = {
    {{{0, 0, 16}, {16, 0, 0}, {0, 16, 0}},  CMM_DIRECTION_UP,    CMM_FACESHAPE_EMPTY, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 0, 0},  {0, 0, 16},  {0, 0, 0}},  CMM_DIRECTION_DOWN, CMM_FACESHAPE_TOPTRI, 0, NULL}, // BOTTOM
    {{{0, 16, 0}, {0, 0, 0},   {0, 0, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_TRI_2, CMM_GROWTH_SLOPE_SIDE_R, &slope_decal_uvs2}, // RIGHT
    {{{0, 0, 0},  {0, 16, 0},  {16, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_TRI_1, CMM_GROWTH_SLOPE_SIDE_L, &slope_decal_uvs1}, // BACK
};

struct cmm_terrain cmm_terrain_scorner = {
    0,
    4,
    NULL,
    cmm_terrain_scorner_tris,
};

struct cmm_terrain_poly cmm_terrain_dscorner_tris[] = {
    {{{16, 16, 0}, {0, 16, 16}, {0, 0, 0}},    CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, CMM_GROWTH_DIAGONAL_SIDE, NULL}, // BOTTOM
    {{{0, 16, 16}, {16, 16, 0}, {0, 16, 0}}, CMM_DIRECTION_UP,   CMM_FACESHAPE_TOPTRI, CMM_GROWTH_FULL, NULL}, // TOP
    {{{0, 0, 0},    {0, 16, 16}, {0, 16, 0}},   CMM_DIRECTION_NEG_X, CMM_FACESHAPE_DOWNTRI_2, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
    {{{0, 0, 0},    {0, 16, 0},  {16, 16, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_DOWNTRI_1, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
};

struct cmm_terrain cmm_terrain_dscorner = {
    0,
    4,
    NULL,
    cmm_terrain_dscorner_tris,
};

s8 bottomslab_decal_uvs1[4][2] = {{16, 16}, {16, 8}, {0, 16}, {0, 8}};

struct cmm_terrain_poly cmm_terrain_bottomslab_quads[] = {
    {{{16, 8, 16}, {16, 8, 0},  {0, 8, 16},  {0, 8, 0}},   CMM_DIRECTION_UP,    CMM_FACESHAPE_EMPTY, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 0, 16}, {0, 0, 16},  {16, 0, 0},  {0, 0, 0}},   CMM_DIRECTION_DOWN,  CMM_FACESHAPE_FULL, 0, NULL}, // BOTTOM
    {{{16, 8, 16}, {16, 0, 16}, {16, 8, 0},  {16, 0, 0}},  CMM_DIRECTION_POS_X, CMM_FACESHAPE_BOTTOMSLAB, CMM_GROWTH_UNCONDITIONAL, &bottomslab_decal_uvs1}, // LEFT
    {{{0, 8, 0},   {0, 0, 0},   {0, 8, 16},  {0, 0, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_BOTTOMSLAB, CMM_GROWTH_UNCONDITIONAL, &bottomslab_decal_uvs1}, // RIGHT
    {{{0, 8, 16},  {0, 0, 16},  {16, 8, 16}, {16, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_BOTTOMSLAB, CMM_GROWTH_UNCONDITIONAL, &bottomslab_decal_uvs1}, // FRONT
    {{{16, 8, 0},  {16, 0, 0},  {0, 8, 0},   {0, 0, 0}},   CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_BOTTOMSLAB, CMM_GROWTH_UNCONDITIONAL, &bottomslab_decal_uvs1}, // BACK
};

struct cmm_terrain cmm_terrain_bottomslab = {
    6,
    0,
    cmm_terrain_bottomslab_quads,
    NULL
};

struct cmm_terrain_poly cmm_terrain_topslab_quads[] = {
    {{{16, 16, 16}, {16, 16, 0}, {0, 16, 16},  {0, 16, 0}},  CMM_DIRECTION_UP,    CMM_FACESHAPE_FULL, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 8, 16},  {0, 8, 16},  {16, 8, 0},   {0, 8, 0}},   CMM_DIRECTION_DOWN,  CMM_FACESHAPE_EMPTY, 0, NULL}, // BOTTOM
    {{{16, 16, 16}, {16, 8, 16}, {16, 16, 0},  {16, 8, 0}},  CMM_DIRECTION_POS_X, CMM_FACESHAPE_TOPSLAB, CMM_GROWTH_NORMAL_SIDE, NULL}, // LEFT
    {{{0, 16, 0},   {0, 8, 0},   {0, 16, 16},  {0, 8, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_TOPSLAB, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
    {{{0, 16, 16},  {0, 8, 16},  {16, 16, 16}, {16, 8, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_TOPSLAB, CMM_GROWTH_NORMAL_SIDE, NULL}, // FRONT
    {{{16, 16, 0},  {16, 8, 0},  {0, 16, 0},   {0, 8, 0}},   CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_TOPSLAB, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
};

struct cmm_terrain cmm_terrain_topslab = {
    6,
    0,
    cmm_terrain_topslab_quads,
    NULL
};

struct cmm_terrain_poly cmm_terrain_vslab_quads[] = {
    {{{16, 16, 8}, {16, 16, 0}, {0, 16, 8},  {0, 16, 0}}, CMM_DIRECTION_UP,    CMM_FACESHAPE_TOPHALF,    CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 0, 8},  {0, 0, 8},   {16, 0, 0},  {0, 0, 0}},  CMM_DIRECTION_DOWN,  CMM_FACESHAPE_TOPHALF,    0, NULL}, // BOTTOM
    {{{16, 16, 8}, {16, 0, 8},  {16, 16, 0}, {16, 0, 0}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_HALFSIDE_1, CMM_GROWTH_HALF_SIDE,   NULL}, // LEFT
    {{{0, 16, 0},  {0, 0, 0},   {0, 16, 8},  {0, 0, 8}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_HALFSIDE_2, CMM_GROWTH_HALF_SIDE,   NULL}, // RIGHT
    {{{0, 16, 8},  {0, 0, 8},   {16, 16, 8}, {16, 0, 8}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY,      CMM_GROWTH_VSLAB_SIDE, NULL}, // FRONT
    {{{16, 16, 0}, {16, 0, 0},  {0, 16, 0},  {0, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL,       CMM_GROWTH_NORMAL_SIDE,   NULL}, // BACK
};
struct cmm_terrain cmm_terrain_vslab = {
    6,
    0,
    cmm_terrain_vslab_quads,
    NULL
};

s8 gentle_decal_tri_uvs1[3][2] = {{0, 8}, {0, 16}, {16, 16}};
s8 gentle_decal_tri_uvs2[3][2] = {{16, 16}, {16, 8}, {0, 16}};
s8 ugentle_decal_quad_uvs1[4][2] = {{16, 16}, {16, 8}, {0, 8}, {0, 0}};
s8 ugentle_decal_quad_uvs2[4][2] = {{16, 8}, {16, 0}, {0, 16}, {0, 8}};

struct cmm_terrain_poly cmm_terrain_ugentle_quads[] = {
    {{{16, 8, 16}, {16, 16, 0}, {0, 8, 16}, {0, 16, 0}}, CMM_DIRECTION_UP,    CMM_FACESHAPE_EMPTY, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 0, 16}, {0, 0, 16},  {16, 0, 0}, {0, 0, 0}},  CMM_DIRECTION_DOWN,  CMM_FACESHAPE_FULL, 0, NULL}, // BOTTOM
    {{{16, 16, 0}, {16, 0, 0},  {0, 16, 0}, {0, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
    {{{0, 8, 16},  {0, 0, 16},  {16, 8, 16}, {16, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_BOTTOMSLAB, CMM_GROWTH_UNCONDITIONAL, &bottomslab_decal_uvs1}, // FRONT
    {{{16, 8, 16}, {16, 0, 16}, {16, 8, 0},  {16, 0, 0}},  CMM_DIRECTION_POS_X, CMM_FACESHAPE_BOTTOMSLAB, CMM_GROWTH_UNCONDITIONAL, &ugentle_decal_quad_uvs1}, // LEFT
    {{{0, 8, 0},   {0, 0, 0},   {0, 8, 16},  {0, 0, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_BOTTOMSLAB, CMM_GROWTH_UNCONDITIONAL, &ugentle_decal_quad_uvs2}, // RIGHT
};

struct cmm_terrain_poly cmm_terrain_ugentle_tris[] = {
    {{{16, 8, 0}, {16, 16, 0}, {16, 8, 16}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_UPPERGENTLE_1, CMM_GROWTH_UNCONDITIONAL, &gentle_decal_tri_uvs1}, // LEFT
    {{{0, 16, 0}, {0, 8, 0},   {0, 8, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_UPPERGENTLE_2, CMM_GROWTH_UNCONDITIONAL, &gentle_decal_tri_uvs2}, // RIGHT
};

struct cmm_terrain cmm_terrain_ugentle = {
    6,
    2,
    cmm_terrain_ugentle_quads,
    cmm_terrain_ugentle_tris,
};

struct cmm_terrain_poly cmm_terrain_dugentle_quads[] = {
    {{{16, 16, 16}, {16, 16, 0}, {0, 16, 16}, {0, 16, 0}}, CMM_DIRECTION_UP,    CMM_FACESHAPE_FULL, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 16, 0},  {16, 0, 0},  {0, 16, 0},  {0, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
    {{{16, 8, 16}, {0, 8, 16}, {16, 0, 0},  {0, 0, 0}},  CMM_DIRECTION_DOWN, CMM_FACESHAPE_EMPTY, CMM_GROWTH_NONE, NULL}, // BOTTOM
    {{{0, 16, 16},  {0, 8, 16},  {16, 16, 16}, {16, 8, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_TOPSLAB, CMM_GROWTH_NORMAL_SIDE, NULL}, // FRONT
    {{{16, 16, 16}, {16, 8, 16}, {16, 16, 0},  {16, 8, 0}},  CMM_DIRECTION_POS_X, CMM_FACESHAPE_TOPSLAB, CMM_GROWTH_NORMAL_SIDE, NULL}, // LEFT
    {{{0, 16, 0},   {0, 8, 0},   {0, 16, 16},  {0, 8, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_TOPSLAB, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
};

struct cmm_terrain_poly cmm_terrain_dugentle_tris[] = {
    {{{16, 0, 0}, {16, 8, 0}, {16, 8, 16}},  CMM_DIRECTION_POS_X, CMM_FACESHAPE_DOWNUPPERGENTLE_1, CMM_GROWTH_NONE, NULL}, // LEFT
    {{{0, 8, 0}, {0, 0, 0},   {0, 8, 16}},   CMM_DIRECTION_NEG_X, CMM_FACESHAPE_DOWNUPPERGENTLE_2, CMM_GROWTH_NONE, NULL}, // RIGHT
};

struct cmm_terrain cmm_terrain_dugentle = {
    6,
    2,
    cmm_terrain_dugentle_quads,
    cmm_terrain_dugentle_tris,
};

struct cmm_terrain_poly cmm_terrain_lgentle_quads[] = {
    {{{16, 0, 16}, {16, 8, 0}, {0, 0, 16}, {0, 8, 0}}, CMM_DIRECTION_UP,    CMM_FACESHAPE_EMPTY, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 0, 16}, {0, 0, 16},  {16, 0, 0}, {0, 0, 0}},  CMM_DIRECTION_DOWN,  CMM_FACESHAPE_FULL, 0, NULL}, // BOTTOM
    {{{16, 8, 0},  {16, 0, 0},  {0, 8, 0},   {0, 0, 0}},   CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_BOTTOMSLAB, CMM_GROWTH_UNCONDITIONAL, &bottomslab_decal_uvs1}, // BACK
};

struct cmm_terrain_poly cmm_terrain_lgentle_tris[] = {
    {{{16, 0, 0}, {16, 8, 0}, {16, 0, 16}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_LOWERGENTLE_1, CMM_GROWTH_GENTLE_SIDE_L, &gentle_decal_tri_uvs1}, // LEFT
    {{{0, 8, 0}, {0, 0, 0},   {0, 0, 16}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_LOWERGENTLE_2, CMM_GROWTH_GENTLE_SIDE_R, &gentle_decal_tri_uvs2}, // RIGHT
};

struct cmm_terrain cmm_terrain_lgentle = {
    3,
    2,
    cmm_terrain_lgentle_quads,
    cmm_terrain_lgentle_tris,
};

s8 dlgentle_decal_uvs[4][2] = {{0, 16}, {16, 16}, {0, 8}, {16, 8}};

struct cmm_terrain_poly cmm_terrain_dlgentle_quads[] = {
    {{{16, 16, 16}, {16, 16, 0}, {0, 16, 16}, {0, 16, 0}}, CMM_DIRECTION_UP,    CMM_FACESHAPE_FULL, CMM_GROWTH_FULL, NULL}, // TOP
    {{{16, 16, 0},  {16, 8, 0},  {0, 16, 0},   {0, 8, 0}}, CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_TOPSLAB, CMM_GROWTH_NORMAL_SIDE, NULL}, // BACK
    {{{16, 16, 16}, {0, 16, 16}, {16, 8, 0},  {0, 8, 0}},  CMM_DIRECTION_DOWN, CMM_FACESHAPE_EMPTY, CMM_GROWTH_DLGENTLE_UNDER, dlgentle_decal_uvs}, // BOTTOM
};

struct cmm_terrain_poly cmm_terrain_dlgentle_tris[] = {
    {{{16, 8, 0}, {16, 16, 0}, {16, 16, 16}},  CMM_DIRECTION_POS_X, CMM_FACESHAPE_DOWNLOWERGENTLE_1, CMM_GROWTH_NORMAL_SIDE, NULL}, // LEFT
    {{{0, 16, 0}, {0, 8, 0},   {0, 16, 16}},   CMM_DIRECTION_NEG_X, CMM_FACESHAPE_DOWNLOWERGENTLE_2, CMM_GROWTH_NORMAL_SIDE, NULL}, // RIGHT
};

struct cmm_terrain cmm_terrain_dlgentle = {
    3,
    2,
    cmm_terrain_dlgentle_quads,
    cmm_terrain_dlgentle_tris,
};


struct cmm_terrain_poly cmm_terrain_slopebelowdecal_quad = {
    {{0, 16, 16}, {0, 0, 16}, {16, 16, 16}, {16, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_FULL, 0, NULL
};
struct cmm_terrain_poly cmm_terrain_slopebelowdecal_downtri1 = {
    {{16, 16, 16}, {0, 16, 16}, {16, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_DOWNTRI_1, 0, NULL
};
struct cmm_terrain_poly cmm_terrain_slopebelowdecal_downtri2 = {
    {{0, 16, 16}, {0, 0, 16}, {16, 16, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_DOWNTRI_2, 0, NULL
};
struct cmm_terrain_poly cmm_terrain_slopebelowdecal_topslab = {
    {{0, 16, 16}, {0, 8, 16}, {16, 16, 16}, {16, 8, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_TOPSLAB, 0, NULL
};
struct cmm_terrain_poly cmm_terrain_slopebelowdecal_vslab_1 = {
    {{8, 16, 16}, {8, 0, 16}, {16, 16, 16}, {16, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_HALFSIDE_1, 0, NULL
};
struct cmm_terrain_poly cmm_terrain_slopebelowdecal_vslab_2 = {
    {{0, 16, 16}, {0, 0, 16}, {8, 16, 16}, {8, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_HALFSIDE_2, 0, NULL
};
struct cmm_terrain_poly cmm_terrain_slopebelowdecal_downlowergentle1 = {
    {{16, 16, 16}, {0, 16, 16}, {16, 8, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_DOWNLOWERGENTLE_1, 0, NULL
};
struct cmm_terrain_poly cmm_terrain_slopebelowdecal_downlowergentle2 = {
    {{0, 16, 16}, {0, 8, 16}, {16, 16, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_DOWNLOWERGENTLE_2, 0, NULL
};

void *slope_decal_below_surfs[] = {
    &cmm_terrain_slopebelowdecal_quad,
    &cmm_terrain_slopebelowdecal_downtri1,
    &cmm_terrain_slopebelowdecal_downtri2,
    &cmm_terrain_slopebelowdecal_topslab,
    &cmm_terrain_slopebelowdecal_vslab_1,
    &cmm_terrain_slopebelowdecal_vslab_2,
    &cmm_terrain_slopebelowdecal_downlowergentle1,
    &cmm_terrain_slopebelowdecal_downlowergentle2,
};

// Shape of fence

s8 fence_uvs[4][2] = {{32, 16},  {32, 0},  {0, 16},  {0, 0}};
struct cmm_terrain_poly cmm_terrain_fence_quad[] = {
    {{{0, 8, 0}, {0, 0, 0}, {16, 8, 0}, {16, 0, 0}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, 0, &fence_uvs}, // FRONT (towards tile)
    {{{16, 8, 0}, {16, 0, 0}, {0, 8, 0}, {0, 0, 0}}, CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_BOTTOMSLAB, 0, &fence_uvs}, // BACK (away from tile)
};

struct cmm_terrain_poly cmm_terrain_fence_col_quads[] = {
    {{{16, 7, 1},  {0, 7, 1},   {16, 0, 1}, {0, 0, 1}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, 0, NULL}, // FRONT (towards tile)
    {{{16, 7, -1}, {16, 0, -1}, {0, 7, -1}, {0, 0, -1}}, CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_BOTTOMSLAB, 0, NULL}, // BACK (away from tile)

    {{{16, 8, 0},  {0, 8, 0},   {16, 7, 1}, {0, 7, 1}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, 0, NULL}, // FRONT (towards tile)
    {{{16, 8, 0},  {16, 7, -1}, {0, 8, 0},  {0, 7, -1}}, CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_BOTTOMSLAB, 0, NULL}, // BACK (away from tile)
};

struct cmm_terrain cmm_terrain_fence = {
    2,
    0,
    cmm_terrain_fence_quad,
    NULL,
};

struct cmm_terrain cmm_terrain_fence_col = {
    4,
    0,
    cmm_terrain_fence_col_quads,
    NULL,
};


s8 pole_uvs1[4][2] = {{16, 0}, {16, 32}, {12, 0}, {12, 32}};
s8 pole_uvs2[4][2] = {{12, 0}, {12, 32}, {8, 0}, {8, 32}};
s8 pole_uvs3[4][2] = {{8, 0}, {8, 32}, {4, 0}, {4, 32}};
s8 pole_uvs4[4][2] = {{4, 0}, {4, 32}, {0, 0}, {0, 32}};
struct cmm_terrain_poly cmm_terrain_pole_quads[] = {
    {{{8, 16, 9}, {8, 0, 9}, {9, 16, 8}, {9, 0, 8}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, 0, &pole_uvs1}, // Diagonal 1
    {{{9, 16, 8}, {9, 0, 8}, {8, 16, 7}, {8, 0, 7}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_EMPTY, 0, &pole_uvs2}, // Diagonal 2
    {{{8, 16, 7}, {8, 0, 7}, {7, 16, 8}, {7, 0, 8}}, CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_EMPTY, 0, &pole_uvs3}, // Diagonal 3
    {{{7, 16, 8}, {7, 0, 8}, {8, 16, 9}, {8, 0, 9}}, CMM_DIRECTION_NEG_X, CMM_FACESHAPE_EMPTY, 0, &pole_uvs4}, // Diagonal 4

    {{{8, 16, 9}, {9, 16, 8}, {7, 16, 8}, {8, 16, 7}}, CMM_DIRECTION_UP,   CMM_FACESHAPE_POLETOP, 0, NULL}, // Top
    {{{8, 0, 9},  {7, 0, 8},  {9, 0, 8},  {8, 0, 7}},  CMM_DIRECTION_DOWN, CMM_FACESHAPE_POLETOP, 0, NULL}, // Bottom
};

struct cmm_terrain cmm_terrain_pole = {
    6,
    0,
    cmm_terrain_pole_quads,
    NULL,
};

struct cmm_terrain_poly cmm_terrain_bars_connected_quads[] = {
    {{{7, 16, 16}, {7, 16, 9}, {7, 0, 16}, {7, 0, 9}}, CMM_DIRECTION_NEG_X, CMM_FACESHAPE_EMPTY, 0, NULL}, // Left
    {{{9, 16, 9}, {9, 16, 16}, {9, 0, 9}, {9, 0, 16}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_EMPTY, 0, NULL}, // Right

    {{{7, 16, 16}, {9, 16, 16}, {7, 16, 9}, {9, 16, 9}}, CMM_DIRECTION_UP, CMM_FACESHAPE_EMPTY, 0, NULL}, // Top
    {{{9, 0, 16}, {7, 0, 16}, {9, 0, 9}, {7, 0, 9}}, CMM_DIRECTION_DOWN, CMM_FACESHAPE_EMPTY, 0, NULL}, // Bottom
};

struct cmm_terrain_poly cmm_terrain_bars_unconnected_quad[] = {
    {{{9, 16, 9}, {7, 16, 9}, {9, 0, 9}, {7, 0, 9}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_EMPTY, 0, NULL}, // Back
};

struct cmm_terrain_poly cmm_terrain_bars_center_quads[] = {
    {{{7, 16, 9}, {9, 16, 9}, {7, 16, 7}, {9, 16, 7}}, CMM_DIRECTION_UP, CMM_FACESHAPE_EMPTY, 0, NULL},
    {{{9, 0, 9}, {7, 0, 9}, {9, 0, 7}, {7, 0, 7}}, CMM_DIRECTION_DOWN, CMM_FACESHAPE_EMPTY, 0, NULL},
};

// Shapes of water tiles
struct cmm_terrain_poly cmm_terrain_shallowwater_quads[] = {
    {{{16, 14, 16}, {16, 14, 0}, {0, 14, 16}, {0, 14, 0}}, CMM_DIRECTION_UP, CMM_FACESHAPE_EMPTY, 0, NULL}, // TOP
    {{{16, 0, 16},  {0, 0, 16},  {16, 0, 0},  {0, 0, 0}},  CMM_DIRECTION_DOWN, CMM_FACESHAPE_FULL, 0, NULL}, // BOTTOM
    {{{16, 14, 16}, {16, 0, 16}, {16, 14, 0}, {16, 0, 0}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_FULL, 0, NULL}, // LEFT
    {{{0, 14, 16},  {0, 14, 0},  {0, 0, 16},  {0, 0, 0}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_FULL, 0, NULL}, // RIGHT
    {{{16, 14, 16}, {0, 14, 16}, {16, 0, 16}, {0, 0, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_FULL, 0, NULL}, // FRONT
    {{{16, 14, 0},  {16, 0, 0},  {0, 14, 0},  {0, 0, 0}},  CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, 0, NULL}, // BACK
};

struct cmm_terrain_poly cmm_terrain_topwater_quads[] = {
    {{{16, 16, 16}, {16, 16, 0}, {0, 16, 16}, {0, 16, 0}}, CMM_DIRECTION_UP, CMM_FACESHAPE_FULL, 0, NULL}, // TOP
    {{{16, 0, 16},  {0, 0, 16},  {16, 0, 0},  {0, 0, 0}},  CMM_DIRECTION_DOWN, CMM_FACESHAPE_FULL, 0, NULL}, // BOTTOM
    {{{16, 16, 16}, {16, 14, 16}, {16, 16, 0}, {16, 14, 0}}, CMM_DIRECTION_POS_X, CMM_FACESHAPE_FULL, 0, NULL}, // LEFT
    {{{0, 16, 16},  {0, 16, 0},  {0, 14, 16},  {0, 14, 0}},  CMM_DIRECTION_NEG_X, CMM_FACESHAPE_FULL, 0, NULL}, // RIGHT
    {{{16, 16, 16}, {0, 16, 16}, {16, 14, 16}, {0, 14, 16}}, CMM_DIRECTION_POS_Z, CMM_FACESHAPE_FULL, 0, NULL}, // FRONT
    {{{16, 16, 0},  {16, 14, 0},  {0, 16, 0},  {0, 14, 0}}, CMM_DIRECTION_NEG_Z, CMM_FACESHAPE_FULL, 0, NULL}, // BACK
};

struct cmm_terrain_poly *cmm_terrain_water_quadlists[] = {
    cmm_terrain_shallowwater_quads,
    cmm_terrain_fullblock_quads,
    cmm_terrain_topwater_quads,
};

enum {
    TILE_TYPE_EMPTY,
    // Flippable tiles
    TILE_TYPE_SLOPE = 2,
    TILE_TYPE_DSLOPE,
    TILE_TYPE_SLAB,
    TILE_TYPE_DSLAB,
    TILE_TYPE_CORNER,
    TILE_TYPE_DCORNER,
    TILE_TYPE_ICORNER,
    TILE_TYPE_DICORNER,
    TILE_TYPE_SCORNER,
    TILE_TYPE_DSCORNER,
    TILE_TYPE_UGENTLE,
    TILE_TYPE_DUGENTLE,
    TILE_TYPE_LGENTLE,
    TILE_TYPE_DLGENTLE,

    TILE_END_OF_FLIPPABLE,
    TILE_TYPE_BLOCK = TILE_END_OF_FLIPPABLE,
    TILE_TYPE_SSLOPE,
    TILE_TYPE_SSLAB,
    TILE_TYPE_CULL,
    TILE_TYPE_TROLL,
    TILE_TYPE_FENCE,
    TILE_TYPE_POLE,
    TILE_TYPE_BARS,

    TILE_TYPE_WATER, // only blocks that are empty otherwise
};

struct cmm_terrain_info {
    char *name;
    Gfx *button;
    struct cmm_terrain *terrain;
};

struct cmm_terrain_info cmm_terrain_info_list[] = {
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {"Slope", mat_b_btn_slope, &cmm_terrain_slope},
    {NULL, mat_b_btn_slope, &cmm_terrain_dslope},
    {"Slab", mat_b_btn_slabtile, &cmm_terrain_bottomslab},
    {NULL, mat_b_btn_slabtile, &cmm_terrain_topslab},
    {"Outer Corner", mat_b_btn_corner, &cmm_terrain_corner},
    {NULL, mat_b_btn_corner, &cmm_terrain_dcorner},
    {"Inner Corner", mat_b_btn_icorner, &cmm_terrain_icorner},
    {NULL, mat_b_btn_icorner, &cmm_terrain_dicorner},
    {"Sloped Corner", mat_b_btn_triangle, &cmm_terrain_scorner},
    {NULL, mat_b_btn_corner, &cmm_terrain_dscorner},
    {"Upper Gentle Slope", mat_b_btn_ugs, &cmm_terrain_ugentle},
    {NULL, mat_b_btn_slope, &cmm_terrain_dugentle},
    {"Lower Gentle Slope", mat_b_btn_lgs, &cmm_terrain_lgentle},
    {NULL, mat_b_btn_slope, &cmm_terrain_dlgentle},

    {"Tile", mat_b_btn_tile, &cmm_terrain_fullblock},
    {"Vertical Slope", mat_b_btn_sideslope, &cmm_terrain_sslope},
    {"Vertical Slab", mat_b_btn_vslab, &cmm_terrain_vslab},
    {"Cull Marker", mat_b_btn_cull, NULL},
    {"Intangible Tile", mat_b_btn_troll, &cmm_terrain_fullblock},
    {"Fence", mat_b_btn_fence, NULL},
    {"Pole", mat_b_btn_pole, NULL},
    {"Iron Mesh", mat_b_btn_bars, NULL},
    {"Water", mat_b_btn_water, NULL},
};

struct cmm_boundary_quad floor_boundary[] = {
    {{{32, 0, 32}, {32, 0, 0}, {0, 0, 32}, {0, 0, 0}}, {-16, 16}, {-16, 16}, FALSE, FALSE, FALSE},
    {{{0, 0, 32}, {0, 0, 0}, {-32, 0, 32}, {-32, 0, 0}}, {-16, 16}, {-16, 16}, FALSE, FALSE, FALSE},
    {{{32, 0, 0}, {32, 0, -32}, {0, 0, 0}, {0, 0, -32}}, {-16, 16}, {-16, 16}, FALSE, FALSE, FALSE},
    {{{0, 0, 0}, {0, 0, -32}, {-32, 0, 0}, {-32, 0, -32}}, {-16, 16}, {-16, 16}, FALSE, FALSE, FALSE},
};

struct cmm_boundary_quad floor_edge_boundary[] = {
    {{{48, 0, 32}, {48, 0, 0}, {32, 0, 32}, {32, 0, 0}}, {-16, 16}, {-8, 8}, FALSE, FALSE, FALSE},
    {{{48, 0, 32}, {32, 0, 32}, {48, 0, 48}, {32, 0, 48}}, {-8, 8}, {8, -8}, FALSE, FALSE, TRUE},
    {{{32, 0, 48}, {32, 0, 32}, {0, 0, 48}, {0, 0, 32}}, {-8, 8}, {-16, 16}, FALSE, FALSE, FALSE},

    {{{-32, 0, 32}, {-32, 0, 0}, {-48, 0, 32}, {-48, 0, 0}}, {-16, 16}, {-8, 8}, FALSE, FALSE, FALSE},
    {{{-32, 0, 48}, {-32, 0, 32}, {-48, 0, 48}, {-48, 0, 32}}, {-8, 8}, {-8, 8}, FALSE, FALSE, FALSE},
    {{{0, 0, 48}, {0, 0, 32}, {-32, 0, 48}, {-32, 0, 32}}, {-8, 8}, {-16, 16}, FALSE, FALSE, FALSE},

    {{{48, 0, 0}, {48, 0, -32}, {32, 0, 0}, {32, 0, -32}}, {-16, 16}, {-8, 8}, FALSE, FALSE, FALSE},
    {{{48, 0, -32}, {48, 0, -48}, {32, 0, -32}, {32, 0, -48}}, {-8, 8}, {-8, 8}, FALSE, FALSE, FALSE},
    {{{32, 0, -32}, {32, 0, -48}, {0, 0, -32}, {0, 0, -48}}, {-8, 8}, {-16, 16}, FALSE, FALSE, FALSE},

    {{{-32, 0, 0}, {-32, 0, -32}, {-48, 0, 0}, {-48, 0, -32}}, {-16, 16}, {-8, 8}, FALSE, FALSE, FALSE},
    {{{-32, 0, -48}, {-48, 0, -48}, {-32, 0, -32}, {-48, 0, -32}}, {-8, 8}, {8, -8}, FALSE, FALSE, TRUE},
    {{{0, 0, -32}, {0, 0, -48}, {-32, 0, -32}, {-32, 0, -48}}, {-8, 8}, {-16, 16}, FALSE, FALSE, FALSE},
};

struct cmm_boundary_quad wall_boundary[] = {
    {{{32, 1, 0}, {32, 1, -32}, {32, 0, 0}, {32, 0, -32}}, {16, -16}, {-8, 8}, FALSE, TRUE, FALSE},
    {{{32, 1, 32}, {32, 1, 0}, {32, 0, 32}, {32, 0, 0}}, {16, -16}, {-8, 8}, FALSE, TRUE, FALSE},

    {{{0, 1, 32}, {32, 1, 32}, {0, 0, 32}, {32, 0, 32}}, {16, -16}, {-8, 8}, FALSE, TRUE, FALSE},
    {{{-32, 1, 32}, {0, 1, 32}, {-32, 0, 32}, {0, 0, 32}}, {16, -16}, {-8, 8}, FALSE, TRUE, FALSE},

    {{{-32, 1, 0}, {-32, 1, 32}, {-32, 0, 0}, {-32, 0, 32}}, {16, -16}, {-8, 8}, FALSE, TRUE, FALSE},
    {{{-32, 1, -32}, {-32, 1, 0}, {-32, 0, -32}, {-32, 0, 0}}, {16, -16}, {-8, 8}, FALSE, TRUE, FALSE},

    {{{0, 1, -32}, {-32, 1, -32}, {0, 0, -32}, {-32, 0, -32}}, {16, -16}, {-8, 8}, FALSE, TRUE, FALSE},
    {{{32, 1, -32}, {0, 1, -32}, {32, 0, -32}, {0, 0, -32}}, {16, -16}, {-8, 8}, FALSE, TRUE, FALSE},
};

extern Gfx mat_maker_MakerMCWater[];
extern Gfx mat_maker_MakerMCLava[];
extern Gfx mat_maker_MakerMCFlowingLava[];

enum cmm_materials {
    CMM_MATLIST_START,

    // Terrain
    CMM_MAT_GRASS = CMM_MATLIST_START,
    CMM_MAT_GRASS_OLD,
    CMM_MAT_CARTOON_GRASS,
    CMM_MAT_DARK_GRASS,
    CMM_MAT_HMC_GRASS,
    CMM_MAT_ORANGE_GRASS,
    CMM_MAT_RED_GRASS,
    CMM_MAT_PURPLE_GRASS,
    CMM_MAT_SAND,
    CMM_MAT_JRB_SAND,
    CMM_MAT_SNOW,
    CMM_MAT_SNOW_OLD,

    CMM_MAT_DIRT,
    CMM_MAT_SANDDIRT,
    CMM_MAT_LIGHTDIRT,
    CMM_MAT_HMC_DIRT,
    CMM_MAT_ROCKY_DIRT,
    CMM_MAT_DIRT_OLD,
    CMM_MAT_WAVY_DIRT,
    CMM_MAT_WAVY_DIRT_BLUE,
    CMM_MAT_SNOWDIRT,
    CMM_MAT_PURPLE_DIRT,
    CMM_MAT_HMC_LAKEGRASS,

    CMM_MATLIST_TERRAIN_END,

    // Stone
    CMM_MAT_STONE = CMM_MATLIST_TERRAIN_END,
    CMM_MAT_HMC_STONE,
    CMM_MAT_HMC_MAZEFLOOR,
    CMM_MAT_CCM_ROCK,
    CMM_MAT_TTM_FLOOR,
    CMM_MAT_TTM_ROCK,
    CMM_MAT_COBBLESTONE,
    CMM_MAT_JRB_WALL,
    CMM_MAT_GABBRO,
    CMM_MAT_RHR_STONE,
    CMM_MAT_LAVA_ROCKS,
    CMM_MAT_VOLCANO_WALL,
    CMM_MAT_RHR_BASALT,
    CMM_MAT_OBSIDIAN,
    CMM_MAT_CASTLE_STONE,
    CMM_MAT_JRB_UNDERWATER,
    CMM_MAT_SNOW_ROCK,
    CMM_MAT_ICY_ROCK,
    CMM_MAT_DESERT_STONE,
    CMM_MAT_RHR_OBSIDIAN,
    CMM_MAT_JRB_STONE,

    CMM_MATLIST_STONE_END,

    // Bricks
    CMM_MAT_BRICKS = CMM_MATLIST_STONE_END,
    CMM_MAT_DESERT_BRICKS,
    CMM_MAT_RHR_BRICK,
    CMM_MAT_HMC_BRICK,
    CMM_MAT_LIGHTBROWN_BRICK,
    CMM_MAT_WDW_BRICK,
    CMM_MAT_TTM_BRICK,
    CMM_MAT_C_BRICK,
    CMM_MAT_BBH_BRICKS,
    CMM_MAT_ROOF_BRICKS,
    CMM_MAT_C_OUTSIDEBRICK,
    CMM_MAT_SNOW_BRICKS,
    CMM_MAT_JRB_BRICKS,
    CMM_MAT_SNOW_TILE_SIDE,
    CMM_MAT_TILESBRICKS,

    CMM_MATLIST_BRICKS_END,

    // Tiling
    CMM_MAT_TILES = CMM_MATLIST_BRICKS_END,
    CMM_MAT_C_TILES,
    CMM_MAT_DESERT_TILES,
    CMM_MAT_VP_BLUETILES,
    CMM_MAT_SNOW_TILES,
    CMM_MAT_JRB_TILETOP,
    CMM_MAT_JRB_TILESIDE,
    CMM_MAT_HMC_TILES,
    CMM_MAT_GRANITE_TILES,
    CMM_MAT_RHR_TILES,
    CMM_MAT_VP_TILES,
    CMM_MAT_DIAMOND_PATTERN,
    CMM_MAT_C_STONETOP,
    CMM_MAT_SNOW_BRICK_TILES,

    CMM_MATLIST_TILES_END,

    // Cut Stone
    CMM_MAT_DESERT_BLOCK = CMM_MATLIST_TILES_END,
    CMM_MAT_VP_BLOCK,
    CMM_MAT_BBH_STONE,
    CMM_MAT_BBH_STONE_PATTERN,
    CMM_MAT_PATTERNED_BLOCK,
    CMM_MAT_HMC_SLAB,
    CMM_MAT_RHR_BLOCK,
    CMM_MAT_GRANITE_BLOCK,
    CMM_MAT_C_STONESIDE,
    CMM_MAT_C_PILLAR,
    CMM_MAT_BBH_PILLAR,
    CMM_MAT_RHR_PILLAR,

    CMM_MATLIST_CUTSTONE_END,

    // Wood
    CMM_MAT_WOOD = CMM_MATLIST_CUTSTONE_END,
    CMM_MAT_BBH_WOOD_FLOOR,
    CMM_MAT_BBH_WOOD_WALL,
    CMM_MAT_C_WOOD,
    CMM_MAT_JRB_WOOD,
    CMM_MAT_JRB_SHIPSIDE,
    CMM_MAT_JRB_SHIPTOP,
    CMM_MAT_BBH_HAUNTED_PLANKS,
    CMM_MAT_BBH_ROOF,
    CMM_MAT_SOLID_WOOD,
    CMM_MAT_RHR_WOOD,

    CMM_MATLIST_WOOD_END,

    // Metal
    CMM_MAT_BBH_METAL = CMM_MATLIST_WOOD_END,
    CMM_MAT_JRB_METALSIDE,
    CMM_MAT_JRB_METAL,
    CMM_MAT_C_BASEMENTWALL,
    CMM_MAT_DESERT_TILES2,
    CMM_MAT_VP_RUSTYBLOCK,

    CMM_MATLIST_METAL_END,

    // Buildings
    CMM_MAT_C_CARPET = CMM_MATLIST_METAL_END,
    CMM_MAT_C_WALL,
    CMM_MAT_ROOF,
    CMM_MAT_C_ROOF,
    CMM_MAT_SNOW_ROOF,
    CMM_MAT_BBH_WINDOW,
    CMM_MAT_HMC_LIGHT,
    CMM_MAT_VP_CAUTION,
    CMM_MAT_RR_BLOCKS,
    CMM_MAT_STUDDED_TILE,
    CMM_MAT_TTC_BLOCK,
    CMM_MAT_TTC_SIDE,
    CMM_MAT_TTC_WALL,
    CMM_MAT_FLOWERS,

    CMM_MATLIST_BUILDING_END,

    // Hazards
    CMM_MAT_LAVA = CMM_MATLIST_BUILDING_END,
    CMM_MAT_LAVA_OLD,
    CMM_MAT_SERVER_ACID,
    CMM_MAT_BURNING_ICE,
    CMM_MAT_QUICKSAND,
    CMM_MAT_DESERT_SLOWSAND,
    CMM_MAT_VP_VOID,

    CMM_MATLIST_HAZARD_END,
    
    // Transparent
    CMM_MAT_RHR_MESH = CMM_MATLIST_HAZARD_END,
    CMM_MAT_VP_MESH,
    CMM_MAT_HMC_MESH,
    CMM_MAT_BBH_MESH,
    CMM_MAT_PINK_MESH,
    CMM_MAT_TTC_MESH,
    CMM_MAT_ICE,
    CMM_MAT_CRYSTAL,
    CMM_MAT_VP_SCREEN,

    CMM_MATLIST_END,

    // Retro
    CMM_MAT_RETRO_GROUND = CMM_MATLIST_END,
    CMM_MAT_RETRO_BRICKS,
    CMM_MAT_RETRO_TREETOP,
    CMM_MAT_RETRO_TREEPLAT,
    CMM_MAT_RETRO_BLOCK,
    CMM_MAT_RETRO_BLUEGROUND,
    CMM_MAT_RETRO_BLUEBRICKS,
    CMM_MAT_RETRO_BLUEBLOCK,
    CMM_MAT_RETRO_WHITEBRICK,
    CMM_MAT_RETRO_LAVA,
    CMM_MAT_RETRO_UNDERWATERGROUND,

    // Minecraft
    CMM_MAT_MC_DIRT,
    CMM_MAT_MC_GRASS,
    CMM_MAT_MC_COBBLESTONE,
    CMM_MAT_MC_STONE,
    CMM_MAT_MC_OAK_LOG_TOP,
    CMM_MAT_MC_OAK_LOG_SIDE,
    CMM_MAT_MC_OAK_LEAVES,
    CMM_MAT_MC_WOOD_PLANKS,
    CMM_MAT_MC_SAND,
    CMM_MAT_MC_BRICKS,
    CMM_MAT_MC_LAVA,
    CMM_MAT_MC_FLOWING_LAVA,
    CMM_MAT_MC_GLASS,
};

u8 cmm_matlist[] = {
    CMM_MATLIST_START,
    CMM_MATLIST_TERRAIN_END,
    CMM_MATLIST_STONE_END,
    CMM_MATLIST_BRICKS_END,
    CMM_MATLIST_TILES_END,
    CMM_MATLIST_CUTSTONE_END,
    CMM_MATLIST_WOOD_END,
    CMM_MATLIST_METAL_END,
    CMM_MATLIST_BUILDING_END,
    CMM_MATLIST_HAZARD_END,
    CMM_MATLIST_END,
};
char *cmm_matlist_names[] = {
    "Terrain",
    "Stone",
    "Bricks",
    "Tiling",
    "Cut Stone",
    "Wood",
    "Metal",
    "Other",
    "Hazards",
    "Transparent",
};

struct cmm_material cmm_mat_table[] = {
    // Terrain
    {mat_maker_MakerGrass,        0, SURFACE_GRASS,        "Grass"},       // CMM_MAT_GRASS
    {mat_maker_MakerVanillaGrass, 0, SURFACE_GRASS,        "Grass (Old)"}, // CMM_MAT_GRASS_OLD
    {mat_maker_MakerCartoonGrass, 0, SURFACE_GRASS,        "Smooth Grass"},// CMM_MAT_CARTOON_GRASS
    {mat_maker_MakerDarkGrass,    0, SURFACE_GRASS,        "Dark Grass"},  // CMM_MAT_DARK_GRASS
    {mat_maker_MakerHGrass,       0, SURFACE_GRASS,        "Cave Grass"},  // CMM_MAT_HMC_GRASS
    {mat_maker_MakerOrangeGrass,  0, SURFACE_GRASS,        "Orange Grass"},// CMM_MAT_ORANGE_GRASS
    {mat_maker_MakerRedGrass,     0, SURFACE_GRASS,        "Red Grass"},   // CMM_MAT_RED_GRASS
    {mat_maker_MakerPurpleGrass,  0, SURFACE_GRASS,        "Purple Grass"},// CMM_MAT_PURPLE_GRASS
    {mat_maker_MakerSand,         0, SURFACE_SAND,         "Sand"},        // CMM_MAT_SAND
    {mat_maker_MakerJRBSand,      0, SURFACE_SAND,         "Ocean Sand"},  // CMM_MAT_JRB_SAND
    {mat_maker_MakerSnow,         0, SURFACE_SNOW,         "Snow"},        // CMM_MAT_SNOW
    {mat_maker_MakerVanillaSnow,  0, SURFACE_SNOW,         "Snow (Old)"},  // CMM_MAT_SNOW_OLD
    {mat_maker_MakerDirt,         0, SURFACE_NOT_SLIPPERY, "Dirt"},        // CMM_MAT_DIRT
    {mat_maker_MakerSandDirt,     0, SURFACE_NOT_SLIPPERY, "Sandy Dirt"},  // CMM_MAT_SANDDIRT
    {mat_maker_MakerLightDirt,    0, SURFACE_NOT_SLIPPERY, "Light Dirt"},  // CMM_MAT_LIGHTDIRT
    {mat_maker_MakerHDirt,        0, SURFACE_NOT_SLIPPERY, "Cave Dirt"},   // CMM_MAT_HMC_DIRT
    {mat_maker_MakerRockyDirt,    0, SURFACE_NOT_SLIPPERY, "Rocky Dirt"},  // CMM_MAT_ROCKY_DIRT
    {mat_maker_MakerVanillaDirt,  0, SURFACE_NOT_SLIPPERY,  "Dirt (Old)"}, // CMM_MAT_DIRT_OLD
    {mat_maker_MakerWavyDirt,     0, SURFACE_NOT_SLIPPERY, "Wavy Dirt"},   // CMM_MAT_WAVY_DIRT
    {mat_maker_MakerWavyDirtBlue, 0, SURFACE_NOT_SLIPPERY, "Wavy Dirt (Blue)"}, // CMM_MAT_WAVY_DIRT_BLUE
    {mat_maker_MakerSnowDirt,     0, SURFACE_NOT_SLIPPERY, "Snowy Dirt"},  // CMM_MAT_SNOWDIRT
    {mat_maker_MakerPurpleDirt,   0, SURFACE_NOT_SLIPPERY, "Purple Dirt"}, // CMM_MAT_PURPLE_DIRT
    {mat_maker_MakerHLakewall,    0, SURFACE_NOT_SLIPPERY, "Clay"},        // CMM_MAT_HMC_LAKEGRASS

    // Stone
    {mat_maker_MakerStoneSide,     0, SURFACE_DEFAULT,      "White Stone"},     // CMM_MAT_STONE
    {mat_maker_MakerHStone,        0, SURFACE_NOT_SLIPPERY, "Cave Stone"},      // CMM_MAT_HMC_STONE
    {mat_maker_MakerHMazefloor,    0, SURFACE_NOT_SLIPPERY, "Beige Stone"},     // CMM_MAT_HMC_MAZEFLOOR
    {mat_maker_MakerCCMWall,       0, SURFACE_NOT_SLIPPERY, "Green Stone"},     // CMM_MAT_CCM_ROCK
    {mat_maker_MakerMountainFloor, 0, SURFACE_NOT_SLIPPERY, "Mountain Stone"},  // CMM_MAT_TTM_FLOOR
    {mat_maker_MakerMountainRock,  0, SURFACE_NOT_SLIPPERY, "Mountain Rock"},   // CMM_MAT_TTM_ROCK
    {mat_maker_MakerStone,         0, SURFACE_NOT_SLIPPERY, "White Rock"},      // CMM_MAT_COBBLESTONE
    {mat_maker_MakerJRBWall,       0, SURFACE_NOT_SLIPPERY, "Green Rock"},      // CMM_MAT_JRB_WALL
    {mat_maker_MakerBlackStone,    0, SURFACE_DEFAULT,      "Black Rock"},      // CMM_MAT_GABBRO
    {mat_maker_MakerRHRStone,      0, SURFACE_NOT_SLIPPERY, "Scorched Rock"},   // CMM_MAT_RHR_STONE
    {mat_maker_MakerLavaRock,      0, SURFACE_NOT_SLIPPERY, "Volcanic Rocks"},  // CMM_MAT_LAVA_ROCKS
    {mat_maker_MakerVolcanicRock,  0, SURFACE_NOT_SLIPPERY, "Volcanic Wall"},   // CMM_MAT_VOLCANO_WALL
    {mat_maker_MakerRHRBasalt,     0, SURFACE_NOT_SLIPPERY, "Basalt"},          // CMM_MAT_RHR_BASALT
    {mat_maker_MakerObsidian,      0, SURFACE_DEFAULT,      "Obsidian"},        // CMM_MAT_OBSIDIAN
    {mat_maker_MakerCastleCobble,  0, SURFACE_NOT_SLIPPERY, "Plum Concrete"},   // CMM_MAT_CASTLE_STONE
    {mat_maker_MakerJRBUnderwater, 0, SURFACE_DEFAULT,      "Ocean Floor"},     // CMM_MAT_JRB_UNDERWATER
    {mat_maker_MakerSnowRock,      0, SURFACE_DEFAULT,      "Snowy Rock"},      // CMM_MAT_SNOW_ROCK
    {mat_maker_MakerIcyRock,       0, SURFACE_VERY_SLIPPERY, "Icy Rock"},       // CMM_MAT_ICY_ROCK
    {mat_maker_MakerDStone,        0, SURFACE_NOT_SLIPPERY, "Cobblestone (1)"}, // CMM_MAT_DESERT_STONE
    {mat_maker_MakerRHRObsidian,   0, SURFACE_NOT_SLIPPERY, "Cobblestone (2)"}, // CMM_MAT_RHR_OBSIDIAN
    {mat_maker_MakerJRBStone,      0, SURFACE_NOT_SLIPPERY, "Cobblestone (3)"}, // CMM_MAT_JRB_STONE

    // Bricks
    {mat_maker_MakerBricks,         0, SURFACE_DEFAULT,      "Stone Bricks"},     // CMM_MAT_BRICKS
    {mat_maker_MakerDBrick,         0, SURFACE_DEFAULT,      "Desert Bricks"},    // CMM_MAT_DESERT_BRICKS
    {mat_maker_MakerRHRBrick,       0, SURFACE_NOT_SLIPPERY, "Scorched Bricks"},  // CMM_MAT_RHR_BRICK
    {mat_maker_MakerHBrick,         0, SURFACE_DEFAULT,      "Cave Bricks"},      // CMM_MAT_HMC_BRICK
    {mat_maker_MakerLightBrownBricks, 0, SURFACE_DEFAULT,    "Fortress Bricks"},  // CMM_MAT_LIGHTBROWN_BRICK
    {mat_maker_MakerBrownBricks,    0, SURFACE_DEFAULT,      "Brown Bricks (1)"}, // CMM_MAT_WDW_BRICK
    {mat_maker_MakerTTMBricks,      0, SURFACE_DEFAULT,      "Brown Bricks (2)"}, // CMM_MAT_TTM_BRICK
    {mat_maker_MakerCBrick,         0, SURFACE_NOT_SLIPPERY, "Castle Bricks"},    // CMM_MAT_C_BRICK
    {mat_maker_MakerBBHBricks,      0, SURFACE_NOT_SLIPPERY, "Red Bricks (1)"},   // CMM_MAT_BBH_BRICKS
    {mat_maker_MakerRoofBricks,     0, SURFACE_DEFAULT,      "Red Bricks (2)"},   // CMM_MAT_ROOF_BRICKS
    {mat_maker_MakerCOutsideBricks, 0, SURFACE_DEFAULT,      "White Bricks (1)"}, // CMM_MAT_C_OUTSIDE_BRICK
    {mat_maker_MakerSnowBricks,     0, SURFACE_DEFAULT,      "White Bricks (2)"}, // CMM_MAT_SNOW_BRICKS
    {mat_maker_MakerJRBBricks,      0, SURFACE_DEFAULT,      "Ocean Bricks"},     // CMM_MAT_JRB_BRICKS 
    {mat_maker_MakerSnowTileSide,   0, SURFACE_DEFAULT,      "Blue Bricks"},      // CMM_MAT_SNOW_TILE_SIDE
    {mat_maker_MakerTileBricks,     0, SURFACE_NOT_SLIPPERY, "Mixed Bricks"},     // CMM_MAT_TILESBRICKS

    // Tiling
    {mat_maker_MakerTiles,          0, SURFACE_NOT_SLIPPERY, "Checkered Tiling"}, // CMM_MAT_TILES
    {mat_maker_MakerCTiles,         0, SURFACE_NOT_SLIPPERY, "Castle Tiling"},    // CMM_MAT_C_TILES
    {mat_maker_MakerDTiles,         0, SURFACE_NOT_SLIPPERY, "Desert Tiling"},    // CMM_MAT_DESERT_TILES
    {mat_maker_MakerVBlueTiles,     0, SURFACE_NOT_SLIPPERY, "Blue Tiling (1)"},  // CMM_MAT_VP_BLUETILES
    {mat_maker_MakerSnowTiles,      0, SURFACE_NOT_SLIPPERY, "Blue Tiling (2)"},  // CMM_MAT_SNOW_TILES
    {mat_maker_MakerJRBTileTop,     0, SURFACE_NOT_SLIPPERY, "Ocean Tiling (1)"}, // CMM_MAT_JRB_TILETOP
    {mat_maker_MakerJRBTileSide,    0, SURFACE_NOT_SLIPPERY, "Ocean Tiling (2)"}, // CMM_MAT_JRB_TILESIDE
    {mat_maker_MakerHTileTop,       0, SURFACE_NOT_SLIPPERY, "Dark Tiling"},     // CMM_MAT_HMC_TILES
    {mat_maker_MakerGraniteTiles,   0, SURFACE_NOT_SLIPPERY, "Granite Tiling"},   // CMM_MAT_GRANITE_TILES
    {mat_maker_MakerRHRTiles,       0, SURFACE_NOT_SLIPPERY, "Black Tiling"},    // CMM_MAT_RHR_TILES
    {mat_maker_MakerVTiles,         0, SURFACE_NOT_SLIPPERY, "Grey Tiling"},     // CMM_MAT_VP_TILES
    {mat_maker_MakerDiamondPattern, 0, SURFACE_NOT_SLIPPERY, "Diamond Pattern"},  // CMM_MAT_DIAMOND_PATTERN
    {mat_maker_MakerCStone,         0, SURFACE_NOT_SLIPPERY, "Hex Tiling"},       // CMM_MAT_C_STONETOP
    {mat_maker_MakerSnowBrickTiles, 0, SURFACE_NOT_SLIPPERY, "Diamond Tiling"},   // CMM_MAT_SNOW_BRICK_TILES

    // Cut Stone
    {mat_maker_MakerDStoneBlock,     0, SURFACE_NOT_SLIPPERY, "Block"},           // CMM_MAT_DESERT_BLOCK
    {mat_maker_MakerVBlock,          0, SURFACE_NOT_SLIPPERY, "Smooth Block"},    // CMM_MAT_VP_BLOCK
    {mat_maker_MakerBBHWall,         0, SURFACE_DEFAULT,      "Mansion Wall"},    // CMM_MAT_BBH_STONE
    {mat_maker_MakerBBHStonePattern, 0, SURFACE_NOT_SLIPPERY, "Chiseled Wall"},   // CMM_MAT_BBH_STONE_PATTERN
    {mat_maker_MakerLauncherTex,     0, SURFACE_DEFAULT,      "Patterned Block"}, // CMM_MAT_PATTERNED_BLOCK
    {mat_maker_MakerHTileSide,       0, SURFACE_NOT_SLIPPERY, "Black Slabs"},     // CMM_MAT_HMC_SLAB
    {mat_maker_MakerRHRPattern,      0, SURFACE_DEFAULT,      "Chiseled Block"},  // CMM_MAT_RHR_BLOCK
    {mat_maker_MakerGraniteBlock,    0, SURFACE_NOT_SLIPPERY, "Granite Block"},   // CMM_MAT_GRANITE_BLOCK
    {mat_maker_MakerCStoneSide,      0, SURFACE_DEFAULT,      "Stone Slab"},      // CMM_MAT_C_STONESIDE
    {mat_maker_MakerCPillar,         0, SURFACE_DEFAULT,      "Castle Pillar"},   // CMM_MAT_C_PILLAR
    {mat_maker_MakerBBHPillar,       0, SURFACE_DEFAULT,      "Mansion Pillar"},  // CMM_MAT_BBH_PILLAR
    {mat_maker_MakerRHRPillar,       0, SURFACE_DEFAULT,      "Scorched Pillar"}, // CMM_MAT_RHR_PILLAR

    // Wood
    {mat_maker_MakerWood,            0, SURFACE_CREAKWOOD,    "Planks (1)"},    // CMM_MAT_WOOD
    {mat_maker_MakerBBHWoodWall,     0, SURFACE_CREAKWOOD,    "Planks (2)"},    // CMM_MAT_BBH_WOOD_WALL
    {mat_maker_MakerBBHWoodFloor,    0, SURFACE_CREAKWOOD,    "Dark Planks"},   // CMM_MAT_BBH_WOOD_FLOOR
    {mat_maker_MakerCWood,           0, SURFACE_CREAKWOOD,    "Castle Planks"}, // CMM_MAT_C_WOOD
    {mat_maker_MakerJRBWood,         0, SURFACE_CREAKWOOD,    "Docks"},         // CMM_MAT_JRB_WOOD
    {mat_maker_MakerJRBShipSide,     0, SURFACE_CREAKWOOD,    "Ship Planks"},   // CMM_MAT_JRB_SHIPSIDE
    {mat_maker_MakerJRBShipTop,      0, SURFACE_CREAKWOOD,    "Ship Decking"},  // CMM_MAT_JRB_SHIPTOP
    {mat_maker_MakerBBHHauntedPlanks,0, SURFACE_CREAKWOOD,    "Spooky Planks"}, // CMM_MAT_BBH_HAUNTED_PLANKS
    {mat_maker_MakerBBHRoof,         0, SURFACE_CREAKWOOD,    "Mansion Roof"},  // CMM_MAT_BBH_ROOF
    {mat_maker_MakerSolidWood,       0, SURFACE_NOT_SLIPPERY, "Wood (Old)"},    // CMM_MAT_SOLID_WOOD
    {mat_maker_MakerRHRWood,         0, SURFACE_NOT_SLIPPERY, "Scorched Wood"}, // CMM_MAT_RHR_WOOD

    // Metal
    {mat_maker_MakerBBHMetal,        0, SURFACE_NOT_SLIPPERY, "Metal Flooring"},   // CMM_MAT_BBH_METAL
    {mat_maker_MakerJRBMetalSide,    0, SURFACE_DEFAULT,      "Metal Sheet"},      // CMM_MAT_JRB_METALSIDE
    {mat_maker_MakerJRBMetal,        0, SURFACE_DEFAULT,      "Metal Plating"},    // CMM_MAT_JRB_METAL
    {mat_maker_MakerCBasementWall,   0, SURFACE_DEFAULT,      "Basement Plating"}, // CMM_MAT_C_BASEMENTWALL
    {mat_maker_MakerDTiles2,         0, SURFACE_DEFAULT,      "Desert Plating"},   // CMM_MAT_DESERT_TILES2
    {mat_maker_MakerVRustyBlock,     0, SURFACE_NOT_SLIPPERY, "Rusted Block"},     // CMM_MAT_VP_RUSTYBLOCK

    // Other
    {mat_maker_MakerCCarpet,   0, SURFACE_GRASS,         "Carpet"},         // CMM_MAT_C_CARPET
    {mat_maker_MakerCWall,     0, SURFACE_DEFAULT,       "Castle Wall"},    // CMM_MAT_C_WALL
    {mat_maker_MakerRoof,      0, SURFACE_NOT_SLIPPERY,  "Roof"},           // CMM_MAT_ROOF
    {mat_maker_MakerCRoof,     0, SURFACE_NOT_SLIPPERY,  "Castle Roof"},    // CMM_MAT_C_ROOF
    {mat_maker_MakerSnowRoof,  0, SURFACE_VERY_SLIPPERY, "Blue Roof"},      // CMM_MAT_SNOW_ROOF
    {mat_maker_MakerBBHWindow, 0, SURFACE_DEFAULT,       "Window"},         // CMM_MAT_BBH_WINDOW
    {mat_maker_MakerHLight,    0, SURFACE_DEFAULT,       "Lantern"},        // CMM_MAT_HMC_LIGHT
    {mat_maker_MakerCaution,   0, SURFACE_DEFAULT,       "Hazard Stripes"}, // CMM_MAT_VP_CAUTION
    {mat_maker_MakerRRBlocks,  0, SURFACE_DEFAULT,       "Rainbow Blocks"},  // CMM_MAT_RR_BLOCKS
    {mat_maker_MakerStuddedFloor, 0, SURFACE_NOT_SLIPPERY, "Studded Tile"},  // CMM_MAT_STUDDED_TILE
    {mat_maker_MakerYellowBlock, 0, SURFACE_DEFAULT,     "Yellow Block"},   // CMM_MAT_TTC_BLOCK
    {mat_maker_MakerTTCSide,   0, SURFACE_DEFAULT,       "Clock Platform"}, // CMM_MAT_TTC_SIDE
    {mat_maker_MakerTTCWall,   0, SURFACE_DEFAULT,       "Clock Exterior"}, // CMM_MAT_TTC_WALL
    {mat_maker_MakerFlowerTop, 0, SURFACE_GRASS,         "Flowers"},        // CMM_MAT_FLOWERS

    // Hazards
    {mat_maker_MakerLava,       0, SURFACE_BURNING_BUBBLES,   "Lava"},           // CMM_MAT_LAVA
    {mat_maker_MakerVanillaLava, 0, SURFACE_BURNING_BUBBLES,  "Lava (Old)"},     // CMM_MAT_LAVA_OLD
    {mat_maker_MakerServerAcid, 0, SURFACE_BURNING_ICE,       "Server Acid"},    // CMM_MAT_SERVER_ACID
    {mat_maker_MakerBurningIce, 0, SURFACE_BURNING_ICE,       "Hazard Ice"},     // CMM_MAT_BURNING_ICE
    {mat_maker_MakerQuicksand,  0, SURFACE_INSTANT_QUICKSAND, "Quicksand"},      // CMM_MAT_QUICKSAND
    {mat_maker_MakerSlowsand,   0, SURFACE_DEEP_QUICKSAND,    "Slow Quicksand"}, // CMM_MAT_DESERT_SLOWSAND
    {mat_maker_MakerVoid,       0, SURFACE_INSTANT_QUICKSAND, "Void"},           // CMM_MAT_VP_VOID

    // Seethrough
    {mat_maker_MakerRHRMesh, MAT_CUTOUT,      SURFACE_HANGABLE_MESH, "Mesh"},         // CMM_MAT_RHR_MESH
    {mat_maker_MakerVPMesh,  MAT_CUTOUT,      SURFACE_HANGABLE_MESH, "Fine Mesh"},    // CMM_MAT_VP_MESH
    {mat_maker_MakerHMesh,   MAT_CUTOUT,      SURFACE_HANGABLE_MESH, "Red Grille"},   // CMM_MAT_HMC_MESH
    {mat_maker_MakerBBHMesh, MAT_CUTOUT,      SURFACE_HANGABLE_MESH, "Red Mesh"},     // CMM_MAT_BBH_MESH
    {mat_maker_MakerGratePink, MAT_CUTOUT,    SURFACE_HANGABLE_MESH, "Pink Mesh"},    // CMM_MAT_PINK_MESH
    {mat_maker_MakerTTCGrate, MAT_CUTOUT,     SURFACE_HANGABLE_MESH, "Clock Grille"}, // CMM_MAT_TTC_MESH
    {mat_maker_MakerIce,     MAT_TRANSPARENT, SURFACE_ICE,           "Ice"},          // CMM_MAT_ICE
    {mat_maker_MakerCrystal, MAT_TRANSPARENT, SURFACE_CRYSTAL,       "Crystal"},      // CMM_MAT_CRYSTAL
    {mat_maker_MakerScreen,  MAT_DECAL,       SURFACE_DEFAULT,       "Screen"},       // CMM_MAT_VP_SCREEN

    // Retro
    {mat_maker_MakerRetroGround,     0, SURFACE_NOT_SLIPPERY, NULL}, // CMM_MAT_RETRO_GROUND
    {mat_maker_MakerRetroBrick,      0, SURFACE_DEFAULT,      NULL}, // CMM_MAT_RETRO_BRICKS
    {mat_maker_MakerRetroTreeTop,    0, SURFACE_GRASS,        NULL}, // CMM_MAT_RETRO_TREETOP
    {mat_maker_MakerRetroTree,       0, SURFACE_DEFAULT,      NULL}, // CMM_MAT_RETRO_TREEPLAT
    {mat_maker_MakerRetroBlock,      0, SURFACE_NOT_SLIPPERY, NULL}, // CMM_MAT_RETRO_BLOCK
    {mat_maker_MakerRetroBGround,    0, SURFACE_NOT_SLIPPERY, NULL}, // CMM_MAT_RETRO_BLUEGROUND
    {mat_maker_MakerRetroBBrick,     0, SURFACE_DEFAULT,      NULL}, // CMM_MAT_RETRO_BLUEBRICKS
    {mat_maker_MakerRetroBBlock,     0, SURFACE_NOT_SLIPPERY, NULL}, // CMM_MAT_RETRO_BLUEBLOCK
    {mat_maker_MakerRetroWBrick,     0, SURFACE_DEFAULT,      NULL}, // CMM_MAT_RETRO_WHITEBRICK
    {mat_maker_MakerRetroLava,       0, SURFACE_BURNING,      NULL}, // CMM_MAT_RETRO_LAVA
    {mat_maker_MakerRetroUnderwater, 0, SURFACE_NOT_SLIPPERY, NULL}, // CMM_MAT_RETRO_UNDERWATERGROUND

    // Minecraft
    {mat_maker_MakerMCDirt,        0, SURFACE_NOT_SLIPPERY, NULL}, // CMM_MAT_MC_DIRT
    {mat_maker_MakerMCGrassTop,    0, SURFACE_GRASS,        NULL}, // CMM_MAT_MC_GRASS
    {mat_maker_MakerMCCobblestone, 0, SURFACE_NOT_SLIPPERY, NULL}, // CMM_MAT_MC_COBBLESTONE
    {mat_maker_MakerMCStone,       0, SURFACE_DEFAULT,      NULL}, // CMM_MAT_MC_STONE
    {mat_maker_MakerMCOakLogTop,   0, SURFACE_CREAKWOOD,    NULL}, // CMM_MAT_MC_OAK_LOG_TOP
    {mat_maker_MakerMCOakLogSide,  0, SURFACE_CREAKWOOD,    NULL}, // CMM_MAT_MC_OAK_LOG_SIDE
    {mat_maker_MakerMCOakLeaves,   MAT_CUTOUT,        SURFACE_GRASS,            NULL}, // CMM_MAT_MC_OAK_LEAVES
    {mat_maker_MakerMCWoodPlanks,  0, SURFACE_CREAKWOOD,    NULL}, // CMM_MAT_MC_WOOD_PLANKS
    {mat_maker_MakerMCSand,        0, SURFACE_SAND,         NULL}, // CMM_MAT_MC_SAND
    {mat_maker_MakerMCBricks,      0, SURFACE_DEFAULT,      NULL}, // CMM_MAT_MC_BRICKS
    {mat_maker_MakerMCLava,        0, SURFACE_BURNING,      NULL}, // CMM_MAT_MC_LAVA
    {mat_maker_MakerMCFlowingLava, 0, SURFACE_BURNING,      NULL}, // CMM_MAT_MC_FLOWING_LAVA
    {mat_maker_MakerMCGlass,       MAT_CUTOUT_NOCULL, SURFACE_VANISH_CAP_WALLS, NULL}, // CMM_MAT_MC_GLASS
};

u32 cmm_render_mode_table[] = {
    /* MAT_OPAQUE */        G_RM_ZB_OPA_SURF    | G_RM_ZB_OPA_SURF2,
    /* MAT_DECAL */         G_RM_TEX_EDGE_DECAL | G_RM_TEX_EDGE_DECAL2,
    /* MAT_CUTOUT */        G_RM_AA_ZB_TEX_EDGE | G_RM_AA_ZB_TEX_EDGE2,
    /* MAT_CUTOUT_NOCULL */ G_RM_AA_ZB_TEX_EDGE | G_RM_AA_ZB_TEX_EDGE2,
    /* MAT_TRANSPARENT */   G_RM_AA_ZB_XLU_SURF | G_RM_AA_ZB_XLU_SURF2,
    /* MAT_SCREEN */        G_RM_VPLEX_SCREEN   | G_RM_VPLEX_SCREEN2,
};

struct cmm_topmaterial cmm_topmat_table[] = {
    {CMM_MAT_GRASS,         mat_maker_MakerGrassSide},
    {CMM_MAT_SAND,          mat_maker_MakerSandSide},
    {CMM_MAT_SNOW,          mat_maker_MakerSnowSide},
    {CMM_MAT_TILES,         mat_maker_MakerTileEdge},
    {CMM_MAT_C_STONETOP,    mat_maker_MakerCastleHexRim},
    {CMM_MAT_HMC_GRASS,     mat_maker_MakerHGrassSide},
    {CMM_MAT_BBH_METAL,     mat_maker_MakerBBHMetalSide},
    {CMM_MAT_BBH_STONE,     mat_maker_MakerBBHMetalSide},
    {CMM_MAT_JRB_TILETOP,   mat_maker_MakerJRBTileRim},
    {CMM_MAT_SNOW_TILES,    mat_maker_MakerSnowTileRim},
    {CMM_MAT_FLOWERS,       mat_maker_MakerFlowerEdge},
    {CMM_MAT_RETRO_TREETOP, mat_maker_MakerRetroTreeSide},
    {CMM_MAT_MC_GRASS,      mat_maker_MakerMCGrassEdge},
    {CMM_MAT_LAVA_ROCKS,    mat_maker_MakerLavaRockEdge},
    {CMM_MAT_DARK_GRASS,    mat_maker_MakerDarkGrassSide},
    {CMM_MAT_CARTOON_GRASS, mat_maker_MakerCartoonGrassSide},
    {CMM_MAT_ORANGE_GRASS,  mat_maker_MakerOrangeGrassSide},
    {CMM_MAT_RED_GRASS,     mat_maker_MakerRedGrassSide},
    {CMM_MAT_PURPLE_GRASS,  mat_maker_MakerPurpleGrassSide},
};

enum cmm_fences {
    CMM_FENCE_NORMAL,
    CMM_FENCE_WOOD2,
    CMM_FENCE_DESERT,
    CMM_FENCE_BARBED,
    CMM_FENCE_RHR,
    CMM_FENCE_HMC,
    CMM_FENCE_CASTLE,
    CMM_FENCE_VIRTUAPLEX,
    CMM_FENCE_BBH,
    CMM_FENCE_JRB,
    CMM_FENCE_SNOW2,
    CMM_FENCE_SNOW,
    CMM_FENCE_RETRO,
    CMM_FENCE_MC,
};

Gfx *cmm_fence_texs[] = {
    mat_maker_MakerFence,
    mat_maker_MakerWoodenFence,
    mat_maker_MakerDFence,
    mat_maker_MakerBarbedWire,
    mat_maker_MakerRHRFence,
    mat_maker_MakerHFence,
    mat_maker_MakerCFence,
    mat_maker_MakerVPFence,
    mat_maker_MakerBBHFence,
    mat_maker_MakerJRBFence,
    mat_maker_MakerSnowFence2,
    mat_maker_MakerSnowFence,
    mat_maker_MakerRetroFence,
    mat_maker_MakerMCFence,
};

enum cmm_bars {
    CMM_BAR_GENERIC,
    CMM_BAR_RHR,
    CMM_BAR_VP,
    CMM_BAR_HMC,
    CMM_BAR_BBH,
    CMM_BAR_LLL,
    CMM_BAR_TTC,
    CMM_BAR_DESERT,
    CMM_BAR_BOB,
    CMM_BAR_RETRO,
    CMM_BAR_MC,
};
Gfx *cmm_bar_texs[][2] = {
    {mat_maker_MakerIronBars,   mat_maker_MakerIronBarsTop},
    {mat_maker_MakerRHRMesh,    mat_maker_MakerChainTop},
    {mat_maker_MakerVPMesh,     mat_maker_MakerChainTop},
    {mat_maker_MakerHMesh,      mat_maker_MakerHMCTop},
    {mat_maker_MakerBBHMesh,    mat_maker_MakerHMCTop},
    {mat_maker_MakerGratePink,  mat_maker_MakerChainTopPink},
    {mat_maker_MakerTTCGrate,   mat_maker_MakerTTCGrateTop},
    {mat_maker_MakerDMesh,      mat_maker_MakerDesertMeshTop},
    {mat_maker_MakerBOBBars,    mat_maker_MakerBOBBarsTop},
    {mat_maker_MakerRetroMesh,  mat_maker_MakerRetroMeshTop},
    {mat_maker_MakerMCIronBars, mat_maker_MakerMCIronBarsTop},
};

enum cmm_water {
    CMM_WATER_DEFAULT,
    CMM_WATER_GREEN,
    CMM_WATER_RETRO,
    CMM_WATER_MC,
};

Gfx *cmm_water_texs[] = {
    mat_maker_MakerWater,
    mat_maker_MakerGreenWater,
    mat_maker_MakerRetroWater,
    mat_maker_MakerMCWater,
};

struct cmm_theme cmm_theme_table[] = {
    // GENERIC
    {
        {
            {CMM_MAT_DIRT,        CMM_MAT_GRASS,     "Grass"},
            {CMM_MAT_BRICKS,      CMM_MAT_BRICKS,    "Bricks"},
            {CMM_MAT_COBBLESTONE, CMM_MAT_STONE,     "Rock"},
            {CMM_MAT_TILESBRICKS, CMM_MAT_TILES,     "Tiling"},
            {CMM_MAT_ROOF,        CMM_MAT_ROOF,      "Roof"},
            {CMM_MAT_WOOD,        CMM_MAT_WOOD,      "Wood"},
            {CMM_MAT_SANDDIRT,    CMM_MAT_SAND,      "Sand"},
            {CMM_MAT_SNOWDIRT,    CMM_MAT_SNOW,      "Snow"},
            {CMM_MAT_LAVA,        CMM_MAT_LAVA,      "Lava"},
            {CMM_MAT_QUICKSAND,   CMM_MAT_QUICKSAND, "Quicksand"},
        },
        CMM_FENCE_NORMAL, CMM_MAT_STONE, CMM_BAR_GENERIC, CMM_WATER_DEFAULT
    },
    // DESERT
    {
        {
            {CMM_MAT_SANDDIRT,        CMM_MAT_SAND,            "Sand"},
            {CMM_MAT_DESERT_BRICKS,   CMM_MAT_DESERT_BRICKS,   "Bricks"},
            {CMM_MAT_DESERT_STONE,    CMM_MAT_DESERT_STONE,    "Cobblestone"},
            {CMM_MAT_DESERT_TILES,    CMM_MAT_DESERT_TILES,    "Tiling"},
            {CMM_MAT_DESERT_BLOCK,    CMM_MAT_DESERT_BLOCK,    "Stone Block"},
            {CMM_MAT_DESERT_SLOWSAND, CMM_MAT_DESERT_SLOWSAND, "Slow Quicksand"},
            {CMM_MAT_DESERT_BRICKS,   CMM_MAT_DESERT_TILES2,   "Plating"},
            {CMM_MAT_DIRT,            CMM_MAT_GRASS,           "Grass"},
            {CMM_MAT_LAVA,            CMM_MAT_LAVA,            "Lava"},
            {CMM_MAT_QUICKSAND,       CMM_MAT_QUICKSAND,       "Quicksand"},
        },
        CMM_FENCE_DESERT, CMM_MAT_DESERT_TILES2, CMM_BAR_DESERT, CMM_WATER_GREEN
    },
    // LAVA
    {
        {
            {CMM_MAT_RHR_STONE,   CMM_MAT_RHR_OBSIDIAN, "Rock"},
            {CMM_MAT_RHR_BRICK,   CMM_MAT_RHR_OBSIDIAN, "Bricks"},
            {CMM_MAT_RHR_BASALT,  CMM_MAT_RHR_BASALT,   "Basalt"},
            {CMM_MAT_RHR_TILES,   CMM_MAT_RHR_TILES,    "Tiling"},
            {CMM_MAT_RHR_BLOCK,   CMM_MAT_RHR_BLOCK,    "Stone Block"},
            {CMM_MAT_RHR_WOOD,    CMM_MAT_RHR_WOOD,     "Wood"},
            {CMM_MAT_RHR_PILLAR,  CMM_MAT_RHR_TILES,    "Pillar"},
            {CMM_MAT_RHR_MESH,    CMM_MAT_RHR_MESH,     "Mesh"},
            {CMM_MAT_LAVA,        CMM_MAT_LAVA,         "Lava"},
            {CMM_MAT_SERVER_ACID, CMM_MAT_SERVER_ACID,  "Server Acid"},
        },
        CMM_FENCE_RHR, CMM_MAT_RHR_PILLAR, CMM_BAR_RHR, CMM_WATER_DEFAULT
    },
    // CAVE
    {
        {
            {CMM_MAT_HMC_DIRT,      CMM_MAT_HMC_GRASS,     "Grass"},
            {CMM_MAT_HMC_BRICK,     CMM_MAT_HMC_MAZEFLOOR, "Bricks"},
            {CMM_MAT_HMC_STONE,     CMM_MAT_HMC_STONE,     "Rock"},
            {CMM_MAT_HMC_SLAB,      CMM_MAT_HMC_TILES,     "Tiling"},
            {CMM_MAT_HMC_BRICK,     CMM_MAT_HMC_GRASS,     "Grassy Bricks"},
            {CMM_MAT_HMC_LAKEGRASS, CMM_MAT_HMC_GRASS,     "Lake Wall"},
            {CMM_MAT_HMC_LIGHT,     CMM_MAT_HMC_LIGHT,     "Light"},
            {CMM_MAT_HMC_MESH,      CMM_MAT_HMC_MESH,      "Grille"},
            {CMM_MAT_LAVA,          CMM_MAT_LAVA,          "Lava"},
            {CMM_MAT_QUICKSAND,     CMM_MAT_QUICKSAND,     "Quicksand"},
        },
        CMM_FENCE_HMC, CMM_MAT_HMC_LAKEGRASS, CMM_BAR_HMC, CMM_WATER_GREEN
    },
    // CASTLE
    {
        {
            {CMM_MAT_C_WOOD,         CMM_MAT_C_TILES,        "Tiling"},
            {CMM_MAT_C_BRICK,        CMM_MAT_C_TILES,        "Tiling (Bricks)"},
            {CMM_MAT_C_STONESIDE,    CMM_MAT_C_STONETOP,     "Tiling (Stone)"},
            {CMM_MAT_C_WOOD,         CMM_MAT_C_CARPET,       "Carpet"},
            {CMM_MAT_C_ROOF,         CMM_MAT_C_ROOF,         "Roof"},
            {CMM_MAT_C_WALL,         CMM_MAT_C_WALL,         "Castle Wall"},
            {CMM_MAT_C_PILLAR,       CMM_MAT_C_STONETOP,     "Pillar"},
            {CMM_MAT_C_BASEMENTWALL, CMM_MAT_C_BASEMENTWALL, "Basement Wall"},
            {CMM_MAT_LAVA,           CMM_MAT_LAVA,           "Lava"},
            {CMM_MAT_C_OUTSIDEBRICK, CMM_MAT_C_OUTSIDEBRICK, "Castle Bricks"},
        },
        CMM_FENCE_CASTLE, CMM_MAT_C_STONESIDE, CMM_BAR_VP, CMM_WATER_DEFAULT
    },
    // VIRTUAPLEX
    {
        {
            {CMM_MAT_VP_BLOCK,      CMM_MAT_VP_BLOCK,      "Block"},
            {CMM_MAT_VP_TILES,      CMM_MAT_VP_TILES,      "Tiling"},
            {CMM_MAT_DIRT,          CMM_MAT_GRASS,         "Grass"},
            {CMM_MAT_VP_TILES,      CMM_MAT_VP_BLUETILES,  "Blue Tiling"},
            {CMM_MAT_VP_RUSTYBLOCK, CMM_MAT_VP_RUSTYBLOCK, "Rusted Block"},
            {CMM_MAT_VP_SCREEN,     CMM_MAT_VP_SCREEN,     "Screen"},
            {CMM_MAT_VP_CAUTION,    CMM_MAT_VP_CAUTION,    "Hazard Stripes"},
            {CMM_MAT_VP_BLOCK,      CMM_MAT_SNOW,          "Snowy Block"},
            {CMM_MAT_LAVA,          CMM_MAT_LAVA,          "Lava"},
            {CMM_MAT_VP_VOID,       CMM_MAT_VP_VOID,       "Void"},
        },
        CMM_FENCE_VIRTUAPLEX, CMM_MAT_VP_CAUTION, CMM_BAR_VP, CMM_WATER_DEFAULT
    },
    // SNOW
    {
        {
            {CMM_MAT_SNOWDIRT,       CMM_MAT_SNOW,             "Snow"},
            {CMM_MAT_SNOW_BRICKS,    CMM_MAT_SNOW_BRICK_TILES, "Bricks"},
            {CMM_MAT_SNOW_ROCK,      CMM_MAT_SNOW_ROCK,        "Rock"},
            {CMM_MAT_SNOW_TILE_SIDE, CMM_MAT_SNOW_TILES,       "Tiling"},
            {CMM_MAT_SNOW_ROOF,      CMM_MAT_SNOW_ROOF,        "Roof"},
            {CMM_MAT_WOOD,           CMM_MAT_WOOD,             "Wood"},
            {CMM_MAT_CRYSTAL,        CMM_MAT_CRYSTAL,          "Crystal"},
            {CMM_MAT_ICE,            CMM_MAT_ICE,              "Ice"},
            {CMM_MAT_BURNING_ICE,    CMM_MAT_BURNING_ICE,      "Hazard Ice"},
            {CMM_MAT_LAVA,           CMM_MAT_LAVA,             "Lava"},
        },
        CMM_FENCE_SNOW, CMM_MAT_SNOW_TILE_SIDE, CMM_BAR_GENERIC, CMM_WATER_DEFAULT
    },
    // BBH
    {
        {
            {CMM_MAT_BBH_BRICKS,         CMM_MAT_BBH_STONE,          "Stone Floor"},
            {CMM_MAT_BBH_HAUNTED_PLANKS, CMM_MAT_BBH_HAUNTED_PLANKS, "Haunted Planks"},
            {CMM_MAT_BBH_STONE_PATTERN,  CMM_MAT_BBH_WOOD_FLOOR,     "Wood Floor"},
            {CMM_MAT_BBH_BRICKS,         CMM_MAT_BBH_METAL,          "Metal Floor"},
            {CMM_MAT_BBH_ROOF,           CMM_MAT_BBH_ROOF,           "Roof"},
            {CMM_MAT_BBH_WOOD_WALL,      CMM_MAT_BBH_WOOD_WALL,      "Wood"},
            {CMM_MAT_BBH_STONE,          CMM_MAT_BBH_STONE,          "Wall"},
            {CMM_MAT_BBH_PILLAR,         CMM_MAT_BBH_STONE,          "Pillar"},
            {CMM_MAT_LAVA,               CMM_MAT_LAVA,               "Lava"},
            {CMM_MAT_BBH_WINDOW,         CMM_MAT_BBH_WINDOW,         "Window"},
        },
        CMM_FENCE_BBH, CMM_MAT_BBH_BRICKS, CMM_BAR_BBH, CMM_WATER_DEFAULT
    },
    // JRB
    {
        {
            {CMM_MAT_JRB_STONE,      CMM_MAT_JRB_SAND,       "Sand"},
            {CMM_MAT_JRB_BRICKS,     CMM_MAT_JRB_BRICKS,     "Bricks"},
            {CMM_MAT_JRB_UNDERWATER, CMM_MAT_JRB_UNDERWATER, "Ocean Floor"},
            {CMM_MAT_JRB_TILESIDE,   CMM_MAT_JRB_TILETOP,    "Tiles"},
            {CMM_MAT_JRB_SHIPSIDE,   CMM_MAT_JRB_SHIPTOP,    "Wood (Ship)"},
            {CMM_MAT_JRB_METAL,      CMM_MAT_JRB_WOOD,       "Wood (Docks)"},
            {CMM_MAT_JRB_METALSIDE,  CMM_MAT_JRB_METAL,      "Metal"},
            {CMM_MAT_HMC_MESH,       CMM_MAT_HMC_MESH,       "Grille"},
            {CMM_MAT_JRB_WALL,       CMM_MAT_JRB_WALL,       "Wall"},
            {CMM_MAT_QUICKSAND,      CMM_MAT_QUICKSAND,      "Quicksand"},
        },
        CMM_FENCE_JRB, CMM_MAT_VP_CAUTION, CMM_BAR_HMC, CMM_WATER_DEFAULT
    },
    // RETRO
    {
        {
            {CMM_MAT_RETRO_GROUND,           CMM_MAT_RETRO_GROUND,           "Ground"},
            {CMM_MAT_RETRO_BRICKS,           CMM_MAT_RETRO_BRICKS,           "Bricks"},
            {CMM_MAT_RETRO_TREEPLAT,         CMM_MAT_RETRO_TREETOP,          "Treetop"},
            {CMM_MAT_RETRO_BLOCK,            CMM_MAT_RETRO_BLOCK,            "Block"},
            {CMM_MAT_RETRO_BLUEGROUND,       CMM_MAT_RETRO_BLUEGROUND,       "Blue Ground"},
            {CMM_MAT_RETRO_BLUEBRICKS,       CMM_MAT_RETRO_BLUEBRICKS,       "Blue Bricks"},
            {CMM_MAT_RETRO_BLUEBLOCK,        CMM_MAT_RETRO_BLUEBLOCK,        "Blue Block"},
            {CMM_MAT_RETRO_WHITEBRICK,       CMM_MAT_RETRO_WHITEBRICK,       "White Bricks"},
            {CMM_MAT_RETRO_LAVA,             CMM_MAT_RETRO_LAVA,             "Lava"},
            {CMM_MAT_RETRO_UNDERWATERGROUND, CMM_MAT_RETRO_UNDERWATERGROUND, "Underwater Tile"},
        },
        CMM_FENCE_RETRO, CMM_MAT_RETRO_BRICKS, CMM_BAR_RETRO, CMM_WATER_RETRO
    },
    // CUSTOM
    {
        {
            {0, 0, "Tile 1"},
            {0, 0, "Tile 2"},
            {0, 0, "Tile 3"},
            {0, 0, "Tile 4"},
            {0, 0, "Tile 5"},
            {0, 0, "Tile 6"},
            {0, 0, "Tile 7"},
            {0, 0, "Tile 8"},
            {0, 0, "Tile 9"},
            {0, 0, "Tile 10"},
        },
        0, 0, 0, 0
    },
    // MINECRAFT
    {
        {
            {CMM_MAT_MC_DIRT,         CMM_MAT_MC_GRASS,       "Grass"},
            {CMM_MAT_MC_COBBLESTONE,  CMM_MAT_MC_COBBLESTONE, "Cobblestone"},
            {CMM_MAT_MC_STONE,        CMM_MAT_MC_STONE,       "Stone"},
            {CMM_MAT_MC_OAK_LOG_SIDE, CMM_MAT_MC_OAK_LOG_TOP, "Oak Log"},
            {CMM_MAT_MC_OAK_LEAVES,   CMM_MAT_MC_OAK_LEAVES,  "Oak Leaves"},
            {CMM_MAT_MC_WOOD_PLANKS,  CMM_MAT_MC_WOOD_PLANKS, "Oak Planks"},
            {CMM_MAT_MC_SAND,         CMM_MAT_MC_SAND,        "Sand"},
            {CMM_MAT_MC_BRICKS,       CMM_MAT_MC_BRICKS,      "Bricks"},
            {CMM_MAT_MC_FLOWING_LAVA, CMM_MAT_MC_LAVA,        "Lava"},
            {CMM_MAT_MC_GLASS,        CMM_MAT_MC_GLASS,       "Glass"},
        },
        CMM_FENCE_MC, CMM_MAT_MC_OAK_LOG_SIDE, CMM_BAR_MC, CMM_WATER_MC
    },
};

struct cmm_custom_theme cmm_default_custom = {
    {
        CMM_MAT_DIRT,
        CMM_MAT_BRICKS,
        CMM_MAT_COBBLESTONE,
        CMM_MAT_TILESBRICKS,
        CMM_MAT_ROOF,
        CMM_MAT_WOOD,
        CMM_MAT_SANDDIRT,
        CMM_MAT_SNOWDIRT,
        CMM_MAT_LAVA,
        CMM_MAT_QUICKSAND,
    },
    {
        CMM_MAT_GRASS,
        CMM_MAT_TILES,
        CMM_MAT_STONE,
        CMM_MAT_TILES,
        CMM_MAT_ROOF,
        CMM_MAT_WOOD,
        CMM_MAT_SAND,
        CMM_MAT_SNOW,
        CMM_MAT_LAVA,
        CMM_MAT_QUICKSAND,
    },
    {1, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    CMM_FENCE_NORMAL, CMM_MAT_STONE, CMM_BAR_GENERIC, CMM_WATER_DEFAULT,
};
struct cmm_custom_theme cmm_curr_custom_theme;

// Returns full tile definition (struct cmm_tilemat_def)
#define TILE_MATDEF(matid) (cmm_theme_table[cmm_lopt_theme].mats[matid])
// Returns main material (struct cmm_material)
#define MATERIAL(matid) (cmm_mat_table[TILE_MATDEF(matid).mat])

// Returns TRUE if given material has a unique top texture
#define HAS_TOPMAT(matid) (TILE_MATDEF(matid).topmat != TILE_MATDEF(matid).mat)
// Returns top material's topmat struct (struct cmm_material)
#define TOPMAT(matid) (cmm_mat_table[TILE_MATDEF(matid).topmat])

// Returns current fence texture
#define FENCE_TEX() (cmm_fence_texs[cmm_theme_table[cmm_lopt_theme].fence])
#define POLE_TEX()  (cmm_mat_table[cmm_theme_table[cmm_lopt_theme].pole].gfx)
#define BARS_TEX() (cmm_bar_texs[cmm_theme_table[cmm_lopt_theme].bars][0])
#define BARS_TOPTEX() (cmm_bar_texs[cmm_theme_table[cmm_lopt_theme].bars][1])
#define WATER_TEX() (cmm_water_texs[cmm_theme_table[cmm_lopt_theme].water])

struct ExclamationBoxContents sExclamationBoxContents_btcm[] = {
    { 0, MODEL_MARIOS_WING_CAP,  bhvWingCap,           0, TRUE,  0},
    { 0, MODEL_MARIOS_METAL_CAP, bhvVanishCap,         2, TRUE,  0},
    { 0, MODEL_KOOPA_SHELL,      bhvKoopaShell,        3, TRUE,  0},
    { 0, 0xEF,                   bhvGreenGetsSpawned,  4, FALSE, 3},
    { 0, MODEL_YELLOW_COIN,      bhvSingleCoinGetsSpawned,  4, FALSE, 1},
    { 0, MODEL_NONE,             bhvThreeCoinsSpawn,   4, FALSE, 3},
    { 0, MODEL_NONE,             bhvTenCoinsSpawn,     4, FALSE, 10},
};

struct ExclamationBoxContents sExclamationBoxContents_vanilla[] = {
    { 0, MODEL_V_MARIOS_WING_CAP,  bhvWingCap,         0, TRUE,  0},
    { 6, MODEL_V_MARIOS_METAL_CAP, bhvMetalCap,        1, TRUE,  0},
    { 0, MODEL_MARIOS_CAP,         bhvVanishCap,       2, TRUE,  0},
    { 0, MODEL_KOOPA_SHELL,        bhvKoopaShell,      3, TRUE,  0},
    { 0, MODEL_YELLOW_COIN,        bhvSingleCoinGetsSpawned, 3, FALSE, 1},
    { 0, MODEL_NONE,               bhvThreeCoinsSpawn, 3, FALSE, 3},
    { 0, MODEL_NONE,               bhvTenCoinsSpawn,   3, FALSE, 10},
};

enum {
    OBJECT_TYPE_SETTINGS,
    OBJECT_TYPE_SCREENSHOT,
    OBJECT_TYPE_STAR,
    OBJECT_TYPE_RED_COIN_STAR,
    OBJECT_TYPE_GOOMBA,
    OBJECT_TYPE_BIG_GOOMBA,
    OBJECT_TYPE_TINY_GOOMBA,
    OBJECT_TYPE_PIRANHA_PLANT,
    OBJECT_TYPE_BIG_PIRANHA_PLANT,
    OBJECT_TYPE_TINY_PIRANHA_PLANT,
    OBJECT_TYPE_KOOPA,
    OBJECT_TYPE_COIN,
    OBJECT_TYPE_GREEN_COIN,
    OBJECT_TYPE_RED_COIN,
    OBJECT_TYPE_BLUE_COIN,
    OBJECT_TYPE_BLUE_COIN_SWITCH,
    OBJECT_TYPE_NOTEBLOCK,
    OBJECT_TYPE_BOBOMB,
    OBJECT_TYPE_CHUCKYA,
    OBJECT_TYPE_BULLY,
    OBJECT_TYPE_CHILL_BULLY,
    OBJECT_TYPE_BULLET_BILL,
    OBJECT_TYPE_HEAVE_HO,
    OBJECT_TYPE_MOTOS,
    OBJECT_TYPE_TREE,
    OBJECT_TYPE_EXCL_BOX,
    OBJECT_TYPE_MARIO_SPAWN,
    OBJECT_TYPE_REX,
    OBJECT_TYPE_PODOBOO,
    OBJECT_TYPE_CRABLET,
    OBJECT_TYPE_HAMMER_BRO,
    OBJECT_TYPE_FIRE_BRO,
    OBJECT_TYPE_CHICKEN,
    OBJECT_TYPE_PHANTASM,
    OBJECT_TYPE_WARP_PIPE,
    OBJECT_TYPE_BADGE,
    OBJECT_TYPE_KING_BOBOMB,
    OBJECT_TYPE_KING_WHOMP,
    OBJECT_TYPE_BIG_BOO,
    OBJECT_TYPE_BIG_BULLY,
    OBJECT_TYPE_BIG_CHILL_BULLY,
    OBJECT_TYPE_WIGGLER,
    OBJECT_TYPE_BOWSER,
    OBJECT_TYPE_PLATFORM_TRACK,
    OBJECT_TYPE_PLATFORM_LOOPING,
    OBJECT_TYPE_BOWLING_BALL,
    OBJECT_TYPE_KOOPA_THE_QUICK,
    OBJECT_TYPE_PURPLE_SWITCH,
    OBJECT_TYPE_TIMED_BOX,
    OBJECT_TYPE_RECOVERY_HEART,
    OBJECT_TYPE_TEST_MARIO,// Fake type, used for the Test mario preview
    OBJECT_TYPE_THWOMP,
    OBJECT_TYPE_WHOMP,
    OBJECT_TYPE_GRINDEL,
    OBJECT_TYPE_LAKITU,
    OBJECT_TYPE_FLY_GUY,
    OBJECT_TYPE_SNUFIT,
    OBJECT_TYPE_AMP,
    OBJECT_TYPE_BOO,
    OBJECT_TYPE_MR_I,
    OBJECT_TYPE_SCUTTLEBUG,
    OBJECT_TYPE_BOWSER_BOMB,
    OBJECT_TYPE_FIRE_SPINNER,
    OBJECT_TYPE_COIN_FORMATION,
    OBJECT_TYPE_RED_FLAME,
    OBJECT_TYPE_BLUE_FLAME,
    OBJECT_TYPE_FIRE_SPITTER,
    OBJECT_TYPE_FLAMETHROWER,
    OBJECT_TYPE_SPINDRIFT,
    OBJECT_TYPE_MR_BLIZZARD,
    OBJECT_TYPE_MONEYBAG,
    OBJECT_TYPE_SKEETER,
    OBJECT_TYPE_POKEY,
    OBJECT_TYPE_BBOX_SMALL,
    OBJECT_TYPE_BBOX_NORMAL,
    OBJECT_TYPE_BBOX_CRAZY,
    OBJECT_TYPE_DIAMOND,
    OBJECT_TYPE_SIGN,
    OBJECT_TYPE_BUDDY,
    OBJECT_TYPE_BUTTON,
    OBJECT_TYPE_ON_OFF_BLOCK,
    OBJECT_TYPE_WOODPLAT,
    OBJECT_TYPE_RFBOX,
    OBJECT_TYPE_CULL_PREVIEW, // also fake type
    OBJECT_TYPE_SHOWRUNNER,
    OBJECT_TYPE_CROWBAR,
    OBJECT_TYPE_MASK,
    OBJECT_TYPE_TOAD,
    OBJECT_TYPE_TUXIE,
    OBJECT_TYPE_UKIKI,
    OBJECT_TYPE_MOLEMAN,
    OBJECT_TYPE_COBIE,
    OBJECT_TYPE_CONVEYOR,
};

/*  Object Type                  Name                       Button GFX              Behavior           Y Offset     Model                      Flags                 Coins/Objs/Scale/Params  Anims   Display Func    Sound*/
struct cmm_object_info cmm_object_type_list[] = {
/* OBJECT_TYPE_SETTINGS */      {"Level Settings",          mat_b_btn_settings},
/* OBJECT_TYPE_SCREENSHOT */    {"Take Screenshot",         mat_b_btn_camera},
/* OBJECT_TYPE_STAR */          {"Normal",                  mat_b_btn_star,         bhvStar,           TILE_SIZE/2, MODEL_STAR,                OBJ_TYPE_HAS_STAR,       0, 0, 1.0f, NULL, df_star, SOUND_MENU_STAR_SOUND | SOUND_VIBRATO},
/* OBJECT_TYPE_RED_COIN_STAR */ {"Red Coins",               mat_b_btn_rcs,          bhvHiddenRedCoinStar, TILE_SIZE/2, MODEL_TRANSPARENT_STAR, OBJ_TYPE_HAS_STAR,       0, 1, 1.0f, NULL, df_reds_marker, SOUND_MENU_STAR_SOUND | SOUND_VIBRATO},
/* OBJECT_TYPE_GOOMBA */        {"Normal",                  mat_b_btn_goomba,       bhvGoomba,         0,           MODEL_GOOMBA,              0,                       1, 0, 1.5f, goomba_seg8_anims_0801DA4C, NULL, SOUND_OBJ_GOOMBA_PREVIEW},
/* OBJECT_TYPE_BIG_GOOMBA */    {"Huge",                    mat_b_btn_goomba_b,     bhvBigGoomba,      0,           MODEL_GOOMBA,              0,                       5, 0, 3.5f, goomba_seg8_anims_0801DA4C, NULL, SOUND_OBJ_GOOMBA_PREVIEW},
/* OBJECT_TYPE_TINY_GOOMBA */   {"Tiny",                    mat_b_btn_goomba_s,     bhvTinyGoomba,     0,           MODEL_GOOMBA,              0,                       1, 0, 0.5f, goomba_seg8_anims_0801DA4C, NULL, SOUND_OBJ_GOOMBA_PREVIEW},
/* OBJECT_TYPE_PIRANHA_PLANT */ {"Normal",                  mat_b_btn_plant,        bhvPiranhaPlant,   0,           MODEL_MAKER_PLANT,         0,                       5, 0, 1.0f, piranha_plant_seg6_anims_0601C31C, NULL, SOUND_OBJ2_PIRANHA_PLANT_BITE},
/* OBJECT_TYPE_BIG_PIRANHA_PLANT */  {"Huge",               mat_b_btn_plant_b,      bhvFirePiranhaPlantBig, 0,      MODEL_MAKER_PLANT,         0,                       2, 0, 2.0f, piranha_plant_seg6_anims_0601C31C, NULL, SOUND_OBJ2_PIRANHA_PLANT_BITE},
/* OBJECT_TYPE_TINY_PIRANHA_PLANT */ {"Tiny",               mat_b_btn_plant_s,      bhvFirePiranhaPlant, 0,         MODEL_MAKER_PLANT,         0,                       1, 0, 0.5f, piranha_plant_seg6_anims_0601C31C, NULL, SOUND_OBJ2_PIRANHA_PLANT_BITE},
/* OBJECT_TYPE_KOOPA */         {"Koopa",                   mat_b_btn_kuppa,        bhvScaredKoopa,    0,           MODEL_KOOPA_WITH_SHELL,    0,                       5, 0, 1.5f, koopa_seg6_anims_06011364, df_koopa, SOUND_OBJ_KOOPA_TALK},
/* OBJECT_TYPE_COIN */          {"Yellow Coin",             mat_b_btn_coin,         bhvYellowCoin,     0,           MODEL_YELLOW_COIN,         OBJ_TYPE_IS_BILLBOARDED, 1, 0, 1.0f, NULL, NULL, SOUND_GENERAL_COIN | SOUND_VIBRATO},
/* OBJECT_TYPE_GREEN_COIN */    {"Green Coin",              mat_b_btn_greencoin,    bhvGreenCoin,      0,           0xEF,                      OBJ_TYPE_IS_BILLBOARDED, 3, 0, 1.0f, NULL, NULL, SOUND_GENERAL_COIN_MULTI},
/* OBJECT_TYPE_RED_COIN */      {"Red Coin",                mat_b_btn_redcoin,      bhvRedCoin,        0,           MODEL_RED_COIN,            OBJ_TYPE_IS_BILLBOARDED, 2, 0, 1.0f, NULL, NULL, SOUND_MENU_COLLECT_RED_COIN},
/* OBJECT_TYPE_BLUE_COIN */     {"Coin",                    mat_b_btn_bluecoin,     bhvHiddenBlueCoin, 0,           MODEL_BLUE_COIN,           OBJ_TYPE_IS_BILLBOARDED, 5, 0, 1.0f, NULL, NULL, SOUND_GENERAL_COIN_MULTI},
/* OBJECT_TYPE_BLUE_COIN_SWITCH */ {"Switch",               mat_b_btn_bcs,          bhvBlueCoinSwitch, 0,           MODEL_BLUE_COIN_SWITCH,    0,                       0, 0, 3.0f, NULL, NULL, SOUND_GENERAL2_PURPLE_SWITCH},
/* OBJECT_TYPE_NOTEBLOCK */     {"Noteblock",               mat_b_btn_noteblock,    bhvNoteblock,      TILE_SIZE/2, MODEL_NOTEBLOCK,           0,                       0, 0, 1.28f,NULL, NULL, SOUND_GENERAL_CRAZY_BOX_BOING_SLOW},
/* OBJECT_TYPE_BOBOMB */        {"Bob-omb",                 mat_b_btn_bobomb,       bhvBobomb,         0,           MODEL_BLACK_BOBOMB,        0,                       1, 0, 1.0f, bobomb_anims, NULL, SOUND_GENERAL2_QUIET_EXPLOSION},
/* OBJECT_TYPE_CHUCKYA */       {"Chuckya",                 mat_b_btn_chuckya,      bhvChuckya,        0,           MODEL_CHUCKYA,             0,                       5, 0, 2.0f, chuckya_seg8_anims_0800C070, df_chuckya, SOUND_OBJ_CHUCKYA_PREVIEW},
/* OBJECT_TYPE_BULLY */         {"Bully",                   mat_b_btn_bully,        bhvSmallBully,     0,           MODEL_BULLY,               0,                       1, 0, 1.0f, bully_seg5_anims_0500470C, NULL, SOUND_OBJ2_SMALL_BULLY_ATTACKED},
/* OBJECT_TYPE_CHILL_BULLY */   {"Chill Bully",             mat_b_btn_chillbully,   bhvSmallBully,     0,           MODEL_CHILL_BULLY,         0,                       1, 0, 1.0f, bully_seg5_anims_0500470C, NULL, SOUND_OBJ2_SMALL_BULLY_ATTACKED},
/* OBJECT_TYPE_BULLET_BILL */   {"Bullet Bill",             mat_b_btn_bill,         bhvBulletBillCannon, TILE_SIZE/2, MODEL_BILL_MAKER_2,      0,                       0, 1, 1.0f, NULL, NULL, SOUND_OBJ_POUNDING_CANNON},
/* OBJECT_TYPE_HEAVE_HO */      {"Heave-Ho",                mat_b_btn_heaveho,      bhvHeaveHo,        0,           MODEL_MAKER_HEAVEHO,       0,                       0, 0, 2.0f, heave_ho_seg5_anims_0501534C, NULL, SOUND_OBJ_HEAVEHO_PREVIEW},
/* OBJECT_TYPE_MOTOS */         {"Motos",                   mat_b_btn_motos,        bhvMotos,          0,           MODEL_MAKER_MOTOS,         0,                       5, 0, 2.0f, motos_anime, NULL, SOUND_OBJ_HEAVEHO_PREVIEW},
/* OBJECT_TYPE_TREE */          {"Tree",                    mat_b_btn_tree,         bhvTree,           0,           MODEL_MAKER_TREE_1,        OBJ_TYPE_IS_BILLBOARDED, 0, 0, 1.0f, NULL, df_tree, SOUND_ACTION_CLIMB_UP_TREE | SOUND_VIBRATO},
/* OBJECT_TYPE_EXCL_BOX */      {"Item Box",                mat_b_btn_excla,        bhvExclamationBox, TILE_SIZE/2, MODEL_EXCLAMATION_BOX,     0,                       0, 0, 2.0f, NULL, df_exbox, SOUND_GENERAL_BOX_PREVIEW},
/* OBJECT_TYPE_SPAWN */         {"Mario Spawn",             mat_b_btn_spawn,        bhvSpawn,          TILE_SIZE/2, MODEL_SPAWN,               0,                       0, 0, 1.0f, NULL, NULL, SOUND_MENU_STAR_SOUND_LETS_A_GO},
/* OBJECT_TYPE_REX */           {"Rex",                     mat_b_btn_rex,          bhvRex,            0,           0xE1,                      0,                       2, 0, 1.5f, Rex_anims, NULL, SOUND_OBJ_GOOMBA_PREVIEW},
/* OBJECT_TYPE_PODOBOO */       {"Podoboo",                 mat_b_btn_podoboo,      bhvPodoboo,        TILE_SIZE/2, MODEL_PODOBOO,             0,                       0, 0, 1.0f, NULL, df_podoboo, SOUND_OBJ_FLAME_BLOWN},
/* OBJECT_TYPE_CRABLET */       {"Crablet",                 mat_b_btn_crablet,      bhvCrablet,        0,           MODEL_MAKER_CRABLET,       0,                       4, 0, 1.0f, crab_anims_anims, NULL, SOUND_OBJ2_SCUTTLEBUG_ALERT},
/* OBJECT_TYPE_HAMMER_BRO */    {"Normal",                  mat_b_btn_hammerbro,    bhvHammerBro,      60.0f,       0xEE,                      0,                       6, 0, 1.0f, Hammerbro_anims, df_hammerbro, SOUND_OBJ_KOOPA_DAMAGE},
/* OBJECT_TYPE_FIRE_BRO */      {"Fire Bro",                mat_b_btn_firebro,      bhvFireBro,        60.0f,       0xEE,                      0,                       6, 0, 1.0f, Hammerbro_anims, df_firebro, SOUND_OBJ_KOOPA_DAMAGE},
/* OBJECT_TYPE_CHICKEN */       {"Chicken",                 mat_b_btn_chicken,      bhvChicken,        0,           MODEL_MAKER_CHICKEN,       0,                       2, 0, 1.0f, chicken_anims, NULL, SOUND_OBJ_BOO_LAUGH_SHORT},
/* OBJECT_TYPE_PHANTASM */      {"Cosmic Phantasm",         mat_b_btn_phantasm,     bhvPhantasm,       0,           MODEL_MARIO,               0,                       5, 0, 1.0f, &evil_mario_anims[2], NULL, SOUND_ACTION_METAL_STEP | SOUND_VIBRATO},
/* OBJECT_TYPE_WARP_PIPE */     {"Warp Pipe",               mat_b_btn_pipe,         bhvWarpPipe,       0,           MODEL_MAKER_PIPE,          0,                       0, 0, 1.0f, NULL, NULL, SOUND_MENU_ENTER_PIPE | SOUND_VIBRATO},
/* OBJECT_TYPE_BADGE */         {"Badge",                   mat_b_btn_badge,        bhvBadge,          TILE_SIZE/2, MODEL_BADGE,               OBJ_TYPE_IS_BILLBOARDED, 0, 0, 5.0f, NULL, NULL, SOUND_GENERAL2_PURPLE_SWITCH},
/* OBJECT_TYPE_KING_BOBOMB */   {"King Bob-omb",            mat_b_btn_boss_kb,      bhvKingBobomb,     0,           MODEL_KINGBOMB_MAKER,      OBJ_TYPE_IMBUABLE,       0, 0, 1.0f, king_bobomb_seg5_anims_0500FE30, df_kingbomb, SOUND_OBJ_KING_BOBOMB_POUNDING1_HIGHPRIO},
/* OBJECT_TYPE_KING_WHOMP */    {"King Whomp",              mat_b_btn_boss_whomp,   bhvWhompKingBoss,  0,           MODEL_WHOMP_MAKER,         OBJ_TYPE_IMBUABLE,       0, 0, 2.f,  whomp_seg6_anims_06020A04, NULL, SOUND_OBJ_WHOMP},
/* OBJECT_TYPE_BIG_BOO */       {"Big Boo",                 mat_b_btn_boss_boo,     bhvBalconyBigBoo,  TILE_SIZE,   MODEL_MAKER_BOO,           OBJ_TYPE_IMBUABLE,       0, 0, 3.0f, NULL, df_boo, SOUND_OBJ_BOO_LAUGH_LONG},
/* OBJECT_TYPE_BIG_BULLY */     {"Big Bully",               mat_b_btn_boss_bully,   bhvBigBully,       0,           MODEL_BULLY,               OBJ_TYPE_IMBUABLE,       0, 0, 2.0f, bully_seg5_anims_0500470C, NULL, SOUND_OBJ2_LARGE_BULLY_ATTACKED},
/* OBJECT_TYPE_BIG_CHILL_BULLY */ {"Big Chill Bully",       mat_b_btn_boss_chillbully,bhvBigBully,     0,           MODEL_CHILL_BULLY,         OBJ_TYPE_IMBUABLE,       0, 0, 2.0f, bully_seg5_anims_0500470C, NULL, SOUND_OBJ2_LARGE_BULLY_ATTACKED},
/* OBJECT_TYPE_WIGGLER */       {"Wiggler",                 mat_b_btn_boss_wiggler, bhvWigglerHead,    0,           MODEL_WIGGLER_HEAD,        OBJ_TYPE_IMBUABLE,       0, 0, 4.0f, wiggler_seg5_anims_0500EC8C, df_wiggler, SOUND_OBJ_WIGGLER_TALK},
/* OBJECT_TYPE_BOWSER */        {"Bowser",                  mat_b_btn_boss_bowser,  bhvBowser,         0,           MODEL_MAKER_BOWSER,        OBJ_TYPE_IMBUABLE,       0, 3, 1.0f, bowser_anims, df_booser, SOUND_OBJ2_BOWSER_ROAR},
/* OBJECT_TYPE_PLATFORM_TRACK */ {"Activated",              mat_b_btn_checker,      bhvPlatformOnTrack, TILE_SIZE/2, MODEL_CHECKERBOARD_PLATFORM, OBJ_TYPE_TRAJECTORY,  0, 0, 1.0f, NULL, NULL, SOUND_ENV_ELEVATOR1 | SOUND_VIBRATO},
/* OBJECT_TYPE_PLATFORM_LOOPING */ {"Looping",              mat_b_btn_checker,      bhvLoopingPlatform, TILE_SIZE/2, MODEL_LOOPINGP,           OBJ_TYPE_TRAJECTORY,     0, 0, 1.0f, NULL, NULL, SOUND_ENV_ELEVATOR1 | SOUND_VIBRATO},
/* OBJECT_TYPE_BOWLING_BALL */  {"Bowling Ball",            mat_b_btn_bball,        bhvBobBowlingBallSpawner, TILE_SIZE/2, MODEL_BOWLING_BALL, OBJ_TYPE_IS_BILLBOARDED | OBJ_TYPE_TRAJECTORY, 0, 0, 1.0f, NULL, NULL, SOUND_GENERAL_QUIET_POUND1 | SOUND_VIBRATO},
/* OBJECT_TYPE_KOOPA_THE_QUICK */ {"Koopa the Quick",       mat_b_btn_kuppaq,       bhvKoopa,          0,           MODEL_KOOPA_WITH_SHELL,    OBJ_TYPE_TRAJECTORY | OBJ_TYPE_HAS_STAR, 0, 1, 3.0f, koopa_seg6_anims_06011364, df_ktq, SOUND_OBJ_KOOPA_TALK},
/* OBJECT_TYPE_PURPLE_SWITCH */ {"Purple Switch",           mat_b_btn_purpleswitch, bhvFloorSwitchHiddenObjects, 0, MODEL_PURPLE_SWITCH,       0,                       0, 0, 1.28f,NULL, NULL, SOUND_GENERAL2_PURPLE_SWITCH},
/* OBJECT_TYPE_TIMED_BOX */     {"Timed Box",               mat_b_btn_tbox,         bhvHiddenObject,   0,           MODEL_BREAKABLE_BOX,       0,                       0, 0, 1.0f, NULL, df_timedbox, SOUND_GENERAL2_SWITCH_TICK_FAST},
/* OBJECT_TYPE_RECOVERY_HEART */ {"Recovery Heart",         mat_b_btn_heart,        bhvRecoveryHeart,  TILE_SIZE/2, MODEL_HEART,               0,                       0, 0, 1.0f, NULL, df_heart, SOUND_GENERAL_HEART_SPIN},
/* OBJECT_TYPE_TEST_MARIO */    {"Save & Test",             mat_b_btn_check,        NULL,              0,           MODEL_MARIO,               0,                       0, 0, 1.f,  &evil_mario_anims[11], NULL, 0},
/* OBJECT_TYPE_THWOMP */        {"Thwomp",                  mat_b_btn_thwomp,       bhvThwomp,         0,           MODEL_THWOMP_MAKER,        0,                       0, 0, 1.5f, NULL, NULL, SOUND_OBJ_THWOMP},
/* OBJECT_TYPE_WHOMP */         {"Whomp",                   mat_b_btn_whomp,        bhvSmallWhomp,     0,           MODEL_WHOMP_MAKER,         0,                       10, 0, 1.f, whomp_seg6_anims_06020A04, NULL, SOUND_OBJ_WHOMP},
/* OBJECT_TYPE_GRINDEL */       {"Grindel",                 mat_b_btn_grindel,      bhvGrindel,        0,           MODEL_MAKER_GRINDEL,       0,                       0, 0, 1.f,  NULL, df_grindel, SOUND_OBJ_KING_BOBOMB_JUMP},
/* OBJECT_TYPE_LAKITU */        {"Lakitu",                  mat_b_btn_lakitu,       bhvEnemyLakitu,    TILE_SIZE/2, MODEL_LAKITU_MAKER,        0,                       5, 5, 1.0f, lakitu_enemy_seg5_anims_050144D4, df_lakitu, SOUND_OBJ_EVIL_LAKITU_THROW},
/* OBJECT_TYPE_FLY_GUY */       {"Fly Guy",                 mat_b_btn_flyguy,       bhvRealFlyGuy,     TILE_SIZE/2, MODEL_FLYGUY,              0,                       2, 0, 1.5f, flyguy_seg8_anims_08011A64, df_flyguy, SOUND_OBJ_KOOPA_FLYGUY_DEATH},
/* OBJECT_TYPE_SNUFIT */        {"Snufit",                  mat_b_btn_snufit,       bhvSnufit,         TILE_SIZE/2, MODEL_MAKER_SNUFIT,        0,                       2, 0, 1.0f, NULL, df_snufit, SOUND_OBJ_SNUFIT_SHOOT},
/* OBJECT_TYPE_AMP */           {"Amp",                     mat_b_btn_amp,          bhvCirclingAmp,    TILE_SIZE/2, MODEL_AMP,                 0,                       0, 0, 1.0f, amp_anims, df_circling_amp, SOUND_AIR_AMP_PREVIEW},
/* OBJECT_TYPE_BOO */           {"Boo",                     mat_b_btn_boo,          bhvBoo,            TILE_SIZE/2, MODEL_MAKER_BOO,           0,                       1, 0, 1.0f, NULL, df_boo, SOUND_OBJ_BOO_LAUGH_LONG},
/* OBJECT_TYPE_MR_I */          {"Mr. I",                   mat_b_btn_mri,          bhvMrI,            0,           MODEL_MAKER_MRI,           OBJ_TYPE_IS_BILLBOARDED, 5, 1, 1.0f, NULL, df_mri, SOUND_OBJ_MRI_SHOOT},
/* OBJECT_TYPE_SCUTTLEBUG */    {"Scuttlebug",              mat_b_btn_scuttlebug,   bhvScuttlebug,     0,           MODEL_MAKER_SCUTTLEBUG,    0,                       3, 0, 1.0f, scuttlebug_seg6_anims_06015064, NULL, SOUND_OBJ2_SCUTTLEBUG_ALERT},
/* OBJECT_TYPE_BOWSER_BOMB */   {"Bowser Bomb",             mat_b_btn_bbomb,        bhvBowserBomb,     TILE_SIZE/2, MODEL_MAKER_BOWSER_BOMB,   0,                       0, 0, 1.0f, NULL, NULL, SOUND_GENERAL2_QUIET_EXPLOSION},
/* OBJECT_TYPE_FIRE_SPINNER */  {"Fire Spinner",            mat_b_btn_firebar,      bhvLllRotatingBlockWithFireBars, 0, MODEL_MAKER_FIREBAR,   0,                       0, 0, 1.0f, NULL, df_fire_spinner, SOUND_OBJ_FLAME_BLOWN},
/* OBJECT_TYPE_COIN_FORMATION */ {"Coin Formation",         mat_b_btn_cformation,   bhvCoinFormation,  0,           MODEL_NONE,                0,                       0, 0, 1.0f, NULL, df_coin_formation, SOUND_GENERAL_COIN_MULTI},
/* OBJECT_TYPE_RED_FLAME */     {"Red",                     mat_b_btn_fire_red,     bhvFlame,          60,          MODEL_RED_FLAME,           OBJ_TYPE_IS_BILLBOARDED, 0, 0, 7.0f, NULL, df_flame, SOUND_OBJ_FLAME_BLOWN},
/* OBJECT_TYPE_BLUE_FLAME */    {"Blue",                    mat_b_btn_fire_blue,    bhvFlame,          60,          MODEL_BLUE_FLAME,          OBJ_TYPE_IS_BILLBOARDED, 0, 0, 7.0f, NULL, df_flame, SOUND_OBJ_FLAME_BLOWN},
/* OBJECT_TYPE_FIRE_SPITTER */  {"Fire Spitter",            mat_b_btn_firespitter,  bhvFireSpitter,    TILE_SIZE/2, MODEL_BOWLING_BALL,        OBJ_TYPE_IS_BILLBOARDED, 0, 0, 0.2f, NULL, NULL, SOUND_OBJ_FLAME_BLOWN},
/* OBJECT_TYPE_FLAMETHROWER */  {"Flamethrower",            mat_b_btn_flamethrower, bhvFlamethrower,   TILE_SIZE/2, MODEL_MAKER_FLAMETHROWER,  0,                       0, 0, 1.0f, NULL, NULL, SOUND_OBJ_FLAME_BLOWN},
/* OBJECT_TYPE_SPINDRIFT */     {"Spindrift",               mat_b_btn_spindrift,    bhvSpindrift,      0,           MODEL_MAKER_SPINDRIFT,     0,                       3, 0, 1.0f, spindrift_seg5_anims_05002D68, NULL, SOUND_ACTION_TWIRL},
/* OBJECT_TYPE_MR_BLIZZARD */   {"Mr. Blizzard",            mat_b_btn_blizzard,     bhvMrBlizzard,     0,           MODEL_MAKER_BLIZZARD,      0,                       3, 0, 1.0f, snowman_seg5_anims_0500D118, df_blizzard, SOUND_OBJ2_SCUTTLEBUG_ALERT},
/* OBJECT_TYPE_MONEYBAG */      {"Moneybag",                mat_b_btn_moneybag,     bhvMoneybagHidden, 0,           MODEL_ATM,                 0,                       5, 0, 1.0f, moneybag_seg6_anims_06005E5C, df_moneybag, SOUND_GENERAL_MONEYBAG_BOING_LOWPRIO},
/* OBJECT_TYPE_SKEETER */       {"Skeeter",                 mat_b_btn_skeeter,      bhvSkeeter,        0,           MODEL_MAKER_SKEETER,       0,                       3, 0, 1.0f, skeeter_seg6_anims_06007DE0, NULL, SOUND_OBJ_SKEETER_WALK},
/* OBJECT_TYPE_POKEY */         {"Pokey",                   mat_b_btn_pokey,        bhvPokey,          0,           MODEL_MAKER_POKEY_HEAD,    OBJ_TYPE_IS_BILLBOARDED, 5, 0, 3.0f, NULL, df_pokey, SOUND_OBJ_POKEY_DEATH},
/* OBJECT_TYPE_BBOX_SMALL*/     {"Throwable Box",           mat_b_btn_sbox,         bhvBreakableBoxSmall, 0,        MODEL_BREAKABLE_BOX,       0,                       3, 0, 0.31f,NULL, df_corkbox, SOUND_GENERAL_BOX_PREVIEW},
/* OBJECT_TYPE_BBOX_NORMAL*/    {"Breakable Box",           mat_b_btn_corkbox,      bhvBreakableBox,   0,           MODEL_BREAKABLE_BOX,       OBJ_TYPE_IMBUABLE,       0, 0, 1.0f, NULL, df_corkbox, SOUND_GENERAL_BOX_PREVIEW},
/* OBJECT_TYPE_BBOX_CRAZY*/     {"Crazy Box",               mat_b_btn_cbox,         bhvJumpingBox,     0,           MODEL_BREAKABLE_BOX,       0,                       5, 0, 0.38f,NULL, NULL, SOUND_GENERAL_CRAZY_BOX_BOING_SLOW},
/* OBJECT_TYPE_DIAMOND*/        {"Water Diamond",           mat_b_btn_water_diamond,bhvWaterLevelDiamond,0,         MODEL_MAKER_DIAMOND,       0,                       0, 0, 1.0f, NULL, NULL, SOUND_GENERAL_WATER_LEVEL_TRIG},
/* OBJECT_TYPE_SIGN */          {"Bill Board",              mat_b_btn_sign,         bhvMessagePanel,   0,           MODEL_WOODEN_SIGNPOST,     OBJ_TYPE_HAS_DIALOG,     0, 0, 1.0f, NULL, NULL, SOUND_ACTION_READ_SIGN},
/* OBJECT_TYPE_BUDDY */         {"Bob-omb Buddy",           mat_b_btn_buddy,        bhvBobombBuddy,    0,           MODEL_BOBOMB_BUDDY,        OBJ_TYPE_HAS_DIALOG,     0, 0, 1.0f, bobomb_anims, NULL, SOUND_OBJ_BOBOMB_BUDDY_TALK},
/* OBJECT_TYPE_BUTTON */        {"On-Off Button",           mat_b_btn_button,       bhvOnOffButton,    0,           MODEL_MAKER_BUTTON,        0,                       0, 0, 1.0f, NULL, df_button, SOUND_GENERAL_DOOR_TURN_KEY},
/* OBJECT_TYPE_ON_OFF_BLOCK */  {"On-Off Block",            mat_b_btn_block,        bhvOnOffBlock,     0,           MODEL_MAKER_BLOCK_1,       0,                       0, 1, 1.0f, NULL, df_block, SOUND_GENERAL_DOOR_TURN_KEY},
/* OBJECT_TYPE_WOODPLAT */      {"Wooden Platform",         mat_b_btn_woodplat,     bhvWoodPlat,       0,           MODEL_MAKER_WOODPLAT,      0,                       0, 1, 1.0f, NULL, df_woodplat, SOUND_GENERAL_POUND_WOOD_POST},
/* OBJECT_TYPE_RFBOX */         {"Reinforced Box",          mat_b_btn_rfbox,        bhvBreakableBoxRF, 0,           MODEL_MAKER_RFBOX,         OBJ_TYPE_IMBUABLE,       0, 0, 1.0f, NULL, NULL, SOUND_ACTION_METAL_BONK},
/* OBJECT_TYPE_CULL_PREVIEW */  {"",                        mat_b_btn_cull,         bhvStaticObject,   TILE_SIZE/2, MODEL_CULL_MARKER,         OBJ_TYPE_IS_BILLBOARDED, 0, 0, 1.f,  NULL, NULL, 0},
/* OBJECT_TYPE_SHOWRUNNER */    {"Showrunner",              mat_b_btn_showrunner,   bhvShowrunner,     0,           MODEL_MAKER_SHOWRUNNER,    OBJ_TYPE_IMBUABLE,       50,60,1.0f,showrunner_anims, NULL, SOUND_OBJ_MRI_SHOOT},
/* OBJECT_TYPE_CROWBAR */       {"Crowbar",                 mat_b_btn_pipebar,      bhvCrowbarPower,   0,           MODEL_MAKER_CROWBAR,       0,                       0, 0, 1.0f, NULL, df_power, SOUND_MENU_EXIT_PIPE},
/* OBJECT_TYPE_MASK    */       {"Bullet Bill Mask",        mat_b_btn_mask,         bhvBMask,          0,           MODEL_MAKER_MASK,          0,                       0, 0, 1.0f, NULL, df_power, SOUND_MENU_EXIT_PIPE},
/* OBJECT_TYPE_TOAD */          {"Toad",                    mat_b_btn_toad,         bhvMakerToad,      0,           MODEL_MAKER_TOAD,          OBJ_TYPE_HAS_DIALOG,     0, 0, 1.0f, toad_seg6_anims_0600FB58, df_toad, SOUND_ACTION_READ_SIGN},
/* OBJECT_TYPE_TUXIE */         {"Tuxie",                   mat_b_btn_tuxie,        bhvMakerTuxie,     0,           MODEL_MAKER_TUXIE,         OBJ_TYPE_HAS_DIALOG,     0, 0, 1.0f, penguin_seg5_anims_05008B74, NULL, SOUND_OBJ2_BABY_PENGUIN_YELL},
/* OBJECT_TYPE_UKIKI */         {"Ukiki",                   mat_b_btn_ukiki,        bhvMakerUkiki,     0,           MODEL_MAKER_UKIKI,         OBJ_TYPE_HAS_DIALOG,     0, 0, 1.0f, ukiki_seg5_anims_05015784, df_ukiki, SOUND_OBJ_UKIKI_CHATTER_SHORT},
/* OBJECT_TYPE_MOLEMAN */       {"Moleman",                 mat_b_btn_moleman,      bhvMoleman,        65,          MODEL_MAKER_MOLEMAN,       OBJ_TYPE_HAS_DIALOG,     0, 0, 1.0f, moleman3_anims, NULL, SOUND_ACTION_READ_SIGN},
/* OBJECT_TYPE_COBIE */         {"Cobie",                   mat_b_btn_cobie,        bhvCobie,          0,           MODEL_MAKER_COBIE,         OBJ_TYPE_HAS_DIALOG,     0, 0, 1.0f, cobie2_anims, NULL, SOUND_ACTION_READ_SIGN},
/* OBJECT_TYPE_CONVEYOR */      {"Conveyor",                mat_b_btn_conveyor,     bhvConveyor,       0,           MODEL_MAKER_CONVEYOR,      0,                       0, 0, 1.0f, NULL, NULL, SOUND_OBJ_HEAVEHO_PREVIEW},
};

//behparam2 strings
char *txt_bp_box[] = {
    "Rocket Boots",
    "Vanetal Cap",
    "Koopa Shell",
    "Green Coin",
    "One Coin",
    "Three Coins",
    "Ten Coins",
};

char *txt_bp_vbox[] = {
    "Wing Cap",
    "Metal Cap",
    "Vanish Cap",
    "Koopa Shell",
    "One Coin",
    "Three Coins",
    "Ten Coins",
};

char *txt_bp_tree[] = {
    "Bubbly",
    "Palm",
    "Spiky",
    "Snowy",
    "Farm",
    "Dead",
};

char *txt_badges[] = {
    "Lava Boost",
    "Fall Damage",
    "Defense",
    "Double Damage",
    "Gills",
    "Fins",
    "HP Regen",
    "Mana Regen",
    "Greed",
    "Double Time",
    "Magnet",
    "Star Radar",
    "Burn",
    "Squish",
    "Feather",
    "Weight",
    "Sticky",
    "Fast Foot",
    "Heal Plus",
    "Bottomless",
    "Slow Fall",
    "Brittle Burden",
    "Withering Burden",
};

char *txt_coin_formation[] = {
    "Line",
    "Vertical Line",
    "Ring",
    "Vertical Ring",
    "Arrow",
};

char *txt_onoff[] = {
    "Red",
    "Blue"
};

char *txt_woodplat[] = {
    "Normal",
    "Thick"
};

char *txt_fire_spinner[] = {
    "Length: 2",
    "Length: 3",
    "Length: 4",
    "Length: 5",
    "Length: 6",
};

enum {
    CMM_BUTTON_SETTINGS,
    CMM_BUTTON_TEST,
    CMM_BUTTON_TERRAIN,
    CMM_BUTTON_SLOPE,
    CMM_BUTTON_TROLL,
    CMM_BUTTON_STAR,
    CMM_BUTTON_GOOMBA,
    CMM_BUTTON_PIRANHA,
    CMM_BUTTON_KOOPA,
    CMM_BUTTON_COIN,
    CMM_BUTTON_BLANK,
    CMM_BUTTON_GCOIN,
    CMM_BUTTON_CORNER,
    CMM_BUTTON_ICORNER,
    CMM_BUTTON_RCOIN,
    CMM_BUTTON_BCOIN,
    CMM_BUTTON_NOTEBLOCK,
    CMM_BUTTON_CULL,
    CMM_BUTTON_BOBOMB,
    CMM_BUTTON_CHUCKYA,
    CMM_BUTTON_BULLY,
    CMM_BUTTON_BULLET,
    CMM_BUTTON_HEAVEHO,
    CMM_BUTTON_MOTOS,
    CMM_BUTTON_TREE,
    CMM_BUTTON_EXCLA,
    CMM_BUTTON_SPAWN,
    CMM_BUTTON_REX,
    CMM_BUTTON_PODOBOO,
    CMM_BUTTON_CRABLET,
    CMM_BUTTON_HAMMER_BRO,
    CMM_BUTTON_CHICKEN,
    CMM_BUTTON_PHANTASM,
    CMM_BUTTON_PIPE,
    CMM_BUTTON_BADGE,
    CMM_BUTTON_WATER,
    CMM_BUTTON_FENCE,
    CMM_BUTTON_KING_BOBOMB,
    CMM_BUTTON_WIGGLER,
    CMM_BUTTON_BOWSER,
    CMM_BUTTON_MPLAT,
    CMM_BUTTON_BBALL,
    CMM_BUTTON_KTQ,
    CMM_BUTTON_SSLOPE,
    CMM_BUTTON_SLAB,
    CMM_BUTTON_PURPLE_SWITCH,
    CMM_BUTTON_TIMED_BOX,
    CMM_BUTTON_HEART,
    CMM_BUTTON_FORMATION,
    CMM_BUTTON_VSLAB,
    CMM_BUTTON_SCORNER,
    CMM_BUTTON_UGENTLE,
    CMM_BUTTON_LGENTLE,
    CMM_BUTTON_BARS,
    CMM_BUTTON_THWOMP,
    CMM_BUTTON_WHOMP,
    CMM_BUTTON_POLE,
    CMM_BUTTON_VEXCLA,
    CMM_BUTTON_LAKITU,
    CMM_BUTTON_FLYGUY,
    CMM_BUTTON_SNUFIT,
    CMM_BUTTON_AMP,
    CMM_BUTTON_BOO,
    CMM_BUTTON_MR_I,
    CMM_BUTTON_SCUTTLEBUG,
    CMM_BUTTON_SPINDRIFT,
    CMM_BUTTON_BLIZZARD,
    CMM_BUTTON_MONEYBAG,
    CMM_BUTTON_SKEETER,
    CMM_BUTTON_POKEY,
    CMM_BUTTON_MINE,
    CMM_BUTTON_FIRE,
    CMM_BUTTON_FLAMETHROWER,
    CMM_BUTTON_FIRE_SPITTER,
    CMM_BUTTON_FIRE_SPINNER,
    CMM_BUTTON_BREAKABLE,
    CMM_BUTTON_THROWABLE,
    CMM_BUTTON_CRAZY,
    CMM_BUTTON_DIAMOND,
    CMM_BUTTON_NPC,
    CMM_BUTTON_NPCCM,
    CMM_BUTTON_BUTTON,
    CMM_BUTTON_BLOCK,
    CMM_BUTTON_WOODPLAT,
    CMM_BUTTON_RFBOX,
    CMM_BUTTON_SHOWRUN,
    CMM_BUTTON_POWER,
    CMM_BUTTON_CONVEYOR,
};

u8 cmm_settings_idlist[] = {OBJECT_TYPE_SETTINGS, OBJECT_TYPE_SCREENSHOT};
u8 cmm_star_idlist[] = {OBJECT_TYPE_STAR, OBJECT_TYPE_RED_COIN_STAR};
u8 cmm_goomba_idlist[] = {OBJECT_TYPE_GOOMBA, OBJECT_TYPE_BIG_GOOMBA, OBJECT_TYPE_TINY_GOOMBA};
u8 cmm_piranha_idlist[] = {OBJECT_TYPE_PIRANHA_PLANT, OBJECT_TYPE_BIG_PIRANHA_PLANT, OBJECT_TYPE_TINY_PIRANHA_PLANT};
u8 cmm_bluecoin_idlist[] = {OBJECT_TYPE_BLUE_COIN, OBJECT_TYPE_BLUE_COIN_SWITCH};
u8 cmm_hammer_idlist[] = {OBJECT_TYPE_HAMMER_BRO, OBJECT_TYPE_FIRE_BRO};
u8 cmm_whomp_idlist[] = {OBJECT_TYPE_WHOMP, OBJECT_TYPE_KING_WHOMP};
u8 cmm_bully_idlist[] = {OBJECT_TYPE_BULLY, OBJECT_TYPE_CHILL_BULLY, OBJECT_TYPE_BIG_BULLY, OBJECT_TYPE_BIG_CHILL_BULLY};
u8 cmm_boo_idlist[] = {OBJECT_TYPE_BOO, OBJECT_TYPE_BIG_BOO};
u8 cmm_plat_idlist[] = {OBJECT_TYPE_PLATFORM_TRACK, OBJECT_TYPE_PLATFORM_LOOPING};
u8 cmm_thwomp_idlist[] = {OBJECT_TYPE_THWOMP, OBJECT_TYPE_GRINDEL};
u8 cmm_flame_idlist[] = {OBJECT_TYPE_RED_FLAME, OBJECT_TYPE_BLUE_FLAME};
u8 cmm_npc_idlist[] = {OBJECT_TYPE_SIGN, OBJECT_TYPE_BUDDY, OBJECT_TYPE_TOAD, OBJECT_TYPE_TUXIE, OBJECT_TYPE_UKIKI};
u8 cmm_npccm_idlist[] = {OBJECT_TYPE_SIGN, OBJECT_TYPE_BUDDY, OBJECT_TYPE_MOLEMAN, OBJECT_TYPE_COBIE};
u8 cmm_power_idlist[] = {OBJECT_TYPE_CROWBAR, OBJECT_TYPE_MASK};

struct cmm_ui_button_type cmm_ui_buttons[] = {
/* CMM_BUTTON_SETTINGS */ {CMM_PM_OBJ,  TRUE,  2, &cmm_settings_idlist,    "Options"},
/* CMM_BUTTON_TEST */     {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_TEST_MARIO,  NULL},
/* CMM_BUTTON_TERRAIN */  {CMM_PM_TILE, FALSE, 0, TILE_TYPE_BLOCK,         NULL},
/* CMM_BUTTON_SLOPE */    {CMM_PM_TILE, FALSE, 0, TILE_TYPE_SLOPE,         NULL},
/* CMM_BUTTON_TROLL */    {CMM_PM_TILE, FALSE, 0, TILE_TYPE_TROLL,         NULL},
/* CMM_BUTTON_STAR */     {CMM_PM_OBJ,  TRUE,  2, &cmm_star_idlist,        "Power Star"},
/* CMM_BUTTON_GOOMBA */   {CMM_PM_OBJ,  TRUE,  3, &cmm_goomba_idlist,      "Goomba"},
/* CMM_BUTTON_PIRANHA */  {CMM_PM_OBJ,  TRUE,  3, &cmm_piranha_idlist,     "Piranha Plant"},
/* CMM_BUTTON_KOOPA */    {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_KOOPA,       NULL},
/* CMM_BUTTON_COIN */     {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_COIN,        NULL},
/* CMM_BUTTON_BLANK */    {CMM_PM_TILE, FALSE, 0, TILE_TYPE_BLOCK,         NULL},
/* CMM_BUTTON_GCOIN */    {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_GREEN_COIN,  NULL},
/* CMM_BUTTON_CORNER */   {CMM_PM_TILE, FALSE, 0, TILE_TYPE_CORNER,        NULL},
/* CMM_BUTTON_ICORNER */  {CMM_PM_TILE, FALSE, 0, TILE_TYPE_ICORNER,       NULL},
/* CMM_BUTTON_RCOIN */    {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_RED_COIN,    NULL},
/* CMM_BUTTON_BCOIN */    {CMM_PM_OBJ,  TRUE,  2, &cmm_bluecoin_idlist,    "Blue Coins"},
/* CMM_BUTTON_NOTEBLOCK */{CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_NOTEBLOCK,   NULL},
/* CMM_BUTTON_CULL */     {CMM_PM_TILE, FALSE, 0, TILE_TYPE_CULL,          NULL},
/* CMM_BUTTON_BOBOMB */   {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_BOBOMB,      NULL},
/* CMM_BUTTON_CHUCKYA */  {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_CHUCKYA,     NULL},
/* CMM_BUTTON_BULLY */    {CMM_PM_OBJ,  TRUE,  4, &cmm_bully_idlist,       "Bully"},
/* CMM_BUTTON_BULLET */   {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_BULLET_BILL, NULL},
/* CMM_BUTTON_HEAVEHO */  {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_HEAVE_HO,    NULL},
/* CMM_BUTTON_MOTOS */    {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_MOTOS,       NULL},
/* CMM_BUTTON_TREE */     {CMM_PM_OBJ,  FALSE, 6, OBJECT_TYPE_TREE,        &txt_bp_tree},
/* CMM_BUTTON_EXCLA */    {CMM_PM_OBJ,  FALSE, 7, OBJECT_TYPE_EXCL_BOX,    &txt_bp_box},
/* CMM_BUTTON_SPAWN */    {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_MARIO_SPAWN, NULL},
/* CMM_BUTTON_REX */      {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_REX,         NULL},
/* CMM_BUTTON_PODOBOO */  {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_PODOBOO,     NULL},
/* CMM_BUTTON_CRABLET */  {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_CRABLET,     NULL},
/* CMM_BUTTON_HAMMER_BRO */{CMM_PM_OBJ, TRUE,  2, &cmm_hammer_idlist,      "Hammer Bro"},
/* CMM_BUTTON_CHICKEN */  {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_CHICKEN,     NULL},
/* CMM_BUTTON_PHANTASM */ {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_PHANTASM,    NULL},
/* CMM_BUTTON_PIPE */     {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_WARP_PIPE,   NULL},
/* CMM_BUTTON_BADGE */    {CMM_PM_OBJ,  FALSE, 23, OBJECT_TYPE_BADGE,      &txt_badges},
/* CMM_BUTTON_WATER */    {CMM_PM_WATER,FALSE, 0, TILE_TYPE_WATER,         NULL},
/* CMM_BUTTON_FENCE */    {CMM_PM_TILE, FALSE, 0, TILE_TYPE_FENCE,         NULL},
/* CMM_BUTTON_KING_BOBOMB */ {CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_KING_BOBOMB, NULL},
/* CMM_BUTTON_WIGGLER */  {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_WIGGLER,     NULL},
/* CMM_BUTTON_BOWSER */   {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_BOWSER,      NULL},
/* CMM_BUTTON_MPLAT */    {CMM_PM_OBJ,  TRUE,  2, &cmm_plat_idlist,        "Moving Platform"},
/* CMM_BUTTON_BBALL */    {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_BOWLING_BALL, NULL},
/* CMM_BUTTON_KTQ */      {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_KOOPA_THE_QUICK, NULL},
/* CMM_BUTTON_SSLOPE */   {CMM_PM_TILE, FALSE, 0, TILE_TYPE_SSLOPE,        NULL},
/* CMM_BUTTON_SLAB */     {CMM_PM_TILE, FALSE, 0, TILE_TYPE_SLAB,          NULL},
/* CMM_BUTTON_PURPLE_SWITCH */{CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_PURPLE_SWITCH, NULL},
/* CMM_BUTTON_TIMED_BOX */ {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_TIMED_BOX,   NULL},
/* CMM_BUTTON_HEART */    {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_RECOVERY_HEART, NULL},
/* CMM_BUTTON_FORMATION */{CMM_PM_OBJ,  FALSE, 5, OBJECT_TYPE_COIN_FORMATION, &txt_coin_formation},
/* CMM_BUTTON_VSLAB */    {CMM_PM_TILE, FALSE, 0, TILE_TYPE_SSLAB,         NULL},
/* CMM_BUTTON_SCORNER */  {CMM_PM_TILE, FALSE, 0, TILE_TYPE_SCORNER,       NULL},
/* CMM_BUTTON_UGENTLE */  {CMM_PM_TILE, FALSE, 0, TILE_TYPE_UGENTLE,       NULL},
/* CMM_BUTTON_LGENTLE */  {CMM_PM_TILE, FALSE, 0, TILE_TYPE_LGENTLE,       NULL},
/* CMM_BUTTON_BARS */     {CMM_PM_TILE, FALSE, 0, TILE_TYPE_BARS,          NULL},
/* CMM_BUTTON_THWOMP */   {CMM_PM_OBJ,  TRUE,  2, &cmm_thwomp_idlist,      "Thwomp"},
/* CMM_BUTTON_WHOMP */    {CMM_PM_OBJ,  TRUE,  2, &cmm_whomp_idlist,       "Whomp"},
/* CMM_BUTTON_POLE */     {CMM_PM_TILE, FALSE, 0, TILE_TYPE_POLE,          NULL},
/* CMM_BUTTON_VEXCLA */   {CMM_PM_OBJ,  FALSE, 7, OBJECT_TYPE_EXCL_BOX,    &txt_bp_vbox},
/* CMM_BUTTON_LAKITU */   {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_LAKITU,      NULL},
/* CMM_BUTTON_FLYGUY */   {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_FLY_GUY,     NULL},
/* CMM_BUTTON_SNUFIT */   {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_SNUFIT,      NULL},
/* CMM_BUTTON_AMP */      {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_AMP,         NULL},
/* CMM_BUTTON_BOO */      {CMM_PM_OBJ,  TRUE,  2, &cmm_boo_idlist,         "Boo"},
/* CMM_BUTTON_MR_I */     {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_MR_I,        NULL},
/* CMM_BUTTON_SCUTTLEBUG */{CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_SCUTTLEBUG,  NULL},
/* CMM_BUTTON_SPINDRIFT */{CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_SPINDRIFT,   NULL},
/* CMM_BUTTON_BLIZZARD */ {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_MR_BLIZZARD, NULL},
/* CMM_BUTTON_MONEYBAG */ {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_MONEYBAG,    NULL},
/* CMM_BUTTON_SKEETER */  {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_SKEETER,     NULL},
/* CMM_BUTTON_POKEY */    {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_POKEY,       NULL},
/* CMM_BUTTON_MINE */     {CMM_PM_OBJ,  FALSE, 0, OBJECT_TYPE_BOWSER_BOMB, NULL},
/* CMM_BUTTON_FIRE */     {CMM_PM_OBJ,  TRUE,  2, &cmm_flame_idlist,       "Flame"},
/* CMM_BUTTON_FLAMETHROWER */{CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_FLAMETHROWER, NULL},
/* CMM_BUTTON_FIRE_SPITTER */{CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_FIRE_SPITTER, NULL},
/* CMM_BUTTON_FIRE_SPINNER */{CMM_PM_OBJ, FALSE, 5, OBJECT_TYPE_FIRE_SPINNER, &txt_fire_spinner},
/* CMM_BUTTON_BREAKABLE */{CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_BBOX_NORMAL, NULL},
/* CMM_BUTTON_THROWABLE */{CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_BBOX_SMALL, NULL},
/* CMM_BUTTON_CRAZY */    {CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_BBOX_CRAZY, NULL},
/* CMM_BUTTON_DIAMOND */  {CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_DIAMOND, NULL},
/* CMM_BUTTON_NPC */      {CMM_PM_OBJ, TRUE, 5, cmm_npc_idlist, "NPC"},
/* CMM_BUTTON_NPCCM */    {CMM_PM_OBJ, TRUE, 4, cmm_npccm_idlist, "NPC"},
/* CMM_BUTTON_BUTTON */   {CMM_PM_OBJ, FALSE, 2, OBJECT_TYPE_BUTTON, &txt_onoff},
/* CMM_BUTTON_BLOCK */    {CMM_PM_OBJ, FALSE, 2, OBJECT_TYPE_ON_OFF_BLOCK, &txt_onoff},
/* CMM_BUTTON_WOODPLAT */ {CMM_PM_OBJ, FALSE, 2, OBJECT_TYPE_WOODPLAT, &txt_woodplat},
/* CMM_BUTTON_RFBOX */    {CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_RFBOX, NULL},
/* CMM_BUTTON_SHOWRUN */  {CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_SHOWRUNNER, NULL},
/* CMM_BUTTON_POWER */    {CMM_PM_OBJ, TRUE, 2, cmm_power_idlist, "Powerup"},
/* CMM_BUTTON_CONVEYOR */ {CMM_PM_OBJ, FALSE, 0, OBJECT_TYPE_CONVEYOR, NULL},
};

u8 cmm_toolbar_defaults[9] = {
    CMM_BUTTON_TERRAIN,
    CMM_BUTTON_SLOPE,
    CMM_BUTTON_BARS,
    CMM_BUTTON_TREE,
    CMM_BUTTON_COIN,
    CMM_BUTTON_STAR,
    CMM_BUTTON_GOOMBA,
    CMM_BUTTON_TEST,
    CMM_BUTTON_SETTINGS,
};

u8 cmm_toolbar[9];
u8 cmm_toolbar_params[9];
f32 cmm_toolbar_y_anim[9] = {
    0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,
};
u8 cmm_toolbox_transition_btn_render = FALSE;
f32 cmm_toolbox_transition_btn_x;
f32 cmm_toolbox_transition_btn_y;
f32 cmm_toolbox_transition_btn_tx;
f32 cmm_toolbox_transition_btn_ty;
Gfx * cmm_toolbox_transition_btn_gfx;
Gfx * cmm_toolbox_transition_btn_old_gfx;
f32 cmm_toolbox_transition_progress;

// went a bit Define Crazy over here, im just quirky like that
#define TOOLBOX_PAGE_WIDTH 9
#define TOOLBOX_NUM_PAGES 2

#define TOOLBOX_WIDTH (TOOLBOX_PAGE_WIDTH * TOOLBOX_NUM_PAGES)
#define TOOLBOX_HEIGHT 5

// gap between the pages
#define TOOLBOX_PAGE_OFFSET 30
#define TOOLBOX_SIZE (TOOLBOX_WIDTH * TOOLBOX_HEIGHT)

// X offset based on scroll
#define TOOLBOX_OFFSET_MIN 34
#define TOOLBOX_OFFSET_MAX ((TOOLBOX_OFFSET_MIN - (32*TOOLBOX_PAGE_WIDTH)) - TOOLBOX_PAGE_OFFSET)

s32 cmm_toolbox_x_offset = TOOLBOX_OFFSET_MIN;

// macros to get position of a certain toolbox position
#define GET_TOOLBOX_X(i) (cmm_toolbox_x_offset + (((i) % TOOLBOX_WIDTH)*32) + ((i) % TOOLBOX_WIDTH >= TOOLBOX_PAGE_WIDTH ? TOOLBOX_PAGE_OFFSET : 0))
#define GET_TOOLBOX_Y(i) (220 - (((i) / TOOLBOX_WIDTH)*32))

u8 cmm_toolbox[TOOLBOX_SIZE];
u8 cmm_toolbox_params[TOOLBOX_SIZE];
//Different toolboxes for different game styles
#define _ CMM_BUTTON_BLANK
u8 cmm_toolbox_btcm[TOOLBOX_SIZE] = {
    CMM_BUTTON_TERRAIN, CMM_BUTTON_SLAB, CMM_BUTTON_SLOPE, CMM_BUTTON_CORNER, CMM_BUTTON_ICORNER, CMM_BUTTON_VSLAB, CMM_BUTTON_SSLOPE, CMM_BUTTON_SCORNER, _,
    CMM_BUTTON_GOOMBA, CMM_BUTTON_BOBOMB, CMM_BUTTON_CHUCKYA, CMM_BUTTON_KOOPA, CMM_BUTTON_LAKITU, CMM_BUTTON_FLYGUY, CMM_BUTTON_SNUFIT, CMM_BUTTON_THWOMP, CMM_BUTTON_WHOMP,

    CMM_BUTTON_LGENTLE, CMM_BUTTON_UGENTLE, CMM_BUTTON_TROLL, CMM_BUTTON_WATER, CMM_BUTTON_FENCE, CMM_BUTTON_BARS, CMM_BUTTON_POLE, CMM_BUTTON_TREE, CMM_BUTTON_CULL,
    CMM_BUTTON_BULLY, CMM_BUTTON_MOTOS, CMM_BUTTON_HEAVEHO, CMM_BUTTON_BULLET, CMM_BUTTON_AMP, CMM_BUTTON_PIRANHA, CMM_BUTTON_BOO,CMM_BUTTON_MR_I,CMM_BUTTON_SCUTTLEBUG,

    CMM_BUTTON_STAR, CMM_BUTTON_COIN, CMM_BUTTON_FORMATION, CMM_BUTTON_GCOIN, CMM_BUTTON_RCOIN, CMM_BUTTON_BCOIN, CMM_BUTTON_EXCLA, CMM_BUTTON_HEART, CMM_BUTTON_BADGE,
    CMM_BUTTON_SPINDRIFT,CMM_BUTTON_BLIZZARD,CMM_BUTTON_MONEYBAG,CMM_BUTTON_SKEETER, CMM_BUTTON_POKEY, CMM_BUTTON_REX, CMM_BUTTON_HAMMER_BRO, CMM_BUTTON_PODOBOO, CMM_BUTTON_PHANTASM,

    CMM_BUTTON_MPLAT, CMM_BUTTON_PURPLE_SWITCH, CMM_BUTTON_TIMED_BOX, CMM_BUTTON_BREAKABLE, CMM_BUTTON_RFBOX, CMM_BUTTON_DIAMOND, CMM_BUTTON_WOODPLAT, CMM_BUTTON_NPCCM, _,
    CMM_BUTTON_FIRE, CMM_BUTTON_FLAMETHROWER, CMM_BUTTON_FIRE_SPITTER, CMM_BUTTON_FIRE_SPINNER, _, _, CMM_BUTTON_CHICKEN, CMM_BUTTON_CRABLET, CMM_BUTTON_SHOWRUN,

    CMM_BUTTON_NOTEBLOCK, CMM_BUTTON_BUTTON, CMM_BUTTON_BLOCK, CMM_BUTTON_CONVEYOR, _, _, _, _, _,
    CMM_BUTTON_SPAWN, CMM_BUTTON_THROWABLE, CMM_BUTTON_CRAZY, CMM_BUTTON_POWER, _, _, _, _, _,
};

u8 cmm_toolbox_vanilla[TOOLBOX_SIZE] = {
    CMM_BUTTON_TERRAIN, CMM_BUTTON_SLAB, CMM_BUTTON_SLOPE, CMM_BUTTON_CORNER, CMM_BUTTON_ICORNER, CMM_BUTTON_VSLAB, CMM_BUTTON_SSLOPE, CMM_BUTTON_SCORNER, _,
    CMM_BUTTON_GOOMBA, CMM_BUTTON_BOBOMB, CMM_BUTTON_CHUCKYA, CMM_BUTTON_KOOPA, CMM_BUTTON_LAKITU, CMM_BUTTON_FLYGUY, CMM_BUTTON_SNUFIT, CMM_BUTTON_THWOMP, CMM_BUTTON_WHOMP,

    CMM_BUTTON_LGENTLE, CMM_BUTTON_UGENTLE, CMM_BUTTON_TROLL, CMM_BUTTON_WATER, CMM_BUTTON_FENCE, CMM_BUTTON_BARS, CMM_BUTTON_POLE, CMM_BUTTON_TREE, CMM_BUTTON_CULL,
    CMM_BUTTON_BULLY, CMM_BUTTON_MOTOS, CMM_BUTTON_HEAVEHO, CMM_BUTTON_BULLET, CMM_BUTTON_AMP, CMM_BUTTON_PIRANHA, CMM_BUTTON_BOO,CMM_BUTTON_MR_I,CMM_BUTTON_SCUTTLEBUG,

    CMM_BUTTON_STAR, CMM_BUTTON_COIN, CMM_BUTTON_FORMATION, CMM_BUTTON_RCOIN, CMM_BUTTON_BCOIN, CMM_BUTTON_VEXCLA, CMM_BUTTON_HEART, CMM_BUTTON_KTQ, _,
    CMM_BUTTON_SPINDRIFT,CMM_BUTTON_BLIZZARD,CMM_BUTTON_MONEYBAG,CMM_BUTTON_SKEETER, CMM_BUTTON_POKEY, CMM_BUTTON_KING_BOBOMB, CMM_BUTTON_WIGGLER, CMM_BUTTON_BOWSER, _,

    CMM_BUTTON_MPLAT, CMM_BUTTON_PURPLE_SWITCH, CMM_BUTTON_TIMED_BOX, CMM_BUTTON_BREAKABLE, CMM_BUTTON_RFBOX, CMM_BUTTON_DIAMOND, CMM_BUTTON_WOODPLAT, CMM_BUTTON_NPC, _,
    CMM_BUTTON_FIRE, CMM_BUTTON_FLAMETHROWER, CMM_BUTTON_FIRE_SPITTER, CMM_BUTTON_FIRE_SPINNER, CMM_BUTTON_BBALL, _, _, _, _,

    CMM_BUTTON_NOTEBLOCK, CMM_BUTTON_BUTTON, CMM_BUTTON_BLOCK, CMM_BUTTON_CONVEYOR, _, _, _, _, _,
    CMM_BUTTON_SPAWN, CMM_BUTTON_THROWABLE, CMM_BUTTON_CRAZY, CMM_BUTTON_MINE, _, _, _, _, _,
};

char *cmm_costume_string_table[] = {
    "Mario",
    "Fire Mario",
    "Glitchy",
    "Luigi",
    "Wario",
    "Disco Mario",
    "Undead Pirate",
    "Mocap Mario",
    "Darius",
    "Butler Mario",
    "Retro Mario",
    "Thwompio",
    "Builder Mario",
    "Showrunner",
    "Cosmic Phantasm",
};

char *cmm_music_type_string_table[] = {
    "Level",
    "Koopa Race",
    "Bossfight",
};

char *cmm_music_album_string_table[] = {
    "Super Mario 64 OST",
    "Beyond the Cursed Mirror OST",
    "ROM Hack Music Ports",
    "Retro 2D Mario Music"
};

char *cmm_music_vanilla_string_table[] = {
    "Bob-omb Battlefield",
    "Slider",
    "Dire, Dire Docks",
    "Dire, Dire Docks (Underwater)",
    "Lethal Lava Land",
    "Cool, Cool Mountain",
    "Big Boo's Haunt",
    "Hazy Maze Cave",
    "Hazy Maze Cave (Haze)",
    "Koopa's Road",
    "Stage Boss",
    "Koopa's Theme",
    "Ultimate Koopa",
    "Inside the Castle Walls",
};

char *cmm_music_btcm_string_table[] = {
    "Cosmic Castle",
    "Red-Hot Reservoir",
    "Lonely Floating Farm",
    "Jurassic Savanna",
    "The Phantom Strider",
    "Virtuaplex",
    "Immense Residence",
    "Thwomp Towers",
    "Cursed Boss",
    "Road To The Boss",
    "Urbowser",
    "Showrunner's Theme",
    "The Show's Finale",
    "Parasite Moon",
    "AGAMEMNON",
};

char *cmm_music_romhack_string_table[] = {
    "Bianco Hills (Super Mario Sunshine)",
    "Sky and Sea (Super Mario Sunshine)",
    "Secret Course (Super Mario Sunshine)",
    "Comet Observatory (Mario Galaxy)",
    "Buoy Base Galaxy (Mario Galaxy)",
    "Battlerock Galaxy (Mario Galaxy)",
    "Ghostly Galaxy (Mario Galaxy)",
    "Purple Comet (Mario Galaxy)",
    "Honeybloom Galaxy (Mario Galaxy 2)",
    "Piranha Creeper Creek (3D World)",
    "Desert (New Super Mario Bros.)",

    "Koopa Troopa Beach (Mario Kart 64)",
    "Frappe Snowland (Mario Kart 64)",
    "Bowser's Castle (Mario Kart 64)",
    "Rainbow Road (Mario Kart 64)",
    "Waluigi Pinball (Mario Kart DS)",
    "Rainbow Road (Mario Kart 8)",

    "Mario's Pad (Super Mario RPG)",
    "Nimbus Land (Super Mario RPG)",
    "Forest Maze (Super Mario RPG)",
    "Sunken Ship (Super Mario RPG)",

    "Dry Dry Desert (Paper Mario 64)",
    "Forever Forest (Paper Mario 64)",
    "Petal Meadows (Paper Mario: TTYD)",
    "Riddle Tower (Paper Mario: TTYD)",
    "Rogueport Sewers (Paper Mario: TTYD)",
    "X-Naut Fortress (Paper Mario: TTYD)",
    "Flipside (Super Paper Mario)",
    "Lineland Road (Super Paper Mario)",
    "Sammer Kingdom (Super Paper Mario)",
    "Floro Caverns (Super Paper Mario)",
    "Overthere Stair (Super Paper Mario)",

    "Yoshi's Tropical Island (Mario Party)",
    "Rainbow Castle (Mario Party)",
    "Behind Yoshi Village (Partners in Time)",
    "Gritzy Desert (Partners in Time)",
    "Bumpsy Plains (Bowser's Inside Story)",
    "Deep Castle (Bowser's Inside Story)",

    "Overworld (Yoshi's Island)",
    "Underground (Yoshi's Island)",
    "Title (Yoshi's Story)",

    "Kokiri Forest (Ocarina of Time)",
    "Lost Woods (Ocarina of Time)",
    "Gerudo Valley (Ocarina of Time)",
    "Stone Tower Temple (Majora's Mask)",
    "Outset Island (Wind Waker)",
    "Lake Hylia (Twilight Princess)",
    "Gerudo Desert (Twilight Princess)",
    "Skyloft (Skyward Sword)",

    "Frantic Factory (Donkey Kong 64)",
    "Hideout Helm (Donkey Kong 64)",
    "Creepy Castle (Donkey Kong 64)",
    "Gloomy Galleon (Donkey Kong 64)",
    "Fungi Forest (Donkey Kong 64)",
    "Crystal Caves (Donkey Kong 64)",
    "Angry Aztec (Donkey Kong 64)",
    "In a Snow-Bound Land (DKC 2)",

    "Bubblegloop Swamp (Banjo-Kazooie)",
    "Freezeezy Peak (Banjo-Kazooie)",
    "Gobi's Valley (Banjo-Kazooie)",

    "Factory Inspection (Kirby 64)",
    "Green Garden (Bomberman 64)",
    "Black Fortress (Bomberman 64)",
    "Windy Hill (Sonic Adventure)",
    "Sky Tower (Pokemon Mystery Dungeon)",
    "Youkai Mountain (Touhou 10)",
    "Forest Temple (Final Fantasy VII)",
    "Band Land (Rayman)",
};

char *cmm_music_retro_string_table[] = {
    "Overworld (Super Mario Bros.)",
    "Castle Mix (Super Mario Bros.)",
    "Overworld (Super Mario Bros. 2)",
    "Overworld Mix (Super Mario Bros. 3)",
    "Fortress (Super Mario Bros. 3)",
    "Athletic (Super Mario World)",
    "Castle (Super Mario World)",
};

/*
    Legacy music contents for v1.0.0 levels
*/ 
u8 seq_musicmenu_array[] = {
    SEQ_LEVEL_GRASS,
    SEQ_LEVEL_SLIDE,
    SEQ_LEVEL_WATER,
    SEQ_LEVEL_WATER,
    SEQ_LEVEL_HOT,
    SEQ_LEVEL_SNOW,
    SEQ_LEVEL_SPOOKY,
    SEQ_LEVEL_UNDERGROUND,
    SEQ_LEVEL_UNDERGROUND,
    SEQ_LEVEL_KOOPA_ROAD_2,
    SEQ_VANILLA_BOSS,
    SEQ_LEVEL_BOSS_KOOPA,
    SEQ_LEVEL_BOSS_KOOPA_FINAL,
    SEQ_LEVEL_INSIDE_CASTLE2,

    SEQ_LEVEL_INSIDE_CASTLE,
    SEQ_REDHOT,
    SEQ_FARM,
    SEQ_JUNGLE,
    SEQ_PIRATE,
    SEQ_EVENT_CUTSCENE_ENDING,
    SEQ_BIG_HOUSE,
    SEQ_NSMB_CASTLE,
    SEQ_EVENT_BOSS,
    SEQ_LEVEL_KOOPA_ROAD,
    SEQ_COSMIC_SEED_BOSS,
    SEQ_SHOWRUNNER_BOSS,
    SEQ_COSMIC_SEED_LEVEL,
    SEQ_FINAL_BOSS,

    SEQ_SMS_BIANCO_HILLS,
    SEQ_SMS_SKY_AND_SEA,
    SEQ_SMS_SECRET_COURSE,
    SEQ_SMG_COMET_OBSERVATORY,
    SEQ_SMG_BUOY_BASE,
    SEQ_SMG_BATTLEROCK,
    SEQ_SMG_GHOSTLY_GALAXY,
    SEQ_SMG_PURPLE_COMET,
    SEQ_SMG2_HONEYBLOOM,
    SEQ_PIRANHA_CREEK,
    SEQ_NSMB_DESERT,

    SEQ_KOOPA_BEACH, // mk64 koopa troopa beach
    SEQ_FRAPPE_SNOWLAND,
    SEQ_MK64_BOWSERS_CASTLE,
    SEQ_MK64_RAINBOW_ROAD,
    SEQ_MKDS_WALUIGI_PINBALL,
    SEQ_MK8_RAINBOW_ROAD,

    SEQ_SMRPG_MARIOS_PAD,             // 0x46
    SEQ_SMRPG_NIMBUS_LAND,
    SEQ_FOREST_MAZE,
    SEQ_SMRPG_SUNKEN_SHIP,            // 0x47

    SEQ_PM_DRY_DESERT,
    SEQ_PM_FOREVER_FOREST,
    SEQ_TTYD_PETAL_MEADOWS,
    SEQ_TTYD_EIGHT_KEY_DOMAIN, // riddle tower
    SEQ_TTYD_ROGUEPORT_SEWERS,
    SEQ_TTYD_XNAUT_FORTRESS,
    SEQ_SPM_FLIPSIDE,
    SEQ_SPM_LINELAND_ROAD,
    SEQ_SAMMER_KINGDOM,
    SEQ_SPM_FLORO_CAVERNS,
    SEQ_SPM_OVERTHERE_STAIR,

    SEQ_MP_YOSHIS_TROPICAL_ISLAND,
    SEQ_MP_RAINBOW_CASTLE,
    SEQ_MLPIT_BEHIND_YOSHI_VILLAGE,
    SEQ_PIT_GRITZY_DESERT,
    SEQ_BIS_BUMPSY_PLAINS,
    SEQ_BIS_DEEP_CASTLE,
    SEQ_YI_OVERWORLD,
    SEQ_YI_CRYSTAL_CAVES,
    SEQ_YS_TITLE,                     // 0x51

    SEQ_OOT_KOKIRI_FOREST,
    SEQ_OOT_LOST_WOODS,
    SEQ_OOT_GERUDO_VALLEY,            // 0x52
    SEQ_STONE_TOWER_TEMPLE,
    SEQ_WW_OUTSET_ISLAND,
    SEQ_TP_LAKE_HYLIA,                // 0x53
    SEQ_TP_GERUDO_DESERT,
    SEQ_SS_SKYLOFT,

    SEQ_DK64_FRANTIC_FACTORY,
    SEQ_DK64_HIDEOUT_HELM,
    SEQ_DK_CREEPY_CASTLE,
    SEQ_DK64_GLOOMY_GALLEON,
    SEQ_DK64_FUNGI_FOREST,
    SEQ_DK64_CRYSTAL_CAVES,
    SEQ_DK64_ANGRY_AZTEC,
    SEQ_DKC2_SNOWBOUND_LAND,

    SEQ_BK_BUBBLEGLOOP_SWAMP,
    SEQ_BK_FREEZEEZY_PEAKS,
    SEQ_BK_GOBI_VALLEY,

    SEQ_K64_FACTORY_INSPECTION,
    SEQ_BM_GREEN_GARDEN,
    SEQ_BM_BLACK_FORTRESS,
    SEQ_SA_WINDY_HILL,
    SEQ_PKMN_SKY_TOWER,
    SEQ_TOUHOU_YOUKAI_MOUNTAIN,
    SEQ_FOREST_TEMPLE,
    SEQ_RAYMAN_BAND_LAND,

    SEQ_SMB1_OVERWORLD,
    SEQ_SMB_BOWSER_REMIX,             // 0x4B
    SEQ_SMB2_OVERWORLD,
    SEQ_SMB3_OVERWORLD,
    SEQ_SMB3_CASTLE,
    SEQ_SMW_ATHLETIC,                 // 0x4E
    SEQ_SMW_CASTLE,
};

// Array of sizes
u8 seq_legacy_sizes[] = {

};

/*
    New album arrays for v1.1.0 and greater
*/

// Vanilla album
u8 seq_album_vanilla[] = {
    SEQ_LEVEL_GRASS,
    SEQ_LEVEL_SLIDE,
    SEQ_LEVEL_WATER,
    SEQ_LEVEL_WATER,
    SEQ_LEVEL_HOT,
    SEQ_LEVEL_SNOW,
    SEQ_LEVEL_SPOOKY,
    SEQ_LEVEL_UNDERGROUND,
    SEQ_LEVEL_UNDERGROUND,
    SEQ_LEVEL_KOOPA_ROAD_2,
    SEQ_VANILLA_BOSS,
    SEQ_LEVEL_BOSS_KOOPA,
    SEQ_LEVEL_BOSS_KOOPA_FINAL,
    SEQ_LEVEL_INSIDE_CASTLE2,
};

// BTCM album
u8 seq_album_btcm[] = {
    SEQ_LEVEL_INSIDE_CASTLE,
    SEQ_REDHOT,
    SEQ_FARM,
    SEQ_JUNGLE,
    SEQ_PIRATE,
    SEQ_EVENT_CUTSCENE_ENDING,
    SEQ_BIG_HOUSE,
    SEQ_NSMB_CASTLE,
    SEQ_EVENT_BOSS,
    SEQ_LEVEL_KOOPA_ROAD,
    SEQ_COSMIC_SEED_BOSS,
    SEQ_SHOWRUNNER,
    SEQ_SHOWRUNNER_BOSS,
    SEQ_COSMIC_SEED_LEVEL,
    SEQ_FINAL_BOSS,
};

// Romhack Album
u8 seq_album_hacks[] = {
    SEQ_SMS_BIANCO_HILLS,
    SEQ_SMS_SKY_AND_SEA,
    SEQ_SMS_SECRET_COURSE,
    SEQ_SMG_COMET_OBSERVATORY,
    SEQ_SMG_BUOY_BASE,
    SEQ_SMG_BATTLEROCK,
    SEQ_SMG_GHOSTLY_GALAXY,
    SEQ_SMG_PURPLE_COMET,
    SEQ_SMG2_HONEYBLOOM,
    SEQ_PIRANHA_CREEK,
    SEQ_NSMB_DESERT,

    SEQ_KOOPA_BEACH, // mk64 koopa troopa beach
    SEQ_FRAPPE_SNOWLAND,
    SEQ_MK64_BOWSERS_CASTLE,
    SEQ_MK64_RAINBOW_ROAD,
    SEQ_MKDS_WALUIGI_PINBALL,
    SEQ_MK8_RAINBOW_ROAD,

    SEQ_SMRPG_MARIOS_PAD,             // 0x46
    SEQ_SMRPG_NIMBUS_LAND,
    SEQ_FOREST_MAZE,
    SEQ_SMRPG_SUNKEN_SHIP,            // 0x47

    SEQ_PM_DRY_DESERT,
    SEQ_PM_FOREVER_FOREST,
    SEQ_TTYD_PETAL_MEADOWS,
    SEQ_TTYD_EIGHT_KEY_DOMAIN, // riddle tower
    SEQ_TTYD_ROGUEPORT_SEWERS,
    SEQ_TTYD_XNAUT_FORTRESS,
    SEQ_SPM_FLIPSIDE,
    SEQ_SPM_LINELAND_ROAD,
    SEQ_SAMMER_KINGDOM,
    SEQ_SPM_FLORO_CAVERNS,
    SEQ_SPM_OVERTHERE_STAIR,

    SEQ_MP_YOSHIS_TROPICAL_ISLAND,
    SEQ_MP_RAINBOW_CASTLE,
    SEQ_MLPIT_BEHIND_YOSHI_VILLAGE,
    SEQ_PIT_GRITZY_DESERT,
    SEQ_BIS_BUMPSY_PLAINS,
    SEQ_BIS_DEEP_CASTLE,
    SEQ_YI_OVERWORLD,
    SEQ_YI_CRYSTAL_CAVES,
    SEQ_YS_TITLE,                     // 0x51

    SEQ_OOT_KOKIRI_FOREST,
    SEQ_OOT_LOST_WOODS,
    SEQ_OOT_GERUDO_VALLEY,            // 0x52
    SEQ_STONE_TOWER_TEMPLE,
    SEQ_WW_OUTSET_ISLAND,
    SEQ_TP_LAKE_HYLIA,                // 0x53
    SEQ_TP_GERUDO_DESERT,
    SEQ_SS_SKYLOFT,

    SEQ_DK64_FRANTIC_FACTORY,
    SEQ_DK64_HIDEOUT_HELM,
    SEQ_DK_CREEPY_CASTLE,
    SEQ_DK64_GLOOMY_GALLEON,
    SEQ_DK64_FUNGI_FOREST,
    SEQ_DK64_CRYSTAL_CAVES,
    SEQ_DK64_ANGRY_AZTEC,
    SEQ_DKC2_SNOWBOUND_LAND,

    SEQ_BK_BUBBLEGLOOP_SWAMP,
    SEQ_BK_FREEZEEZY_PEAKS,
    SEQ_BK_GOBI_VALLEY,

    SEQ_K64_FACTORY_INSPECTION,
    SEQ_BM_GREEN_GARDEN,
    SEQ_BM_BLACK_FORTRESS,
    SEQ_SA_WINDY_HILL,
    SEQ_PKMN_SKY_TOWER,
    SEQ_TOUHOU_YOUKAI_MOUNTAIN,
    SEQ_FOREST_TEMPLE,
    SEQ_RAYMAN_BAND_LAND,   // Band Land is Cinema
};

// Retro album
u8 seq_album_retro[] = {
    SEQ_SMB1_OVERWORLD,
    SEQ_SMB_BOWSER_REMIX,             // 0x4B
    SEQ_SMB2_OVERWORLD,
    SEQ_SMB3_OVERWORLD,
    SEQ_SMB3_CASTLE,
    SEQ_SMW_ATHLETIC,                 // 0x4E
    SEQ_SMW_CASTLE,
};

char *cmm_envfx_string_table[] = {
    "None",
    "Ashes",
    "Snow",
    "Rain",
    "Sandstorm",
};

//envfx table
u8 cmm_envfx_table[] = {
    ENVFX_NONE,         // no effects
    ENVFX_ASHES,       // CCM, SL
    ENVFX_SNOW,     // unused
    ENVFX_RAIN,
    ENVFX_SANDSTORM,
};

char *cmm_theme_string_table[] = {
    "Generic",
    "Shifting Sand Land",
    "Red Hot Reservoir",
    "Hazy Maze Cave",
    "Peach's Castle",
    "Virtuaplex",
    "Snowy Palace",
    "Big Boo's Haunt",
    "Jolly Roger Bay",
    "Retroland",
    "Custom",
    "Minecraft",
};

//cmm themes moved to cursed_mirror_maker.h to work with object df
//example: ice bully appears in snow theme
//impossible to extern enum : (

char *cmm_bg_string_table[] = {
    "Ocean Hills",
    "Cloudy Sky",
    "Fiery Sky",
    "Green Cave",
    "Haunted Forest", // 4 - doesn't generate black chasm
    "Ice Mountains",
    "Desert Pyramids",
    "Underwater City",
    "Pink Sky",
    "None", // 9 - doesn't generate black chasm
};

#define CMM_BOUNDARY_INNER_FLOOR   (1 << 0) // Has the main floor
#define CMM_BOUNDARY_OUTER_FLOOR   (1 << 1) // Has the fading outer floor
#define CMM_BOUNDARY_INNER_WALLS   (1 << 2) // Has the inner walls going up to boundary height - has fading part if death plane
#define CMM_BOUNDARY_OUTER_WALLS   (1 << 3) // Has fading outer walls extending downwards

u8 cmm_boundary_table[] = {
    0, // Void
    CMM_BOUNDARY_INNER_FLOOR | CMM_BOUNDARY_OUTER_FLOOR, // Plain
    CMM_BOUNDARY_INNER_FLOOR | CMM_BOUNDARY_OUTER_FLOOR | CMM_BOUNDARY_INNER_WALLS, // Valley
    CMM_BOUNDARY_OUTER_FLOOR | CMM_BOUNDARY_INNER_WALLS, // Chasm
    CMM_BOUNDARY_INNER_FLOOR | CMM_BOUNDARY_OUTER_WALLS, // Plateau
};

char *cmm_bound_string_table[] = {
    "Void",
    "Plain",
    "Valley",
    "Chasm",
    "Plateau",
};

//skybox table
u8 *cmm_skybox_table[] = {
    _water_skybox_yay0SegmentRomStart,
    _water_skybox_yay0SegmentRomEnd,
    _cloud_floor_skybox_yay0SegmentRomStart,
    _cloud_floor_skybox_yay0SegmentRomEnd,
    _bitfs_skybox_yay0SegmentRomStart,
    _bitfs_skybox_yay0SegmentRomEnd,
    _bidw_skybox_yay0SegmentRomStart,
    _bidw_skybox_yay0SegmentRomEnd,
    _bbh_skybox_yay0SegmentRomStart,
    _bbh_skybox_yay0SegmentRomEnd,
    _ccm_skybox_yay0SegmentRomStart,
    _ccm_skybox_yay0SegmentRomEnd,
    _ssl_skybox_yay0SegmentRomStart,
    _ssl_skybox_yay0SegmentRomEnd,
    _wdw_skybox_yay0SegmentRomStart,
    _wdw_skybox_yay0SegmentRomEnd,
    _bits_skybox_yay0SegmentRomStart,
    _bits_skybox_yay0SegmentRomEnd,
    NULL,
    NULL,
};

extern char *cmm_get_floor_name(s32, char *);
extern char *cmm_get_coinstar_str(s32, char *);
extern char *cmm_get_waterlevel_name(s32, char *);
extern char *cmm_get_boundaryheight_name(s32, char *);
extern char *cmm_get_category(s32, char *);
extern char *cmm_get_custom_mat(s32, char *);
extern void reload_bg(void);
extern void reload_theme(void);
extern void generate_terrain_gfx(void);

extern u8 get_seq(u8 album, u8 id);
extern void music_type_changed(void);
extern void music_category_changed(void);
extern void song_changed(void);

struct cmm_settings_button cmm_settings_misc_buttons[] = {
    {"Coin Star:", &cmm_lopt_coinstar, NULL, 1, cmm_get_coinstar_str, NULL},
    {"Water Level:", &cmm_lopt_waterlevel, NULL,               65,               cmm_get_waterlevel_name, generate_terrain_gfx},
    {"Costume:", &cmm_lopt_costume, cmm_costume_string_table, ARRAY_COUNT(cmm_costume_string_table), NULL, NULL},
};

#define MISC_COINSTAR_INDEX 0
#define MISC_WATER_INDEX 1
#define MISC_COSTUME_INDEX 2

struct cmm_settings_button cmm_settings_misc_buttons_vanilla[] = {
    {"Coin Star:", &cmm_lopt_coinstar, NULL, 1, cmm_get_coinstar_str, NULL},
    {"Water Level:", &cmm_lopt_waterlevel, NULL,               65,               cmm_get_waterlevel_name, generate_terrain_gfx},
};
#define MISCV_COINSTAR_INDEX 0
#define MISCV_WATER_INDEX 1

struct cmm_settings_button cmm_settings_env_buttons[] = {
    {"Theme:",   &cmm_lopt_theme,   cmm_theme_string_table,   ARRAY_COUNT(cmm_theme_string_table) - 1, NULL, reload_theme},
    {"Skybox:",  &cmm_lopt_bg,      cmm_bg_string_table,      ARRAY_COUNT(cmm_bg_string_table),    NULL, reload_bg},
    {"Effect:",  &cmm_lopt_envfx,   cmm_envfx_string_table,   ARRAY_COUNT(cmm_envfx_string_table), NULL, NULL},
};
#define ENV_THEME_INDEX 0
#define ENV_SKYBOX_INDEX 1
#define ENV_EFFECT_INDEX 2

struct cmm_settings_button cmm_settings_boundary_buttons[] = {
    {"Boundary:", &cmm_lopt_boundary, cmm_bound_string_table, ARRAY_COUNT(cmm_bound_string_table), NULL, generate_terrain_gfx},
    {"Material:",   &cmm_lopt_boundary_mat, NULL, NUM_MATERIALS_PER_THEME, cmm_get_floor_name, generate_terrain_gfx}, // Filled in by code
    {"Height:", &cmm_lopt_boundary_height,   NULL, 65, cmm_get_boundaryheight_name, generate_terrain_gfx},
};

#define BOUNDARY_BOUNDARY_INDEX 0
#define BOUNDARY_TILE_INDEX 1
#define BOUNDARY_HEIGHT_INDEX 2

struct cmm_settings_button cmm_settings_music_buttons[] = {
    {"Type:", &cmm_lopt_seq_seqtype, cmm_music_type_string_table, ARRAY_COUNT(cmm_music_type_string_table), NULL, music_type_changed},
    {"Album:",   &cmm_lopt_seq_album,  cmm_music_album_string_table,  ARRAY_COUNT(cmm_music_album_string_table), NULL, music_category_changed},
    {"Song:", NULL, NULL, 0, NULL, NULL}, // Filled in by code
};
#define MUSIC_ALBUM_INDEX 1
#define MUSIC_SONG_INDEX 2

struct cmm_settings_button cmm_settings_mat_selector[] = {
    {"Category:", NULL, NULL, ARRAY_COUNT(cmm_matlist) - 1, cmm_get_category,   NULL},
    {"Material:", NULL, NULL, 0, cmm_get_custom_mat, NULL},
};

char *cmm_fence_names[] = {
    "Wooden (1)",
    "Wooden (2)",
    "Wooden (3)",
    "Barbed Wire",
    "Metal",
    "Netting",
    "Castle",
    "Stanchion",
    "Mansion",
    "Rope",
    "Snowy (1)",
    "Snowy (2)",
};

char *cmm_bar_names[] = {
    "Grille",
    "Mesh",
    "Fine Mesh",
    "Red Grille",
    "Red Mesh",
    "Pink Mesh",
    "Clock Grille",
    "Desert Grille",
    "Cage Bars",
};

char *cmm_water_names[] = {
    "Default",
    "Swampy",
};

struct cmm_settings_button cmm_settings_other_selectors[] = {
    {"Fence:", &cmm_curr_custom_theme.fence, cmm_fence_names, ARRAY_COUNT(cmm_fence_names), NULL, NULL},
    {"Iron Mesh:", &cmm_curr_custom_theme.bars, cmm_bar_names, ARRAY_COUNT(cmm_bar_names), NULL, NULL},
    {"Water:", &cmm_curr_custom_theme.water, cmm_water_names, ARRAY_COUNT(cmm_water_names), NULL, NULL},
};

char *cmm_settings_menu_names[] = {
    "Environment",
    "Level Boundary",
    "Music",
    "Miscellaneous",
    "System",
};

char *cmm_settings_system_buttons[] = {
    "Save & Quit",
    "Play Level",
    //"Level Size:",
    //"Apply Size Change (Dangerous!)",
};


void draw_cmm_settings_misc(f32,f32);
void draw_cmm_settings_misc_vanilla(f32,f32);
void draw_cmm_settings_env(f32,f32);
void draw_cmm_settings_boundary(f32,f32);
void draw_cmm_settings_music(f32,f32);
void draw_cmm_settings_system(f32,f32);

void (*cmm_settings_menus[])(f32, f32) = {
    draw_cmm_settings_env,
    draw_cmm_settings_boundary,
    draw_cmm_settings_music,
    draw_cmm_settings_misc,
    draw_cmm_settings_system,
};

u8 cmm_settings_menu_lengths[] = {
    ARRAY_COUNT(cmm_settings_env_buttons),
    ARRAY_COUNT(cmm_settings_boundary_buttons),
    ARRAY_COUNT(cmm_settings_music_buttons),
    ARRAY_COUNT(cmm_settings_misc_buttons),
    ARRAY_COUNT(cmm_settings_system_buttons),
};

#define SETTINGS_ENV_INDEX 0
#define SETTINGS_BOUNDARY_INDEX 1
#define SETTINGS_MUSIC_INDEX 2
#define SETTINGS_MISC_INDEX 3
#define SETTINGS_SYSTEM_INDEX 4

// These get copied over to the above array
struct cmm_settings_button cmm_settings_music_albums[] = {
    {"Song:",  &cmm_lopt_seq_song, cmm_music_vanilla_string_table, ARRAY_COUNT(cmm_music_vanilla_string_table), NULL, song_changed},
    {"Song:",  &cmm_lopt_seq_song, cmm_music_btcm_string_table, ARRAY_COUNT(cmm_music_btcm_string_table), NULL, song_changed},
    {"Song:",  &cmm_lopt_seq_song, cmm_music_romhack_string_table, ARRAY_COUNT(cmm_music_romhack_string_table), NULL, song_changed},
    {"Song:",  &cmm_lopt_seq_song, cmm_music_retro_string_table, ARRAY_COUNT(cmm_music_retro_string_table), NULL, song_changed},
};

struct cmm_settings_button cmm_settings_backtomainmenu[] = {
};

char *cmm_gamemode_string_table[] = {
    "Vanilla SM64",
    "Cursed Mirror",
};

char *cmm_levelsize_string_table[] = {
    "Small (32)",
    "Medium (48)",
    "Large (64)",
};

char *cmm_template_string_table[] = {
    "Grassy",
    "Desert",
    "Lava",
    "Underwater",
    "Snowy",
};

struct cmm_template {
    u8 music[2]; // vanilla, btcm
    u8 envfx;
    u8 bg;
    u8 theme;
    u8 plane;

    u8 spawnHeight;
    u8 platform;
};

struct cmm_template cmm_templates[] = {
    {{0, 16}, 0, 0, 0, 0,     2, FALSE},   // Grassy - BoB, Floating Farm
    {{4, 49}, 0, 6, 1, 0,     2, FALSE},   // Desert - LLL, Dry Dry Desert
    {{4, 15}, 1, 2, 2, 8,     2, TRUE},    // Lava -   LLL, Red-Hot Reservoir
    {{2, 29}, 0, 0, 8, 0,     2, FALSE},   // Water -  DDD, Sky and Sea
    {{5, 39}, 2, 5, 6, 0,     2, FALSE},   // Snowy -  CCM, Frappe Snowland
};

struct cmm_settings_button cmm_mode_settings_buttons[] = {
    {"Mode:", &cmm_lopt_game, cmm_gamemode_string_table, ARRAY_COUNT(cmm_gamemode_string_table), NULL, NULL},
    {"Size:", &cmm_lopt_size, cmm_levelsize_string_table, ARRAY_COUNT(cmm_levelsize_string_table), NULL, NULL},
    {"Template:", &cmm_lopt_template, cmm_template_string_table, ARRAY_COUNT(cmm_template_string_table), NULL, NULL},
};

char *cmm_tips[] = {
    "Tip: Use D-Pad ^ to flip certain tiles like slopes or slabs!",
    "Tip: Use D-Pad | to change the camera's\n   zoom level while building!",
    "Tip: You can place objects or tiles inside\n   water blocks to submerge them!",
    "Tip: The thin Iron Meshes can be used to create walls\n   that require a Vanish Cap to pass through.",
    "Tip: Mesh materials can be used as both\n   hangable ceilings and Vanish Cap walls.",
    "Tip: The maximum number of stars you can place is 63,\n   or 64 if the coin star is enabled.",
    "Tip: Objects such as coin formations or fire spinners\n   can use up the object limit rather quickly.",
    "Tip: The available items inside an Item Box will change\n   depending on the chosen gamemode.",
    "Tip: Thwomps and Grindels will use the height they are\n   placed at as the peak of their movement.",
    "Tip: The Vertical Slope tile is very useful for making\n   smooth, natural terrain!",
    "Tip: Cull Markers are very useful for lowering your\n   level's complexity!",
    "Tip: If you want to rename your level, simply rename the\n   .mb64 file itself.",
    "Tip: Entering and exiting water from the side with a shell\n   will let you transition between riding and swimming!",
    "Tip: Entering a famous code while on a certain menu\n   might reward you with a little surprise...",
    "Tip: Transparent materials such as water, flames or ice\n   can look strange when layered together, so watch out.",
    "Tip: Using the Cursed Mirror gamemode will let you use a\n   bunch of new enemies and collectible badges!",
    "Tip: Remember to use the Take Screenshot button to capture\n   a thumbnail before publishing your level!",
    "Tip: You can place some objects inside of\n   other objects as loot.",
// BTCM
    "Tip: The Double Time badge extends the timer of\n   hidden corkboxes and blue coin switches!",
    "Tip: The Star Radar badge will let the player know\n   what direction the nearest star is in.",
    "Tip: Badges that the player collects will be kept\n   as permanent collectibles even after death.",
    "Tip: You can use the Burden badges as a punishment\n   when touched, or an optional challenge!",
    "Tip: Green Coins heal the player for 4 HP when collected,\n   or fully with the Heal Plus badge.",
};
#define NUM_BTCM_TIPS 5

struct cmm_dialog_topic cmm_dialog_topics_greetings[] = {
    {"Hello",DIALOG_004},
    {"Going",DIALOG_006},
    {"Sup",DIALOG_007},
    {"Howdy",DIALOG_008},
};

struct cmm_dialog_topic cmm_dialog_topics_trouble[] = {
    {"King Bob-omb",DIALOG_000},
    {"King Whomp",DIALOG_001},
    {"Big Boo",DIALOG_016},
    {"Big Bully",DIALOG_019},
    {"Chief Chilly",DIALOG_020},
    {"Wiggler",DIALOG_021},
    {"Bowser",DIALOG_022},
};

struct cmm_dialog_topic cmm_dialog_topics_tricks[] = {
    {"Triple Jump Kick",DIALOG_002},
    {"BLJ",DIALOG_003},
    {"QSLG",DIALOG_018},
    {"Bomb Clip",DIALOG_051},
};

struct cmm_dialog_topic cmm_dialog_topics_keys[] = {
    {"Vanish Cap",DIALOG_030},
    {"Wing Cap",DIALOG_031},
    {"Metal Cap",DIALOG_032},
    {"Koopa Shell",DIALOG_033},
    {"Corkbox",DIALOG_034},
    {"Rocket Boots",DIALOG_035},
    {"Vanetal",DIALOG_036},
    {"Pipebar",DIALOG_038},
    {"B.Bill Mask",DIALOG_037},
};

struct cmm_dialog_topic cmm_dialog_topics_mystery[] = {
    {"Hmm",DIALOG_039},
    {"This",DIALOG_040},
    {"What",DIALOG_041},
    {"Peculiar",DIALOG_042},
    {"Box",DIALOG_043},
    {"Way",DIALOG_044},
};

struct cmm_dialog_topic cmm_dialog_topics_warning[] = {
    {"Pit",DIALOG_045},
    {"Lava",DIALOG_046},
    {"Quicksand",DIALOG_047},
    {"Enemies",DIALOG_048},
    {"Trolling",DIALOG_049},
    {"Void",DIALOG_050},
};

struct cmm_dialog_subject cmm_dialog_subjects[] = {
    {"Greetings",&cmm_dialog_topics_greetings, 4},
    {"Trouble",&cmm_dialog_topics_trouble, 7},
    {"Warning",&cmm_dialog_topics_warning,6},
    {"Keys",&cmm_dialog_topics_keys, 9},
    {"Mystery",&cmm_dialog_topics_mystery, 6},
    {"Tricks",&cmm_dialog_topics_tricks, 4},
};

#define NUM_DIALOG_SUBJECT_COUNT 6