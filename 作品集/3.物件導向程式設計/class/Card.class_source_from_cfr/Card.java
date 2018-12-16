/*
 * Decompiled with CFR 0_118.
 * 
 * Could not load the following classes:
 *  Card$Suit
 */
import java.io.PrintStream;

public class Card {
    private Suit suit;
    private int rank;

    public Card(Suit s, int r) {
        this.suit = s;
        this.rank = r;
    }

    public void printCard() {
        System.out.println((Object)this.suit + "," + this.rank);
    }

    public Suit getSuit() {
        return this.suit;
    }

    public int getRank() {
        return this.rank;
    }
}
