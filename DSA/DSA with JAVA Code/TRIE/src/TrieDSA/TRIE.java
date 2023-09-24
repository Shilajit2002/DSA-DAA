package TrieDSA;

class TrieNode {
    //  Create a Node Class Array
    private TrieNode[] children;
    //  Create a variable which represent each word ends value true or false
    private boolean isEndOfWord;

    //  SizeNode Class for get each node size
    //  It is not require, but we implement this because => Go to SizeNode Class and read all
    SizeNode S = new SizeNode();

    //  Default Constructor
    public TrieNode() {
        //  Creating a 94 Node Array
        this.children = new TrieNode[S.getSize()];
        //  Set Array Value with Null
        for (int i = 0; i < this.children.length; i++) {
            this.children[i] = null;
        }
        //  Initially End Of Word value is false
        this.isEndOfWord = false;
    }

    //  Getter Method
    public TrieNode[] getChildren() {
        return children;
    }

    //  Getter Method
    public boolean getEndOfWord() {
        return isEndOfWord;
    }

    //  Setter Method
    public void setEndOfWord(boolean endOfWord) {
        isEndOfWord = endOfWord;
    }
}

class TRIE {
    //  Root
    private TrieNode Root;

    //  SizeNode Class for get each letters index
    SizeNode SN = new SizeNode();

    //  Default Constructor
    public TRIE() {
        this.Root = new TrieNode();
    }

    //  Getter
    public TrieNode getRoot() {
        return Root;
    }

    //  Setter
    public void setRoot(TrieNode root) {
        Root = root;
    }

    //  Insert Module
    public void insertWordNode(String word) {
        int level = 0, idx = 0;
        //  Take Current Node from Root
        TrieNode curr = Root;

        //  Loop for inserting word in to TRIE
        for (; level < word.length(); level++) {
            //  Get Index by characters
            idx = SN.capsSmallSpaceSymNumIndexFinder(word.charAt(level));

            //  Check if the node is null
            if (curr.getChildren()[idx] == null) {
                //  Then create new Node
                curr.getChildren()[idx] = new TrieNode();
            }
            //  Set the Current Node with new Node
            curr = curr.getChildren()[idx];
        }
        //  After Ending the word End of Word value will be true
        curr.setEndOfWord(true);
    }

    //  Search Module
    public boolean searchWordNode(String key) {
        int level = 0, idx = 0;
        //  Take Current Node from Root
        TrieNode curr = Root;

        //  Loop for searching word in to TRIE
        for (; level < key.length(); level++) {
            //  Get Index by characters
            idx = SN.capsSmallSpaceSymNumIndexFinder(key.charAt(level));

            //  Check if the node is null
            if (curr.getChildren()[idx] == null) {
                //  Then the Word is not present so return false
                return false;
            }
            //  Set the Current Node with new Node
            curr = curr.getChildren()[idx];
        }
        // After all iteration if the last letter End Of Word value is true then Word is present and return true
        //  Otherwise return false
        return curr.getEndOfWord();
    }

    public static void main(String[] args) {
        TRIE T = new TRIE();
        String dict[] = new String[]{"and", "ant", "dad", "do"};
        for (String word : dict) {
            T.insertWordNode(word);
        }

        System.out.println("and " + (T.searchWordNode("and") ? "Present in TRIE" : "Not Present in TRIE"));
        System.out.println("ant " + (T.searchWordNode("ant") ? "Present in TRIE" : "Not Present in TRIE"));
        System.out.println("anti " + (T.searchWordNode("anti") ? "Present in TRIE" : "Not Present in TRIE"));
        System.out.println("an " + (T.searchWordNode("an") ? "Present in TRIE" : "Not Present in TRIE"));
        System.out.println("dad " + (T.searchWordNode("dad") ? "Present in TRIE" : "Not Present in TRIE"));
        System.out.println("day " + (T.searchWordNode("day") ? "Present in TRIE" : "Not Present in TRIE"));
        System.out.println("do " + (T.searchWordNode("do") ? "Present in TRIE" : "Not Present in TRIE"));
        System.out.println("done " + (T.searchWordNode("done") ? "Present in TRIE" : "Not Present in TRIE"));
    }
}
