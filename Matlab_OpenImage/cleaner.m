function cleaned = cleaner(array)
    len = length(array);
    newarray = cell(1,len);
    for i = 1:len
        newarray{i} = array{1,i}(2:9);
    end
    cleaned = newarray;
end