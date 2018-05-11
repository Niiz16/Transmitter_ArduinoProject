
clear;
clc
 
[archivo,ruta]=uigetfile('*.txt','ABRIR ARCHIVO');
if archivo==0
    return;
else
fileID = fopen([ruta archivo],'r'); 
texto = fscanf(fileID,'%c');
fclose(fileID);
end

texto1 = fixed(texto);
array =  parser(texto1);
%array =  parser(texto);
array1 = cleaner(array);
imageStr = cellfun(@decoder,array1(2:length(array1) - 1));
imageArr = imageCut(imageStr);

%magicNum = 'P3';
magicNum =imageArr{1};
width = str2num(imageArr{2});
height = str2num(imageArr{3});
colorAdjusment = imageArr{4};
pixels = imageArr(5:length(imageArr));

 fileOutID = fopen('trama4.ppm','w');
 fprintf(fileOutID,'%s\n',magicNum');
fprintf(fileOutID,'%d %d\n',width, height);
fprintf(fileOutID,'%s\n',colorAdjusment');

h=1;
for i = 1:height
    for j = 1:width
       for k = 1:3
         fprintf(fileOutID,'%s ',pixels{1,h});
         h = h+1;
       end
    end
   fprintf(fileOutID,'\n');
end
  fclose(fileOutID);

%h=1;

%imagen(1,1,1) = pixels(1,7132);
% for i = 1:height
%     for j = 1:width
%        for k = 1:3
%          imagen(i,j,k)= pixels(1,h);
%          h = h+1;
%        end
%     end
% end
%  imagen1 = cellfun(@str2double,imagen);

finalImage = imread('trama4.ppm')
imshow(finalImage)
% imshow(imagen1);