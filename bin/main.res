        ��  ��                  �  ,   �� D E F A U L T       0	        <!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
    <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    </head>
    <style>
		body,ul,ol,dl,dd,li,div,h1,h2,h3,th,strong{margin:0;padding:0;list-style:none;font-size:12px; font-weight:normal}
    	//body,legend{color:#000;background:#edeae4}/*background:transparent*/
		table,th,td{ border-collapse:collapse;}
		.search{flow:horizontal}
		.search fieldset{margin-left:1%;}
		.main{padding:5px 10px;}
		input{}
		
		.body{flow:horizontal-flow;margin-top:10px; height:1*;background:#FFF;}
		dt,th{ height:16px; background:url(allbg.png) repeat-x 0 0;border-bottom:1px solid #c2bfb8}
		dt{ text-align:center;}
		dl{ border:1px solid #7b7b78;margin-left:0 1%}
		dl.left{width:20%;}
        dl li {height:20px; color:#006699;vertical-align:middle;padding:3px;text-indent:10px; cursor:pointer
            background:url(allbg.png) repeat-x 0 0;
        }
		dl li:hover{ background:#EFEFEF;behavior:clickable;}
		//dl dd{ background:#FFF; }
		
		table{width:100%;}
		//td{ background:#fff; border:1px solid #EFEFEF; }

    html 
	{ 
		font:10pt Verdana; 
		overflow:hidden;
		background-color:transparent;
		//background-color:#ccc;
		background-image:url(back.png);
		background-repeat:expand;
		background-position:15 15 15 15;
	}
	body 
	{ 
		padding:3px;
		margin:0;
		width:100%%; 
		height:100%%; 
	}
    #topbar widget[type="button"] 
	{
		width:1em;
		height:1em;
		background-image:none;
		padding:1px;
		font-family: marlett;
		font-size:10pt;
		color: #274749;
		border:1px solid #B0CFD1;
		text-align:center;
		vertical-align:center;
		margin:0;
		
	}
	#topbar widget[type="button"]:hover 
	{
		color:orange;
		border-color:orange;
		background-color:#B0CFD1;
		outline:2px glow orange 4px;
	} 
	#topbar widget[type="button"]:active 
	{
		background-color:#274749;
	} 

	#topbar #minimize,
	#topbar #maximize { margin-right:2px; } 

	#topbar #icon 
	{
		foreground-image:url(back.png);
		foreground-repeat:no-repeat;
		foreground-position:50% 50%;
	}
	#topbar
	{
		flow:horizontal;
		margin-bottom:3px;
	}

	#topbar #caption 
	{
		//color: #274749;
		color: black;
		padding:0 4px;
		outline:3px glow #274749;
	}
    #bottombar 
	{
		margin-top:3px;
		flow:horizontal;
	}

	#bottombar #corner
	{
	    margin-top:100%%;
		font-family: marlett;
		font-size:10pt;
		color: #274749;
		width:min-intrinsic;
	}

	#bottombar #status
	{
		color: #274749;
		font-size:9pt;
	}
    </style>
    <body>
    <div id="topbar">
		<widget id="icon" type="button"></widget>
		<div id="caption"></div>
		<widget id="minimize" type="button">0</widget>
		<widget id="maximize" type="button">1</widget>
		<widget id="close" type="button" title="Guess what is this button doing?">r</widget>
	</div>

        <div .main>
            <div .head>
                <ul .search>
					<fieldset>
                    	<legend>ssss</legend>
                       	<input type="text"> 
                    </fieldset>
					<fieldset>
                    	<legend>ssss</legend>
						<input type="radio" name="searchtype" value="1">
                        <label>精确</label>
                        <input type="radio" name="searchtype" value="2">
                        <label>模糊</label>
                    </fieldset>
                    <fieldset>
                    	<legend>ssss</legend>
                       	<input type="text"> 
                    </fieldset>
                    <fieldset>
                    	<legend>ssss</legend>
                       	<input type="text"> 
                    </fieldset>
                    <fieldset>
                    	<legend>ssss</legend>
                       	<input type="text"> 
                    </fieldset>
                </ul>
            </div>

            <div .body>
            	<dl .left>
                	<dt>ROOT</dt>
                    <dd idd="333333">
                    	<ul>
                        	<li idd="1">C++</li>
                            <li idd="2">MFC</li>
                        </ul>
                    </dd>
                </dl>
            	<dl .right>
                	<table cellspacing="0">
                    	<tr>
                        	<th width="1%%">LIST</th>
                            <th>MEAN</th>
                        </tr>	
                        <tbody>
                        	<tr>
                                <td>
                                1111
                                </td>
                                <td>
                                1111
                                </td>
                            </tr>
                            <tr>
                                <td>
                                1111
                                </td>
                                <td>
                                1111
                                </td>
                            </tr>
                            <tr>
                                <td>
                                1111
                                </td>
                                <td>
                                1111
                                </td>
                            </tr>
                        </tbody>
                        
                    </table>
                </dl>
            </div>
        </div>
    </body>


</html>
        �� ���     0 	        <html>
	<head>
	<title>About this Demo</title>
	<style>
html { 
       margin:0; 
	   padding:0; 
       overflow:hidden; /* no scrolbars at all */
	   width:min-intrinsic; height:min-intrinsic; /* but dimensions of the content */
	 }
body { margin:0; padding:0; height:*; }

div.content 
{ 
	padding:8px; 
	text-align:center;
	background-color: infobackground window window infobackground;
}
h1 { font: 12pt bold Verdana; white-space:nowrap; }
p { font: 10pt bold Verdana; white-space:nowrap; }
div.footer 
{ 
	padding:8px; 
	text-align:center;
	border-top:1px solid threedshadow;
	background-color: threedface;
}
	</style>
	</head>
	<body>
	<div class="content">
		<h1>HTMLayout Demo Application</h1> 
		<p>&copy; Terra Informatica Software, 2004-2006</p>
		<p><a href="http://terrainformatica.com">www.terrainformatica.com</a></p>
	</div>
	<div class="footer">
		<button name="OK" role="default-button">OK</button>
		<button name="CANCEL" role="cancel-button">Cancel</button>
	</div>
	</body>
</html>
   �      �� ���     0 	        <html>
	<head>
    	<title>ROOT</title>
    	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8"> 
        <style>
		*{margin:0;padding:0;}
		html { 
		   margin:0; 
		   padding:0; 
		   overflow:hidden; /* no scrolbars at all */
		   width:min-intrinsic; height:min-intrinsic; /* but dimensions of the content */
		   background-color: infobackground window window infobackground;
		 }
		input {
			width: 80%%;
			padding:5px 0 4px 0;	
		}
		input[type="text"]{
			font-family: Helvetica,Arial,Tahoma,sans-serif;
			height: 17px;
			border: 1px solid #ccc;
			margin: 0;
			//padding: 1px 2px;
			background-color: white;
			color: #333;
			font-size: 13px;
			vertical-align:middle;
			border-radius: 1px;
			outline: 0 1px 2px rgba(0,0,0,0.2);
			transition: border .3s ease-in;	
			padding-left:5px;
			
		}	
		.input-prepend {
			//display:inline-block;
			background-color: #eee;
			height: 24px;
			padding: 5px 8px;
			border: 1px solid #ccc;
			vertical-align:middle;
		}
		.main{
			padding:10%% 0 0 10%%;
			min-width:200px;
			outline:8px glow lightred 2px; 
		}
		
        </style>
    </head>
	<body>
    	<div .main>
        	<label for="author"><span class="input-prepend">昵称</span></label><input type="text">
        </div>
        <br>
	
    <!--	<input class="comt-submit" name="submit" type="submit" id="submit" tabindex="5" value="发布评论"> -->




		
        
    </body>
</html>    @   P N G   B I G - R E D - B U T T O N         0	        �PNG

   IHDR   T   T   k�   	pHYs  �  ��o�d  �IDATx��y�՝�]G_��3=���0��0�	1�qpCpl68l�p�BP�\b���?�E9�(	"�@X�/��- eCV�,f� �s<��ꫪ����zտz�����H�IO�]]Sǧ�����_��v���9�u�늘���#pՉlay�����%�D>�J��aDL�KZ�y�0�z��V9r b��������{b䬽+�|������Tת��ϏLfoJ���������n���$t���P2HcK�r��ϐ6oL�a�D���]Q�뒄������99�C0k����|�=��)|�'��}eo�=���W˿�f"[�@.���k�©Yx��4��T�H���K�����n�g�n%�@>g6@}sV�n�q�����쇶D̽�i�������i5͂��K���7g�oS���$<����(C��xέ�@����{�.Oo[� I>�0� K��JP
-@�V����<��,<=�M]���������5v�T��m=[�~x�{V.���2�m�rse_�i��|hujn�V+��Zf
��kyxy�8Ҧ�]�>/��jvêm�5
4�nɂ�+v^��-k�T"^����80��������x��.�~x� �ԍ��(�C�N~���%VlӬn���..���_�q�����r��r* u|�  �0~����V�]�F�3G�K��I8e��1�M1��?�~�烊"=��;7w��o!�%�DoU-/e{��tH�i�8�);RY�7C�M��,��N0��g&`�p
���	�s��7n5ݼ�ϴ%�=v׍�Lk�Ga�P),ՆJ?+hi)X)����A�f�
X_~ H@��(j����l�,��e�up�w�ؚ�n\��ˋ3�/>z�Ƙ�W@�H�X�P��Wf5u2��L�ʒ�}3��t9�?w�L�^G���>�B���B����h���o�J�hE�V��U��U��e��b�Ԙ:�,,Hn��}��Ү1X=����r�R]{�:��z��K�����cc܂��I�V��a��}'����&��"��.. �s]z�d?[���QXכ��o��T�jr��@o�x\��q��oJF�qww��G����p0-�~��$N�p���D�mFT�[���Q�..���̢ˮj5�r�E~�';���՞�vq�T�R�wE���`z���t�D�W���lV��89��iP����F�� ���ݰ���{�}Ǫ5����cJU��J
�JT��o��aA�A�.r�%ZIBz��<��1�5U}�޲l�������W�$��g�?u��u}>����_Y$��睭 O�CoJ��Gp
��PC��|��'c������D"QQ������a�m�uEv���+9�<T�3CeA�+8����c�Oo������@���Ɩ����-��$�N���R�SV�U�N~h�+k����49�QR		b���T��P�~I��t����$� ��r'�|�Wc�%YB4�nD��|S,IpC$.�U�.��+�/L��~�p��2��W͊<l_���m+�]տ �h�wga��'���Bvq�C)���;���i�E��Rބ(YFf]*e�ZO�(��T�c;V]R�nT#����nj̭L^����@\�r2Q��o'����`+�HN���T�n�*U�;�9p�PW&U�Ʉ�x��mX�"��HUC��
b >G�	N�9���m��6nxb�ry/j7���1�BON�>�����-М��o�}��o
�s��,>������
%� ��Ȕ�U*�=�9
]�Օ���Po&�·?�j��.��RJ?S�e��㶭>G�uت@�6@bgL��-
�fuK�L��͌6�R��җ��~~���x��	y��>�b`�:)\���u����6�����l�2#��Y92�ݼ钅�G��a�w�u�"5�苷�m=ճj�X�m� dKp���H�ʠ
����Ec�@{�����u��'��9MQ�R���g@�h�;������Q�a�i�d�X,�b���J�p'K�_]��q:�&�
�Y����k�r+�C6�~y��|^_l=1h�,��V)kvu�t"W�ax^k�&p~ 1L��X�@�ѣ_� ���F���*6��	Xc��m^2��t:�]I'ny.��Vp�U�L<`��WT�<�����:'A���bC��+2�_T�X`r��z"[ʴ��N���@�:�����œ�}`7�j��o���d�S�s@q�� ���TA_���8�H����H���'=�7��	���a�ǽ�>@��^�dڀy����^�J�*���$�ju4E�$=�ǿ��qM ��`�W����Gi����~R4/Pr�$�DɆ�A:�T��xk\����sϔ��:�+�^�5���"�z��+��6�%�At���A��8�] �;�N\q=��cb.�on(��[��O$�p�eL����4�ҩ �/2 uZcv�NGh�� a��.�>��1�az�Z@���}%��<H?ebu���A�?�N�R���
sY?�U;P����P�Q%6L�_iw")�Z��\��,P�ߴo޷
] �́�����2�Y@�RI7t��R���4]T��ȩ�Up��)tD*��Y>��Uj�om �Ai+T4�J�F&stp@=S�y�>�t=D Ł)�Jkq%N�l�6B��
���;.��?>�z�-. �����T��d%h�k4B�U���V���R޾��
�ĳSh����gr��O��S�@�di�H���0�.�R�R1䰾�;�#�1�`-S��1���N䈷�#�]��DQݷ�\����JE�԰yk���Wg�ܗ���O<x"��{Ͼy���$9�vaw�M��KLᅙ��l8��^Xʿ%"juڱ��:a�%�y�RkU������>@q����`�-��*�SLAЪ��G�G�����"O=ulf�'S���""��R�Ty$��=7��V)?��ԓJ��*�s#��' ����60]@��]���;����c�)4�9�h^��w�Ex?���)L}D*��@�M:g}v�>О=7gȱ�&-O��<c�Y{��Q�sc0�i�ypd:���������Jt~����~�SPQ�V����4`#yk��������˻*)�3�6�3����� P��PQp�G?�N�y�ٰJ�3�������c G�0��j
��U�fCu����f�����=�����c��C�3��Q�((��i�)�"9������ք1f�1��N?�lЎy�ڭ�3c���T�xO+U�xt��ˍ\��X�:�F>���3�o&�GN�._�]����h*�,@�E\������Hg�]�L�j���"|P
�#}#*m��bȵ{a�Oeu�L�Q5��D�T������kӑΓ�]W��gD�A�H�X�&�G���E*��5���5y{��~w(/��%���Be
�0=]�w��Ui8��reaO��U�:q��>�2t�D�0*m���������i��(8�ά݊  ��+�-O����̏�M��"q�9�.U+��auwA9O�)`u7����`�S��[M�=��5�N�}�7�<#�q��\�Њ��x�Q�_��K����Wa=��1F5��( ���I�ZM/��c�(������vy۔�����K�w�M����=���{�#�9~�<��&Dp�$���a��It.(�[4b q j(���-�+��CKv�y�h���d�;�,(���9�I���}��y3'�O,Q�,���<��NfU�R��n�0����!����{��C-�Uz�&�$���t�繓�~�£�2Y��ˡ���̓�[d���e��a�*LP�a�f3��> :I��C`>����&��(K��&�U���<����3�l�$4ԭ�����sfT��hv>7	�q?S��.�|'�;}#;��@�����&��O�{o������m���U(�����N�.�g�%�|����x{uK�%x��!Hҹ��F+�? �����4�7�3���%[����jJ��R]��K���S=���(�v6�g>x�Nh�Y.�S�d����J��a����T`�7AY�sosd'	�{�A�~�,�;�3+�ݼf���^����:��:<�.����D��i4��"�o��tф/�8��m���y�LV��9r6z�*�f|k'�7�Ýẇԝ�/��K�|'��?�ل���<�mZRXL����`֬Lf�����^��o���kp��h�`{b�;h�h���|�̴ʰ�3�#�fX�f܏4�I�Y��M�w��m]��ؤ�;!����bj3�r��a4�U%�-��{��$����$����J����辰p��D�
�2p��k%��B�t.M���A�-0h�C!�e
�Tf�$����	���n��F:j�2��_^�E�`/F���y�����S`u)W����%������F�û�"�%�$����lL�2���z���2��k3U�:&�ֱG�M����L���L��E��~ݏ��"�e��aY�ƍ)�c*e�5��5�	�ſū��5i�����yF"�L�X�l�9)&����A�ы�A@�[�Uʃ�A0ӣ�v�Spz<�Z��F��'���)3se�sLàa�"�
f�:KC=����A�c�Ih����L��z�.��`�)��/5���    IEND�B`� �  D   P N G   B I G - G R E E N - B U T T O N         0	        �PNG

   IHDR   j   P   ~�w   	pHYs  �  ��o�d  KIDATx��ߏ�F��͢RAE���P�������@%$Z�{h��HJ��w��Ƴ���q��ٯ,�.��n>7���8���|�+<`P@�>� ����5�!������f�k�O7�a��)(װ�7���L�W%�7 �%�}b[��5�\�o���.�	�����?2�!���	��]�K��n��Hna�9M�3p��=�S�J�H�z	���+��>��#�/�� ���ɗ7i騺��[X���q��9,��ri���G���e��%��]%�W�Sg(Cc[o]��_S�����k��Ã.Gҙ���Ĉՠ+�M��B���m�#ʚ��8�`@1L��S��->s�����0>�f�4<� )����&X4[�e7 ߀ō;&R{Mg����bШD/0k�f�#�� {�-��ʉ��c��T�67Ä7�r֐RMz�nt%�1��$I2�v���7��f�T����L*�Q�2���>S��н/P:�q1��0>�����l\�Z	��6B{�[�*3`�H͈)��lW	�+��ƥ�W�6A�htx�;7�.�]�aん��Yf�S:��%\:&��xK��h��އ�Cw�^J���l�$�@ɫ��(�����҉���y1�^v���$�}�D�����]F��fto�S�@e���X4�zA��	3%�?y{��g���k��'����{��"�M���ZN^ю5�p%��fc���F_6.Xn��u�Ң5l'��v�⩿����l\�5{Y>#}�&̴��ȅ���qe��N9]W�E�q����w�L{�x;.-�"����ʱ2�(���6���gL�y1�N �l�l�}ظ�G_�Lq��s�&���'m^������˻�~ܯ��9k�LC-�6�@�͚So����F�y�l\�puU(y��a����E��6��	ڰ��%��ҹ���Ed��t\H��b�\����ʛ���k4��6SRy�Pê����:�t1�� |�7G�n���}�t�7lq#��� ��>�m3�]i>�2�����q!�*j\x;�x�q9��<z��c�;:.�KE|l�2_��nГ�l\�c��Ǹ�r�#U���D��}���̧óq!c�S|%)��o�Y#5/��?�v&/�_o�/���q)�m6\>�#B��S��.`��b��bo>��$���2��'�w�w2�xc�����k\\{���,"�oCn�r�|��~����y�-l�����Dd>jk}dpV^� qW��}fG���ˤ�O���˫��Ȏ%	���<�[|���O��.�6�
_}'웋�.�+��J��;��*|��r����:,�K�aG�`%+u��fye~�_u¾���W�`�"#i����:    IEND�B`�   8  4   P N G   T O P R I G H T         0	        �PNG

   IHDR     ]   	�G   	pHYs  �  ��o�d  �IDATx��]	��0�����G��=ÍE�MH��DW�#A�$�������������no�:1���*s������� %���uh4RQ�Ah�%ro?7}���'a>BO��c��q>n�o���6M����A���F����C l�}h�R����s8_+?��?~��������F�c���\�f^����9F��գly]^��O�7%<�N���lq@4H�%��0��er�_\�=6~	��mJ�`���xFn[j#����:Ŕ+��T��YTe�����}��L�.�uڸJn����=0�u}��OH[T�v��Z�I�Z�5�8<��y�Cq�|���mu�d`����05v�1��g3/�{_O�q�w񧉇"nՑl%B�T��ed��W����"Q��aI�~�x)�R��Z;'�w"����8;��l�~<
�}J�A���8ƊrT�?�y��8N�p��^��V�����*��f��x:t��a&�������-��$㘞���F�M�u��a�����%,������eID��:Mez(��g4 ����nP@�騆�D����]s��>����Q{����B4�	�$��W�@�%}�H�	f8*�~ՓE����}��"�s�е|^��pV�~�����Ԣs���sDd4$��M�-�Q��Ѵ���(r�>ɩ����民SB[�V�����s2��J���fZ�4\�b��|�1�{e.�_o~�f���!4O��G�i�ΣpA�U0���"*�'T����ī�%gJ���3)�N^�Ӓ��!x>s(����޸�N�OĎ�G�^j~�J�Nޤ��1-�+�f��1щ�yjgSo'gOi^�W^�K�s�l��#R�8���LI��{��5B�S��Qn&Zk2��>։
2k�p��u��s�Ǥ���6�fe��6�*d��C.�M�Wv�ʦ��0g;}�AQ���MG�wj"����2/�pW��D�)o���qyP����ݭN��\�5S�f-%�a��8g�#��%<�acI��q#����s9�=8I��t�CmN�s�*�d�O`��/=�U0^�ߎKHr��<�>����0}&�;������m�6K�PEi�������HslƝ��J�xޜw��̗ۜ;V�,����J���C~�HZ�)�=�����(+IUY����h�r�+�5\X���94k2�X$�}f�,k<
C7��t}F��5�N�6ڬ��ž����!�:C 	u�~OM�ϣ�ȉ�k��d7�0	`��$eL׼Qa)�Lq���C@z��vM�b ��u^W|�ZXV���N���:�L�l���Tk�t�q9��Ĭ��˙��֜3�u�tB�|��_{�q��u����C%M��[�j_[��{�\㽨`4�M O��S�>�O��wc�>�B�<�TaQ���P�����x9��X�Qh���>�9�g%�Z��`jp�j���g��	�K؍)rNh�:_L������p�[X�-��K�
#��C��X�1Ue>�9nrz~��z)4#�+�8�Ε}N�|�̘$����Rc
Z�m����U��ٸ.�F�s����zlu�cMƭϼ�X��X�/�Ih�K��ΰ�*V#<,\�`'K.��8E�Ǩ5��]v4�8#�5�x9��Wd��}~��},��ʽ�|/,׾�)O���;G=+��"�u-i���:S�cv��3��ilP.�K�~WS ���+2G�$��c�X�^6��C�ңϝ�T��ɤ��Gm�SOu���مxp��b>��>.�p.YXBϙ�j�5mا���3Q���_@&9�09�=����X����W `�=�L�2�A�|L����x�/:�4�=���}��tOS��nw����\5�y'r�?VZ���7d������Iۻpi�.p�)~��N�g�܌�nY���)m\�Or�D���/9l�[�Q����٥��%�����{���
[	�F꨼��~�E!&Ĕ -x�p�����wi��e��l�����㼂ː�\��ݘ�i˝0Y�D�V�
�	k�0I�����o�s\f�A݈�6�ʳz�SRm=>.eޅ�K4D���I4#��bk��*k�2�-"��5W��#��tk̲������b��������i^pU'�� �{�fD���b�5����(��nʧKܹ#Z�[w��4�s�	�L�b�~�."-��3����w��� t�:�QSֲl��?$�i���O���hB�?�A�G��c�_�odN2���FtB�X�^jv���بzl�������m��0���L�+F�7��yAK(��X����i	e�q��c�:��b�RF�|�A%1@�6�����M�m1�Y�&Cb���陾/AQ2_}���t��{�'͖����c��G|h�R4�~'s4�u�7��!a��	O5�5)�:�;۩M�i.f�������L#�ޔzy
�Bl��i
Wu���=�w�8�ĎR��u�{Q��.r	�sl=��>�޷�Jx�2�m67�N���(r�@ڐ����=�v*5�0iN��63�	�,�N7�m�&�R���K~6��c ^�>��}3�J�C�ts��d1/�F���2
��F�҅S3�r�vpQK�Yһ��#FUkcyTw�ܐ=�B��S1g�gk��^�>y�����'&0�q\��&��O0J��PVڲٯ蚝t�Iގ�͌a�*�[��O�vZ�b�5x���v+O̇A��*��Ͻ5�����S����ŜEs\�=v��>ޚBP�P*�JV������)̤�Ύ嗿�qţv{q�H,֚�Z��־<�8��c�����Q��7������������06g�d�J)���������-	�O�΅����dٜ�b�Z0�]���2An-J��h'N�Z�%VwH�t�n�ٌ�)o�X���n���&#�������ٲKŜ�!�.���꘥��7���pajd�;J-���yˑ�6٨���9��'��h�̍�[(�|wNe��/��#��v��c#���6t�j�����³@g	���L�7:6/�sM�֛|�9
m���n� l�9�;³.��Dvx��4f_څ��V�c��J��X˝��B�1P��F��s>n0��ͪ�!�� �����6��5;�T &[vV�e�?��Q�]�ƛ�s��CFs�
2��6�$��v���=|��8d6�*��&W�E҉Ŝ��'[!W^� ��K���e)�r��D,����m4$�1�m�3�W���po�kN����盹�X:�����<��km�xՉ[<��k������	c����N?O��霘��#�֏�4�SX#l�v���Q9�Y��lη�̹�4����=��~5Ka�3>'��OBƋ<Ŝ�K[�QS�����:�_i�v2�/���^��دo�̀�~ ���ӳE~���.��\u�eLO����j��*�?�.��4d0�"�ă��0����n�J��}U���b/��u"qc�&��ǆ&�(q�zcG1��b���*t�d��7/�l��bFd��W�g��s����\1���On���_"���d`�ɸ>��ӌ���g8���!D�r�e�bίC�p\��w�Jvq�F*#cY�O����Y��%��9��B�/�wv/�m����)��� g&�Ŝ���j���ᩀ�7͏)��޼���52�;�qEW�9�Sg���E,����%lw��z�2�c��ok`�g1���ig�k0���E�
�.w�=nk֥bNa� ���6Y�9FɡT&��M#��z?.s
א����}=~�T�Mye���lq�mꭨP�)<I���[?�o�g�N#�gD�{�v�Ҹ�ö/�-3�a�F���J���9�g"��Ư�H%m��~��g�sY��m��cӳx1��dd~�����ף[2=Ԏ�������m3]�A7J^e'N��wQ�)|(6�Ș���g�ǤA<�UX�](�>W�z����9��G��֛	�L�pgP�/��
�������P�.S�)|Q�����fo�:�����E1���P��k��#u�`u�����B�wm��?5o �T�)�(��z�偷�^(���)�L\��n���9���|j:N|ӳbN��#�����8a����/�s
��qQ��J~3�]?�W}�I1��۱���i��9��/;7䵞S(�AٜB�Ο��a
��
7ю�ѠP(\F1�P��bN�pŜB��9��s
�;(�
wP�)S(�A1�P��bN�pŜB��9����G�v9�    IEND�B`�(      �� ��     0	        (                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���   ��� � �� � ��������      �������� � � � � � � � � � � � � � � � ��������                                                                               �� ��f     0	               (   �      �� ��     0	        (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ��� ��  ���� ��������������������� ������� �� ������� ����� �����������������              ���������������� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� �� ��� ��� ������������������                                                                                                                                              (      �� ��     0	        (                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���    �     � � ���������      �������� ��� � ��� � ��� � ��� � ��� � ��� � ��� � ��� ��������                                                                        "       �� ��g     0	                 �      (     y  ,   P N G   B A C K         0	        �PNG

   IHDR   �   �   �Y�.   	pHYs  �  ��o�d  +IDATx���Ok���y�YURm�L��SrI	��@(=4�^J{ɡ/��^�JH�
r��%�K �����*nSG�TU%k��73OV��C��B�Y��G-�]�Ӳ_=��ٙT�����S�:=�v�����r�E�5�]��w_)w�v�.X�[��~��E[�w��?�~ckw�����Gu~f6;{��o�u�or����:ĥ����7=���.?w���+���I0�,c��k�̻�������d���|~}�u{�	+�N�L��_u�U�$��T�0m��7��e�`�ڢ�á��Ur�2�u㳟-v�bgz��=>|C,��嶤_O����d����,���U��<�f}��_zXu�EW.���MWn=���g�+L�V��k"�z Xu^2� �@�`���-���rD���e�` @0 �t�W�@�` @0�S�4��^J�&��`���"�� �@_Y0"}���]�5�@���Wm�� �@�` @0p]����9��2{���}��%�wr�񡇀��` @0 �� �����/O�,���W�� �@�` @0�Wʂ��re���@�` @0 �� �@�` @0 ���. H0 �� �@O������ �@�` @0�C��U0�K��2D	�� �@�` @0�W��� �@�` @0 �� �@O�|	�|	�
!����E0 �� �@�` @0 ��U���lK��a D0�O�rV0 �� �@�` @0Гm� $"�� �@�` @0 ��;��SC���RJszZ0�S��e{���@�` @0 �� �@�` @0 ����$�!��/���@�` @0 r���g��Fn�jQ��R�ꡇ�Ք�*U۵�|�,v�ҵuN�V�r%97k�vwo'�f�Ϛv�1�8�`��Fu}iwoo���������՛�����G9o=���lb��>�׭��̓�W�o����>�~���h�^���=$���l�4��W��s�������7G�g|�ٍ�/�G.]���s�\�F5m󯦪���:�rU]�,�}|���/�we2�?|^:��o^~���Z~���Ѕg�ln���=s�wJ)��Φ��w��\U>����o�g�s�����n��O���S�?�����/�u�ѽ�Ӷ]uxt������t���×^z���)�O��.��    IEND�B`�     0   P N G   A L L _ B G         0	        �PNG

   IHDR      �   ��0�   	pHYs  �  ��+  
MiCCPPhotoshop ICC profile  xڝSwX��>��eVB��l� "#��Y�� a�@Ņ�
V�HUĂ�
H���(�gA��Z�U\8�ܧ�}z�����������y��&��j 9R�<:��OH�ɽ�H� ���g�  �yx~t�?��o  p�.$�����P&W  � �"��R �.T� � �S�d
 �  ly|B" � ��I> ة�� آ� � �(G$@� `U�R,�� ��@".���Y�2G�� v�X�@` ��B,�  8 C� L�0ҿ�_p��H �˕͗K�3���w����!��l�Ba)f	�"���#H�L�  ����8?������f�l��Ţ�k�o">!����� N���_���p��u�k�[ �V h��]3�	�Z
�z��y8�@��P�<
�%b��0�>�3�o��~��@��z� q�@������qanv�R���B1n��#�ǅ��)��4�\,��X��P"M�y�R�D!ɕ��2���	�w ��O�N���l�~��X�v @~�-�� g42y�  ����@+ ͗��  ��\��L�  D��*�A�������aD@$�<B�
��AT�:��������18��\��p`����	A�a!:�b��"���"aH4��� �Q"��r��Bj�]H#�-r9�\@���� 2����G1���Q�u@���Ơs�t4]���k��=�����K�ut }��c��1f��a\��E`�X&�c�X5V�5cX7v��a�$���^��l���GXLXC�%�#��W	��1�'"��O�%z��xb:��XF�&�!!�%^'_�H$ɒ�N
!%�2IIkH�H-�S�>�i�L&�m������ �����O�����:ň�L	�$R��J5e?���2B���Qͩ����:�ZIm�vP/S��4u�%͛Cˤ-��Кigi�h/�t�	݃E�З�k�����w���Hb(k{��/�L�ӗ��T0�2�g��oUX*�*|���:�V�~��TUsU?�y�T�U�^V}�FU�P�	��թU��6��RwR�P�Q_��_���c���F��H�Tc���!�2e�XB�rV�,k�Mb[���Lv�v/{LSCs�f�f�f��q�Ʊ��9ٜJ�!��{--?-��j�f�~�7�zھ�b�r�����up�@�,��:m:�u	�6�Q����u��>�c�y�	������G�m��������7046�l18c�̐c�k�i������h���h��I�'�&�g�5x>f�ob�4�e�k<abi2ۤĤ��)͔k�f�Ѵ�t���,ܬج��9՜k�a�ټ�����E��J�6�ǖږ|��M����V>VyV�V׬I�\�,�m�WlPW��:�˶�����v�m���)�)�Sn�1���
���9�a�%�m����;t;|rtu�vlp���4éĩ��Wgg�s��5�K���v�Sm���n�z˕��ҵ������ܭ�m���=�}��M.��]�=�A���X�q�㝧�����/^v^Y^��O��&��0m���[��{`:>=e���>�>�z�����"�=�#~�~�~���;�������y��N`������k��5��/>B	Yr�o���c3�g,����Z�0�&L�����~o��L�̶��Gl��i��})*2�.�Q�Stqt�,֬�Y�g��񏩌�;�j�rvg�jlRlc웸�����x��E�t$	�����=��s�l�3��T�tc��ܢ����˞w<Y5Y�|8����?� BP/O�nM򄛅OE����Q���J<��V��8�;}C�h�OFu�3	OR+y���#�MVD�ެ��q�-9�����Ri��+�0�(�Of++��y�m������#�s��l�Lѣ�R�PL/�+x[[x�H�HZ�3�f���#�|���P���ظxY��"�E�#�Sw.1]R�dxi��}�h˲��P�XRU�jy��R�ҥ�C+�W4�����n��Z�ca�dU�j��[V*�_�p�����F���WN_�|�ym���J����H��n��Y��J�jA�І����_mJ�t�zj��ʹ���5a5�[̶���6��z�]�V������&�ֿ�w{��;��켵+xWk�E}�n��ݏb���~ݸGwOŞ�{�{�E��jtolܯ���	mR6�H:p囀oڛ�w�pZ*�A��'ߦ|{�P������ߙ���Hy+�:�u�-�m�=���茣�^G���~�1�cu�5�W���(=��䂓�d���N?=ԙ�y�L��k]Q]�gCϞ?t�L�_�����]�p�"�b�%�K�=�=G~p��H�[o�e���W<�t�M�;����j��s���.]�y�����n&��%���v��w
�L�]z�x�����������e�m��`�`��Y�	�����Ӈ��G�G�#F#�����dΓ᧲���~V�y�s������K�X�����Ͽ�y��r﫩�:�#���y=�����}���ǽ�(�@�P���cǧ�O�>�|��/����%ҟ3    cHRM  z%  ��  ��  ��  u0  �`  :�  o�_�F   9IDATx�b����&(`a����O
�߿d��`0�p��2F��Q�(c�A;` g 1A����    IEND�B`��      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���               ?                       L   S t r i n g F i l e I n f o   (   0 4 0 9 0 4 b 0       C o m m e n t s   N   C o m p a n y N a m e     T e r r a   I n f o r m a t i c a ,   I n c     2   F i l e D e s c r i p t i o n     s k i n     6   F i l e V e r s i o n     1 ,   0 ,   0 ,   1     *   I n t e r n a l N a m e   s k i n     � i  L e g a l C o p y r i g h t   C o p y r i g h t   ? 2 0 0 2 - 2 0 0 6 ,   A n d r e w   F e d o n i o u k   a n d   T e r r a   I n f o r m a t i c a   S o f t w a r e ,   I n c . ,   h t t p : / / t e r r a i n f o r m a t i c a . c o m     (    L e g a l T r a d e m a r k s     : 	  O r i g i n a l F i l e n a m e   s k i n . e x e          P r i v a t e B u i l d   6   P r o d u c t N a m e     T e r r a   s k i n     :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1          S p e c i a l B u i l d   D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�