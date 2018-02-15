#ifndef _KTABLE_HDR_
#define _KTABLE_HDR_
#include "KNT_defaults.h"
#define KTABLE_LEN (893)

struct knot_id {
	int k_id;  //checked by KNTarc_SETif to see if object is defined
	int Adets[2];
};
typedef struct knot_id KNTid;


#define _KNTid_DEFAULT {DONT_CARE,{DONT_CARE,DONT_CARE}}

#define K_UNCRT (-3)
#define K_UNKNWN  (-1)
#define K_UNKNWN_B  (-4)
#define K_Un (0)
#define KADT_K_Un { 1, 1}
#define K_3_1 (1)
#define KADT_K_3_1 { 3, 7}
#define K_4_1 (2)
#define KADT_K_4_1 { 5, 11}
#define K_5_1 (3)
#define KADT_K_5_1 { 5, 31}
#define K_5_2 (4)
#define KADT_K_5_2 { 7, 1}
#define K_6_1 (5)
#define KADT_K_6_1 { 9, 5}
#define K_6_2 (6)
#define KADT_K_6_2 { 11, 59}
#define K_6_3 (7)
#define KADT_K_6_3 { 13, 67}
#define K_7_1 (8)
#define KADT_K_7_1 { 7, 127}
#define K_7_2 (9)
#define KADT_K_7_2 { 11, 25}
#define K_7_3 (10)
#define KADT_K_7_3 { 13, 19}
#define K_7_4 (11)
#define KADT_K_7_4 { 15, 17}
#define K_7_5 (12)
#define KADT_K_7_5 { 17, 47}
#define K_7_6 (13)
#define KADT_K_7_6 { 19, 95}
#define K_7_7 (14)
#define KADT_K_7_7 { 21, 103}
#define K_8_1 (15)
#define KADT_K_8_1 { 13, 29}
#define K_8_2 (16)
#define KADT_K_8_2 { 17, 251}
#define K_8_3 (17)
#define KADT_K_8_3 { 17, 19}
#define K_8_4 (18)
#define KADT_K_8_4 { 19, 13}
#define K_8_5 (19)
#define KADT_K_8_5 { 21, 287}
#define K_8_6 (20)
#define KADT_K_8_6 { 23, 61}
#define K_8_7 (21)
#define KADT_K_8_7 { 23, 307}
#define K_8_8 (22)
#define KADT_K_8_8 { 25, 65}
#define K_8_9 (23)
#define KADT_K_8_9 { 25, 323}
#define K_8_10 (24)
#define KADT_K_8_10 { 27, 343}
#define K_8_11 (25)
#define KADT_K_8_11 { 27, 35}
#define K_8_12 (26)
#define KADT_K_8_12 { 29, 139}
#define K_8_13 (27)
#define KADT_K_8_13 { 29, 37}
#define K_8_14 (28)
#define KADT_K_8_14 { 31, 79}
#define K_8_15 (29)
#define KADT_K_8_15 { 33, 175}
#define K_8_16 (30)
#define KADT_K_8_16 { 35, 433}
#define K_8_17 (31)
#define KADT_K_8_17 { 37, 449}
#define K_8_18 (32)
#define KADT_K_8_18 { 45, 539}
#define K_8_19 (33)
#define KADT_K_8_19 { 3, 91}
#define K_8_20 (34)
#define KADT_K_8_20 { 9, 49}
#define K_8_21 (35)
#define KADT_K_8_21 { 15, 77}
#define K_9_1 (36)
#define KADT_K_9_1 { 9, 511}
#define K_9_2 (37)
#define KADT_K_9_2 { 15, 17}
#define K_9_3 (38)
#define KADT_K_9_3 { 19, 79}
#define K_9_4 (39)
#define KADT_K_9_4 { 21, 121}
#define K_9_5 (40)
#define KADT_K_9_5 { 23, 13}
#define K_9_6 (41)
#define KADT_K_9_6 { 27, 203}
#define K_9_7 (42)
#define KADT_K_9_7 { 29, 157}
#define K_9_8 (43)
#define KADT_K_9_8 { 31, 79}
#define K_9_9 (44)
#define KADT_K_9_9 { 31, 221}
#define K_9_10 (45)
#define KADT_K_9_10 { 33, 23}
#define K_9_11 (46)
#define KADT_K_9_11 { 33, 431}
#define K_9_12 (47)
#define KADT_K_9_12 { 35, 11}
#define K_9_13 (48)
#define KADT_K_9_13 { 37, 101}
#define K_9_14 (49)
#define KADT_K_9_14 { 37, 23}
#define K_9_15 (50)
#define KADT_K_9_15 { 39, 97}
#define K_9_16 (51)
#define KADT_K_9_16 { 39, 133}
#define K_9_17 (52)
#define KADT_K_9_17 { 39, 487}
#define K_9_18 (53)
#define KADT_K_9_18 { 41, 55}
#define K_9_19 (54)
#define KADT_K_9_19 { 41, 101}
#define K_9_20 (55)
#define KADT_K_9_20 { 41, 503}
#define K_9_21 (56)
#define KADT_K_9_21 { 43, 53}
#define K_9_22 (57)
#define KADT_K_9_22 { 43, 523}
#define K_9_23 (58)
#define KADT_K_9_23 { 45, 119}
#define K_9_24 (59)
#define KADT_K_9_24 { 45, 539}
#define K_9_25 (60)
#define KADT_K_9_25 { 47, 239}
#define K_9_26 (61)
#define KADT_K_9_26 { 47, 559}
#define K_9_27 (62)
#define KADT_K_9_27 { 49, 575}
#define K_9_28 (63)
#define KADT_K_9_28 { 51, 595}
#define K_9_29 (64)
#define KADT_K_9_29 { 51, 595}
#define K_9_30 (65)
#define KADT_K_9_30 { 53, 611}
#define K_9_31 (66)
#define KADT_K_9_31 { 55, 631}
#define K_9_32 (67)
#define KADT_K_9_32 { 59, 685}
#define K_9_33 (68)
#define KADT_K_9_33 { 61, 701}
#define K_9_34 (69)
#define KADT_K_9_34 { 69, 773}
#define K_9_35 (70)
#define KADT_K_9_35 { 27, 61}
#define K_9_36 (71)
#define KADT_K_9_36 { 37, 467}
#define K_9_37 (72)
#define KADT_K_9_37 { 45, 55}
#define K_9_38 (73)
#define KADT_K_9_38 { 57, 301}
#define K_9_39 (74)
#define KADT_K_9_39 { 55, 275}
#define K_9_40 (75)
#define KADT_K_9_40 { 75, 847}
#define K_9_41 (76)
#define KADT_K_9_41 { 49, 247}
#define K_9_42 (77)
#define KADT_K_9_42 { 7, 41}
#define K_9_43 (78)
#define KADT_K_9_43 { 13, 215}
#define K_9_44 (79)
#define KADT_K_9_44 { 17, 85}
#define K_9_45 (80)
#define KADT_K_9_45 { 23, 113}
#define K_9_46 (81)
#define KADT_K_9_46 { 9, 5}
#define K_9_47 (82)
#define KADT_K_9_47 { 27, 361}
#define K_9_48 (83)
#define KADT_K_9_48 { 27, 131}
#define K_9_49 (84)
#define KADT_K_9_49 { 25, 139}
#define K_10_1 (85)
#define KADT_K_10_1 { 17, 19}
#define K_10_2 (86)
#define KADT_K_10_2 { 23, 1019}
#define K_10_3 (87)
#define KADT_K_10_3 { 25, 7}
#define K_10_4 (88)
#define KADT_K_10_4 { 27, 149}
#define K_10_5 (89)
#define KADT_K_10_5 { 33, 1267}
#define K_10_6 (90)
#define KADT_K_10_6 { 37, 265}
#define K_10_7 (91)
#define KADT_K_10_7 { 43, 221}
#define K_10_8 (92)
#define KADT_K_10_8 { 29, 55}
#define K_10_9 (93)
#define KADT_K_10_9 { 39, 1379}
#define K_10_10 (94)
#define KADT_K_10_10 { 45, 229}
#define K_10_11 (95)
#define KADT_K_10_11 { 43, 115}
#define K_10_12 (96)
#define KADT_K_10_12 { 47, 311}
#define K_10_13 (97)
#define KADT_K_10_13 { 53, 1}
#define K_10_14 (98)
#define KADT_K_10_14 { 57, 373}
#define K_10_15 (99)
#define KADT_K_10_15 { 43, 293}
#define K_10_16 (100)
#define KADT_K_10_16 { 47, 31}
#define K_10_17 (101)
#define KADT_K_10_17 { 41, 1411}
#define K_10_18 (102)
#define KADT_K_10_18 { 55, 71}
#define K_10_19 (103)
#define KADT_K_10_19 { 51, 169}
#define K_10_20 (104)
#define KADT_K_10_20 { 35, 185}
#define K_10_21 (105)
#define KADT_K_10_21 { 45, 155}
#define K_10_22 (106)
#define KADT_K_10_22 { 49, 319}
#define K_10_23 (107)
#define KADT_K_10_23 { 59, 187}
#define K_10_24 (108)
#define KADT_K_10_24 { 55, 71}
#define K_10_25 (109)
#define KADT_K_10_25 { 65, 409}
#define K_10_26 (110)
#define KADT_K_10_26 { 61, 191}
#define K_10_27 (111)
#define KADT_K_10_27 { 71, 437}
#define K_10_28 (112)
#define KADT_K_10_28 { 53, 137}
#define K_10_29 (113)
#define KADT_K_10_29 { 63, 739}
#define K_10_30 (114)
#define KADT_K_10_30 { 67, 169}
#define K_10_31 (115)
#define KADT_K_10_31 { 57, 73}
#define K_10_32 (116)
#define KADT_K_10_32 { 69, 427}
#define K_10_33 (117)
#define KADT_K_10_33 { 65, 41}
#define K_10_34 (118)
#define KADT_K_10_34 { 37, 193}
#define K_10_35 (119)
#define KADT_K_10_35 { 49, 119}
#define K_10_36 (120)
#define KADT_K_10_36 { 51, 257}
#define K_10_37 (121)
#define KADT_K_10_37 { 53, 137}
#define K_10_38 (122)
#define KADT_K_10_38 { 59, 151}
#define K_10_39 (123)
#define KADT_K_10_39 { 61, 391}
#define K_10_40 (124)
#define KADT_K_10_40 { 75, 455}
#define K_10_41 (125)
#define KADT_K_10_41 { 71, 811}
#define K_10_42 (126)
#define KADT_K_10_42 { 81, 899}
#define K_10_43 (127)
#define KADT_K_10_43 { 73, 827}
#define K_10_44 (128)
#define KADT_K_10_44 { 79, 883}
#define K_10_45 (129)
#define KADT_K_10_45 { 89, 971}
#define K_10_46 (130)
#define KADT_K_10_46 { 31, 1199}
#define K_10_47 (131)
#define KADT_K_10_47 { 41, 1447}
#define K_10_48 (132)
#define KADT_K_10_48 { 49, 1591}
#define K_10_49 (133)
#define KADT_K_10_49 { 59, 811}
#define K_10_50 (134)
#define KADT_K_10_50 { 53, 173}
#define K_10_51 (135)
#define KADT_K_10_51 { 67, 205}
#define K_10_52 (136)
#define KADT_K_10_52 { 59, 187}
#define K_10_53 (137)
#define KADT_K_10_53 { 73, 191}
#define K_10_54 (138)
#define KADT_K_10_54 { 47, 311}
#define K_10_55 (139)
#define KADT_K_10_55 { 61, 319}
#define K_10_56 (140)
#define KADT_K_10_56 { 65, 409}
#define K_10_57 (141)
#define KADT_K_10_57 { 79, 473}
#define K_10_58 (142)
#define KADT_K_10_58 { 65, 319}
#define K_10_59 (143)
#define KADT_K_10_59 { 75, 847}
#define K_10_60 (144)
#define KADT_K_10_60 { 85, 935}
#define K_10_61 (145)
#define KADT_K_10_61 { 33, 119}
#define K_10_62 (146)
#define KADT_K_10_62 { 45, 1519}
#define K_10_63 (147)
#define KADT_K_10_63 { 57, 301}
#define K_10_64 (148)
#define KADT_K_10_64 { 51, 1631}
#define K_10_65 (149)
#define KADT_K_10_65 { 63, 49}
#define K_10_66 (150)
#define KADT_K_10_66 { 75, 973}
#define K_10_67 (151)
#define KADT_K_10_67 { 63, 5}
#define K_10_68 (152)
#define KADT_K_10_68 { 57, 73}
#define K_10_69 (153)
#define KADT_K_10_69 { 87, 955}
#define K_10_70 (154)
#define KADT_K_10_70 { 67, 775}
#define K_10_71 (155)
#define KADT_K_10_71 { 77, 863}
#define K_10_72 (156)
#define KADT_K_10_72 { 73, 227}
#define K_10_73 (157)
#define KADT_K_10_73 { 83, 919}
#define K_10_74 (158)
#define KADT_K_10_74 { 63, 5}
#define K_10_75 (159)
#define KADT_K_10_75 { 81, 899}
#define K_10_76 (160)
#define KADT_K_10_76 { 57, 91}
#define K_10_77 (161)
#define KADT_K_10_77 { 63, 49}
#define K_10_78 (162)
#define KADT_K_10_78 { 69, 791}
#define K_10_79 (163)
#define KADT_K_10_79 { 61, 1843}
#define K_10_80 (164)
#define KADT_K_10_80 { 71, 937}
#define K_10_81 (165)
#define KADT_K_10_81 { 85, 953}
#define K_10_82 (166)
#define KADT_K_10_82 { 63, 2009}
#define K_10_83 (167)
#define KADT_K_10_83 { 85, 127}
#define K_10_84 (168)
#define KADT_K_10_84 { 87, 259}
#define K_10_85 (169)
#define KADT_K_10_85 { 57, 1897}
#define K_10_86 (170)
#define KADT_K_10_86 { 83, 125}
#define K_10_87 (171)
#define KADT_K_10_87 { 81, 245}
#define K_10_88 (172)
#define KADT_K_10_88 { 101, 1097}
#define K_10_89 (173)
#define KADT_K_10_89 { 99, 1081}
#define K_10_90 (174)
#define KADT_K_10_90 { 77, 463}
#define K_10_91 (175)
#define KADT_K_10_91 { 73, 2221}
#define K_10_92 (176)
#define KADT_K_10_92 { 89, 535}
#define K_10_93 (177)
#define KADT_K_10_93 { 67, 419}
#define K_10_94 (178)
#define KADT_K_10_94 { 71, 2189}
#define K_10_95 (179)
#define KADT_K_10_95 { 91, 67}
#define K_10_96 (180)
#define KADT_K_10_96 { 93, 1007}
#define K_10_97 (181)
#define KADT_K_10_97 { 87, 437}
#define K_10_98 (182)
#define KADT_K_10_98 { 81, 245}
#define K_10_99 (183)
#define KADT_K_10_99 { 81, 2401}
#define K_10_100 (184)
#define KADT_K_10_100 { 65, 2077}
#define K_10_101 (185)
#define KADT_K_10_101 { 85, 445}
#define K_10_102 (186)
#define KADT_K_10_102 { 73, 445}
#define K_10_103 (187)
#define KADT_K_10_103 { 75, 455}
#define K_10_104 (188)
#define KADT_K_10_104 { 77, 2293}
#define K_10_105 (189)
#define KADT_K_10_105 { 91, 1009}
#define K_10_106 (190)
#define KADT_K_10_106 { 75, 2261}
#define K_10_107 (191)
#define KADT_K_10_107 { 93, 1025}
#define K_10_108 (192)
#define KADT_K_10_108 { 63, 401}
#define K_10_109 (193)
#define KADT_K_10_109 { 85, 2473}
#define K_10_110 (194)
#define KADT_K_10_110 { 83, 937}
#define K_10_111 (195)
#define KADT_K_10_111 { 77, 59}
#define K_10_112 (196)
#define KADT_K_10_112 { 87, 2639}
#define K_10_113 (197)
#define KADT_K_10_113 { 111, 161}
#define K_10_114 (198)
#define KADT_K_10_114 { 93, 553}
#define K_10_115 (199)
#define KADT_K_10_115 { 109, 1187}
#define K_10_116 (200)
#define KADT_K_10_116 { 95, 2819}
#define K_10_117 (201)
#define KADT_K_10_117 { 103, 599}
#define K_10_118 (202)
#define KADT_K_10_118 { 97, 2851}
#define K_10_119 (203)
#define KADT_K_10_119 { 101, 589}
#define K_10_120 (204)
#define KADT_K_10_120 { 105, 17}
#define K_10_121 (205)
#define KADT_K_10_121 { 115, 331}
#define K_10_122 (206)
#define KADT_K_10_122 { 105, 77}
#define K_10_123 (207)
#define KADT_K_10_123 { 121, 3481}
#define K_10_124 (208)
#define KADT_K_10_124 { 1, 331}
#define K_10_125 (209)
#define KADT_K_10_125 { 11, 181}
#define K_10_126 (210)
#define KADT_K_10_126 { 19, 253}
#define K_10_127 (211)
#define KADT_K_10_127 { 29, 377}
#define K_10_128 (212)
#define KADT_K_10_128 { 11, 61}
#define K_10_129 (213)
#define KADT_K_10_129 { 25, 65}
#define K_10_130 (214)
#define KADT_K_10_130 { 17, 47}
#define K_10_131 (215)
#define KADT_K_10_131 { 31, 79}
#define K_10_132 (216)
#define KADT_K_10_132 { 5, 31}
#define K_10_133 (217)
#define KADT_K_10_133 { 19, 95}
#define K_10_134 (218)
#define KADT_K_10_134 { 23, 185}
#define K_10_135 (219)
#define KADT_K_10_135 { 37, 193}
#define K_10_136 (220)
#define KADT_K_10_136 { 15, 77}
#define K_10_137 (221)
#define KADT_K_10_137 { 25, 121}
#define K_10_138 (222)
#define KADT_K_10_138 { 35, 451}
#define K_10_139 (223)
#define KADT_K_10_139 { -3, 259}
#define K_10_140 (224)
#define KADT_K_10_140 { 9, 49}
#define K_10_141 (225)
#define KADT_K_10_141 { 21, 287}
#define K_10_142 (226)
#define KADT_K_10_142 { 15, 35}
#define K_10_143 (227)
#define KADT_K_10_143 { 27, 343}
#define K_10_144 (228)
#define KADT_K_10_144 { 39, 203}
#define K_10_145 (229)
#define KADT_K_10_145 { -3, -5}
#define K_10_146 (230)
#define KADT_K_10_146 { 33, 83}
#define K_10_147 (231)
#define KADT_K_10_147 { 27, 35}
#define K_10_148 (232)
#define KADT_K_10_148 { 31, 379}
#define K_10_149 (233)
#define KADT_K_10_149 { 41, 503}
#define K_10_150 (234)
#define KADT_K_10_150 { 29, 377}
#define K_10_151 (235)
#define KADT_K_10_151 { 43, 505}
#define K_10_152 (236)
#define KADT_K_10_152 { -11, 79}
#define K_10_153 (237)
#define KADT_K_10_153 { -1, 55}
#define K_10_154 (238)
#define KADT_K_10_154 { -13, -71}
#define K_10_155 (239)
#define KADT_K_10_155 { 25, 323}
#define K_10_156 (240)
#define KADT_K_10_156 { 35, 433}
#define K_10_157 (241)
#define KADT_K_10_157 { 49, 593}
#define K_10_158 (242)
#define KADT_K_10_158 { 45, 521}
#define K_10_159 (243)
#define KADT_K_10_159 { 39, 469}
#define K_10_160 (244)
#define KADT_K_10_160 { 21, 305}
#define K_10_161 (245)
#define KADT_K_10_161 { -5, 1}
#define K_10_162 (246)
#define KADT_K_10_162 { 35, 185}
#define K_10_163 (247)
#define KADT_K_10_163 { 51, 595}
#define K_10_164 (248)
#define KADT_K_10_164 { 45, 229}
#define K_10_165 (249)
#define KADT_K_10_165 { 39, 97}
#define K_11a_1 (250)
#define KADT_K_11a_1 { 127, 725}
#define K_11a_2 (251)
#define KADT_K_11a_2 { 137, 1637}
#define K_11a_3 (252)
#define KADT_K_11a_3 { 115, 3215}
#define K_11a_4 (253)
#define KADT_K_11a_4 { 97, 571}
#define K_11a_5 (254)
#define KADT_K_11a_5 { 125, 1331}
#define K_11a_6 (255)
#define KADT_K_11a_6 { 135, 385}
#define K_11a_7 (256)
#define KADT_K_11a_7 { 95, 2819}
#define K_11a_8 (257)
#define KADT_K_11a_8 { 117, 335}
#define K_11a_9 (258)
#define KADT_K_11a_9 { 65, 2203}
#define K_11a_10 (259)
#define KADT_K_11a_10 { 107, 313}
#define K_11a_11 (260)
#define KADT_K_11a_11 { 113, 163}
#define K_11a_12 (261)
#define KADT_K_11a_12 { 103, 19}
#define K_11a_13 (262)
#define KADT_K_11a_13 { 61, 301}
#define K_11a_14 (263)
#define KADT_K_11a_14 { 133, 3607}
#define K_11a_15 (264)
#define KADT_K_11a_15 { 107, 3071}
#define K_11a_16 (265)
#define KADT_K_11a_16 { 105, 607}
#define K_11a_17 (266)
#define KADT_K_11a_17 { 123, 1333}
#define K_11a_18 (267)
#define KADT_K_11a_18 { 127, 1513}
#define K_11a_19 (268)
#define KADT_K_11a_19 { 155, 4205}
#define K_11a_20 (269)
#define KADT_K_11a_20 { 113, 1385}
#define K_11a_21 (270)
#define KADT_K_11a_21 { 75, 383}
#define K_11a_22 (271)
#define KADT_K_11a_22 { 101, 2959}
#define K_11a_23 (272)
#define KADT_K_11a_23 { 103, 599}
#define K_11a_24 (273)
#define KADT_K_11a_24 { 157, 4237}
#define K_11a_25 (274)
#define KADT_K_11a_25 { 155, 4205}
#define K_11a_26 (275)
#define KADT_K_11a_26 { 157, 4237}
#define K_11a_27 (276)
#define KADT_K_11a_27 { 143, 403}
#define K_11a_28 (277)
#define KADT_K_11a_28 { 121, 3481}
#define K_11a_29 (278)
#define KADT_K_11a_29 { 115, 671}
#define K_11a_30 (279)
#define KADT_K_11a_30 { 149, 13}
#define K_11a_31 (280)
#define KADT_K_11a_31 { 125, 1511}
#define K_11a_32 (281)
#define KADT_K_11a_32 { 139, 1639}
#define K_11a_33 (282)
#define KADT_K_11a_33 { 95, 2819}
#define K_11a_34 (283)
#define KADT_K_11a_34 { 119, 3323}
#define K_11a_35 (284)
#define KADT_K_11a_35 { 121, 3355}
#define K_11a_36 (285)
#define KADT_K_11a_36 { 121, 697}
#define K_11a_37 (286)
#define KADT_K_11a_37 { 93, 17}
#define K_11a_38 (287)
#define KADT_K_11a_38 { 117, 335}
#define K_11a_39 (288)
#define KADT_K_11a_39 { 101, 1259}
#define K_11a_40 (289)
#define KADT_K_11a_40 { 89, 2707}
#define K_11a_41 (290)
#define KADT_K_11a_41 { 115, 331}
#define K_11a_42 (291)
#define KADT_K_11a_42 { 107, 1171}
#define K_11a_43 (292)
#define KADT_K_11a_43 { 135, 833}
#define K_11a_44 (293)
#define KADT_K_11a_44 { 117, 3283}
#define K_11a_45 (294)
#define KADT_K_11a_45 { 87, 223}
#define K_11a_46 (295)
#define KADT_K_11a_46 { 87, 259}
#define K_11a_47 (296)
#define KADT_K_11a_47 { 117, 3283}
#define K_11a_48 (297)
#define KADT_K_11a_48 { 113, 661}
#define K_11a_49 (298)
#define KADT_K_11a_49 { 105, 1313}
#define K_11a_50 (299)
#define KADT_K_11a_50 { 83, 419}
#define K_11a_51 (300)
#define KADT_K_11a_51 { 115, 1243}
#define K_11a_52 (301)
#define KADT_K_11a_52 { 137, 389}
#define K_11a_53 (302)
#define KADT_K_11a_53 { 97, 3013}
#define K_11a_54 (303)
#define KADT_K_11a_54 { 139, 197}
#define K_11a_55 (304)
#define KADT_K_11a_55 { 71, 2315}
#define K_11a_56 (305)
#define KADT_K_11a_56 { 109, 317}
#define K_11a_57 (306)
#define KADT_K_11a_57 { 99, 2891}
#define K_11a_58 (307)
#define KADT_K_11a_58 { 81, 245}
#define K_11a_59 (308)
#define KADT_K_11a_59 { 43, 221}
#define K_11a_60 (309)
#define KADT_K_11a_60 { 85, 1115}
#define K_11a_61 (310)
#define KADT_K_11a_61 { 103, 259}
#define K_11a_62 (311)
#define KADT_K_11a_62 { 55, 1955}
#define K_11a_63 (312)
#define KADT_K_11a_63 { 93, 281}
#define K_11a_64 (313)
#define KADT_K_11a_64 { 97, 145}
#define K_11a_65 (314)
#define KADT_K_11a_65 { 59, 293}
#define K_11a_66 (315)
#define KADT_K_11a_66 { 119, 3449}
#define K_11a_67 (316)
#define KADT_K_11a_67 { 125, 715}
#define K_11a_68 (317)
#define KADT_K_11a_68 { 103, 3125}
#define K_11a_69 (318)
#define KADT_K_11a_69 { 141, 199}
#define K_11a_70 (319)
#define KADT_K_11a_70 { 151, 851}
#define K_11a_71 (320)
#define KADT_K_11a_71 { 159, 4277}
#define K_11a_72 (321)
#define KADT_K_11a_72 { 153, 4165}
#define K_11a_73 (322)
#define KADT_K_11a_73 { 177, 4795}
#define K_11a_74 (323)
#define KADT_K_11a_74 { 73, 2347}
#define K_11a_75 (324)
#define KADT_K_11a_75 { 83, 509}
#define K_11a_76 (325)
#define KADT_K_11a_76 { 145, 3985}
#define K_11a_77 (326)
#define KADT_K_11a_77 { 131, 743}
#define K_11a_78 (327)
#define KADT_K_11a_78 { 123, 707}
#define K_11a_79 (328)
#define KADT_K_11a_79 { 143, 3953}
#define K_11a_80 (329)
#define KADT_K_11a_80 { 137, 3805}
#define K_11a_81 (330)
#define KADT_K_11a_81 { 127, 3629}
#define K_11a_82 (331)
#define KADT_K_11a_82 { 95, 2819}
#define K_11a_83 (332)
#define KADT_K_11a_83 { 113, 3211}
#define K_11a_84 (333)
#define KADT_K_11a_84 { 101, 589}
#define K_11a_85 (334)
#define KADT_K_11a_85 { 107, 617}
#define K_11a_86 (335)
#define KADT_K_11a_86 { 91, 2747}
#define K_11a_87 (336)
#define KADT_K_11a_87 { 121, 43}
#define K_11a_88 (337)
#define KADT_K_11a_88 { 101, 2923}
#define K_11a_89 (338)
#define KADT_K_11a_89 { 119, 689}
#define K_11a_90 (339)
#define KADT_K_11a_90 { 87, 527}
#define K_11a_91 (340)
#define KADT_K_11a_91 { 129, 733}
#define K_11a_92 (341)
#define KADT_K_11a_92 { 103, 2963}
#define K_11a_93 (342)
#define KADT_K_11a_93 { 93, 553}
#define K_11a_94 (343)
#define KADT_K_11a_94 { 107, 689}
#define K_11a_95 (344)
#define KADT_K_11a_95 { 73, 191}
#define K_11a_96 (345)
#define KADT_K_11a_96 { 121, 1295}
#define K_11a_97 (346)
#define KADT_K_11a_97 { 71, 223}
#define K_11a_98 (347)
#define KADT_K_11a_98 { 77, 191}
#define K_11a_99 (348)
#define KADT_K_11a_99 { 135, 3809}
#define K_11a_100 (349)
#define KADT_K_11a_100 { 141, 1673}
#define K_11a_101 (350)
#define KADT_K_11a_101 { 167, 1927}
#define K_11a_102 (351)
#define KADT_K_11a_102 { 99, 295}
#define K_11a_103 (352)
#define KADT_K_11a_103 { 81, 25}
#define K_11a_104 (353)
#define KADT_K_11a_104 { 125, 715}
#define K_11a_105 (354)
#define KADT_K_11a_105 { 109, 1349}
#define K_11a_106 (355)
#define KADT_K_11a_106 { 93, 2779}
#define K_11a_107 (356)
#define KADT_K_11a_107 { 111, 161}
#define K_11a_108 (357)
#define KADT_K_11a_108 { 99, 2891}
#define K_11a_109 (358)
#define KADT_K_11a_109 { 117, 3283}
#define K_11a_110 (359)
#define KADT_K_11a_110 { 97, 571}
#define K_11a_111 (360)
#define KADT_K_11a_111 { 103, 599}
#define K_11a_112 (361)
#define KADT_K_11a_112 { 125, 3553}
#define K_11a_113 (362)
#define KADT_K_11a_113 { 109, 3265}
#define K_11a_114 (363)
#define KADT_K_11a_114 { 151, 1765}
#define K_11a_115 (364)
#define KADT_K_11a_115 { 121, 1457}
#define K_11a_116 (365)
#define KADT_K_11a_116 { 137, 1637}
#define K_11a_117 (366)
#define KADT_K_11a_117 { 117, 679}
#define K_11a_118 (367)
#define KADT_K_11a_118 { 87, 527}
#define K_11a_119 (368)
#define KADT_K_11a_119 { 77, 191}
#define K_11a_120 (369)
#define KADT_K_11a_120 { 109, 643}
#define K_11a_121 (370)
#define KADT_K_11a_121 { 119, 1279}
#define K_11a_122 (371)
#define KADT_K_11a_122 { 127, 725}
#define K_11a_123 (372)
#define KADT_K_11a_123 { 117, 607}
#define K_11a_124 (373)
#define KADT_K_11a_124 { 155, 1945}
#define K_11a_125 (374)
#define KADT_K_11a_125 { 175, 4601}
#define K_11a_126 (375)
#define KADT_K_11a_126 { 145, 3859}
#define K_11a_127 (376)
#define KADT_K_11a_127 { 137, 3841}
#define K_11a_128 (377)
#define KADT_K_11a_128 { 129, 1367}
#define K_11a_129 (378)
#define KADT_K_11a_129 { 113, 3337}
#define K_11a_130 (379)
#define KADT_K_11a_130 { 123, 707}
#define K_11a_131 (380)
#define KADT_K_11a_131 { 131, 3701}
#define K_11a_132 (381)
#define KADT_K_11a_132 { 135, 385}
#define K_11a_133 (382)
#define KADT_K_11a_133 { 79, 401}
#define K_11a_134 (383)
#define KADT_K_11a_134 { 123, 1477}
#define K_11a_135 (384)
#define KADT_K_11a_135 { 153, 425}
#define K_11a_136 (385)
#define KADT_K_11a_136 { 163, 905}
#define K_11a_137 (386)
#define KADT_K_11a_137 { 111, 653}
#define K_11a_138 (387)
#define KADT_K_11a_138 { 161, 895}
#define K_11a_139 (388)
#define KADT_K_11a_139 { 99, 2891}
#define K_11a_140 (389)
#define KADT_K_11a_140 { 65, 409}
#define K_11a_141 (390)
#define KADT_K_11a_141 { 103, 19}
#define K_11a_142 (391)
#define KADT_K_11a_142 { 59, 2027}
#define K_11a_143 (392)
#define KADT_K_11a_143 { 89, 17}
#define K_11a_144 (393)
#define KADT_K_11a_144 { 73, 463}
#define K_11a_145 (394)
#define KADT_K_11a_145 { 83, 205}
#define K_11a_146 (395)
#define KADT_K_11a_146 { 123, 3521}
#define K_11a_147 (396)
#define KADT_K_11a_147 { 151, 4097}
#define K_11a_148 (397)
#define KADT_K_11a_148 { 115, 581}
#define K_11a_149 (398)
#define KADT_K_11a_149 { 127, 725}
#define K_11a_150 (399)
#define KADT_K_11a_150 { 125, 181}
#define K_11a_151 (400)
#define KADT_K_11a_151 { 127, 3593}
#define K_11a_152 (401)
#define KADT_K_11a_152 { 117, 679}
#define K_11a_153 (402)
#define KADT_K_11a_153 { 89, 535}
#define K_11a_154 (403)
#define KADT_K_11a_154 { 67, 169}
#define K_11a_155 (404)
#define KADT_K_11a_155 { 171, 1963}
#define K_11a_156 (405)
#define KADT_K_11a_156 { 91, 2711}
#define K_11a_157 (406)
#define KADT_K_11a_157 { 135, 3773}
#define K_11a_158 (407)
#define KADT_K_11a_158 { 119, 3323}
#define K_11a_159 (408)
#define KADT_K_11a_159 { 111, 1207}
#define K_11a_160 (409)
#define KADT_K_11a_160 { 145, 3985}
#define K_11a_161 (410)
#define KADT_K_11a_161 { 57, 373}
#define K_11a_162 (411)
#define KADT_K_11a_162 { 167, 4583}
#define K_11a_163 (412)
#define KADT_K_11a_163 { 119, 3449}
#define K_11a_164 (413)
#define KADT_K_11a_164 { 169, 4615}
#define K_11a_165 (414)
#define KADT_K_11a_165 { 81, 245}
#define K_11a_166 (415)
#define KADT_K_11a_166 { 59, 151}
#define K_11a_167 (416)
#define KADT_K_11a_167 { 113, 163}
#define K_11a_168 (417)
#define KADT_K_11a_168 { 125, 715}
#define K_11a_169 (418)
#define KADT_K_11a_169 { 121, 697}
#define K_11a_170 (419)
#define KADT_K_11a_170 { 185, 4813}
#define K_11a_171 (420)
#define KADT_K_11a_171 { 183, 4907}
#define K_11a_172 (421)
#define KADT_K_11a_172 { 139, 197}
#define K_11a_173 (422)
#define KADT_K_11a_173 { 135, 761}
#define K_11a_174 (423)
#define KADT_K_11a_174 { 79, 2495}
#define K_11a_175 (424)
#define KADT_K_11a_175 { 105, 3031}
#define K_11a_176 (425)
#define KADT_K_11a_176 { 111, 3143}
#define K_11a_177 (426)
#define KADT_K_11a_177 { 97, 2887}
#define K_11a_178 (427)
#define KADT_K_11a_178 { 123, 349}
#define K_11a_179 (428)
#define KADT_K_11a_179 { 57, 2023}
#define K_11a_180 (429)
#define KADT_K_11a_180 { 89, 2671}
#define K_11a_181 (430)
#define KADT_K_11a_181 { 99, 295}
#define K_11a_182 (431)
#define KADT_K_11a_182 { 73, 2383}
#define K_11a_183 (432)
#define KADT_K_11a_183 { 115, 331}
#define K_11a_184 (433)
#define KADT_K_11a_184 { 87, 2639}
#define K_11a_185 (434)
#define KADT_K_11a_185 { 109, 317}
#define K_11a_186 (435)
#define KADT_K_11a_186 { 95, 313}
#define K_11a_187 (436)
#define KADT_K_11a_187 { 117, 335}
#define K_11a_188 (437)
#define KADT_K_11a_188 { 67, 107}
#define K_11a_189 (438)
#define KADT_K_11a_189 { 149, 4057}
#define K_11a_190 (439)
#define KADT_K_11a_190 { 85, 127}
#define K_11a_191 (440)
#define KADT_K_11a_191 { 83, 563}
#define K_11a_192 (441)
#define KADT_K_11a_192 { 97, 127}
#define K_11a_193 (442)
#define KADT_K_11a_193 { 95, 563}
#define K_11a_194 (443)
#define KADT_K_11a_194 { 93, 2779}
#define K_11a_195 (444)
#define KADT_K_11a_195 { 53, 265}
#define K_11a_196 (445)
#define KADT_K_11a_196 { 147, 4025}
#define K_11a_197 (446)
#define KADT_K_11a_197 { 143, 1675}
#define K_11a_198 (447)
#define KADT_K_11a_198 { 115, 331}
#define K_11a_199 (448)
#define KADT_K_11a_199 { 99, 295}
#define K_11a_200 (449)
#define KADT_K_11a_200 { 85, 445}
#define K_11a_201 (450)
#define KADT_K_11a_201 { 81, 25}
#define K_11a_202 (451)
#define KADT_K_11a_202 { 111, 653}
#define K_11a_203 (452)
#define KADT_K_11a_203 { 63, 2135}
#define K_11a_204 (453)
#define KADT_K_11a_204 { 101, 299}
#define K_11a_205 (454)
#define KADT_K_11a_205 { 91, 545}
#define K_11a_206 (455)
#define KADT_K_11a_206 { 47, 1775}
#define K_11a_207 (456)
#define KADT_K_11a_207 { 85, 263}
#define K_11a_208 (457)
#define KADT_K_11a_208 { 105, 625}
#define K_11a_209 (458)
#define KADT_K_11a_209 { 141, 1493}
#define K_11a_210 (459)
#define KADT_K_11a_210 { 73, 91}
#define K_11a_211 (460)
#define KADT_K_11a_211 { 67, 329}
#define K_11a_212 (461)
#define KADT_K_11a_212 { 153, 1799}
#define K_11a_213 (462)
#define KADT_K_11a_213 { 145, 1727}
#define K_11a_214 (463)
#define KADT_K_11a_214 { 69, 337}
#define K_11a_215 (464)
#define KADT_K_11a_215 { 133, 3769}
#define K_11a_216 (465)
#define KADT_K_11a_216 { 147, 4025}
#define K_11a_217 (466)
#define KADT_K_11a_217 { 139, 3845}
#define K_11a_218 (467)
#define KADT_K_11a_218 { 131, 1405}
#define K_11a_219 (468)
#define KADT_K_11a_219 { 87, 107}
#define K_11a_220 (469)
#define KADT_K_11a_220 { 85, 517}
#define K_11a_221 (470)
#define KADT_K_11a_221 { 79, 2459}
#define K_11a_222 (471)
#define KADT_K_11a_222 { 101, 299}
#define K_11a_223 (472)
#define KADT_K_11a_223 { 75, 2387}
#define K_11a_224 (473)
#define KADT_K_11a_224 { 89, 535}
#define K_11a_225 (474)
#define KADT_K_11a_225 { 53, 355}
#define K_11a_226 (475)
#define KADT_K_11a_226 { 71, 89}
#define K_11a_227 (476)
#define KADT_K_11a_227 { 143, 1819}
#define K_11a_228 (477)
#define KADT_K_11a_228 { 133, 1421}
#define K_11a_229 (478)
#define KADT_K_11a_229 { 71, 89}
#define K_11a_230 (479)
#define KADT_K_11a_230 { 51, 257}
#define K_11a_231 (480)
#define KADT_K_11a_231 { 99, 2891}
#define K_11a_232 (481)
#define KADT_K_11a_232 { 123, 3395}
#define K_11a_233 (482)
#define KADT_K_11a_233 { 173, 4561}
#define K_11a_234 (483)
#define KADT_K_11a_234 { 37, 827}
#define K_11a_235 (484)
#define KADT_K_11a_235 { 71, 125}
#define K_11a_236 (485)
#define KADT_K_11a_236 { 99, 161}
#define K_11a_237 (486)
#define KADT_K_11a_237 { 93, 245}
#define K_11a_238 (487)
#define KADT_K_11a_238 { 65, 173}
#define K_11a_239 (488)
#define KADT_K_11a_239 { 195, 5159}
#define K_11a_240 (489)
#define KADT_K_11a_240 { 61, 571}
#define K_11a_241 (490)
#define KADT_K_11a_241 { 95, 313}
#define K_11a_242 (491)
#define KADT_K_11a_242 { 47, 685}
#define K_11a_243 (492)
#define KADT_K_11a_243 { 69, 91}
#define K_11a_244 (493)
#define KADT_K_11a_244 { 147, 1855}
#define K_11a_245 (494)
#define KADT_K_11a_245 { 75, 973}
#define K_11a_246 (495)
#define KADT_K_11a_246 { 41, 55}
#define K_11a_247 (496)
#define KADT_K_11a_247 { 19, 43}
#define K_11a_248 (497)
#define KADT_K_11a_248 { 159, 4277}
#define K_11a_249 (498)
#define KADT_K_11a_249 { 117, 335}
#define K_11a_250 (499)
#define KADT_K_11a_250 { 85, 2599}
#define K_11a_251 (500)
#define KADT_K_11a_251 { 133, 3733}
#define K_11a_252 (501)
#define KADT_K_11a_252 { 131, 3701}
#define K_11a_253 (502)
#define KADT_K_11a_253 { 133, 3733}
#define K_11a_254 (503)
#define KADT_K_11a_254 { 131, 3701}
#define K_11a_255 (504)
#define KADT_K_11a_255 { 143, 3953}
#define K_11a_256 (505)
#define KADT_K_11a_256 { 133, 751}
#define K_11a_257 (506)
#define KADT_K_11a_257 { 97, 2851}
#define K_11a_258 (507)
#define KADT_K_11a_258 { 75, 29}
#define K_11a_259 (508)
#define KADT_K_11a_259 { 79, 2459}
#define K_11a_260 (509)
#define KADT_K_11a_260 { 69, 109}
#define K_11a_261 (510)
#define KADT_K_11a_261 { 129, 3661}
#define K_11a_262 (511)
#define KADT_K_11a_262 { 107, 313}
#define K_11a_263 (512)
#define KADT_K_11a_263 { 81, 1421}
#define K_11a_264 (513)
#define KADT_K_11a_264 { 135, 3773}
#define K_11a_265 (514)
#define KADT_K_11a_265 { 109, 317}
#define K_11a_266 (515)
#define KADT_K_11a_266 { 209, 5443}
#define K_11a_267 (516)
#define KADT_K_11a_267 { 191, 5087}
#define K_11a_268 (517)
#define KADT_K_11a_268 { 139, 3881}
#define K_11a_269 (518)
#define KADT_K_11a_269 { 151, 4133}
#define K_11a_270 (519)
#define KADT_K_11a_270 { 137, 769}
#define K_11a_271 (520)
#define KADT_K_11a_271 { 171, 1981}
#define K_11a_272 (521)
#define KADT_K_11a_272 { 149, 13}
#define K_11a_273 (522)
#define KADT_K_11a_273 { 159, 1855}
#define K_11a_274 (523)
#define KADT_K_11a_274 { 165, 4381}
#define K_11a_275 (524)
#define KADT_K_11a_275 { 129, 1565}
#define K_11a_276 (525)
#define KADT_K_11a_276 { 161, 1889}
#define K_11a_277 (526)
#define KADT_K_11a_277 { 135, 3809}
#define K_11a_278 (527)
#define KADT_K_11a_278 { 141, 787}
#define K_11a_279 (528)
#define KADT_K_11a_279 { 91, 1171}
#define K_11a_280 (529)
#define KADT_K_11a_280 { 105, 263}
#define K_11a_281 (530)
#define KADT_K_11a_281 { 155, 4205}
#define K_11a_282 (531)
#define KADT_K_11a_282 { 127, 3629}
#define K_11a_283 (532)
#define KADT_K_11a_283 { 147, 1729}
#define K_11a_284 (533)
#define KADT_K_11a_284 { 179, 4835}
#define K_11a_285 (534)
#define KADT_K_11a_285 { 161, 895}
#define K_11a_286 (535)
#define KADT_K_11a_286 { 147, 4025}
#define K_11a_287 (536)
#define KADT_K_11a_287 { 181, 4867}
#define K_11a_288 (537)
#define KADT_K_11a_288 { 205, 5371}
#define K_11a_289 (538)
#define KADT_K_11a_289 { 145, 3985}
#define K_11a_290 (539)
#define KADT_K_11a_290 { 141, 1673}
#define K_11a_291 (540)
#define KADT_K_11a_291 { 99, 1369}
#define K_11a_292 (541)
#define KADT_K_11a_292 { 129, 335}
#define K_11a_293 (542)
#define KADT_K_11a_293 { 81, 2563}
#define K_11a_294 (543)
#define KADT_K_11a_294 { 123, 349}
#define K_11a_295 (544)
#define KADT_K_11a_295 { 109, 1367}
#define K_11a_296 (545)
#define KADT_K_11a_296 { 111, 277}
#define K_11a_297 (546)
#define KADT_K_11a_297 { 175, 121}
#define K_11a_298 (547)
#define KADT_K_11a_298 { 131, 1693}
#define K_11a_299 (548)
#define KADT_K_11a_299 { 97, 127}
#define K_11a_300 (549)
#define KADT_K_11a_300 { 153, 4129}
#define K_11a_301 (550)
#define KADT_K_11a_301 { 199, 5231}
#define K_11a_302 (551)
#define KADT_K_11a_302 { 161, 4471}
#define K_11a_303 (552)
#define KADT_K_11a_303 { 149, 1745}
#define K_11a_304 (553)
#define KADT_K_11a_304 { 117, 1439}
#define K_11a_305 (554)
#define KADT_K_11a_305 { 135, 3773}
#define K_11a_306 (555)
#define KADT_K_11a_306 { 105, 3031}
#define K_11a_307 (556)
#define KADT_K_11a_307 { 83, 125}
#define K_11a_308 (557)
#define KADT_K_11a_308 { 71, 2279}
#define K_11a_309 (558)
#define KADT_K_11a_309 { 93, 281}
#define K_11a_310 (559)
#define KADT_K_11a_310 { 61, 25}
#define K_11a_311 (560)
#define KADT_K_11a_311 { 79, 49}
#define K_11a_312 (561)
#define KADT_K_11a_312 { 119, 1441}
#define K_11a_313 (562)
#define KADT_K_11a_313 { 77, 391}
#define K_11a_314 (563)
#define KADT_K_11a_314 { 171, 4691}
#define K_11a_315 (564)
#define KADT_K_11a_315 { 157, 4237}
#define K_11a_316 (565)
#define KADT_K_11a_316 { 121, 3355}
#define K_11a_317 (566)
#define KADT_K_11a_317 { 125, 1511}
#define K_11a_318 (567)
#define KADT_K_11a_318 { 135, 1729}
#define K_11a_319 (568)
#define KADT_K_11a_319 { 119, 1567}
#define K_11a_320 (569)
#define KADT_K_11a_320 { 109, 571}
#define K_11a_321 (570)
#define KADT_K_11a_321 { 121, 1493}
#define K_11a_322 (571)
#define KADT_K_11a_322 { 151, 421}
#define K_11a_323 (572)
#define KADT_K_11a_323 { 83, 125}
#define K_11a_324 (573)
#define KADT_K_11a_324 { 99, 491}
#define K_11a_325 (574)
#define KADT_K_11a_325 { 95, 241}
#define K_11a_326 (575)
#define KADT_K_11a_326 { 169, 4489}
#define K_11a_327 (576)
#define KADT_K_11a_327 { 187, 2125}
#define K_11a_328 (577)
#define KADT_K_11a_328 { 149, 1763}
#define K_11a_329 (578)
#define KADT_K_11a_329 { 145, 751}
#define K_11a_330 (579)
#define KADT_K_11a_330 { 89, 2707}
#define K_11a_331 (580)
#define KADT_K_11a_331 { 115, 331}
#define K_11a_332 (581)
#define KADT_K_11a_332 { 189, 5047}
#define K_11a_333 (582)
#define KADT_K_11a_333 { 65, 41}
#define K_11a_334 (583)
#define KADT_K_11a_334 { 49, 953}
#define K_11a_335 (584)
#define KADT_K_11a_335 { 75, 259}
#define K_11a_336 (585)
#define KADT_K_11a_336 { 59, 437}
#define K_11a_337 (586)
#define KADT_K_11a_337 { 89, 59}
#define K_11a_338 (587)
#define KADT_K_11a_338 { 69, 77}
#define K_11a_339 (588)
#define KADT_K_11a_339 { 55, 757}
#define K_11a_340 (589)
#define KADT_K_11a_340 { 87, 581}
#define K_11a_341 (590)
#define KADT_K_11a_341 { 61, 41}
#define K_11a_342 (591)
#define KADT_K_11a_342 { 29, 83}
#define K_11a_343 (592)
#define KADT_K_11a_343 { 31, 35}
#define K_11a_344 (593)
#define KADT_K_11a_344 { 129, 1565}
#define K_11a_345 (594)
#define KADT_K_11a_345 { 91, 455}
#define K_11a_346 (595)
#define KADT_K_11a_346 { 93, 2779}
#define K_11a_347 (596)
#define KADT_K_11a_347 { 111, 161}
#define K_11a_348 (597)
#define KADT_K_11a_348 { 145, 4147}
#define K_11a_349 (598)
#define KADT_K_11a_349 { 155, 869}
#define K_11a_350 (599)
#define KADT_K_11a_350 { 185, 4939}
#define K_11a_351 (600)
#define KADT_K_11a_351 { 165, 4543}
#define K_11a_352 (601)
#define KADT_K_11a_352 { 135, 385}
#define K_11a_353 (602)
#define KADT_K_11a_353 { 123, 1603}
#define K_11a_354 (603)
#define KADT_K_11a_354 { 105, 553}
#define K_11a_355 (604)
#define KADT_K_11a_355 { 45, 917}
#define K_11a_356 (605)
#define KADT_K_11a_356 { 79, 67}
#define K_11a_357 (606)
#define KADT_K_11a_357 { 91, 599}
#define K_11a_358 (607)
#define KADT_K_11a_358 { 31, 505}
#define K_11a_359 (608)
#define KADT_K_11a_359 { 53, 73}
#define K_11a_360 (609)
#define KADT_K_11a_360 { 57, 155}
#define K_11a_361 (610)
#define KADT_K_11a_361 { 69, 373}
#define K_11a_362 (611)
#define KADT_K_11a_362 { 39, 11}
#define K_11a_363 (612)
#define KADT_K_11a_363 { 35, 79}
#define K_11a_364 (613)
#define KADT_K_11a_364 { 25, 319}
#define K_11a_365 (614)
#define KADT_K_11a_365 { 51, 49}
#define K_11a_366 (615)
#define KADT_K_11a_366 { 81, 109}
#define K_11a_367 (616)
#define KADT_K_11a_367 { 11, 2047}
#define K_11n_1 (617)
#define KADT_K_11n_1 { 27, 131}
#define K_11n_2 (618)
#define KADT_K_11n_2 { 57, 373}
#define K_11n_3 (619)
#define KADT_K_11n_3 { 43, 221}
#define K_11n_4 (620)
#define KADT_K_11n_4 { 49, 575}
#define K_11n_5 (621)
#define KADT_K_11n_5 { 71, 811}
#define K_11n_6 (622)
#define KADT_K_11n_6 { 17, 251}
#define K_11n_7 (623)
#define KADT_K_11n_7 { 67, 757}
#define K_11n_8 (624)
#define KADT_K_11n_8 { 53, 629}
#define K_11n_9 (625)
#define KADT_K_11n_9 { -5, 443}
#define K_11n_10 (626)
#define KADT_K_11n_10 { 65, 755}
#define K_11n_11 (627)
#define KADT_K_11n_11 { 55, 631}
#define K_11n_12 (628)
#define KADT_K_11n_12 { 13, 67}
#define K_11n_13 (629)
#define KADT_K_11n_13 { 15, 839}
#define K_11n_14 (630)
#define KADT_K_11n_14 { 45, 557}
#define K_11n_15 (631)
#define KADT_K_11n_15 { 35, 433}
#define K_11n_16 (632)
#define KADT_K_11n_16 { 37, 137}
#define K_11n_17 (633)
#define KADT_K_11n_17 { 47, 115}
#define K_11n_18 (634)
#define KADT_K_11n_18 { 33, 83}
#define K_11n_19 (635)
#define KADT_K_11n_19 { 5, 125}
#define K_11n_20 (636)
#define KADT_K_11n_20 { 23, 61}
#define K_11n_21 (637)
#define KADT_K_11n_21 { 49, 575}
#define K_11n_22 (638)
#define KADT_K_11n_22 { 55, 631}
#define K_11n_23 (639)
#define KADT_K_11n_23 { 29, 1195}
#define K_11n_24 (640)
#define KADT_K_11n_24 { 23, 307}
#define K_11n_25 (641)
#define KADT_K_11n_25 { 47, 559}
#define K_11n_26 (642)
#define KADT_K_11n_26 { 41, 503}
#define K_11n_27 (643)
#define KADT_K_11n_27 { 19, 947}
#define K_11n_28 (644)
#define KADT_K_11n_28 { 21, 103}
#define K_11n_29 (645)
#define KADT_K_11n_29 { 51, 257}
#define K_11n_30 (646)
#define KADT_K_11n_30 { 33, 247}
#define K_11n_31 (647)
#define KADT_K_11n_31 { -3, 53}
#define K_11n_32 (648)
#define KADT_K_11n_32 { 69, 773}
#define K_11n_33 (649)
#define KADT_K_11n_33 { 51, 613}
#define K_11n_34 (650)
#define KADT_K_11n_34 { 1, 1}
#define K_11n_35 (651)
#define KADT_K_11n_35 { 89, 535}
#define K_11n_36 (652)
#define KADT_K_11n_36 { 67, 2081}
#define K_11n_37 (653)
#define KADT_K_11n_37 { 25, 323}
#define K_11n_38 (654)
#define KADT_K_11n_38 { 3, 23}
#define K_11n_39 (655)
#define KADT_K_11n_39 { 25, 65}
#define K_11n_40 (656)
#define KADT_K_11n_40 { 79, 473}
#define K_11n_41 (657)
#define KADT_K_11n_41 { 53, 1825}
#define K_11n_42 (658)
#define KADT_K_11n_42 { 1, 1}
#define K_11n_43 (659)
#define KADT_K_11n_43 { 89, 535}
#define K_11n_44 (660)
#define KADT_K_11n_44 { 67, 2081}
#define K_11n_45 (661)
#define KADT_K_11n_45 { 25, 65}
#define K_11n_46 (662)
#define KADT_K_11n_46 { 79, 473}
#define K_11n_47 (663)
#define KADT_K_11n_47 { 53, 1825}
#define K_11n_48 (664)
#define KADT_K_11n_48 { 29, 359}
#define K_11n_49 (665)
#define KADT_K_11n_49 { -1, 5}
#define K_11n_50 (666)
#define KADT_K_11n_50 { 25, 65}
#define K_11n_51 (667)
#define KADT_K_11n_51 { 29, 377}
#define K_11n_52 (668)
#define KADT_K_11n_52 { 59, 685}
#define K_11n_53 (669)
#define KADT_K_11n_53 { 37, 449}
#define K_11n_54 (670)
#define KADT_K_11n_54 { 43, 505}
#define K_11n_55 (671)
#define KADT_K_11n_55 { 61, 701}
#define K_11n_56 (672)
#define KADT_K_11n_56 { 35, 433}
#define K_11n_57 (673)
#define KADT_K_11n_57 { 7, 695}
#define K_11n_58 (674)
#define KADT_K_11n_58 { 35, 433}
#define K_11n_59 (675)
#define KADT_K_11n_59 { 53, 629}
#define K_11n_60 (676)
#define KADT_K_11n_60 { 31, 1199}
#define K_11n_61 (677)
#define KADT_K_11n_61 { 17, 943}
#define K_11n_62 (678)
#define KADT_K_11n_62 { 33, 83}
#define K_11n_63 (679)
#define KADT_K_11n_63 { 39, 97}
#define K_11n_64 (680)
#define KADT_K_11n_64 { 21, 23}
#define K_11n_65 (681)
#define KADT_K_11n_65 { 33, 175}
#define K_11n_66 (682)
#define KADT_K_11n_66 { 75, 847}
#define K_11n_67 (683)
#define KADT_K_11n_67 { 9, 5}
#define K_11n_68 (684)
#define KADT_K_11n_68 { 63, 5}
#define K_11n_69 (685)
#define KADT_K_11n_69 { 45, 155}
#define K_11n_70 (686)
#define KADT_K_11n_70 { 13, 197}
#define K_11n_71 (687)
#define KADT_K_11n_71 { 63, 49}
#define K_11n_72 (688)
#define KADT_K_11n_72 { 81, 245}
#define K_11n_73 (689)
#define KADT_K_11n_73 { 9, 49}
#define K_11n_74 (690)
#define KADT_K_11n_74 { 9, 49}
#define K_11n_75 (691)
#define KADT_K_11n_75 { 63, 49}
#define K_11n_76 (692)
#define KADT_K_11n_76 { 45, 1519}
#define K_11n_77 (693)
#define KADT_K_11n_77 { -27, -245}
#define K_11n_78 (694)
#define KADT_K_11n_78 { 45, 1519}
#define K_11n_79 (695)
#define KADT_K_11n_79 { 15, 43}
#define K_11n_80 (696)
#define KADT_K_11n_80 { -15, -73}
#define K_11n_81 (697)
#define KADT_K_11n_81 { 27, 1127}
#define K_11n_82 (698)
#define KADT_K_11n_82 { 19, 271}
#define K_11n_83 (699)
#define KADT_K_11n_83 { 49, 247}
#define K_11n_84 (700)
#define KADT_K_11n_84 { 35, 11}
#define K_11n_85 (701)
#define KADT_K_11n_85 { 45, 539}
#define K_11n_86 (702)
#define KADT_K_11n_86 { 33, 413}
#define K_11n_87 (703)
#define KADT_K_11n_87 { 51, 595}
#define K_11n_88 (704)
#define KADT_K_11n_88 { 11, 767}
#define K_11n_89 (705)
#define KADT_K_11n_89 { 61, 719}
#define K_11n_90 (706)
#define KADT_K_11n_90 { 41, 73}
#define K_11n_91 (707)
#define KADT_K_11n_91 { 31, 149}
#define K_11n_92 (708)
#define KADT_K_11n_92 { 15, 235}
#define K_11n_93 (709)
#define KADT_K_11n_93 { 47, 685}
#define K_11n_94 (710)
#define KADT_K_11n_94 { 57, 665}
#define K_11n_95 (711)
#define KADT_K_11n_95 { 33, 431}
#define K_11n_96 (712)
#define KADT_K_11n_96 { 7, 145}
#define K_11n_97 (713)
#define KADT_K_11n_97 { 9, 5}
#define K_11n_98 (714)
#define KADT_K_11n_98 { 69, 791}
#define K_11n_99 (715)
#define KADT_K_11n_99 { 39, 203}
#define K_11n_100 (716)
#define KADT_K_11n_100 { 45, 55}
#define K_11n_101 (717)
#define KADT_K_11n_101 { 39, 97}
#define K_11n_102 (718)
#define KADT_K_11n_102 { 3, 23}
#define K_11n_103 (719)
#define KADT_K_11n_103 { 65, 755}
#define K_11n_104 (720)
#define KADT_K_11n_104 { 3, 623}
#define K_11n_105 (721)
#define KADT_K_11n_105 { 69, 791}
#define K_11n_106 (722)
#define KADT_K_11n_106 { 27, 343}
#define K_11n_107 (723)
#define KADT_K_11n_107 { 21, 1015}
#define K_11n_108 (724)
#define KADT_K_11n_108 { 73, 845}
#define K_11n_109 (725)
#define KADT_K_11n_109 { 57, 683}
#define K_11n_110 (726)
#define KADT_K_11n_110 { 41, 485}
#define K_11n_111 (727)
#define KADT_K_11n_111 { -7, -1}
#define K_11n_112 (728)
#define KADT_K_11n_112 { 55, 631}
#define K_11n_113 (729)
#define KADT_K_11n_113 { 35, 167}
#define K_11n_114 (730)
#define KADT_K_11n_114 { 53, 265}
#define K_11n_115 (731)
#define KADT_K_11n_115 { 77, 845}
#define K_11n_116 (732)
#define KADT_K_11n_116 { -1, 5}
#define K_11n_117 (733)
#define KADT_K_11n_117 { 35, 185}
#define K_11n_118 (734)
#define KADT_K_11n_118 { 21, 305}
#define K_11n_119 (735)
#define KADT_K_11n_119 { 69, 773}
#define K_11n_120 (736)
#define KADT_K_11n_120 { 47, 1685}
#define K_11n_121 (737)
#define KADT_K_11n_121 { 45, 557}
#define K_11n_122 (738)
#define KADT_K_11n_122 { 27, 35}
#define K_11n_123 (739)
#define KADT_K_11n_123 { 57, 283}
#define K_11n_124 (740)
#define KADT_K_11n_124 { 59, 685}
#define K_11n_125 (741)
#define KADT_K_11n_125 { 63, 721}
#define K_11n_126 (742)
#define KADT_K_11n_126 { 27, 487}
#define K_11n_127 (743)
#define KADT_K_11n_127 { 55, 631}
#define K_11n_128 (744)
#define KADT_K_11n_128 { 43, 523}
#define K_11n_129 (745)
#define KADT_K_11n_129 { 43, 505}
#define K_11n_130 (746)
#define KADT_K_11n_130 { 53, 611}
#define K_11n_131 (747)
#define KADT_K_11n_131 { 67, 757}
#define K_11n_132 (748)
#define KADT_K_11n_132 { 25, 65}
#define K_11n_133 (749)
#define KADT_K_11n_133 { 25, 1249}
#define K_11n_134 (750)
#define KADT_K_11n_134 { 47, 239}
#define K_11n_135 (751)
#define KADT_K_11n_135 { 5, 125}
#define K_11n_136 (752)
#define KADT_K_11n_136 { 63, 847}
#define K_11n_137 (753)
#define KADT_K_11n_137 { 57, 683}
#define K_11n_138 (754)
#define KADT_K_11n_138 { 15, 43}
#define K_11n_139 (755)
#define KADT_K_11n_139 { 9, 5}
#define K_11n_140 (756)
#define KADT_K_11n_140 { 51, 31}
#define K_11n_141 (757)
#define KADT_K_11n_141 { 21, 47}
#define K_11n_142 (758)
#define KADT_K_11n_142 { 33, 157}
#define K_11n_143 (759)
#define KADT_K_11n_143 { 9, 161}
#define K_11n_144 (760)
#define KADT_K_11n_144 { 65, 755}
#define K_11n_145 (761)
#define KADT_K_11n_145 { -9, -17}
#define K_11n_146 (762)
#define KADT_K_11n_146 { 63, 703}
#define K_11n_147 (763)
#define KADT_K_11n_147 { 37, 1501}
#define K_11n_148 (764)
#define KADT_K_11n_148 { 75, 2387}
#define K_11n_149 (765)
#define KADT_K_11n_149 { 33, 1393}
#define K_11n_150 (766)
#define KADT_K_11n_150 { 75, 29}
#define K_11n_151 (767)
#define KADT_K_11n_151 { 23, 61}
#define K_11n_152 (768)
#define KADT_K_11n_152 { 23, 61}
#define K_11n_153 (769)
#define KADT_K_11n_153 { 57, 1861}
#define K_11n_154 (770)
#define KADT_K_11n_154 { 79, 883}
#define K_11n_155 (771)
#define KADT_K_11n_155 { 51, 347}
#define K_11n_156 (772)
#define KADT_K_11n_156 { 77, 863}
#define K_11n_157 (773)
#define KADT_K_11n_157 { 65, 737}
#define K_11n_158 (774)
#define KADT_K_11n_158 { 45, 1645}
#define K_11n_159 (775)
#define KADT_K_11n_159 { 71, 793}
#define K_11n_160 (776)
#define KADT_K_11n_160 { 67, 757}
#define K_11n_161 (777)
#define KADT_K_11n_161 { 63, 401}
#define K_11n_162 (778)
#define KADT_K_11n_162 { 55, 275}
#define K_11n_163 (779)
#define KADT_K_11n_163 { 91, 1009}
#define K_11n_164 (780)
#define KADT_K_11n_164 { 45, 539}
#define K_11n_165 (781)
#define KADT_K_11n_165 { 85, 935}
#define K_11n_166 (782)
#define KADT_K_11n_166 { 59, 1937}
#define K_11n_167 (783)
#define KADT_K_11n_167 { 63, 703}
#define K_11n_168 (784)
#define KADT_K_11n_168 { 75, 829}
#define K_11n_169 (785)
#define KADT_K_11n_169 { 35, 559}
#define K_11n_170 (786)
#define KADT_K_11n_170 { 63, 311}
#define K_11n_171 (787)
#define KADT_K_11n_171 { 65, 173}
#define K_11n_172 (788)
#define KADT_K_11n_172 { 49, 575}
#define K_11n_173 (789)
#define KADT_K_11n_173 { 45, 1681}
#define K_11n_174 (790)
#define KADT_K_11n_174 { 97, 145}
#define K_11n_175 (791)
#define KADT_K_11n_175 { 65, 209}
#define K_11n_176 (792)
#define KADT_K_11n_176 { 63, 721}
#define K_11n_177 (793)
#define KADT_K_11n_177 { 83, 2567}
#define K_11n_178 (794)
#define KADT_K_11n_178 { 95, 277}
#define K_11n_179 (795)
#define KADT_K_11n_179 { 77, 863}
#define K_11n_180 (796)
#define KADT_K_11n_180 { 55, 757}
#define K_11n_181 (797)
#define KADT_K_11n_181 { 45, 247}
#define K_11n_182 (798)
#define KADT_K_11n_182 { 93, 2743}
#define K_11n_183 (799)
#define KADT_K_11n_183 { -21, -161}
#define K_11n_184 (800)
#define KADT_K_11n_184 { 87, 259}
#define K_11n_185 (801)
#define KADT_K_11n_185 { 105, 77}
#define K_3_1X3_1 (802)
#define KADT_K_3_1X3_1 { 9, 49}
#define K_3_1X4_1 (803)
#define KADT_K_3_1X4_1 { 15, 77}
#define K_3_1X5_1 (804)
#define KADT_K_3_1X5_1 { 15, 217}
#define K_3_1X5_2 (805)
#define KADT_K_3_1X5_2 { 21, 7}
#define K_3_1X6_1 (806)
#define KADT_K_3_1X6_1 { 27, 35}
#define K_3_1X6_2 (807)
#define KADT_K_3_1X6_2 { 33, 413}
#define K_3_1X6_3 (808)
#define KADT_K_3_1X6_3 { 39, 469}
#define K_3_1X7_1 (809)
#define KADT_K_3_1X7_1 { 21, 889}
#define K_3_1X7_2 (810)
#define KADT_K_3_1X7_2 { 33, 175}
#define K_3_1X7_3 (811)
#define KADT_K_3_1X7_3 { 39, 133}
#define K_3_1X7_4 (812)
#define KADT_K_3_1X7_4 { 45, 119}
#define K_3_1X7_5 (813)
#define KADT_K_3_1X7_5 { 51, 329}
#define K_3_1X7_6 (814)
#define KADT_K_3_1X7_6 { 57, 665}
#define K_4_1X4_1 (815)
#define KADT_K_4_1X4_1 { 25, 121}
#define K_4_1X5_1 (816)
#define KADT_K_4_1X5_1 { 25, 341}
#define K_4_1X5_2 (817)
#define KADT_K_4_1X5_2 { 35, 11}
#define K_4_1X6_1 (818)
#define KADT_K_4_1X6_1 { 45, 55}
#define K_4_1X6_2 (819)
#define KADT_K_4_1X6_2 { 55, 649}
#define K_4_1X6_3 (820)
#define KADT_K_4_1X6_3 { 65, 737}
#define K_4_1X7_1 (821)
#define KADT_K_4_1X7_1 { 35, 1397}
#define K_4_1X7_2 (822)
#define KADT_K_4_1X7_2 { 55, 275}
#define K_4_1X7_3 (823)
#define KADT_K_4_1X7_3 { 65, 209}
#define K_4_1X7_4 (824)
#define KADT_K_4_1X7_4 { 75, 187}
#define K_4_1X7_5 (825)
#define KADT_K_4_1X7_5 { 85, 517}
#define K_4_1X7_6 (826)
#define KADT_K_4_1X7_6 { 95, 1045}
#define K_5_1X5_1 (827)
#define KADT_K_5_1X5_1 { 25, 961}
#define K_5_1X5_2 (828)
#define KADT_K_5_1X5_2 { 35, 31}
#define K_5_1X6_1 (829)
#define KADT_K_5_1X6_1 { 45, 155}
#define K_5_1X6_2 (830)
#define KADT_K_5_1X6_2 { 55, 1829}
#define K_5_1X6_3 (831)
#define KADT_K_5_1X6_3 { 65, 2077}
#define K_5_1X7_1 (832)
#define KADT_K_5_1X7_1 { 35, 3937}
#define K_5_1X7_2 (833)
#define KADT_K_5_1X7_2 { 55, 775}
#define K_5_1X7_3 (834)
#define KADT_K_5_1X7_3 { 65, 589}
#define K_5_1X7_4 (835)
#define KADT_K_5_1X7_4 { 75, 527}
#define K_5_1X7_5 (836)
#define KADT_K_5_1X7_5 { 85, 1457}
#define K_5_1X7_6 (837)
#define KADT_K_5_1X7_6 { 95, 2945}
#define K_5_2X5_2 (838)
#define KADT_K_5_2X5_2 { 49, 1}
#define K_5_2X6_1 (839)
#define KADT_K_5_2X6_1 { 63, 5}
#define K_5_2X6_2 (840)
#define KADT_K_5_2X6_2 { 77, 59}
#define K_5_2X6_3 (841)
#define KADT_K_5_2X6_3 { 91, 67}
#define K_5_2X7_1 (842)
#define KADT_K_5_2X7_1 { 49, 127}
#define K_5_2X7_2 (843)
#define KADT_K_5_2X7_2 { 77, 25}
#define K_5_2X7_3 (844)
#define KADT_K_5_2X7_3 { 91, 19}
#define K_5_2X7_4 (845)
#define KADT_K_5_2X7_4 { 105, 17}
#define K_5_2X7_5 (846)
#define KADT_K_5_2X7_5 { 119, 47}
#define K_5_2X7_6 (847)
#define KADT_K_5_2X7_6 { 133, 95}
#define K_6_1X6_1 (848)
#define KADT_K_6_1X6_1 { 81, 25}
#define K_6_1X6_2 (849)
#define KADT_K_6_1X6_2 { 99, 295}
#define K_6_1X6_3 (850)
#define KADT_K_6_1X6_3 { 117, 335}
#define K_6_1X7_1 (851)
#define KADT_K_6_1X7_1 { 63, 635}
#define K_6_1X7_2 (852)
#define KADT_K_6_1X7_2 { 99, 125}
#define K_6_1X7_3 (853)
#define KADT_K_6_1X7_3 { 117, 95}
#define K_6_1X7_4 (854)
#define KADT_K_6_1X7_4 { 135, 85}
#define K_6_1X7_5 (855)
#define KADT_K_6_1X7_5 { 153, 235}
#define K_6_1X7_6 (856)
#define KADT_K_6_1X7_6 { 171, 475}
#define K_6_2X6_2 (857)
#define KADT_K_6_2X6_2 { 121, 3481}
#define K_6_2X6_3 (858)
#define KADT_K_6_2X6_3 { 143, 3953}
#define K_6_2X7_1 (859)
#define KADT_K_6_2X7_1 { 77, 7493}
#define K_6_2X7_2 (860)
#define KADT_K_6_2X7_2 { 121, 1475}
#define K_6_2X7_3 (861)
#define KADT_K_6_2X7_3 { 143, 1121}
#define K_6_2X7_4 (862)
#define KADT_K_6_2X7_4 { 165, 1003}
#define K_6_2X7_5 (863)
#define KADT_K_6_2X7_5 { 187, 2773}
#define K_6_2X7_6 (864)
#define KADT_K_6_2X7_6 { 209, 5605}
#define K_6_3X6_3 (865)
#define KADT_K_6_3X6_3 { 169, 4489}
#define K_6_3X7_1 (866)
#define KADT_K_6_3X7_1 { 91, 8509}
#define K_6_3X7_2 (867)
#define KADT_K_6_3X7_2 { 143, 1675}
#define K_6_3X7_3 (868)
#define KADT_K_6_3X7_3 { 169, 1273}
#define K_6_3X7_4 (869)
#define KADT_K_6_3X7_4 { 195, 1139}
#define K_6_3X7_5 (870)
#define KADT_K_6_3X7_5 { 221, 3149}
#define K_6_3X7_6 (871)
#define KADT_K_6_3X7_6 { 247, 6365}
#define K_7_1X7_1 (872)
#define KADT_K_7_1X7_1 { 49, 16129}
#define K_7_1X7_2 (873)
#define KADT_K_7_1X7_2 { 77, 3175}
#define K_7_1X7_3 (874)
#define KADT_K_7_1X7_3 { 91, 2413}
#define K_7_1X7_4 (875)
#define KADT_K_7_1X7_4 { 105, 2159}
#define K_7_1X7_5 (876)
#define KADT_K_7_1X7_5 { 119, 5969}
#define K_7_1X7_6 (877)
#define KADT_K_7_1X7_6 { 133, 12065}
#define K_7_2X7_2 (878)
#define KADT_K_7_2X7_2 { 121, 625}
#define K_7_2X7_3 (879)
#define KADT_K_7_2X7_3 { 143, 475}
#define K_7_2X7_4 (880)
#define KADT_K_7_2X7_4 { 165, 425}
#define K_7_2X7_5 (881)
#define KADT_K_7_2X7_5 { 187, 1175}
#define K_7_2X7_6 (882)
#define KADT_K_7_2X7_6 { 209, 2375}
#define K_7_3X7_3 (883)
#define KADT_K_7_3X7_3 { 169, 361}
#define K_7_3X7_4 (884)
#define KADT_K_7_3X7_4 { 195, 323}
#define K_7_3X7_5 (885)
#define KADT_K_7_3X7_5 { 221, 893}
#define K_7_3X7_6 (886)
#define KADT_K_7_3X7_6 { 247, 1805}
#define K_7_4X7_4 (887)
#define KADT_K_7_4X7_4 { 225, 289}
#define K_7_4X7_5 (888)
#define KADT_K_7_4X7_5 { 255, 799}
#define K_7_4X7_6 (889)
#define KADT_K_7_4X7_6 { 285, 1615}
#define K_7_5X7_5 (890)
#define KADT_K_7_5X7_5 { 289, 2209}
#define K_7_5X7_6 (891)
#define KADT_K_7_5X7_6 { 323, 4465}
#define K_7_6X7_6 (892)
#define KADT_K_7_6X7_6 { 361, 9025}

#define KTABLE {\
K_Un,\
K_3_1,\
K_4_1,\
K_5_1,\
K_5_2,\
K_6_1,\
K_6_2,\
K_6_3,\
K_7_1,\
K_7_2,\
K_7_3,\
K_7_4,\
K_7_5,\
K_7_6,\
K_7_7,\
K_8_1,\
K_8_2,\
K_8_3,\
K_8_4,\
K_8_5,\
K_8_6,\
K_8_7,\
K_8_8,\
K_8_9,\
K_8_10,\
K_8_11,\
K_8_12,\
K_8_13,\
K_8_14,\
K_8_15,\
K_8_16,\
K_8_17,\
K_8_18,\
K_8_19,\
K_8_20,\
K_8_21,\
K_9_1,\
K_9_2,\
K_9_3,\
K_9_4,\
K_9_5,\
K_9_6,\
K_9_7,\
K_9_8,\
K_9_9,\
K_9_10,\
K_9_11,\
K_9_12,\
K_9_13,\
K_9_14,\
K_9_15,\
K_9_16,\
K_9_17,\
K_9_18,\
K_9_19,\
K_9_20,\
K_9_21,\
K_9_22,\
K_9_23,\
K_9_24,\
K_9_25,\
K_9_26,\
K_9_27,\
K_9_28,\
K_9_29,\
K_9_30,\
K_9_31,\
K_9_32,\
K_9_33,\
K_9_34,\
K_9_35,\
K_9_36,\
K_9_37,\
K_9_38,\
K_9_39,\
K_9_40,\
K_9_41,\
K_9_42,\
K_9_43,\
K_9_44,\
K_9_45,\
K_9_46,\
K_9_47,\
K_9_48,\
K_9_49,\
K_10_1,\
K_10_2,\
K_10_3,\
K_10_4,\
K_10_5,\
K_10_6,\
K_10_7,\
K_10_8,\
K_10_9,\
K_10_10,\
K_10_11,\
K_10_12,\
K_10_13,\
K_10_14,\
K_10_15,\
K_10_16,\
K_10_17,\
K_10_18,\
K_10_19,\
K_10_20,\
K_10_21,\
K_10_22,\
K_10_23,\
K_10_24,\
K_10_25,\
K_10_26,\
K_10_27,\
K_10_28,\
K_10_29,\
K_10_30,\
K_10_31,\
K_10_32,\
K_10_33,\
K_10_34,\
K_10_35,\
K_10_36,\
K_10_37,\
K_10_38,\
K_10_39,\
K_10_40,\
K_10_41,\
K_10_42,\
K_10_43,\
K_10_44,\
K_10_45,\
K_10_46,\
K_10_47,\
K_10_48,\
K_10_49,\
K_10_50,\
K_10_51,\
K_10_52,\
K_10_53,\
K_10_54,\
K_10_55,\
K_10_56,\
K_10_57,\
K_10_58,\
K_10_59,\
K_10_60,\
K_10_61,\
K_10_62,\
K_10_63,\
K_10_64,\
K_10_65,\
K_10_66,\
K_10_67,\
K_10_68,\
K_10_69,\
K_10_70,\
K_10_71,\
K_10_72,\
K_10_73,\
K_10_74,\
K_10_75,\
K_10_76,\
K_10_77,\
K_10_78,\
K_10_79,\
K_10_80,\
K_10_81,\
K_10_82,\
K_10_83,\
K_10_84,\
K_10_85,\
K_10_86,\
K_10_87,\
K_10_88,\
K_10_89,\
K_10_90,\
K_10_91,\
K_10_92,\
K_10_93,\
K_10_94,\
K_10_95,\
K_10_96,\
K_10_97,\
K_10_98,\
K_10_99,\
K_10_100,\
K_10_101,\
K_10_102,\
K_10_103,\
K_10_104,\
K_10_105,\
K_10_106,\
K_10_107,\
K_10_108,\
K_10_109,\
K_10_110,\
K_10_111,\
K_10_112,\
K_10_113,\
K_10_114,\
K_10_115,\
K_10_116,\
K_10_117,\
K_10_118,\
K_10_119,\
K_10_120,\
K_10_121,\
K_10_122,\
K_10_123,\
K_10_124,\
K_10_125,\
K_10_126,\
K_10_127,\
K_10_128,\
K_10_129,\
K_10_130,\
K_10_131,\
K_10_132,\
K_10_133,\
K_10_134,\
K_10_135,\
K_10_136,\
K_10_137,\
K_10_138,\
K_10_139,\
K_10_140,\
K_10_141,\
K_10_142,\
K_10_143,\
K_10_144,\
K_10_145,\
K_10_146,\
K_10_147,\
K_10_148,\
K_10_149,\
K_10_150,\
K_10_151,\
K_10_152,\
K_10_153,\
K_10_154,\
K_10_155,\
K_10_156,\
K_10_157,\
K_10_158,\
K_10_159,\
K_10_160,\
K_10_161,\
K_10_162,\
K_10_163,\
K_10_164,\
K_10_165,\
K_11a_1,\
K_11a_2,\
K_11a_3,\
K_11a_4,\
K_11a_5,\
K_11a_6,\
K_11a_7,\
K_11a_8,\
K_11a_9,\
K_11a_10,\
K_11a_11,\
K_11a_12,\
K_11a_13,\
K_11a_14,\
K_11a_15,\
K_11a_16,\
K_11a_17,\
K_11a_18,\
K_11a_19,\
K_11a_20,\
K_11a_21,\
K_11a_22,\
K_11a_23,\
K_11a_24,\
K_11a_25,\
K_11a_26,\
K_11a_27,\
K_11a_28,\
K_11a_29,\
K_11a_30,\
K_11a_31,\
K_11a_32,\
K_11a_33,\
K_11a_34,\
K_11a_35,\
K_11a_36,\
K_11a_37,\
K_11a_38,\
K_11a_39,\
K_11a_40,\
K_11a_41,\
K_11a_42,\
K_11a_43,\
K_11a_44,\
K_11a_45,\
K_11a_46,\
K_11a_47,\
K_11a_48,\
K_11a_49,\
K_11a_50,\
K_11a_51,\
K_11a_52,\
K_11a_53,\
K_11a_54,\
K_11a_55,\
K_11a_56,\
K_11a_57,\
K_11a_58,\
K_11a_59,\
K_11a_60,\
K_11a_61,\
K_11a_62,\
K_11a_63,\
K_11a_64,\
K_11a_65,\
K_11a_66,\
K_11a_67,\
K_11a_68,\
K_11a_69,\
K_11a_70,\
K_11a_71,\
K_11a_72,\
K_11a_73,\
K_11a_74,\
K_11a_75,\
K_11a_76,\
K_11a_77,\
K_11a_78,\
K_11a_79,\
K_11a_80,\
K_11a_81,\
K_11a_82,\
K_11a_83,\
K_11a_84,\
K_11a_85,\
K_11a_86,\
K_11a_87,\
K_11a_88,\
K_11a_89,\
K_11a_90,\
K_11a_91,\
K_11a_92,\
K_11a_93,\
K_11a_94,\
K_11a_95,\
K_11a_96,\
K_11a_97,\
K_11a_98,\
K_11a_99,\
K_11a_100,\
K_11a_101,\
K_11a_102,\
K_11a_103,\
K_11a_104,\
K_11a_105,\
K_11a_106,\
K_11a_107,\
K_11a_108,\
K_11a_109,\
K_11a_110,\
K_11a_111,\
K_11a_112,\
K_11a_113,\
K_11a_114,\
K_11a_115,\
K_11a_116,\
K_11a_117,\
K_11a_118,\
K_11a_119,\
K_11a_120,\
K_11a_121,\
K_11a_122,\
K_11a_123,\
K_11a_124,\
K_11a_125,\
K_11a_126,\
K_11a_127,\
K_11a_128,\
K_11a_129,\
K_11a_130,\
K_11a_131,\
K_11a_132,\
K_11a_133,\
K_11a_134,\
K_11a_135,\
K_11a_136,\
K_11a_137,\
K_11a_138,\
K_11a_139,\
K_11a_140,\
K_11a_141,\
K_11a_142,\
K_11a_143,\
K_11a_144,\
K_11a_145,\
K_11a_146,\
K_11a_147,\
K_11a_148,\
K_11a_149,\
K_11a_150,\
K_11a_151,\
K_11a_152,\
K_11a_153,\
K_11a_154,\
K_11a_155,\
K_11a_156,\
K_11a_157,\
K_11a_158,\
K_11a_159,\
K_11a_160,\
K_11a_161,\
K_11a_162,\
K_11a_163,\
K_11a_164,\
K_11a_165,\
K_11a_166,\
K_11a_167,\
K_11a_168,\
K_11a_169,\
K_11a_170,\
K_11a_171,\
K_11a_172,\
K_11a_173,\
K_11a_174,\
K_11a_175,\
K_11a_176,\
K_11a_177,\
K_11a_178,\
K_11a_179,\
K_11a_180,\
K_11a_181,\
K_11a_182,\
K_11a_183,\
K_11a_184,\
K_11a_185,\
K_11a_186,\
K_11a_187,\
K_11a_188,\
K_11a_189,\
K_11a_190,\
K_11a_191,\
K_11a_192,\
K_11a_193,\
K_11a_194,\
K_11a_195,\
K_11a_196,\
K_11a_197,\
K_11a_198,\
K_11a_199,\
K_11a_200,\
K_11a_201,\
K_11a_202,\
K_11a_203,\
K_11a_204,\
K_11a_205,\
K_11a_206,\
K_11a_207,\
K_11a_208,\
K_11a_209,\
K_11a_210,\
K_11a_211,\
K_11a_212,\
K_11a_213,\
K_11a_214,\
K_11a_215,\
K_11a_216,\
K_11a_217,\
K_11a_218,\
K_11a_219,\
K_11a_220,\
K_11a_221,\
K_11a_222,\
K_11a_223,\
K_11a_224,\
K_11a_225,\
K_11a_226,\
K_11a_227,\
K_11a_228,\
K_11a_229,\
K_11a_230,\
K_11a_231,\
K_11a_232,\
K_11a_233,\
K_11a_234,\
K_11a_235,\
K_11a_236,\
K_11a_237,\
K_11a_238,\
K_11a_239,\
K_11a_240,\
K_11a_241,\
K_11a_242,\
K_11a_243,\
K_11a_244,\
K_11a_245,\
K_11a_246,\
K_11a_247,\
K_11a_248,\
K_11a_249,\
K_11a_250,\
K_11a_251,\
K_11a_252,\
K_11a_253,\
K_11a_254,\
K_11a_255,\
K_11a_256,\
K_11a_257,\
K_11a_258,\
K_11a_259,\
K_11a_260,\
K_11a_261,\
K_11a_262,\
K_11a_263,\
K_11a_264,\
K_11a_265,\
K_11a_266,\
K_11a_267,\
K_11a_268,\
K_11a_269,\
K_11a_270,\
K_11a_271,\
K_11a_272,\
K_11a_273,\
K_11a_274,\
K_11a_275,\
K_11a_276,\
K_11a_277,\
K_11a_278,\
K_11a_279,\
K_11a_280,\
K_11a_281,\
K_11a_282,\
K_11a_283,\
K_11a_284,\
K_11a_285,\
K_11a_286,\
K_11a_287,\
K_11a_288,\
K_11a_289,\
K_11a_290,\
K_11a_291,\
K_11a_292,\
K_11a_293,\
K_11a_294,\
K_11a_295,\
K_11a_296,\
K_11a_297,\
K_11a_298,\
K_11a_299,\
K_11a_300,\
K_11a_301,\
K_11a_302,\
K_11a_303,\
K_11a_304,\
K_11a_305,\
K_11a_306,\
K_11a_307,\
K_11a_308,\
K_11a_309,\
K_11a_310,\
K_11a_311,\
K_11a_312,\
K_11a_313,\
K_11a_314,\
K_11a_315,\
K_11a_316,\
K_11a_317,\
K_11a_318,\
K_11a_319,\
K_11a_320,\
K_11a_321,\
K_11a_322,\
K_11a_323,\
K_11a_324,\
K_11a_325,\
K_11a_326,\
K_11a_327,\
K_11a_328,\
K_11a_329,\
K_11a_330,\
K_11a_331,\
K_11a_332,\
K_11a_333,\
K_11a_334,\
K_11a_335,\
K_11a_336,\
K_11a_337,\
K_11a_338,\
K_11a_339,\
K_11a_340,\
K_11a_341,\
K_11a_342,\
K_11a_343,\
K_11a_344,\
K_11a_345,\
K_11a_346,\
K_11a_347,\
K_11a_348,\
K_11a_349,\
K_11a_350,\
K_11a_351,\
K_11a_352,\
K_11a_353,\
K_11a_354,\
K_11a_355,\
K_11a_356,\
K_11a_357,\
K_11a_358,\
K_11a_359,\
K_11a_360,\
K_11a_361,\
K_11a_362,\
K_11a_363,\
K_11a_364,\
K_11a_365,\
K_11a_366,\
K_11a_367,\
K_11n_1,\
K_11n_2,\
K_11n_3,\
K_11n_4,\
K_11n_5,\
K_11n_6,\
K_11n_7,\
K_11n_8,\
K_11n_9,\
K_11n_10,\
K_11n_11,\
K_11n_12,\
K_11n_13,\
K_11n_14,\
K_11n_15,\
K_11n_16,\
K_11n_17,\
K_11n_18,\
K_11n_19,\
K_11n_20,\
K_11n_21,\
K_11n_22,\
K_11n_23,\
K_11n_24,\
K_11n_25,\
K_11n_26,\
K_11n_27,\
K_11n_28,\
K_11n_29,\
K_11n_30,\
K_11n_31,\
K_11n_32,\
K_11n_33,\
K_11n_34,\
K_11n_35,\
K_11n_36,\
K_11n_37,\
K_11n_38,\
K_11n_39,\
K_11n_40,\
K_11n_41,\
K_11n_42,\
K_11n_43,\
K_11n_44,\
K_11n_45,\
K_11n_46,\
K_11n_47,\
K_11n_48,\
K_11n_49,\
K_11n_50,\
K_11n_51,\
K_11n_52,\
K_11n_53,\
K_11n_54,\
K_11n_55,\
K_11n_56,\
K_11n_57,\
K_11n_58,\
K_11n_59,\
K_11n_60,\
K_11n_61,\
K_11n_62,\
K_11n_63,\
K_11n_64,\
K_11n_65,\
K_11n_66,\
K_11n_67,\
K_11n_68,\
K_11n_69,\
K_11n_70,\
K_11n_71,\
K_11n_72,\
K_11n_73,\
K_11n_74,\
K_11n_75,\
K_11n_76,\
K_11n_77,\
K_11n_78,\
K_11n_79,\
K_11n_80,\
K_11n_81,\
K_11n_82,\
K_11n_83,\
K_11n_84,\
K_11n_85,\
K_11n_86,\
K_11n_87,\
K_11n_88,\
K_11n_89,\
K_11n_90,\
K_11n_91,\
K_11n_92,\
K_11n_93,\
K_11n_94,\
K_11n_95,\
K_11n_96,\
K_11n_97,\
K_11n_98,\
K_11n_99,\
K_11n_100,\
K_11n_101,\
K_11n_102,\
K_11n_103,\
K_11n_104,\
K_11n_105,\
K_11n_106,\
K_11n_107,\
K_11n_108,\
K_11n_109,\
K_11n_110,\
K_11n_111,\
K_11n_112,\
K_11n_113,\
K_11n_114,\
K_11n_115,\
K_11n_116,\
K_11n_117,\
K_11n_118,\
K_11n_119,\
K_11n_120,\
K_11n_121,\
K_11n_122,\
K_11n_123,\
K_11n_124,\
K_11n_125,\
K_11n_126,\
K_11n_127,\
K_11n_128,\
K_11n_129,\
K_11n_130,\
K_11n_131,\
K_11n_132,\
K_11n_133,\
K_11n_134,\
K_11n_135,\
K_11n_136,\
K_11n_137,\
K_11n_138,\
K_11n_139,\
K_11n_140,\
K_11n_141,\
K_11n_142,\
K_11n_143,\
K_11n_144,\
K_11n_145,\
K_11n_146,\
K_11n_147,\
K_11n_148,\
K_11n_149,\
K_11n_150,\
K_11n_151,\
K_11n_152,\
K_11n_153,\
K_11n_154,\
K_11n_155,\
K_11n_156,\
K_11n_157,\
K_11n_158,\
K_11n_159,\
K_11n_160,\
K_11n_161,\
K_11n_162,\
K_11n_163,\
K_11n_164,\
K_11n_165,\
K_11n_166,\
K_11n_167,\
K_11n_168,\
K_11n_169,\
K_11n_170,\
K_11n_171,\
K_11n_172,\
K_11n_173,\
K_11n_174,\
K_11n_175,\
K_11n_176,\
K_11n_177,\
K_11n_178,\
K_11n_179,\
K_11n_180,\
K_11n_181,\
K_11n_182,\
K_11n_183,\
K_11n_184,\
K_11n_185,\
K_3_1X3_1,\
K_3_1X4_1,\
K_3_1X5_1,\
K_3_1X5_2,\
K_3_1X6_1,\
K_3_1X6_2,\
K_3_1X6_3,\
K_3_1X7_1,\
K_3_1X7_2,\
K_3_1X7_3,\
K_3_1X7_4,\
K_3_1X7_5,\
K_3_1X7_6,\
K_4_1X4_1,\
K_4_1X5_1,\
K_4_1X5_2,\
K_4_1X6_1,\
K_4_1X6_2,\
K_4_1X6_3,\
K_4_1X7_1,\
K_4_1X7_2,\
K_4_1X7_3,\
K_4_1X7_4,\
K_4_1X7_5,\
K_4_1X7_6,\
K_5_1X5_1,\
K_5_1X5_2,\
K_5_1X6_1,\
K_5_1X6_2,\
K_5_1X6_3,\
K_5_1X7_1,\
K_5_1X7_2,\
K_5_1X7_3,\
K_5_1X7_4,\
K_5_1X7_5,\
K_5_1X7_6,\
K_5_2X5_2,\
K_5_2X6_1,\
K_5_2X6_2,\
K_5_2X6_3,\
K_5_2X7_1,\
K_5_2X7_2,\
K_5_2X7_3,\
K_5_2X7_4,\
K_5_2X7_5,\
K_5_2X7_6,\
K_6_1X6_1,\
K_6_1X6_2,\
K_6_1X6_3,\
K_6_1X7_1,\
K_6_1X7_2,\
K_6_1X7_3,\
K_6_1X7_4,\
K_6_1X7_5,\
K_6_1X7_6,\
K_6_2X6_2,\
K_6_2X6_3,\
K_6_2X7_1,\
K_6_2X7_2,\
K_6_2X7_3,\
K_6_2X7_4,\
K_6_2X7_5,\
K_6_2X7_6,\
K_6_3X6_3,\
K_6_3X7_1,\
K_6_3X7_2,\
K_6_3X7_3,\
K_6_3X7_4,\
K_6_3X7_5,\
K_6_3X7_6,\
K_7_1X7_1,\
K_7_1X7_2,\
K_7_1X7_3,\
K_7_1X7_4,\
K_7_1X7_5,\
K_7_1X7_6,\
K_7_2X7_2,\
K_7_2X7_3,\
K_7_2X7_4,\
K_7_2X7_5,\
K_7_2X7_6,\
K_7_3X7_3,\
K_7_3X7_4,\
K_7_3X7_5,\
K_7_3X7_6,\
K_7_4X7_4,\
K_7_4X7_5,\
K_7_4X7_6,\
K_7_5X7_5,\
K_7_5X7_6,\
K_7_6X7_6}

#define KADT_TABLE {\
KADT_K_Un,\
KADT_K_3_1,\
KADT_K_4_1,\
KADT_K_5_1,\
KADT_K_5_2,\
KADT_K_6_1,\
KADT_K_6_2,\
KADT_K_6_3,\
KADT_K_7_1,\
KADT_K_7_2,\
KADT_K_7_3,\
KADT_K_7_4,\
KADT_K_7_5,\
KADT_K_7_6,\
KADT_K_7_7,\
KADT_K_8_1,\
KADT_K_8_2,\
KADT_K_8_3,\
KADT_K_8_4,\
KADT_K_8_5,\
KADT_K_8_6,\
KADT_K_8_7,\
KADT_K_8_8,\
KADT_K_8_9,\
KADT_K_8_10,\
KADT_K_8_11,\
KADT_K_8_12,\
KADT_K_8_13,\
KADT_K_8_14,\
KADT_K_8_15,\
KADT_K_8_16,\
KADT_K_8_17,\
KADT_K_8_18,\
KADT_K_8_19,\
KADT_K_8_20,\
KADT_K_8_21,\
KADT_K_9_1,\
KADT_K_9_2,\
KADT_K_9_3,\
KADT_K_9_4,\
KADT_K_9_5,\
KADT_K_9_6,\
KADT_K_9_7,\
KADT_K_9_8,\
KADT_K_9_9,\
KADT_K_9_10,\
KADT_K_9_11,\
KADT_K_9_12,\
KADT_K_9_13,\
KADT_K_9_14,\
KADT_K_9_15,\
KADT_K_9_16,\
KADT_K_9_17,\
KADT_K_9_18,\
KADT_K_9_19,\
KADT_K_9_20,\
KADT_K_9_21,\
KADT_K_9_22,\
KADT_K_9_23,\
KADT_K_9_24,\
KADT_K_9_25,\
KADT_K_9_26,\
KADT_K_9_27,\
KADT_K_9_28,\
KADT_K_9_29,\
KADT_K_9_30,\
KADT_K_9_31,\
KADT_K_9_32,\
KADT_K_9_33,\
KADT_K_9_34,\
KADT_K_9_35,\
KADT_K_9_36,\
KADT_K_9_37,\
KADT_K_9_38,\
KADT_K_9_39,\
KADT_K_9_40,\
KADT_K_9_41,\
KADT_K_9_42,\
KADT_K_9_43,\
KADT_K_9_44,\
KADT_K_9_45,\
KADT_K_9_46,\
KADT_K_9_47,\
KADT_K_9_48,\
KADT_K_9_49,\
KADT_K_10_1,\
KADT_K_10_2,\
KADT_K_10_3,\
KADT_K_10_4,\
KADT_K_10_5,\
KADT_K_10_6,\
KADT_K_10_7,\
KADT_K_10_8,\
KADT_K_10_9,\
KADT_K_10_10,\
KADT_K_10_11,\
KADT_K_10_12,\
KADT_K_10_13,\
KADT_K_10_14,\
KADT_K_10_15,\
KADT_K_10_16,\
KADT_K_10_17,\
KADT_K_10_18,\
KADT_K_10_19,\
KADT_K_10_20,\
KADT_K_10_21,\
KADT_K_10_22,\
KADT_K_10_23,\
KADT_K_10_24,\
KADT_K_10_25,\
KADT_K_10_26,\
KADT_K_10_27,\
KADT_K_10_28,\
KADT_K_10_29,\
KADT_K_10_30,\
KADT_K_10_31,\
KADT_K_10_32,\
KADT_K_10_33,\
KADT_K_10_34,\
KADT_K_10_35,\
KADT_K_10_36,\
KADT_K_10_37,\
KADT_K_10_38,\
KADT_K_10_39,\
KADT_K_10_40,\
KADT_K_10_41,\
KADT_K_10_42,\
KADT_K_10_43,\
KADT_K_10_44,\
KADT_K_10_45,\
KADT_K_10_46,\
KADT_K_10_47,\
KADT_K_10_48,\
KADT_K_10_49,\
KADT_K_10_50,\
KADT_K_10_51,\
KADT_K_10_52,\
KADT_K_10_53,\
KADT_K_10_54,\
KADT_K_10_55,\
KADT_K_10_56,\
KADT_K_10_57,\
KADT_K_10_58,\
KADT_K_10_59,\
KADT_K_10_60,\
KADT_K_10_61,\
KADT_K_10_62,\
KADT_K_10_63,\
KADT_K_10_64,\
KADT_K_10_65,\
KADT_K_10_66,\
KADT_K_10_67,\
KADT_K_10_68,\
KADT_K_10_69,\
KADT_K_10_70,\
KADT_K_10_71,\
KADT_K_10_72,\
KADT_K_10_73,\
KADT_K_10_74,\
KADT_K_10_75,\
KADT_K_10_76,\
KADT_K_10_77,\
KADT_K_10_78,\
KADT_K_10_79,\
KADT_K_10_80,\
KADT_K_10_81,\
KADT_K_10_82,\
KADT_K_10_83,\
KADT_K_10_84,\
KADT_K_10_85,\
KADT_K_10_86,\
KADT_K_10_87,\
KADT_K_10_88,\
KADT_K_10_89,\
KADT_K_10_90,\
KADT_K_10_91,\
KADT_K_10_92,\
KADT_K_10_93,\
KADT_K_10_94,\
KADT_K_10_95,\
KADT_K_10_96,\
KADT_K_10_97,\
KADT_K_10_98,\
KADT_K_10_99,\
KADT_K_10_100,\
KADT_K_10_101,\
KADT_K_10_102,\
KADT_K_10_103,\
KADT_K_10_104,\
KADT_K_10_105,\
KADT_K_10_106,\
KADT_K_10_107,\
KADT_K_10_108,\
KADT_K_10_109,\
KADT_K_10_110,\
KADT_K_10_111,\
KADT_K_10_112,\
KADT_K_10_113,\
KADT_K_10_114,\
KADT_K_10_115,\
KADT_K_10_116,\
KADT_K_10_117,\
KADT_K_10_118,\
KADT_K_10_119,\
KADT_K_10_120,\
KADT_K_10_121,\
KADT_K_10_122,\
KADT_K_10_123,\
KADT_K_10_124,\
KADT_K_10_125,\
KADT_K_10_126,\
KADT_K_10_127,\
KADT_K_10_128,\
KADT_K_10_129,\
KADT_K_10_130,\
KADT_K_10_131,\
KADT_K_10_132,\
KADT_K_10_133,\
KADT_K_10_134,\
KADT_K_10_135,\
KADT_K_10_136,\
KADT_K_10_137,\
KADT_K_10_138,\
KADT_K_10_139,\
KADT_K_10_140,\
KADT_K_10_141,\
KADT_K_10_142,\
KADT_K_10_143,\
KADT_K_10_144,\
KADT_K_10_145,\
KADT_K_10_146,\
KADT_K_10_147,\
KADT_K_10_148,\
KADT_K_10_149,\
KADT_K_10_150,\
KADT_K_10_151,\
KADT_K_10_152,\
KADT_K_10_153,\
KADT_K_10_154,\
KADT_K_10_155,\
KADT_K_10_156,\
KADT_K_10_157,\
KADT_K_10_158,\
KADT_K_10_159,\
KADT_K_10_160,\
KADT_K_10_161,\
KADT_K_10_162,\
KADT_K_10_163,\
KADT_K_10_164,\
KADT_K_10_165,\
KADT_K_11a_1,\
KADT_K_11a_2,\
KADT_K_11a_3,\
KADT_K_11a_4,\
KADT_K_11a_5,\
KADT_K_11a_6,\
KADT_K_11a_7,\
KADT_K_11a_8,\
KADT_K_11a_9,\
KADT_K_11a_10,\
KADT_K_11a_11,\
KADT_K_11a_12,\
KADT_K_11a_13,\
KADT_K_11a_14,\
KADT_K_11a_15,\
KADT_K_11a_16,\
KADT_K_11a_17,\
KADT_K_11a_18,\
KADT_K_11a_19,\
KADT_K_11a_20,\
KADT_K_11a_21,\
KADT_K_11a_22,\
KADT_K_11a_23,\
KADT_K_11a_24,\
KADT_K_11a_25,\
KADT_K_11a_26,\
KADT_K_11a_27,\
KADT_K_11a_28,\
KADT_K_11a_29,\
KADT_K_11a_30,\
KADT_K_11a_31,\
KADT_K_11a_32,\
KADT_K_11a_33,\
KADT_K_11a_34,\
KADT_K_11a_35,\
KADT_K_11a_36,\
KADT_K_11a_37,\
KADT_K_11a_38,\
KADT_K_11a_39,\
KADT_K_11a_40,\
KADT_K_11a_41,\
KADT_K_11a_42,\
KADT_K_11a_43,\
KADT_K_11a_44,\
KADT_K_11a_45,\
KADT_K_11a_46,\
KADT_K_11a_47,\
KADT_K_11a_48,\
KADT_K_11a_49,\
KADT_K_11a_50,\
KADT_K_11a_51,\
KADT_K_11a_52,\
KADT_K_11a_53,\
KADT_K_11a_54,\
KADT_K_11a_55,\
KADT_K_11a_56,\
KADT_K_11a_57,\
KADT_K_11a_58,\
KADT_K_11a_59,\
KADT_K_11a_60,\
KADT_K_11a_61,\
KADT_K_11a_62,\
KADT_K_11a_63,\
KADT_K_11a_64,\
KADT_K_11a_65,\
KADT_K_11a_66,\
KADT_K_11a_67,\
KADT_K_11a_68,\
KADT_K_11a_69,\
KADT_K_11a_70,\
KADT_K_11a_71,\
KADT_K_11a_72,\
KADT_K_11a_73,\
KADT_K_11a_74,\
KADT_K_11a_75,\
KADT_K_11a_76,\
KADT_K_11a_77,\
KADT_K_11a_78,\
KADT_K_11a_79,\
KADT_K_11a_80,\
KADT_K_11a_81,\
KADT_K_11a_82,\
KADT_K_11a_83,\
KADT_K_11a_84,\
KADT_K_11a_85,\
KADT_K_11a_86,\
KADT_K_11a_87,\
KADT_K_11a_88,\
KADT_K_11a_89,\
KADT_K_11a_90,\
KADT_K_11a_91,\
KADT_K_11a_92,\
KADT_K_11a_93,\
KADT_K_11a_94,\
KADT_K_11a_95,\
KADT_K_11a_96,\
KADT_K_11a_97,\
KADT_K_11a_98,\
KADT_K_11a_99,\
KADT_K_11a_100,\
KADT_K_11a_101,\
KADT_K_11a_102,\
KADT_K_11a_103,\
KADT_K_11a_104,\
KADT_K_11a_105,\
KADT_K_11a_106,\
KADT_K_11a_107,\
KADT_K_11a_108,\
KADT_K_11a_109,\
KADT_K_11a_110,\
KADT_K_11a_111,\
KADT_K_11a_112,\
KADT_K_11a_113,\
KADT_K_11a_114,\
KADT_K_11a_115,\
KADT_K_11a_116,\
KADT_K_11a_117,\
KADT_K_11a_118,\
KADT_K_11a_119,\
KADT_K_11a_120,\
KADT_K_11a_121,\
KADT_K_11a_122,\
KADT_K_11a_123,\
KADT_K_11a_124,\
KADT_K_11a_125,\
KADT_K_11a_126,\
KADT_K_11a_127,\
KADT_K_11a_128,\
KADT_K_11a_129,\
KADT_K_11a_130,\
KADT_K_11a_131,\
KADT_K_11a_132,\
KADT_K_11a_133,\
KADT_K_11a_134,\
KADT_K_11a_135,\
KADT_K_11a_136,\
KADT_K_11a_137,\
KADT_K_11a_138,\
KADT_K_11a_139,\
KADT_K_11a_140,\
KADT_K_11a_141,\
KADT_K_11a_142,\
KADT_K_11a_143,\
KADT_K_11a_144,\
KADT_K_11a_145,\
KADT_K_11a_146,\
KADT_K_11a_147,\
KADT_K_11a_148,\
KADT_K_11a_149,\
KADT_K_11a_150,\
KADT_K_11a_151,\
KADT_K_11a_152,\
KADT_K_11a_153,\
KADT_K_11a_154,\
KADT_K_11a_155,\
KADT_K_11a_156,\
KADT_K_11a_157,\
KADT_K_11a_158,\
KADT_K_11a_159,\
KADT_K_11a_160,\
KADT_K_11a_161,\
KADT_K_11a_162,\
KADT_K_11a_163,\
KADT_K_11a_164,\
KADT_K_11a_165,\
KADT_K_11a_166,\
KADT_K_11a_167,\
KADT_K_11a_168,\
KADT_K_11a_169,\
KADT_K_11a_170,\
KADT_K_11a_171,\
KADT_K_11a_172,\
KADT_K_11a_173,\
KADT_K_11a_174,\
KADT_K_11a_175,\
KADT_K_11a_176,\
KADT_K_11a_177,\
KADT_K_11a_178,\
KADT_K_11a_179,\
KADT_K_11a_180,\
KADT_K_11a_181,\
KADT_K_11a_182,\
KADT_K_11a_183,\
KADT_K_11a_184,\
KADT_K_11a_185,\
KADT_K_11a_186,\
KADT_K_11a_187,\
KADT_K_11a_188,\
KADT_K_11a_189,\
KADT_K_11a_190,\
KADT_K_11a_191,\
KADT_K_11a_192,\
KADT_K_11a_193,\
KADT_K_11a_194,\
KADT_K_11a_195,\
KADT_K_11a_196,\
KADT_K_11a_197,\
KADT_K_11a_198,\
KADT_K_11a_199,\
KADT_K_11a_200,\
KADT_K_11a_201,\
KADT_K_11a_202,\
KADT_K_11a_203,\
KADT_K_11a_204,\
KADT_K_11a_205,\
KADT_K_11a_206,\
KADT_K_11a_207,\
KADT_K_11a_208,\
KADT_K_11a_209,\
KADT_K_11a_210,\
KADT_K_11a_211,\
KADT_K_11a_212,\
KADT_K_11a_213,\
KADT_K_11a_214,\
KADT_K_11a_215,\
KADT_K_11a_216,\
KADT_K_11a_217,\
KADT_K_11a_218,\
KADT_K_11a_219,\
KADT_K_11a_220,\
KADT_K_11a_221,\
KADT_K_11a_222,\
KADT_K_11a_223,\
KADT_K_11a_224,\
KADT_K_11a_225,\
KADT_K_11a_226,\
KADT_K_11a_227,\
KADT_K_11a_228,\
KADT_K_11a_229,\
KADT_K_11a_230,\
KADT_K_11a_231,\
KADT_K_11a_232,\
KADT_K_11a_233,\
KADT_K_11a_234,\
KADT_K_11a_235,\
KADT_K_11a_236,\
KADT_K_11a_237,\
KADT_K_11a_238,\
KADT_K_11a_239,\
KADT_K_11a_240,\
KADT_K_11a_241,\
KADT_K_11a_242,\
KADT_K_11a_243,\
KADT_K_11a_244,\
KADT_K_11a_245,\
KADT_K_11a_246,\
KADT_K_11a_247,\
KADT_K_11a_248,\
KADT_K_11a_249,\
KADT_K_11a_250,\
KADT_K_11a_251,\
KADT_K_11a_252,\
KADT_K_11a_253,\
KADT_K_11a_254,\
KADT_K_11a_255,\
KADT_K_11a_256,\
KADT_K_11a_257,\
KADT_K_11a_258,\
KADT_K_11a_259,\
KADT_K_11a_260,\
KADT_K_11a_261,\
KADT_K_11a_262,\
KADT_K_11a_263,\
KADT_K_11a_264,\
KADT_K_11a_265,\
KADT_K_11a_266,\
KADT_K_11a_267,\
KADT_K_11a_268,\
KADT_K_11a_269,\
KADT_K_11a_270,\
KADT_K_11a_271,\
KADT_K_11a_272,\
KADT_K_11a_273,\
KADT_K_11a_274,\
KADT_K_11a_275,\
KADT_K_11a_276,\
KADT_K_11a_277,\
KADT_K_11a_278,\
KADT_K_11a_279,\
KADT_K_11a_280,\
KADT_K_11a_281,\
KADT_K_11a_282,\
KADT_K_11a_283,\
KADT_K_11a_284,\
KADT_K_11a_285,\
KADT_K_11a_286,\
KADT_K_11a_287,\
KADT_K_11a_288,\
KADT_K_11a_289,\
KADT_K_11a_290,\
KADT_K_11a_291,\
KADT_K_11a_292,\
KADT_K_11a_293,\
KADT_K_11a_294,\
KADT_K_11a_295,\
KADT_K_11a_296,\
KADT_K_11a_297,\
KADT_K_11a_298,\
KADT_K_11a_299,\
KADT_K_11a_300,\
KADT_K_11a_301,\
KADT_K_11a_302,\
KADT_K_11a_303,\
KADT_K_11a_304,\
KADT_K_11a_305,\
KADT_K_11a_306,\
KADT_K_11a_307,\
KADT_K_11a_308,\
KADT_K_11a_309,\
KADT_K_11a_310,\
KADT_K_11a_311,\
KADT_K_11a_312,\
KADT_K_11a_313,\
KADT_K_11a_314,\
KADT_K_11a_315,\
KADT_K_11a_316,\
KADT_K_11a_317,\
KADT_K_11a_318,\
KADT_K_11a_319,\
KADT_K_11a_320,\
KADT_K_11a_321,\
KADT_K_11a_322,\
KADT_K_11a_323,\
KADT_K_11a_324,\
KADT_K_11a_325,\
KADT_K_11a_326,\
KADT_K_11a_327,\
KADT_K_11a_328,\
KADT_K_11a_329,\
KADT_K_11a_330,\
KADT_K_11a_331,\
KADT_K_11a_332,\
KADT_K_11a_333,\
KADT_K_11a_334,\
KADT_K_11a_335,\
KADT_K_11a_336,\
KADT_K_11a_337,\
KADT_K_11a_338,\
KADT_K_11a_339,\
KADT_K_11a_340,\
KADT_K_11a_341,\
KADT_K_11a_342,\
KADT_K_11a_343,\
KADT_K_11a_344,\
KADT_K_11a_345,\
KADT_K_11a_346,\
KADT_K_11a_347,\
KADT_K_11a_348,\
KADT_K_11a_349,\
KADT_K_11a_350,\
KADT_K_11a_351,\
KADT_K_11a_352,\
KADT_K_11a_353,\
KADT_K_11a_354,\
KADT_K_11a_355,\
KADT_K_11a_356,\
KADT_K_11a_357,\
KADT_K_11a_358,\
KADT_K_11a_359,\
KADT_K_11a_360,\
KADT_K_11a_361,\
KADT_K_11a_362,\
KADT_K_11a_363,\
KADT_K_11a_364,\
KADT_K_11a_365,\
KADT_K_11a_366,\
KADT_K_11a_367,\
KADT_K_11n_1,\
KADT_K_11n_2,\
KADT_K_11n_3,\
KADT_K_11n_4,\
KADT_K_11n_5,\
KADT_K_11n_6,\
KADT_K_11n_7,\
KADT_K_11n_8,\
KADT_K_11n_9,\
KADT_K_11n_10,\
KADT_K_11n_11,\
KADT_K_11n_12,\
KADT_K_11n_13,\
KADT_K_11n_14,\
KADT_K_11n_15,\
KADT_K_11n_16,\
KADT_K_11n_17,\
KADT_K_11n_18,\
KADT_K_11n_19,\
KADT_K_11n_20,\
KADT_K_11n_21,\
KADT_K_11n_22,\
KADT_K_11n_23,\
KADT_K_11n_24,\
KADT_K_11n_25,\
KADT_K_11n_26,\
KADT_K_11n_27,\
KADT_K_11n_28,\
KADT_K_11n_29,\
KADT_K_11n_30,\
KADT_K_11n_31,\
KADT_K_11n_32,\
KADT_K_11n_33,\
KADT_K_11n_34,\
KADT_K_11n_35,\
KADT_K_11n_36,\
KADT_K_11n_37,\
KADT_K_11n_38,\
KADT_K_11n_39,\
KADT_K_11n_40,\
KADT_K_11n_41,\
KADT_K_11n_42,\
KADT_K_11n_43,\
KADT_K_11n_44,\
KADT_K_11n_45,\
KADT_K_11n_46,\
KADT_K_11n_47,\
KADT_K_11n_48,\
KADT_K_11n_49,\
KADT_K_11n_50,\
KADT_K_11n_51,\
KADT_K_11n_52,\
KADT_K_11n_53,\
KADT_K_11n_54,\
KADT_K_11n_55,\
KADT_K_11n_56,\
KADT_K_11n_57,\
KADT_K_11n_58,\
KADT_K_11n_59,\
KADT_K_11n_60,\
KADT_K_11n_61,\
KADT_K_11n_62,\
KADT_K_11n_63,\
KADT_K_11n_64,\
KADT_K_11n_65,\
KADT_K_11n_66,\
KADT_K_11n_67,\
KADT_K_11n_68,\
KADT_K_11n_69,\
KADT_K_11n_70,\
KADT_K_11n_71,\
KADT_K_11n_72,\
KADT_K_11n_73,\
KADT_K_11n_74,\
KADT_K_11n_75,\
KADT_K_11n_76,\
KADT_K_11n_77,\
KADT_K_11n_78,\
KADT_K_11n_79,\
KADT_K_11n_80,\
KADT_K_11n_81,\
KADT_K_11n_82,\
KADT_K_11n_83,\
KADT_K_11n_84,\
KADT_K_11n_85,\
KADT_K_11n_86,\
KADT_K_11n_87,\
KADT_K_11n_88,\
KADT_K_11n_89,\
KADT_K_11n_90,\
KADT_K_11n_91,\
KADT_K_11n_92,\
KADT_K_11n_93,\
KADT_K_11n_94,\
KADT_K_11n_95,\
KADT_K_11n_96,\
KADT_K_11n_97,\
KADT_K_11n_98,\
KADT_K_11n_99,\
KADT_K_11n_100,\
KADT_K_11n_101,\
KADT_K_11n_102,\
KADT_K_11n_103,\
KADT_K_11n_104,\
KADT_K_11n_105,\
KADT_K_11n_106,\
KADT_K_11n_107,\
KADT_K_11n_108,\
KADT_K_11n_109,\
KADT_K_11n_110,\
KADT_K_11n_111,\
KADT_K_11n_112,\
KADT_K_11n_113,\
KADT_K_11n_114,\
KADT_K_11n_115,\
KADT_K_11n_116,\
KADT_K_11n_117,\
KADT_K_11n_118,\
KADT_K_11n_119,\
KADT_K_11n_120,\
KADT_K_11n_121,\
KADT_K_11n_122,\
KADT_K_11n_123,\
KADT_K_11n_124,\
KADT_K_11n_125,\
KADT_K_11n_126,\
KADT_K_11n_127,\
KADT_K_11n_128,\
KADT_K_11n_129,\
KADT_K_11n_130,\
KADT_K_11n_131,\
KADT_K_11n_132,\
KADT_K_11n_133,\
KADT_K_11n_134,\
KADT_K_11n_135,\
KADT_K_11n_136,\
KADT_K_11n_137,\
KADT_K_11n_138,\
KADT_K_11n_139,\
KADT_K_11n_140,\
KADT_K_11n_141,\
KADT_K_11n_142,\
KADT_K_11n_143,\
KADT_K_11n_144,\
KADT_K_11n_145,\
KADT_K_11n_146,\
KADT_K_11n_147,\
KADT_K_11n_148,\
KADT_K_11n_149,\
KADT_K_11n_150,\
KADT_K_11n_151,\
KADT_K_11n_152,\
KADT_K_11n_153,\
KADT_K_11n_154,\
KADT_K_11n_155,\
KADT_K_11n_156,\
KADT_K_11n_157,\
KADT_K_11n_158,\
KADT_K_11n_159,\
KADT_K_11n_160,\
KADT_K_11n_161,\
KADT_K_11n_162,\
KADT_K_11n_163,\
KADT_K_11n_164,\
KADT_K_11n_165,\
KADT_K_11n_166,\
KADT_K_11n_167,\
KADT_K_11n_168,\
KADT_K_11n_169,\
KADT_K_11n_170,\
KADT_K_11n_171,\
KADT_K_11n_172,\
KADT_K_11n_173,\
KADT_K_11n_174,\
KADT_K_11n_175,\
KADT_K_11n_176,\
KADT_K_11n_177,\
KADT_K_11n_178,\
KADT_K_11n_179,\
KADT_K_11n_180,\
KADT_K_11n_181,\
KADT_K_11n_182,\
KADT_K_11n_183,\
KADT_K_11n_184,\
KADT_K_11n_185,\
KADT_K_3_1X3_1,\
KADT_K_3_1X4_1,\
KADT_K_3_1X5_1,\
KADT_K_3_1X5_2,\
KADT_K_3_1X6_1,\
KADT_K_3_1X6_2,\
KADT_K_3_1X6_3,\
KADT_K_3_1X7_1,\
KADT_K_3_1X7_2,\
KADT_K_3_1X7_3,\
KADT_K_3_1X7_4,\
KADT_K_3_1X7_5,\
KADT_K_3_1X7_6,\
KADT_K_4_1X4_1,\
KADT_K_4_1X5_1,\
KADT_K_4_1X5_2,\
KADT_K_4_1X6_1,\
KADT_K_4_1X6_2,\
KADT_K_4_1X6_3,\
KADT_K_4_1X7_1,\
KADT_K_4_1X7_2,\
KADT_K_4_1X7_3,\
KADT_K_4_1X7_4,\
KADT_K_4_1X7_5,\
KADT_K_4_1X7_6,\
KADT_K_5_1X5_1,\
KADT_K_5_1X5_2,\
KADT_K_5_1X6_1,\
KADT_K_5_1X6_2,\
KADT_K_5_1X6_3,\
KADT_K_5_1X7_1,\
KADT_K_5_1X7_2,\
KADT_K_5_1X7_3,\
KADT_K_5_1X7_4,\
KADT_K_5_1X7_5,\
KADT_K_5_1X7_6,\
KADT_K_5_2X5_2,\
KADT_K_5_2X6_1,\
KADT_K_5_2X6_2,\
KADT_K_5_2X6_3,\
KADT_K_5_2X7_1,\
KADT_K_5_2X7_2,\
KADT_K_5_2X7_3,\
KADT_K_5_2X7_4,\
KADT_K_5_2X7_5,\
KADT_K_5_2X7_6,\
KADT_K_6_1X6_1,\
KADT_K_6_1X6_2,\
KADT_K_6_1X6_3,\
KADT_K_6_1X7_1,\
KADT_K_6_1X7_2,\
KADT_K_6_1X7_3,\
KADT_K_6_1X7_4,\
KADT_K_6_1X7_5,\
KADT_K_6_1X7_6,\
KADT_K_6_2X6_2,\
KADT_K_6_2X6_3,\
KADT_K_6_2X7_1,\
KADT_K_6_2X7_2,\
KADT_K_6_2X7_3,\
KADT_K_6_2X7_4,\
KADT_K_6_2X7_5,\
KADT_K_6_2X7_6,\
KADT_K_6_3X6_3,\
KADT_K_6_3X7_1,\
KADT_K_6_3X7_2,\
KADT_K_6_3X7_3,\
KADT_K_6_3X7_4,\
KADT_K_6_3X7_5,\
KADT_K_6_3X7_6,\
KADT_K_7_1X7_1,\
KADT_K_7_1X7_2,\
KADT_K_7_1X7_3,\
KADT_K_7_1X7_4,\
KADT_K_7_1X7_5,\
KADT_K_7_1X7_6,\
KADT_K_7_2X7_2,\
KADT_K_7_2X7_3,\
KADT_K_7_2X7_4,\
KADT_K_7_2X7_5,\
KADT_K_7_2X7_6,\
KADT_K_7_3X7_3,\
KADT_K_7_3X7_4,\
KADT_K_7_3X7_5,\
KADT_K_7_3X7_6,\
KADT_K_7_4X7_4,\
KADT_K_7_4X7_5,\
KADT_K_7_4X7_6,\
KADT_K_7_5X7_5,\
KADT_K_7_5X7_6,\
KADT_K_7_6X7_6}

#define KNTadets_KNTLIST {\
{K_Un, KADT_K_Un},\
{K_3_1, KADT_K_3_1},\
{K_4_1, KADT_K_4_1},\
{K_5_1, KADT_K_5_1},\
{K_5_2, KADT_K_5_2},\
{K_6_1, KADT_K_6_1},\
{K_6_2, KADT_K_6_2},\
{K_6_3, KADT_K_6_3},\
{K_7_1, KADT_K_7_1},\
{K_7_2, KADT_K_7_2},\
{K_7_3, KADT_K_7_3},\
{K_7_4, KADT_K_7_4},\
{K_7_5, KADT_K_7_5},\
{K_7_6, KADT_K_7_6},\
{K_7_7, KADT_K_7_7},\
{K_8_1, KADT_K_8_1},\
{K_8_2, KADT_K_8_2},\
{K_8_3, KADT_K_8_3},\
{K_8_4, KADT_K_8_4},\
{K_8_5, KADT_K_8_5},\
{K_8_6, KADT_K_8_6},\
{K_8_7, KADT_K_8_7},\
{K_8_8, KADT_K_8_8},\
{K_8_9, KADT_K_8_9},\
{K_8_10, KADT_K_8_10},\
{K_8_11, KADT_K_8_11},\
{K_8_12, KADT_K_8_12},\
{K_8_13, KADT_K_8_13},\
{K_8_14, KADT_K_8_14},\
{K_8_15, KADT_K_8_15},\
{K_8_16, KADT_K_8_16},\
{K_8_17, KADT_K_8_17},\
{K_8_18, KADT_K_8_18},\
{K_8_19, KADT_K_8_19},\
{K_8_20, KADT_K_8_20},\
{K_8_21, KADT_K_8_21},\
{K_9_1, KADT_K_9_1},\
{K_9_2, KADT_K_9_2},\
{K_9_3, KADT_K_9_3},\
{K_9_4, KADT_K_9_4},\
{K_9_5, KADT_K_9_5},\
{K_9_6, KADT_K_9_6},\
{K_9_7, KADT_K_9_7},\
{K_9_8, KADT_K_9_8},\
{K_9_9, KADT_K_9_9},\
{K_9_10, KADT_K_9_10},\
{K_9_11, KADT_K_9_11},\
{K_9_12, KADT_K_9_12},\
{K_9_13, KADT_K_9_13},\
{K_9_14, KADT_K_9_14},\
{K_9_15, KADT_K_9_15},\
{K_9_16, KADT_K_9_16},\
{K_9_17, KADT_K_9_17},\
{K_9_18, KADT_K_9_18},\
{K_9_19, KADT_K_9_19},\
{K_9_20, KADT_K_9_20},\
{K_9_21, KADT_K_9_21},\
{K_9_22, KADT_K_9_22},\
{K_9_23, KADT_K_9_23},\
{K_9_24, KADT_K_9_24},\
{K_9_25, KADT_K_9_25},\
{K_9_26, KADT_K_9_26},\
{K_9_27, KADT_K_9_27},\
{K_9_28, KADT_K_9_28},\
{K_9_29, KADT_K_9_29},\
{K_9_30, KADT_K_9_30},\
{K_9_31, KADT_K_9_31},\
{K_9_32, KADT_K_9_32},\
{K_9_33, KADT_K_9_33},\
{K_9_34, KADT_K_9_34},\
{K_9_35, KADT_K_9_35},\
{K_9_36, KADT_K_9_36},\
{K_9_37, KADT_K_9_37},\
{K_9_38, KADT_K_9_38},\
{K_9_39, KADT_K_9_39},\
{K_9_40, KADT_K_9_40},\
{K_9_41, KADT_K_9_41},\
{K_9_42, KADT_K_9_42},\
{K_9_43, KADT_K_9_43},\
{K_9_44, KADT_K_9_44},\
{K_9_45, KADT_K_9_45},\
{K_9_46, KADT_K_9_46},\
{K_9_47, KADT_K_9_47},\
{K_9_48, KADT_K_9_48},\
{K_9_49, KADT_K_9_49},\
{K_10_1, KADT_K_10_1},\
{K_10_2, KADT_K_10_2},\
{K_10_3, KADT_K_10_3},\
{K_10_4, KADT_K_10_4},\
{K_10_5, KADT_K_10_5},\
{K_10_6, KADT_K_10_6},\
{K_10_7, KADT_K_10_7},\
{K_10_8, KADT_K_10_8},\
{K_10_9, KADT_K_10_9},\
{K_10_10, KADT_K_10_10},\
{K_10_11, KADT_K_10_11},\
{K_10_12, KADT_K_10_12},\
{K_10_13, KADT_K_10_13},\
{K_10_14, KADT_K_10_14},\
{K_10_15, KADT_K_10_15},\
{K_10_16, KADT_K_10_16},\
{K_10_17, KADT_K_10_17},\
{K_10_18, KADT_K_10_18},\
{K_10_19, KADT_K_10_19},\
{K_10_20, KADT_K_10_20},\
{K_10_21, KADT_K_10_21},\
{K_10_22, KADT_K_10_22},\
{K_10_23, KADT_K_10_23},\
{K_10_24, KADT_K_10_24},\
{K_10_25, KADT_K_10_25},\
{K_10_26, KADT_K_10_26},\
{K_10_27, KADT_K_10_27},\
{K_10_28, KADT_K_10_28},\
{K_10_29, KADT_K_10_29},\
{K_10_30, KADT_K_10_30},\
{K_10_31, KADT_K_10_31},\
{K_10_32, KADT_K_10_32},\
{K_10_33, KADT_K_10_33},\
{K_10_34, KADT_K_10_34},\
{K_10_35, KADT_K_10_35},\
{K_10_36, KADT_K_10_36},\
{K_10_37, KADT_K_10_37},\
{K_10_38, KADT_K_10_38},\
{K_10_39, KADT_K_10_39},\
{K_10_40, KADT_K_10_40},\
{K_10_41, KADT_K_10_41},\
{K_10_42, KADT_K_10_42},\
{K_10_43, KADT_K_10_43},\
{K_10_44, KADT_K_10_44},\
{K_10_45, KADT_K_10_45},\
{K_10_46, KADT_K_10_46},\
{K_10_47, KADT_K_10_47},\
{K_10_48, KADT_K_10_48},\
{K_10_49, KADT_K_10_49},\
{K_10_50, KADT_K_10_50},\
{K_10_51, KADT_K_10_51},\
{K_10_52, KADT_K_10_52},\
{K_10_53, KADT_K_10_53},\
{K_10_54, KADT_K_10_54},\
{K_10_55, KADT_K_10_55},\
{K_10_56, KADT_K_10_56},\
{K_10_57, KADT_K_10_57},\
{K_10_58, KADT_K_10_58},\
{K_10_59, KADT_K_10_59},\
{K_10_60, KADT_K_10_60},\
{K_10_61, KADT_K_10_61},\
{K_10_62, KADT_K_10_62},\
{K_10_63, KADT_K_10_63},\
{K_10_64, KADT_K_10_64},\
{K_10_65, KADT_K_10_65},\
{K_10_66, KADT_K_10_66},\
{K_10_67, KADT_K_10_67},\
{K_10_68, KADT_K_10_68},\
{K_10_69, KADT_K_10_69},\
{K_10_70, KADT_K_10_70},\
{K_10_71, KADT_K_10_71},\
{K_10_72, KADT_K_10_72},\
{K_10_73, KADT_K_10_73},\
{K_10_74, KADT_K_10_74},\
{K_10_75, KADT_K_10_75},\
{K_10_76, KADT_K_10_76},\
{K_10_77, KADT_K_10_77},\
{K_10_78, KADT_K_10_78},\
{K_10_79, KADT_K_10_79},\
{K_10_80, KADT_K_10_80},\
{K_10_81, KADT_K_10_81},\
{K_10_82, KADT_K_10_82},\
{K_10_83, KADT_K_10_83},\
{K_10_84, KADT_K_10_84},\
{K_10_85, KADT_K_10_85},\
{K_10_86, KADT_K_10_86},\
{K_10_87, KADT_K_10_87},\
{K_10_88, KADT_K_10_88},\
{K_10_89, KADT_K_10_89},\
{K_10_90, KADT_K_10_90},\
{K_10_91, KADT_K_10_91},\
{K_10_92, KADT_K_10_92},\
{K_10_93, KADT_K_10_93},\
{K_10_94, KADT_K_10_94},\
{K_10_95, KADT_K_10_95},\
{K_10_96, KADT_K_10_96},\
{K_10_97, KADT_K_10_97},\
{K_10_98, KADT_K_10_98},\
{K_10_99, KADT_K_10_99},\
{K_10_100, KADT_K_10_100},\
{K_10_101, KADT_K_10_101},\
{K_10_102, KADT_K_10_102},\
{K_10_103, KADT_K_10_103},\
{K_10_104, KADT_K_10_104},\
{K_10_105, KADT_K_10_105},\
{K_10_106, KADT_K_10_106},\
{K_10_107, KADT_K_10_107},\
{K_10_108, KADT_K_10_108},\
{K_10_109, KADT_K_10_109},\
{K_10_110, KADT_K_10_110},\
{K_10_111, KADT_K_10_111},\
{K_10_112, KADT_K_10_112},\
{K_10_113, KADT_K_10_113},\
{K_10_114, KADT_K_10_114},\
{K_10_115, KADT_K_10_115},\
{K_10_116, KADT_K_10_116},\
{K_10_117, KADT_K_10_117},\
{K_10_118, KADT_K_10_118},\
{K_10_119, KADT_K_10_119},\
{K_10_120, KADT_K_10_120},\
{K_10_121, KADT_K_10_121},\
{K_10_122, KADT_K_10_122},\
{K_10_123, KADT_K_10_123},\
{K_10_124, KADT_K_10_124},\
{K_10_125, KADT_K_10_125},\
{K_10_126, KADT_K_10_126},\
{K_10_127, KADT_K_10_127},\
{K_10_128, KADT_K_10_128},\
{K_10_129, KADT_K_10_129},\
{K_10_130, KADT_K_10_130},\
{K_10_131, KADT_K_10_131},\
{K_10_132, KADT_K_10_132},\
{K_10_133, KADT_K_10_133},\
{K_10_134, KADT_K_10_134},\
{K_10_135, KADT_K_10_135},\
{K_10_136, KADT_K_10_136},\
{K_10_137, KADT_K_10_137},\
{K_10_138, KADT_K_10_138},\
{K_10_139, KADT_K_10_139},\
{K_10_140, KADT_K_10_140},\
{K_10_141, KADT_K_10_141},\
{K_10_142, KADT_K_10_142},\
{K_10_143, KADT_K_10_143},\
{K_10_144, KADT_K_10_144},\
{K_10_145, KADT_K_10_145},\
{K_10_146, KADT_K_10_146},\
{K_10_147, KADT_K_10_147},\
{K_10_148, KADT_K_10_148},\
{K_10_149, KADT_K_10_149},\
{K_10_150, KADT_K_10_150},\
{K_10_151, KADT_K_10_151},\
{K_10_152, KADT_K_10_152},\
{K_10_153, KADT_K_10_153},\
{K_10_154, KADT_K_10_154},\
{K_10_155, KADT_K_10_155},\
{K_10_156, KADT_K_10_156},\
{K_10_157, KADT_K_10_157},\
{K_10_158, KADT_K_10_158},\
{K_10_159, KADT_K_10_159},\
{K_10_160, KADT_K_10_160},\
{K_10_161, KADT_K_10_161},\
{K_10_162, KADT_K_10_162},\
{K_10_163, KADT_K_10_163},\
{K_10_164, KADT_K_10_164},\
{K_10_165, KADT_K_10_165},\
{K_11a_1, KADT_K_11a_1},\
{K_11a_2, KADT_K_11a_2},\
{K_11a_3, KADT_K_11a_3},\
{K_11a_4, KADT_K_11a_4},\
{K_11a_5, KADT_K_11a_5},\
{K_11a_6, KADT_K_11a_6},\
{K_11a_7, KADT_K_11a_7},\
{K_11a_8, KADT_K_11a_8},\
{K_11a_9, KADT_K_11a_9},\
{K_11a_10, KADT_K_11a_10},\
{K_11a_11, KADT_K_11a_11},\
{K_11a_12, KADT_K_11a_12},\
{K_11a_13, KADT_K_11a_13},\
{K_11a_14, KADT_K_11a_14},\
{K_11a_15, KADT_K_11a_15},\
{K_11a_16, KADT_K_11a_16},\
{K_11a_17, KADT_K_11a_17},\
{K_11a_18, KADT_K_11a_18},\
{K_11a_19, KADT_K_11a_19},\
{K_11a_20, KADT_K_11a_20},\
{K_11a_21, KADT_K_11a_21},\
{K_11a_22, KADT_K_11a_22},\
{K_11a_23, KADT_K_11a_23},\
{K_11a_24, KADT_K_11a_24},\
{K_11a_25, KADT_K_11a_25},\
{K_11a_26, KADT_K_11a_26},\
{K_11a_27, KADT_K_11a_27},\
{K_11a_28, KADT_K_11a_28},\
{K_11a_29, KADT_K_11a_29},\
{K_11a_30, KADT_K_11a_30},\
{K_11a_31, KADT_K_11a_31},\
{K_11a_32, KADT_K_11a_32},\
{K_11a_33, KADT_K_11a_33},\
{K_11a_34, KADT_K_11a_34},\
{K_11a_35, KADT_K_11a_35},\
{K_11a_36, KADT_K_11a_36},\
{K_11a_37, KADT_K_11a_37},\
{K_11a_38, KADT_K_11a_38},\
{K_11a_39, KADT_K_11a_39},\
{K_11a_40, KADT_K_11a_40},\
{K_11a_41, KADT_K_11a_41},\
{K_11a_42, KADT_K_11a_42},\
{K_11a_43, KADT_K_11a_43},\
{K_11a_44, KADT_K_11a_44},\
{K_11a_45, KADT_K_11a_45},\
{K_11a_46, KADT_K_11a_46},\
{K_11a_47, KADT_K_11a_47},\
{K_11a_48, KADT_K_11a_48},\
{K_11a_49, KADT_K_11a_49},\
{K_11a_50, KADT_K_11a_50},\
{K_11a_51, KADT_K_11a_51},\
{K_11a_52, KADT_K_11a_52},\
{K_11a_53, KADT_K_11a_53},\
{K_11a_54, KADT_K_11a_54},\
{K_11a_55, KADT_K_11a_55},\
{K_11a_56, KADT_K_11a_56},\
{K_11a_57, KADT_K_11a_57},\
{K_11a_58, KADT_K_11a_58},\
{K_11a_59, KADT_K_11a_59},\
{K_11a_60, KADT_K_11a_60},\
{K_11a_61, KADT_K_11a_61},\
{K_11a_62, KADT_K_11a_62},\
{K_11a_63, KADT_K_11a_63},\
{K_11a_64, KADT_K_11a_64},\
{K_11a_65, KADT_K_11a_65},\
{K_11a_66, KADT_K_11a_66},\
{K_11a_67, KADT_K_11a_67},\
{K_11a_68, KADT_K_11a_68},\
{K_11a_69, KADT_K_11a_69},\
{K_11a_70, KADT_K_11a_70},\
{K_11a_71, KADT_K_11a_71},\
{K_11a_72, KADT_K_11a_72},\
{K_11a_73, KADT_K_11a_73},\
{K_11a_74, KADT_K_11a_74},\
{K_11a_75, KADT_K_11a_75},\
{K_11a_76, KADT_K_11a_76},\
{K_11a_77, KADT_K_11a_77},\
{K_11a_78, KADT_K_11a_78},\
{K_11a_79, KADT_K_11a_79},\
{K_11a_80, KADT_K_11a_80},\
{K_11a_81, KADT_K_11a_81},\
{K_11a_82, KADT_K_11a_82},\
{K_11a_83, KADT_K_11a_83},\
{K_11a_84, KADT_K_11a_84},\
{K_11a_85, KADT_K_11a_85},\
{K_11a_86, KADT_K_11a_86},\
{K_11a_87, KADT_K_11a_87},\
{K_11a_88, KADT_K_11a_88},\
{K_11a_89, KADT_K_11a_89},\
{K_11a_90, KADT_K_11a_90},\
{K_11a_91, KADT_K_11a_91},\
{K_11a_92, KADT_K_11a_92},\
{K_11a_93, KADT_K_11a_93},\
{K_11a_94, KADT_K_11a_94},\
{K_11a_95, KADT_K_11a_95},\
{K_11a_96, KADT_K_11a_96},\
{K_11a_97, KADT_K_11a_97},\
{K_11a_98, KADT_K_11a_98},\
{K_11a_99, KADT_K_11a_99},\
{K_11a_100, KADT_K_11a_100},\
{K_11a_101, KADT_K_11a_101},\
{K_11a_102, KADT_K_11a_102},\
{K_11a_103, KADT_K_11a_103},\
{K_11a_104, KADT_K_11a_104},\
{K_11a_105, KADT_K_11a_105},\
{K_11a_106, KADT_K_11a_106},\
{K_11a_107, KADT_K_11a_107},\
{K_11a_108, KADT_K_11a_108},\
{K_11a_109, KADT_K_11a_109},\
{K_11a_110, KADT_K_11a_110},\
{K_11a_111, KADT_K_11a_111},\
{K_11a_112, KADT_K_11a_112},\
{K_11a_113, KADT_K_11a_113},\
{K_11a_114, KADT_K_11a_114},\
{K_11a_115, KADT_K_11a_115},\
{K_11a_116, KADT_K_11a_116},\
{K_11a_117, KADT_K_11a_117},\
{K_11a_118, KADT_K_11a_118},\
{K_11a_119, KADT_K_11a_119},\
{K_11a_120, KADT_K_11a_120},\
{K_11a_121, KADT_K_11a_121},\
{K_11a_122, KADT_K_11a_122},\
{K_11a_123, KADT_K_11a_123},\
{K_11a_124, KADT_K_11a_124},\
{K_11a_125, KADT_K_11a_125},\
{K_11a_126, KADT_K_11a_126},\
{K_11a_127, KADT_K_11a_127},\
{K_11a_128, KADT_K_11a_128},\
{K_11a_129, KADT_K_11a_129},\
{K_11a_130, KADT_K_11a_130},\
{K_11a_131, KADT_K_11a_131},\
{K_11a_132, KADT_K_11a_132},\
{K_11a_133, KADT_K_11a_133},\
{K_11a_134, KADT_K_11a_134},\
{K_11a_135, KADT_K_11a_135},\
{K_11a_136, KADT_K_11a_136},\
{K_11a_137, KADT_K_11a_137},\
{K_11a_138, KADT_K_11a_138},\
{K_11a_139, KADT_K_11a_139},\
{K_11a_140, KADT_K_11a_140},\
{K_11a_141, KADT_K_11a_141},\
{K_11a_142, KADT_K_11a_142},\
{K_11a_143, KADT_K_11a_143},\
{K_11a_144, KADT_K_11a_144},\
{K_11a_145, KADT_K_11a_145},\
{K_11a_146, KADT_K_11a_146},\
{K_11a_147, KADT_K_11a_147},\
{K_11a_148, KADT_K_11a_148},\
{K_11a_149, KADT_K_11a_149},\
{K_11a_150, KADT_K_11a_150},\
{K_11a_151, KADT_K_11a_151},\
{K_11a_152, KADT_K_11a_152},\
{K_11a_153, KADT_K_11a_153},\
{K_11a_154, KADT_K_11a_154},\
{K_11a_155, KADT_K_11a_155},\
{K_11a_156, KADT_K_11a_156},\
{K_11a_157, KADT_K_11a_157},\
{K_11a_158, KADT_K_11a_158},\
{K_11a_159, KADT_K_11a_159},\
{K_11a_160, KADT_K_11a_160},\
{K_11a_161, KADT_K_11a_161},\
{K_11a_162, KADT_K_11a_162},\
{K_11a_163, KADT_K_11a_163},\
{K_11a_164, KADT_K_11a_164},\
{K_11a_165, KADT_K_11a_165},\
{K_11a_166, KADT_K_11a_166},\
{K_11a_167, KADT_K_11a_167},\
{K_11a_168, KADT_K_11a_168},\
{K_11a_169, KADT_K_11a_169},\
{K_11a_170, KADT_K_11a_170},\
{K_11a_171, KADT_K_11a_171},\
{K_11a_172, KADT_K_11a_172},\
{K_11a_173, KADT_K_11a_173},\
{K_11a_174, KADT_K_11a_174},\
{K_11a_175, KADT_K_11a_175},\
{K_11a_176, KADT_K_11a_176},\
{K_11a_177, KADT_K_11a_177},\
{K_11a_178, KADT_K_11a_178},\
{K_11a_179, KADT_K_11a_179},\
{K_11a_180, KADT_K_11a_180},\
{K_11a_181, KADT_K_11a_181},\
{K_11a_182, KADT_K_11a_182},\
{K_11a_183, KADT_K_11a_183},\
{K_11a_184, KADT_K_11a_184},\
{K_11a_185, KADT_K_11a_185},\
{K_11a_186, KADT_K_11a_186},\
{K_11a_187, KADT_K_11a_187},\
{K_11a_188, KADT_K_11a_188},\
{K_11a_189, KADT_K_11a_189},\
{K_11a_190, KADT_K_11a_190},\
{K_11a_191, KADT_K_11a_191},\
{K_11a_192, KADT_K_11a_192},\
{K_11a_193, KADT_K_11a_193},\
{K_11a_194, KADT_K_11a_194},\
{K_11a_195, KADT_K_11a_195},\
{K_11a_196, KADT_K_11a_196},\
{K_11a_197, KADT_K_11a_197},\
{K_11a_198, KADT_K_11a_198},\
{K_11a_199, KADT_K_11a_199},\
{K_11a_200, KADT_K_11a_200},\
{K_11a_201, KADT_K_11a_201},\
{K_11a_202, KADT_K_11a_202},\
{K_11a_203, KADT_K_11a_203},\
{K_11a_204, KADT_K_11a_204},\
{K_11a_205, KADT_K_11a_205},\
{K_11a_206, KADT_K_11a_206},\
{K_11a_207, KADT_K_11a_207},\
{K_11a_208, KADT_K_11a_208},\
{K_11a_209, KADT_K_11a_209},\
{K_11a_210, KADT_K_11a_210},\
{K_11a_211, KADT_K_11a_211},\
{K_11a_212, KADT_K_11a_212},\
{K_11a_213, KADT_K_11a_213},\
{K_11a_214, KADT_K_11a_214},\
{K_11a_215, KADT_K_11a_215},\
{K_11a_216, KADT_K_11a_216},\
{K_11a_217, KADT_K_11a_217},\
{K_11a_218, KADT_K_11a_218},\
{K_11a_219, KADT_K_11a_219},\
{K_11a_220, KADT_K_11a_220},\
{K_11a_221, KADT_K_11a_221},\
{K_11a_222, KADT_K_11a_222},\
{K_11a_223, KADT_K_11a_223},\
{K_11a_224, KADT_K_11a_224},\
{K_11a_225, KADT_K_11a_225},\
{K_11a_226, KADT_K_11a_226},\
{K_11a_227, KADT_K_11a_227},\
{K_11a_228, KADT_K_11a_228},\
{K_11a_229, KADT_K_11a_229},\
{K_11a_230, KADT_K_11a_230},\
{K_11a_231, KADT_K_11a_231},\
{K_11a_232, KADT_K_11a_232},\
{K_11a_233, KADT_K_11a_233},\
{K_11a_234, KADT_K_11a_234},\
{K_11a_235, KADT_K_11a_235},\
{K_11a_236, KADT_K_11a_236},\
{K_11a_237, KADT_K_11a_237},\
{K_11a_238, KADT_K_11a_238},\
{K_11a_239, KADT_K_11a_239},\
{K_11a_240, KADT_K_11a_240},\
{K_11a_241, KADT_K_11a_241},\
{K_11a_242, KADT_K_11a_242},\
{K_11a_243, KADT_K_11a_243},\
{K_11a_244, KADT_K_11a_244},\
{K_11a_245, KADT_K_11a_245},\
{K_11a_246, KADT_K_11a_246},\
{K_11a_247, KADT_K_11a_247},\
{K_11a_248, KADT_K_11a_248},\
{K_11a_249, KADT_K_11a_249},\
{K_11a_250, KADT_K_11a_250},\
{K_11a_251, KADT_K_11a_251},\
{K_11a_252, KADT_K_11a_252},\
{K_11a_253, KADT_K_11a_253},\
{K_11a_254, KADT_K_11a_254},\
{K_11a_255, KADT_K_11a_255},\
{K_11a_256, KADT_K_11a_256},\
{K_11a_257, KADT_K_11a_257},\
{K_11a_258, KADT_K_11a_258},\
{K_11a_259, KADT_K_11a_259},\
{K_11a_260, KADT_K_11a_260},\
{K_11a_261, KADT_K_11a_261},\
{K_11a_262, KADT_K_11a_262},\
{K_11a_263, KADT_K_11a_263},\
{K_11a_264, KADT_K_11a_264},\
{K_11a_265, KADT_K_11a_265},\
{K_11a_266, KADT_K_11a_266},\
{K_11a_267, KADT_K_11a_267},\
{K_11a_268, KADT_K_11a_268},\
{K_11a_269, KADT_K_11a_269},\
{K_11a_270, KADT_K_11a_270},\
{K_11a_271, KADT_K_11a_271},\
{K_11a_272, KADT_K_11a_272},\
{K_11a_273, KADT_K_11a_273},\
{K_11a_274, KADT_K_11a_274},\
{K_11a_275, KADT_K_11a_275},\
{K_11a_276, KADT_K_11a_276},\
{K_11a_277, KADT_K_11a_277},\
{K_11a_278, KADT_K_11a_278},\
{K_11a_279, KADT_K_11a_279},\
{K_11a_280, KADT_K_11a_280},\
{K_11a_281, KADT_K_11a_281},\
{K_11a_282, KADT_K_11a_282},\
{K_11a_283, KADT_K_11a_283},\
{K_11a_284, KADT_K_11a_284},\
{K_11a_285, KADT_K_11a_285},\
{K_11a_286, KADT_K_11a_286},\
{K_11a_287, KADT_K_11a_287},\
{K_11a_288, KADT_K_11a_288},\
{K_11a_289, KADT_K_11a_289},\
{K_11a_290, KADT_K_11a_290},\
{K_11a_291, KADT_K_11a_291},\
{K_11a_292, KADT_K_11a_292},\
{K_11a_293, KADT_K_11a_293},\
{K_11a_294, KADT_K_11a_294},\
{K_11a_295, KADT_K_11a_295},\
{K_11a_296, KADT_K_11a_296},\
{K_11a_297, KADT_K_11a_297},\
{K_11a_298, KADT_K_11a_298},\
{K_11a_299, KADT_K_11a_299},\
{K_11a_300, KADT_K_11a_300},\
{K_11a_301, KADT_K_11a_301},\
{K_11a_302, KADT_K_11a_302},\
{K_11a_303, KADT_K_11a_303},\
{K_11a_304, KADT_K_11a_304},\
{K_11a_305, KADT_K_11a_305},\
{K_11a_306, KADT_K_11a_306},\
{K_11a_307, KADT_K_11a_307},\
{K_11a_308, KADT_K_11a_308},\
{K_11a_309, KADT_K_11a_309},\
{K_11a_310, KADT_K_11a_310},\
{K_11a_311, KADT_K_11a_311},\
{K_11a_312, KADT_K_11a_312},\
{K_11a_313, KADT_K_11a_313},\
{K_11a_314, KADT_K_11a_314},\
{K_11a_315, KADT_K_11a_315},\
{K_11a_316, KADT_K_11a_316},\
{K_11a_317, KADT_K_11a_317},\
{K_11a_318, KADT_K_11a_318},\
{K_11a_319, KADT_K_11a_319},\
{K_11a_320, KADT_K_11a_320},\
{K_11a_321, KADT_K_11a_321},\
{K_11a_322, KADT_K_11a_322},\
{K_11a_323, KADT_K_11a_323},\
{K_11a_324, KADT_K_11a_324},\
{K_11a_325, KADT_K_11a_325},\
{K_11a_326, KADT_K_11a_326},\
{K_11a_327, KADT_K_11a_327},\
{K_11a_328, KADT_K_11a_328},\
{K_11a_329, KADT_K_11a_329},\
{K_11a_330, KADT_K_11a_330},\
{K_11a_331, KADT_K_11a_331},\
{K_11a_332, KADT_K_11a_332},\
{K_11a_333, KADT_K_11a_333},\
{K_11a_334, KADT_K_11a_334},\
{K_11a_335, KADT_K_11a_335},\
{K_11a_336, KADT_K_11a_336},\
{K_11a_337, KADT_K_11a_337},\
{K_11a_338, KADT_K_11a_338},\
{K_11a_339, KADT_K_11a_339},\
{K_11a_340, KADT_K_11a_340},\
{K_11a_341, KADT_K_11a_341},\
{K_11a_342, KADT_K_11a_342},\
{K_11a_343, KADT_K_11a_343},\
{K_11a_344, KADT_K_11a_344},\
{K_11a_345, KADT_K_11a_345},\
{K_11a_346, KADT_K_11a_346},\
{K_11a_347, KADT_K_11a_347},\
{K_11a_348, KADT_K_11a_348},\
{K_11a_349, KADT_K_11a_349},\
{K_11a_350, KADT_K_11a_350},\
{K_11a_351, KADT_K_11a_351},\
{K_11a_352, KADT_K_11a_352},\
{K_11a_353, KADT_K_11a_353},\
{K_11a_354, KADT_K_11a_354},\
{K_11a_355, KADT_K_11a_355},\
{K_11a_356, KADT_K_11a_356},\
{K_11a_357, KADT_K_11a_357},\
{K_11a_358, KADT_K_11a_358},\
{K_11a_359, KADT_K_11a_359},\
{K_11a_360, KADT_K_11a_360},\
{K_11a_361, KADT_K_11a_361},\
{K_11a_362, KADT_K_11a_362},\
{K_11a_363, KADT_K_11a_363},\
{K_11a_364, KADT_K_11a_364},\
{K_11a_365, KADT_K_11a_365},\
{K_11a_366, KADT_K_11a_366},\
{K_11a_367, KADT_K_11a_367},\
{K_11n_1, KADT_K_11n_1},\
{K_11n_2, KADT_K_11n_2},\
{K_11n_3, KADT_K_11n_3},\
{K_11n_4, KADT_K_11n_4},\
{K_11n_5, KADT_K_11n_5},\
{K_11n_6, KADT_K_11n_6},\
{K_11n_7, KADT_K_11n_7},\
{K_11n_8, KADT_K_11n_8},\
{K_11n_9, KADT_K_11n_9},\
{K_11n_10, KADT_K_11n_10},\
{K_11n_11, KADT_K_11n_11},\
{K_11n_12, KADT_K_11n_12},\
{K_11n_13, KADT_K_11n_13},\
{K_11n_14, KADT_K_11n_14},\
{K_11n_15, KADT_K_11n_15},\
{K_11n_16, KADT_K_11n_16},\
{K_11n_17, KADT_K_11n_17},\
{K_11n_18, KADT_K_11n_18},\
{K_11n_19, KADT_K_11n_19},\
{K_11n_20, KADT_K_11n_20},\
{K_11n_21, KADT_K_11n_21},\
{K_11n_22, KADT_K_11n_22},\
{K_11n_23, KADT_K_11n_23},\
{K_11n_24, KADT_K_11n_24},\
{K_11n_25, KADT_K_11n_25},\
{K_11n_26, KADT_K_11n_26},\
{K_11n_27, KADT_K_11n_27},\
{K_11n_28, KADT_K_11n_28},\
{K_11n_29, KADT_K_11n_29},\
{K_11n_30, KADT_K_11n_30},\
{K_11n_31, KADT_K_11n_31},\
{K_11n_32, KADT_K_11n_32},\
{K_11n_33, KADT_K_11n_33},\
{K_11n_34, KADT_K_11n_34},\
{K_11n_35, KADT_K_11n_35},\
{K_11n_36, KADT_K_11n_36},\
{K_11n_37, KADT_K_11n_37},\
{K_11n_38, KADT_K_11n_38},\
{K_11n_39, KADT_K_11n_39},\
{K_11n_40, KADT_K_11n_40},\
{K_11n_41, KADT_K_11n_41},\
{K_11n_42, KADT_K_11n_42},\
{K_11n_43, KADT_K_11n_43},\
{K_11n_44, KADT_K_11n_44},\
{K_11n_45, KADT_K_11n_45},\
{K_11n_46, KADT_K_11n_46},\
{K_11n_47, KADT_K_11n_47},\
{K_11n_48, KADT_K_11n_48},\
{K_11n_49, KADT_K_11n_49},\
{K_11n_50, KADT_K_11n_50},\
{K_11n_51, KADT_K_11n_51},\
{K_11n_52, KADT_K_11n_52},\
{K_11n_53, KADT_K_11n_53},\
{K_11n_54, KADT_K_11n_54},\
{K_11n_55, KADT_K_11n_55},\
{K_11n_56, KADT_K_11n_56},\
{K_11n_57, KADT_K_11n_57},\
{K_11n_58, KADT_K_11n_58},\
{K_11n_59, KADT_K_11n_59},\
{K_11n_60, KADT_K_11n_60},\
{K_11n_61, KADT_K_11n_61},\
{K_11n_62, KADT_K_11n_62},\
{K_11n_63, KADT_K_11n_63},\
{K_11n_64, KADT_K_11n_64},\
{K_11n_65, KADT_K_11n_65},\
{K_11n_66, KADT_K_11n_66},\
{K_11n_67, KADT_K_11n_67},\
{K_11n_68, KADT_K_11n_68},\
{K_11n_69, KADT_K_11n_69},\
{K_11n_70, KADT_K_11n_70},\
{K_11n_71, KADT_K_11n_71},\
{K_11n_72, KADT_K_11n_72},\
{K_11n_73, KADT_K_11n_73},\
{K_11n_74, KADT_K_11n_74},\
{K_11n_75, KADT_K_11n_75},\
{K_11n_76, KADT_K_11n_76},\
{K_11n_77, KADT_K_11n_77},\
{K_11n_78, KADT_K_11n_78},\
{K_11n_79, KADT_K_11n_79},\
{K_11n_80, KADT_K_11n_80},\
{K_11n_81, KADT_K_11n_81},\
{K_11n_82, KADT_K_11n_82},\
{K_11n_83, KADT_K_11n_83},\
{K_11n_84, KADT_K_11n_84},\
{K_11n_85, KADT_K_11n_85},\
{K_11n_86, KADT_K_11n_86},\
{K_11n_87, KADT_K_11n_87},\
{K_11n_88, KADT_K_11n_88},\
{K_11n_89, KADT_K_11n_89},\
{K_11n_90, KADT_K_11n_90},\
{K_11n_91, KADT_K_11n_91},\
{K_11n_92, KADT_K_11n_92},\
{K_11n_93, KADT_K_11n_93},\
{K_11n_94, KADT_K_11n_94},\
{K_11n_95, KADT_K_11n_95},\
{K_11n_96, KADT_K_11n_96},\
{K_11n_97, KADT_K_11n_97},\
{K_11n_98, KADT_K_11n_98},\
{K_11n_99, KADT_K_11n_99},\
{K_11n_100, KADT_K_11n_100},\
{K_11n_101, KADT_K_11n_101},\
{K_11n_102, KADT_K_11n_102},\
{K_11n_103, KADT_K_11n_103},\
{K_11n_104, KADT_K_11n_104},\
{K_11n_105, KADT_K_11n_105},\
{K_11n_106, KADT_K_11n_106},\
{K_11n_107, KADT_K_11n_107},\
{K_11n_108, KADT_K_11n_108},\
{K_11n_109, KADT_K_11n_109},\
{K_11n_110, KADT_K_11n_110},\
{K_11n_111, KADT_K_11n_111},\
{K_11n_112, KADT_K_11n_112},\
{K_11n_113, KADT_K_11n_113},\
{K_11n_114, KADT_K_11n_114},\
{K_11n_115, KADT_K_11n_115},\
{K_11n_116, KADT_K_11n_116},\
{K_11n_117, KADT_K_11n_117},\
{K_11n_118, KADT_K_11n_118},\
{K_11n_119, KADT_K_11n_119},\
{K_11n_120, KADT_K_11n_120},\
{K_11n_121, KADT_K_11n_121},\
{K_11n_122, KADT_K_11n_122},\
{K_11n_123, KADT_K_11n_123},\
{K_11n_124, KADT_K_11n_124},\
{K_11n_125, KADT_K_11n_125},\
{K_11n_126, KADT_K_11n_126},\
{K_11n_127, KADT_K_11n_127},\
{K_11n_128, KADT_K_11n_128},\
{K_11n_129, KADT_K_11n_129},\
{K_11n_130, KADT_K_11n_130},\
{K_11n_131, KADT_K_11n_131},\
{K_11n_132, KADT_K_11n_132},\
{K_11n_133, KADT_K_11n_133},\
{K_11n_134, KADT_K_11n_134},\
{K_11n_135, KADT_K_11n_135},\
{K_11n_136, KADT_K_11n_136},\
{K_11n_137, KADT_K_11n_137},\
{K_11n_138, KADT_K_11n_138},\
{K_11n_139, KADT_K_11n_139},\
{K_11n_140, KADT_K_11n_140},\
{K_11n_141, KADT_K_11n_141},\
{K_11n_142, KADT_K_11n_142},\
{K_11n_143, KADT_K_11n_143},\
{K_11n_144, KADT_K_11n_144},\
{K_11n_145, KADT_K_11n_145},\
{K_11n_146, KADT_K_11n_146},\
{K_11n_147, KADT_K_11n_147},\
{K_11n_148, KADT_K_11n_148},\
{K_11n_149, KADT_K_11n_149},\
{K_11n_150, KADT_K_11n_150},\
{K_11n_151, KADT_K_11n_151},\
{K_11n_152, KADT_K_11n_152},\
{K_11n_153, KADT_K_11n_153},\
{K_11n_154, KADT_K_11n_154},\
{K_11n_155, KADT_K_11n_155},\
{K_11n_156, KADT_K_11n_156},\
{K_11n_157, KADT_K_11n_157},\
{K_11n_158, KADT_K_11n_158},\
{K_11n_159, KADT_K_11n_159},\
{K_11n_160, KADT_K_11n_160},\
{K_11n_161, KADT_K_11n_161},\
{K_11n_162, KADT_K_11n_162},\
{K_11n_163, KADT_K_11n_163},\
{K_11n_164, KADT_K_11n_164},\
{K_11n_165, KADT_K_11n_165},\
{K_11n_166, KADT_K_11n_166},\
{K_11n_167, KADT_K_11n_167},\
{K_11n_168, KADT_K_11n_168},\
{K_11n_169, KADT_K_11n_169},\
{K_11n_170, KADT_K_11n_170},\
{K_11n_171, KADT_K_11n_171},\
{K_11n_172, KADT_K_11n_172},\
{K_11n_173, KADT_K_11n_173},\
{K_11n_174, KADT_K_11n_174},\
{K_11n_175, KADT_K_11n_175},\
{K_11n_176, KADT_K_11n_176},\
{K_11n_177, KADT_K_11n_177},\
{K_11n_178, KADT_K_11n_178},\
{K_11n_179, KADT_K_11n_179},\
{K_11n_180, KADT_K_11n_180},\
{K_11n_181, KADT_K_11n_181},\
{K_11n_182, KADT_K_11n_182},\
{K_11n_183, KADT_K_11n_183},\
{K_11n_184, KADT_K_11n_184},\
{K_11n_185, KADT_K_11n_185},\
{K_3_1X3_1, KADT_K_3_1X3_1},\
{K_3_1X4_1, KADT_K_3_1X4_1},\
{K_3_1X5_1, KADT_K_3_1X5_1},\
{K_3_1X5_2, KADT_K_3_1X5_2},\
{K_3_1X6_1, KADT_K_3_1X6_1},\
{K_3_1X6_2, KADT_K_3_1X6_2},\
{K_3_1X6_3, KADT_K_3_1X6_3},\
{K_3_1X7_1, KADT_K_3_1X7_1},\
{K_3_1X7_2, KADT_K_3_1X7_2},\
{K_3_1X7_3, KADT_K_3_1X7_3},\
{K_3_1X7_4, KADT_K_3_1X7_4},\
{K_3_1X7_5, KADT_K_3_1X7_5},\
{K_3_1X7_6, KADT_K_3_1X7_6},\
{K_4_1X4_1, KADT_K_4_1X4_1},\
{K_4_1X5_1, KADT_K_4_1X5_1},\
{K_4_1X5_2, KADT_K_4_1X5_2},\
{K_4_1X6_1, KADT_K_4_1X6_1},\
{K_4_1X6_2, KADT_K_4_1X6_2},\
{K_4_1X6_3, KADT_K_4_1X6_3},\
{K_4_1X7_1, KADT_K_4_1X7_1},\
{K_4_1X7_2, KADT_K_4_1X7_2},\
{K_4_1X7_3, KADT_K_4_1X7_3},\
{K_4_1X7_4, KADT_K_4_1X7_4},\
{K_4_1X7_5, KADT_K_4_1X7_5},\
{K_4_1X7_6, KADT_K_4_1X7_6},\
{K_5_1X5_1, KADT_K_5_1X5_1},\
{K_5_1X5_2, KADT_K_5_1X5_2},\
{K_5_1X6_1, KADT_K_5_1X6_1},\
{K_5_1X6_2, KADT_K_5_1X6_2},\
{K_5_1X6_3, KADT_K_5_1X6_3},\
{K_5_1X7_1, KADT_K_5_1X7_1},\
{K_5_1X7_2, KADT_K_5_1X7_2},\
{K_5_1X7_3, KADT_K_5_1X7_3},\
{K_5_1X7_4, KADT_K_5_1X7_4},\
{K_5_1X7_5, KADT_K_5_1X7_5},\
{K_5_1X7_6, KADT_K_5_1X7_6},\
{K_5_2X5_2, KADT_K_5_2X5_2},\
{K_5_2X6_1, KADT_K_5_2X6_1},\
{K_5_2X6_2, KADT_K_5_2X6_2},\
{K_5_2X6_3, KADT_K_5_2X6_3},\
{K_5_2X7_1, KADT_K_5_2X7_1},\
{K_5_2X7_2, KADT_K_5_2X7_2},\
{K_5_2X7_3, KADT_K_5_2X7_3},\
{K_5_2X7_4, KADT_K_5_2X7_4},\
{K_5_2X7_5, KADT_K_5_2X7_5},\
{K_5_2X7_6, KADT_K_5_2X7_6},\
{K_6_1X6_1, KADT_K_6_1X6_1},\
{K_6_1X6_2, KADT_K_6_1X6_2},\
{K_6_1X6_3, KADT_K_6_1X6_3},\
{K_6_1X7_1, KADT_K_6_1X7_1},\
{K_6_1X7_2, KADT_K_6_1X7_2},\
{K_6_1X7_3, KADT_K_6_1X7_3},\
{K_6_1X7_4, KADT_K_6_1X7_4},\
{K_6_1X7_5, KADT_K_6_1X7_5},\
{K_6_1X7_6, KADT_K_6_1X7_6},\
{K_6_2X6_2, KADT_K_6_2X6_2},\
{K_6_2X6_3, KADT_K_6_2X6_3},\
{K_6_2X7_1, KADT_K_6_2X7_1},\
{K_6_2X7_2, KADT_K_6_2X7_2},\
{K_6_2X7_3, KADT_K_6_2X7_3},\
{K_6_2X7_4, KADT_K_6_2X7_4},\
{K_6_2X7_5, KADT_K_6_2X7_5},\
{K_6_2X7_6, KADT_K_6_2X7_6},\
{K_6_3X6_3, KADT_K_6_3X6_3},\
{K_6_3X7_1, KADT_K_6_3X7_1},\
{K_6_3X7_2, KADT_K_6_3X7_2},\
{K_6_3X7_3, KADT_K_6_3X7_3},\
{K_6_3X7_4, KADT_K_6_3X7_4},\
{K_6_3X7_5, KADT_K_6_3X7_5},\
{K_6_3X7_6, KADT_K_6_3X7_6},\
{K_7_1X7_1, KADT_K_7_1X7_1},\
{K_7_1X7_2, KADT_K_7_1X7_2},\
{K_7_1X7_3, KADT_K_7_1X7_3},\
{K_7_1X7_4, KADT_K_7_1X7_4},\
{K_7_1X7_5, KADT_K_7_1X7_5},\
{K_7_1X7_6, KADT_K_7_1X7_6},\
{K_7_2X7_2, KADT_K_7_2X7_2},\
{K_7_2X7_3, KADT_K_7_2X7_3},\
{K_7_2X7_4, KADT_K_7_2X7_4},\
{K_7_2X7_5, KADT_K_7_2X7_5},\
{K_7_2X7_6, KADT_K_7_2X7_6},\
{K_7_3X7_3, KADT_K_7_3X7_3},\
{K_7_3X7_4, KADT_K_7_3X7_4},\
{K_7_3X7_5, KADT_K_7_3X7_5},\
{K_7_3X7_6, KADT_K_7_3X7_6},\
{K_7_4X7_4, KADT_K_7_4X7_4},\
{K_7_4X7_5, KADT_K_7_4X7_5},\
{K_7_4X7_6, KADT_K_7_4X7_6},\
{K_7_5X7_5, KADT_K_7_5X7_5},\
{K_7_5X7_6, KADT_K_7_5X7_6},\
{K_7_6X7_6,KADT_K_7_6X7_6}}

#define ROLFSEN_TABLE {\
"UN",\
"3_1",\
"4_1",\
"5_1",\
"5_2",\
"6_1",\
"6_2",\
"6_3",\
"7_1",\
"7_2",\
"7_3",\
"7_4",\
"7_5",\
"7_6",\
"7_7",\
"8_1",\
"8_2",\
"8_3",\
"8_4",\
"8_5",\
"8_6",\
"8_7",\
"8_8",\
"8_9",\
"8_10",\
"8_11",\
"8_12",\
"8_13",\
"8_14",\
"8_15",\
"8_16",\
"8_17",\
"8_18",\
"8_19",\
"8_20",\
"8_21",\
"9_1",\
"9_2",\
"9_3",\
"9_4",\
"9_5",\
"9_6",\
"9_7",\
"9_8",\
"9_9",\
"9_10",\
"9_11",\
"9_12",\
"9_13",\
"9_14",\
"9_15",\
"9_16",\
"9_17",\
"9_18",\
"9_19",\
"9_20",\
"9_21",\
"9_22",\
"9_23",\
"9_24",\
"9_25",\
"9_26",\
"9_27",\
"9_28",\
"9_29",\
"9_30",\
"9_31",\
"9_32",\
"9_33",\
"9_34",\
"9_35",\
"9_36",\
"9_37",\
"9_38",\
"9_39",\
"9_40",\
"9_41",\
"9_42",\
"9_43",\
"9_44",\
"9_45",\
"9_46",\
"9_47",\
"9_48",\
"9_49",\
"10_1",\
"10_2",\
"10_3",\
"10_4",\
"10_5",\
"10_6",\
"10_7",\
"10_8",\
"10_9",\
"10_10",\
"10_11",\
"10_12",\
"10_13",\
"10_14",\
"10_15",\
"10_16",\
"10_17",\
"10_18",\
"10_19",\
"10_20",\
"10_21",\
"10_22",\
"10_23",\
"10_24",\
"10_25",\
"10_26",\
"10_27",\
"10_28",\
"10_29",\
"10_30",\
"10_31",\
"10_32",\
"10_33",\
"10_34",\
"10_35",\
"10_36",\
"10_37",\
"10_38",\
"10_39",\
"10_40",\
"10_41",\
"10_42",\
"10_43",\
"10_44",\
"10_45",\
"10_46",\
"10_47",\
"10_48",\
"10_49",\
"10_50",\
"10_51",\
"10_52",\
"10_53",\
"10_54",\
"10_55",\
"10_56",\
"10_57",\
"10_58",\
"10_59",\
"10_60",\
"10_61",\
"10_62",\
"10_63",\
"10_64",\
"10_65",\
"10_66",\
"10_67",\
"10_68",\
"10_69",\
"10_70",\
"10_71",\
"10_72",\
"10_73",\
"10_74",\
"10_75",\
"10_76",\
"10_77",\
"10_78",\
"10_79",\
"10_80",\
"10_81",\
"10_82",\
"10_83",\
"10_84",\
"10_85",\
"10_86",\
"10_87",\
"10_88",\
"10_89",\
"10_90",\
"10_91",\
"10_92",\
"10_93",\
"10_94",\
"10_95",\
"10_96",\
"10_97",\
"10_98",\
"10_99",\
"10_100",\
"10_101",\
"10_102",\
"10_103",\
"10_104",\
"10_105",\
"10_106",\
"10_107",\
"10_108",\
"10_109",\
"10_110",\
"10_111",\
"10_112",\
"10_113",\
"10_114",\
"10_115",\
"10_116",\
"10_117",\
"10_118",\
"10_119",\
"10_120",\
"10_121",\
"10_122",\
"10_123",\
"10_124",\
"10_125",\
"10_126",\
"10_127",\
"10_128",\
"10_129",\
"10_130",\
"10_131",\
"10_132",\
"10_133",\
"10_134",\
"10_135",\
"10_136",\
"10_137",\
"10_138",\
"10_139",\
"10_140",\
"10_141",\
"10_142",\
"10_143",\
"10_144",\
"10_145",\
"10_146",\
"10_147",\
"10_148",\
"10_149",\
"10_150",\
"10_151",\
"10_152",\
"10_153",\
"10_154",\
"10_155",\
"10_156",\
"10_157",\
"10_158",\
"10_159",\
"10_160",\
"10_161",\
"10_162",\
"10_163",\
"10_164",\
"10_165",\
"11a_1",\
"11a_2",\
"11a_3",\
"11a_4",\
"11a_5",\
"11a_6",\
"11a_7",\
"11a_8",\
"11a_9",\
"11a_10",\
"11a_11",\
"11a_12",\
"11a_13",\
"11a_14",\
"11a_15",\
"11a_16",\
"11a_17",\
"11a_18",\
"11a_19",\
"11a_20",\
"11a_21",\
"11a_22",\
"11a_23",\
"11a_24",\
"11a_25",\
"11a_26",\
"11a_27",\
"11a_28",\
"11a_29",\
"11a_30",\
"11a_31",\
"11a_32",\
"11a_33",\
"11a_34",\
"11a_35",\
"11a_36",\
"11a_37",\
"11a_38",\
"11a_39",\
"11a_40",\
"11a_41",\
"11a_42",\
"11a_43",\
"11a_44",\
"11a_45",\
"11a_46",\
"11a_47",\
"11a_48",\
"11a_49",\
"11a_50",\
"11a_51",\
"11a_52",\
"11a_53",\
"11a_54",\
"11a_55",\
"11a_56",\
"11a_57",\
"11a_58",\
"11a_59",\
"11a_60",\
"11a_61",\
"11a_62",\
"11a_63",\
"11a_64",\
"11a_65",\
"11a_66",\
"11a_67",\
"11a_68",\
"11a_69",\
"11a_70",\
"11a_71",\
"11a_72",\
"11a_73",\
"11a_74",\
"11a_75",\
"11a_76",\
"11a_77",\
"11a_78",\
"11a_79",\
"11a_80",\
"11a_81",\
"11a_82",\
"11a_83",\
"11a_84",\
"11a_85",\
"11a_86",\
"11a_87",\
"11a_88",\
"11a_89",\
"11a_90",\
"11a_91",\
"11a_92",\
"11a_93",\
"11a_94",\
"11a_95",\
"11a_96",\
"11a_97",\
"11a_98",\
"11a_99",\
"11a_100",\
"11a_101",\
"11a_102",\
"11a_103",\
"11a_104",\
"11a_105",\
"11a_106",\
"11a_107",\
"11a_108",\
"11a_109",\
"11a_110",\
"11a_111",\
"11a_112",\
"11a_113",\
"11a_114",\
"11a_115",\
"11a_116",\
"11a_117",\
"11a_118",\
"11a_119",\
"11a_120",\
"11a_121",\
"11a_122",\
"11a_123",\
"11a_124",\
"11a_125",\
"11a_126",\
"11a_127",\
"11a_128",\
"11a_129",\
"11a_130",\
"11a_131",\
"11a_132",\
"11a_133",\
"11a_134",\
"11a_135",\
"11a_136",\
"11a_137",\
"11a_138",\
"11a_139",\
"11a_140",\
"11a_141",\
"11a_142",\
"11a_143",\
"11a_144",\
"11a_145",\
"11a_146",\
"11a_147",\
"11a_148",\
"11a_149",\
"11a_150",\
"11a_151",\
"11a_152",\
"11a_153",\
"11a_154",\
"11a_155",\
"11a_156",\
"11a_157",\
"11a_158",\
"11a_159",\
"11a_160",\
"11a_161",\
"11a_162",\
"11a_163",\
"11a_164",\
"11a_165",\
"11a_166",\
"11a_167",\
"11a_168",\
"11a_169",\
"11a_170",\
"11a_171",\
"11a_172",\
"11a_173",\
"11a_174",\
"11a_175",\
"11a_176",\
"11a_177",\
"11a_178",\
"11a_179",\
"11a_180",\
"11a_181",\
"11a_182",\
"11a_183",\
"11a_184",\
"11a_185",\
"11a_186",\
"11a_187",\
"11a_188",\
"11a_189",\
"11a_190",\
"11a_191",\
"11a_192",\
"11a_193",\
"11a_194",\
"11a_195",\
"11a_196",\
"11a_197",\
"11a_198",\
"11a_199",\
"11a_200",\
"11a_201",\
"11a_202",\
"11a_203",\
"11a_204",\
"11a_205",\
"11a_206",\
"11a_207",\
"11a_208",\
"11a_209",\
"11a_210",\
"11a_211",\
"11a_212",\
"11a_213",\
"11a_214",\
"11a_215",\
"11a_216",\
"11a_217",\
"11a_218",\
"11a_219",\
"11a_220",\
"11a_221",\
"11a_222",\
"11a_223",\
"11a_224",\
"11a_225",\
"11a_226",\
"11a_227",\
"11a_228",\
"11a_229",\
"11a_230",\
"11a_231",\
"11a_232",\
"11a_233",\
"11a_234",\
"11a_235",\
"11a_236",\
"11a_237",\
"11a_238",\
"11a_239",\
"11a_240",\
"11a_241",\
"11a_242",\
"11a_243",\
"11a_244",\
"11a_245",\
"11a_246",\
"11a_247",\
"11a_248",\
"11a_249",\
"11a_250",\
"11a_251",\
"11a_252",\
"11a_253",\
"11a_254",\
"11a_255",\
"11a_256",\
"11a_257",\
"11a_258",\
"11a_259",\
"11a_260",\
"11a_261",\
"11a_262",\
"11a_263",\
"11a_264",\
"11a_265",\
"11a_266",\
"11a_267",\
"11a_268",\
"11a_269",\
"11a_270",\
"11a_271",\
"11a_272",\
"11a_273",\
"11a_274",\
"11a_275",\
"11a_276",\
"11a_277",\
"11a_278",\
"11a_279",\
"11a_280",\
"11a_281",\
"11a_282",\
"11a_283",\
"11a_284",\
"11a_285",\
"11a_286",\
"11a_287",\
"11a_288",\
"11a_289",\
"11a_290",\
"11a_291",\
"11a_292",\
"11a_293",\
"11a_294",\
"11a_295",\
"11a_296",\
"11a_297",\
"11a_298",\
"11a_299",\
"11a_300",\
"11a_301",\
"11a_302",\
"11a_303",\
"11a_304",\
"11a_305",\
"11a_306",\
"11a_307",\
"11a_308",\
"11a_309",\
"11a_310",\
"11a_311",\
"11a_312",\
"11a_313",\
"11a_314",\
"11a_315",\
"11a_316",\
"11a_317",\
"11a_318",\
"11a_319",\
"11a_320",\
"11a_321",\
"11a_322",\
"11a_323",\
"11a_324",\
"11a_325",\
"11a_326",\
"11a_327",\
"11a_328",\
"11a_329",\
"11a_330",\
"11a_331",\
"11a_332",\
"11a_333",\
"11a_334",\
"11a_335",\
"11a_336",\
"11a_337",\
"11a_338",\
"11a_339",\
"11a_340",\
"11a_341",\
"11a_342",\
"11a_343",\
"11a_344",\
"11a_345",\
"11a_346",\
"11a_347",\
"11a_348",\
"11a_349",\
"11a_350",\
"11a_351",\
"11a_352",\
"11a_353",\
"11a_354",\
"11a_355",\
"11a_356",\
"11a_357",\
"11a_358",\
"11a_359",\
"11a_360",\
"11a_361",\
"11a_362",\
"11a_363",\
"11a_364",\
"11a_365",\
"11a_366",\
"11a_367",\
"11n_1",\
"11n_2",\
"11n_3",\
"11n_4",\
"11n_5",\
"11n_6",\
"11n_7",\
"11n_8",\
"11n_9",\
"11n_10",\
"11n_11",\
"11n_12",\
"11n_13",\
"11n_14",\
"11n_15",\
"11n_16",\
"11n_17",\
"11n_18",\
"11n_19",\
"11n_20",\
"11n_21",\
"11n_22",\
"11n_23",\
"11n_24",\
"11n_25",\
"11n_26",\
"11n_27",\
"11n_28",\
"11n_29",\
"11n_30",\
"11n_31",\
"11n_32",\
"11n_33",\
"11n_34",\
"11n_35",\
"11n_36",\
"11n_37",\
"11n_38",\
"11n_39",\
"11n_40",\
"11n_41",\
"11n_42",\
"11n_43",\
"11n_44",\
"11n_45",\
"11n_46",\
"11n_47",\
"11n_48",\
"11n_49",\
"11n_50",\
"11n_51",\
"11n_52",\
"11n_53",\
"11n_54",\
"11n_55",\
"11n_56",\
"11n_57",\
"11n_58",\
"11n_59",\
"11n_60",\
"11n_61",\
"11n_62",\
"11n_63",\
"11n_64",\
"11n_65",\
"11n_66",\
"11n_67",\
"11n_68",\
"11n_69",\
"11n_70",\
"11n_71",\
"11n_72",\
"11n_73",\
"11n_74",\
"11n_75",\
"11n_76",\
"11n_77",\
"11n_78",\
"11n_79",\
"11n_80",\
"11n_81",\
"11n_82",\
"11n_83",\
"11n_84",\
"11n_85",\
"11n_86",\
"11n_87",\
"11n_88",\
"11n_89",\
"11n_90",\
"11n_91",\
"11n_92",\
"11n_93",\
"11n_94",\
"11n_95",\
"11n_96",\
"11n_97",\
"11n_98",\
"11n_99",\
"11n_100",\
"11n_101",\
"11n_102",\
"11n_103",\
"11n_104",\
"11n_105",\
"11n_106",\
"11n_107",\
"11n_108",\
"11n_109",\
"11n_110",\
"11n_111",\
"11n_112",\
"11n_113",\
"11n_114",\
"11n_115",\
"11n_116",\
"11n_117",\
"11n_118",\
"11n_119",\
"11n_120",\
"11n_121",\
"11n_122",\
"11n_123",\
"11n_124",\
"11n_125",\
"11n_126",\
"11n_127",\
"11n_128",\
"11n_129",\
"11n_130",\
"11n_131",\
"11n_132",\
"11n_133",\
"11n_134",\
"11n_135",\
"11n_136",\
"11n_137",\
"11n_138",\
"11n_139",\
"11n_140",\
"11n_141",\
"11n_142",\
"11n_143",\
"11n_144",\
"11n_145",\
"11n_146",\
"11n_147",\
"11n_148",\
"11n_149",\
"11n_150",\
"11n_151",\
"11n_152",\
"11n_153",\
"11n_154",\
"11n_155",\
"11n_156",\
"11n_157",\
"11n_158",\
"11n_159",\
"11n_160",\
"11n_161",\
"11n_162",\
"11n_163",\
"11n_164",\
"11n_165",\
"11n_166",\
"11n_167",\
"11n_168",\
"11n_169",\
"11n_170",\
"11n_171",\
"11n_172",\
"11n_173",\
"11n_174",\
"11n_175",\
"11n_176",\
"11n_177",\
"11n_178",\
"11n_179",\
"11n_180",\
"11n_181",\
"11n_182",\
"11n_183",\
"11n_184",\
"11n_185",\
"3_1#3_1",\
"3_1#4_1",\
"3_1#5_1",\
"3_1#5_2",\
"3_1#6_1",\
"3_1#6_2",\
"3_1#6_3",\
"3_1#7_1",\
"3_1#7_2",\
"3_1#7_3",\
"3_1#7_4",\
"3_1#7_5",\
"3_1#7_6",\
"4_1#4_1",\
"4_1#5_1",\
"4_1#5_2",\
"4_1#6_1",\
"4_1#6_2",\
"4_1#6_3",\
"4_1#7_1",\
"4_1#7_2",\
"4_1#7_3",\
"4_1#7_4",\
"4_1#7_5",\
"4_1#7_6",\
"5_1#5_1",\
"5_1#5_2",\
"5_1#6_1",\
"5_1#6_2",\
"5_1#6_3",\
"5_1#7_1",\
"5_1#7_2",\
"5_1#7_3",\
"5_1#7_4",\
"5_1#7_5",\
"5_1#7_6",\
"5_2#5_2",\
"5_2#6_1",\
"5_2#6_2",\
"5_2#6_3",\
"5_2#7_1",\
"5_2#7_2",\
"5_2#7_3",\
"5_2#7_4",\
"5_2#7_5",\
"5_2#7_6",\
"6_1#6_1",\
"6_1#6_2",\
"6_1#6_3",\
"6_1#7_1",\
"6_1#7_2",\
"6_1#7_3",\
"6_1#7_4",\
"6_1#7_5",\
"6_1#7_6",\
"6_2#6_2",\
"6_2#6_3",\
"6_2#7_1",\
"6_2#7_2",\
"6_2#7_3",\
"6_2#7_4",\
"6_2#7_5",\
"6_2#7_6",\
"6_3#6_3",\
"6_3#7_1",\
"6_3#7_2",\
"6_3#7_3",\
"6_3#7_4",\
"6_3#7_5",\
"6_3#7_6",\
"7_1#7_1",\
"7_1#7_2",\
"7_1#7_3",\
"7_1#7_4",\
"7_1#7_5",\
"7_1#7_6",\
"7_2#7_2",\
"7_2#7_3",\
"7_2#7_4",\
"7_2#7_5",\
"7_2#7_6",\
"7_3#7_3",\
"7_3#7_4",\
"7_3#7_5",\
"7_3#7_6",\
"7_4#7_4",\
"7_4#7_5",\
"7_4#7_6",\
"7_5#7_5",\
"7_5#7_6",\
"7_6X7_6"}
#endif
