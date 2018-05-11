function array = fixed(text)
a1 = regexp(text,'\w','match');
Horizontal = strjoin(a1);
array = regexprep(Horizontal,'\W','');
end 