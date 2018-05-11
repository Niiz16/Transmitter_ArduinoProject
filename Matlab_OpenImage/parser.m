function array = parser(text)
array = regexp(text, '[0|1]{1,11}', 'match');
end 