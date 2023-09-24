package TrieDSA;

/*
            Here Node Children Array Size vary on alphabets,symbols
            Case 1 : Size = 26 => If only Capital Letter Alphabets are present in the Input String
            Case 2 : Size = 26 => If only Small Letter Alphabets are present in the Input String
            Case 3 : Size = 1 => If only Space is present in the Input String
            Case 4 : Size = 42 => If only Symbols & Numbers are present in the Input String

            Case 5 : Size = (26+26=52) => If both Capital & Small Letter Alphabets are present in the Input String
            Case 6 : Size = (26+1=27) => If Capital Letter & Space are present in the Input String
            Case 7 : Size = (26+42=68) => If Capital Letter Alphabets & Symbols,Numbers are present in the Input String
            Case 8 : Size = (26+26+1=53) => If Capital & Small Letter & Space are present in the Input String
            Case 9 : Size = (26+26+42=94) => If Capital Letter Alphabets & Small Letter Alphabets & Symbols,
                                                Numbers are present in the Input String
            Case 10 : Size = (26+42+1=69) => If Capital Letter Alphabets & Symbols,Numbers &
                                                Space are present in the Input String
            Case 11 : Size = (26+26+1+42=95) => If Capital Letter Alphabets & Small Letter Alphabets & Space
                                                    & Symbols,Numbers are present in the Input String


            Case 12 : Size = (26+1=27) => If Small Letter & Space are present in the Input String
            Case 13 : Size = (26+42=68) => If Small Letter Alphabets & Symbols,Numbers are present in the Input String
            Case 14 : Size = (26+42+1=69) => If Small Letter Alphabets & Symbols,Numbers &
                                                Space are present in the Input String

            Case 15 : Size = (42+1=43) => If Symbols,Numbers & Space are present in the Input String

*/

public class SizeNode {
    private int size;

    //  Default Constructor
    public SizeNode() {
        this.size = 95; //  Here we take basically Case 11 i.e; Size = 95
    }

    //  Getter
    public int getSize() {
        return size;
    }

    //  Setter
    public void setSize(int size) {
        this.size = size;
    }

    //  Case 1 : Size = 26 => If only Capital Letter Alphabets are present in the Input String
    public int capsIndexFinder(char c) {
        //  Only Capital Alphabets = 26
        return c - 'A';
    }

    //  Case 2 : Size = 26 => If only Small Letter Alphabets are present in the Input String
    public int smallIndexFinder(char c) {
        //  Only Small Alphabets = 26
        return c - 'a';
    }

    //  Case 3 : Size = 1 => If only Space is present in the Input String
    public int spaceIndexFinder(char c) {
        //  Only Space = 1
        return 0;
    }

    //  Case 4 : Size = 42 => If only Symbols & Numbers are present in the Input String
    public int symNumIndexFinder(char c) {
        //  Return Symbols and Numbers Index
        if (c - '!' >= 0 && c - '!' <= 31) {
            return c - '!';
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 26 >= 32 && c - '!' - 26 <= 37) {
            return c - '!' - 26;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 52 >= 38 && c - '!' - 52 <= 41) {
            return c - '!' - 52;
        }
        return -1;
    }

    //  Case 5 : Size = (26+26=52) => If both Capital & Small Letter Alphabets are present in the Input String
    public int capsSmallIndexFinder(char c) {
        //  Return Capital Alphabet Index
        if (c - 'A' >= 0 && c - 'A' <= 25) {
            return (c - 'A');
        }
        //  Return Small Alphabet Index
        if (c - 'a' >= 0 && c - 'a' <= 25) {
            return (c - 'a') + 26;
        }
        return -1;
    }

    //  Case 6 : Size = (26+1=27) => If Capital Letter & Space are present in the Input String
    public int capsSpaceIndexFinder(char c) {
        //  Return Capital Alphabet Index
        if (c - 'A' >= 0 && c - 'A' <= 25) {
            return (c - 'A');
        }
        //  Return Space
        if (c == ' ') {
            return (0) + 26;
        }
        return -1;
    }

    //  Case 7 : Size = (26+42=68) => If Capital Letter Alphabets & Symbols,Numbers are present in the Input String
    public int capsSymNumIndexFinder(char c) {
        //  Return Capital Alphabet Index
        if (c - 'A' >= 0 && c - 'A' <= 25) {
            return (c - 'A');
        }
        //  Return Symbols and Numbers Index
        if (c - '!' >= 0 && c - '!' <= 31) {
            return (c - '!') + 26;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 26 >= 32 && c - '!' - 26 <= 37) {
            return (c - '!' - 26) + 26;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 52 >= 38 && c - '!' - 52 <= 41) {
            return (c - '!' - 52) + 26;
        }
        return -1;
    }

    //  Case 8 : Size = (26+26+1=53) => If Capital & Small Letter & Space are present in the Input String
    public int capsSmallSpaceFinder(char c) {
        //  Return Capital Alphabet Index
        if (c - 'A' >= 0 && c - 'A' <= 25) {
            return (c - 'A');
        }
        //  Return Small Alphabet Index
        if (c - 'a' >= 0 && c - 'a' <= 25) {
            return (c - 'a') + 26;
        }
        //  Return Space
        if (c == ' ') {
            return (0) + 52;
        }
        return -1;
    }

    /*  Case 9 : Size = (26+26+42=94) => If Capital Letter Alphabets & Small Letter Alphabets & Symbols,
                                            Numbers are present in the Input String */
    public int capsSmallSymNumIndexFinder(char c) {
        //  Return Capital Alphabet Index
        if (c - 'A' >= 0 && c - 'A' <= 25) {
            return (c - 'A');
        }
        //  Return Small Alphabet Index
        if (c - 'a' >= 0 && c - 'a' <= 25) {
            return (c - 'a') + 26;
        }
        //  Return Symbols and Numbers Index
        if (c - '!' >= 0 && c - '!' <= 31) {
            return (c - '!') + 52;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 26 >= 32 && c - '!' - 26 <= 37) {
            return (c - '!' - 26) + 52;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 52 >= 38 && c - '!' - 52 <= 41) {
            return (c - '!' - 52) + 52;
        }
        return -1;
    }

    /* Case 10 : Size = (26+42+1=69) => If Capital Letter Alphabets & Symbols,Numbers &
                                                Space are present in the Input String */
    public int capsSpaceSymNumIndexFinder(char c) {
        //  Return Capital Alphabet Index
        if (c - 'A' >= 0 && c - 'A' <= 25) {
            return (c - 'A');
        }
        //  Return Space
        if (c == ' ') {
            return (0) + 26;
        }
        //  Return Symbols and Numbers Index
        if (c - '!' >= 0 && c - '!' <= 31) {
            return (c - '!') + 27;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 26 >= 32 && c - '!' - 26 <= 37) {
            return (c - '!' - 26) + 27;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 52 >= 38 && c - '!' - 52 <= 41) {
            return (c - '!' - 52) + 27;
        }
        return -1;
    }

    /* Case 11 : Size = (26+26+1+42=95) => If Capital Letter Alphabets & Small Letter Alphabets & Space
                                                    & Symbols,Numbers are present in the Input String */
    public int capsSmallSpaceSymNumIndexFinder(char c) {
        //  Return Capital Alphabet Index
        if (c - 'A' >= 0 && c - 'A' <= 25) {
            return (c - 'A');
        }
        //  Return Small Alphabet Index
        if (c - 'a' >= 0 && c - 'a' <= 25) {
            return (c - 'a') + 26;
        }
        //  Return Space Index
        if (c == ' ') {
            return (0) + 52;
        }
        //  Return Symbols and Numbers Index
        if (c - '!' >= 0 && c - '!' <= 31) {
            return (c - '!') + 53;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 26 >= 32 && c - '!' - 26 <= 37) {
            return (c - '!' - 26) + 53;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 52 >= 38 && c - '!' - 52 <= 41) {
            return (c - '!' - 52) + 53;
        }
        return -1;
    }

    //  Case 12 : Size = (26+1=27) => If Small Letter & Space are present in the Input String
    public int smallSpaceIndexFinder(char c) {
        //  Return Small Alphabet Index
        if (c - 'a' >= 0 && c - 'a' <= 25) {
            return (c - 'a');
        }
        //  Return Space
        if (c == ' ') {
            return (0) + 26;
        }
        return -1;
    }

    //  Case 13 : Size = (26+42=68) => If Small Letter Alphabets & Symbols,Numbers are present in the Input String
    public int smallSymNumIndexFinder(char c) {
        //  Return Small Alphabet Index
        if (c - 'a' >= 0 && c - 'a' <= 25) {
            return (c - 'a');
        }
        //  Return Symbols and Numbers Index
        if (c - '!' >= 0 && c - '!' <= 31) {
            return (c - '!') + 26;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 26 >= 32 && c - '!' - 26 <= 37) {
            return (c - '!' - 26) + 26;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 52 >= 38 && c - '!' - 52 <= 41) {
            return (c - '!' - 52) + 26;
        }
        return -1;
    }

    /* Case 14 : Size = (26+42+1=69) => If Small Letter Alphabets & Symbols,Numbers &
                                                Space are present in the Input String */
    public int smallSpaceSymNumIndexFinder(char c) {
        //  Return Small Alphabet Index
        if (c - 'a' >= 0 && c - 'a' <= 25) {
            return (c - 'a');
        }
        //  Return Space
        if (c == ' ') {
            return (0) + 26;
        }
        //  Return Symbols and Numbers Index
        if (c - '!' >= 0 && c - '!' <= 31) {
            return (c - '!') + 27;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 26 >= 32 && c - '!' - 26 <= 37) {
            return (c - '!' - 26) + 27;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 52 >= 38 && c - '!' - 52 <= 41) {
            return (c - '!' - 52) + 27;
        }
        return -1;
    }

    //  Case 15 : Size = (42+1=43) => If Symbols,Numbers & Space are present in the Input String
    public int spaceSymNumIndexFinder(char c) {
        //  Return Space
        if (c == ' ') {
            return 0;
        }
        //  Return Symbols and Numbers Index
        if (c - '!' >= 0 && c - '!' <= 31) {
            return (c - '!') + 1;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 26 >= 32 && c - '!' - 26 <= 37) {
            return (c - '!' - 26) + 1;
        }
        //  Return Some Extra Symbol Index
        if (c - '!' - 52 >= 38 && c - '!' - 52 <= 41) {
            return (c - '!' - 52) + 1;
        }
        return -1;
    }
}
