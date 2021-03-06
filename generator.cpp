#include "generator.h"

void mgraphgen::square(graph& G,int m){ //γραφημα τετραγώνων

node u[m];  // +1	//πινακας με τον αριθμο των κομβων



	for (int i = 0; i < m; ++i)
		{
		u[i]=G.new_node(); //προσθήκη των κομβων στο γράφημα 
		}
		
	int k=0;
	int t=3;
	for (int j =0 ; j < (m*9)/12; ++j){	//επαναληψη για την δημιουργια των τετραγώνων, ο αριθμός των επαναλήψεων για τους
										//n κόμβους υπολογίζεται με την μέθοδο των τριών
			if (k == t){ 		//συνθήκη για να δημιουργηθει η 4η ακμη του τετραγωνου οταν έχουν δημιουτγηθεί οι προηγούμενες 3
				

			
				G.new_edge(u[k],u[k-3]); //δημιουργία της τελευταίας ακμής του τετραγώνου.γίνεται με τον τελευταίο κόμβο και τον 
				k = k +1; 				//αρχικο κόμβο ο οποίος είναι ο αρχκός κόμβος με τον τελευταίο για αυτό είναι -3
				t= t+4;					//εδω γίνεται ανάθεση για την συνθήκη του επόμενου τετραγώνου το κ+1 είναι ο αρχικός και το t+4 ο τελευταιος
						}				//π.χ. ο τελευταιος κομβος του πρώτου τετραγώνου είναι ο 3 οποτε ο 4 είναι ο αρχικός του 2ου (κ+1)
										//και ο τελευταίος του επόμενου είναι ο t+4 δηλαδη ο 7, η αρίθμηση ξεκινάει απο τον κόμβο 0
			
			G.new_edge(u[k],u[k+1]);   //δημιουργία των ακμών του τετραγώνου
				k=k+1;
			
		}

		G.new_edge(u[k],u[k-3]); //δημιουργία της τελευταίας ακμής του τελευταίου τετραγώνου,είναι εκτώς
								//της επανάληψης γιατί έβγαινε εκτώς μνήμης

for (int i = 0; i < m-4; ++i) //sunolikos arithmos nodes -4, δημιουργία των διαγόνιων ακμών μεταξύ των τετραγώνων
{
	G.new_edge(u[i],u[i+4]); //
}
G.insert_reverse_edges(); //δημιουργία των αντίθετων ακμών για την μετατροπή σε μη κατευθηνόμενο γράφημα σύμφωνα με την εκφώνηση

};


void mgraphgen::circle(graph& G,int m){ //κυκλικό διάγραμμα


	
	node u[m];

	for (int i = 0; i < m; ++i)
	{
		u[i]=G.new_node();		//προσθήκη των κόμβων
	}
		
	for (int i = 0; i < m-1; ++i) //-1 επανάληψη για να μην βγει εκτώς μνήμης
	{
		G.new_edge(u[i],u[i+1]);	//δημιουργία των ακμών
	}
	
	G.new_edge(G.last_node(),G.first_node()); //δημιουργία της τελευταίας ακμής μεταξύ του τελευταίου κόμβου 
												//και του πρώτου για να ολοκληρωθεί ο κύκλος
	G.insert_reverse_edges();	//προσθήκη των αντίθετων ακμών

};





void mgraphgen::leveled(graph& G,int m){
 							//γράφημα με τα επίπεδα
	
	node u[m];

	for (int i = 0; i < m; ++i)
	{
		u[i]=G.new_node();      //προσθήκη των κόμβων στο γράφημα
		
	}
	

	
	list<node> L[4];			//τα 4 επίπεδα υλοποιούνται με 1 πίνακα λίστας
	list<node>::iterator it;
	list<node>::iterator it2;	//δημιουργία δεικτών για την προσπέλαση και την απονοφοριοποιηση
								//των περιεχομένων

	node v;
	int counter=0, j=0;		//ο counter μετράει πόσοι κόμβοι μπαίνουν στην λίστα έστω ότι έχουμε 80 κόμβους μετράει 20, το j είναι για να αλλάζουμε λίστα	
	forall_nodes(v,G){			//επανάληψη για την προσπέλαση των κόμβων
	
	if (counter == m/4)
	{		//όταν μπουν οι n/4 (20) κόμβοι στην i λίστα πάει στην επόμενη
		j=j+1;				//αλλαγή λίστας 
		counter=0;			//μηδενισμός του μετρητή 
	}
		L[j].append(v);			//προσθήκη των κόμβων στην i λίστα		
		++counter;				//αυξηση του μετρητή
	}
						


		node r,d;

		for (int i = 0; i < 3; ++i) //δημιουργία των ακμων μεταξύ των επιπεδων L0 -> L1 -> L2 -> L3
		{	it =L[i].begin();		//η προσπέλαση της κάθε λίστας γίνεται με την συνάρτηση begin για την ανάθεση του αρχικού 
			it2 = L[i+1].begin();	//κόμβου της καθε λίστας στους iterators και ύστερα γίνεται αυξηση για την προσπέλαση των υπολοίπων κόμβων
				for (int j = 0; j < m/4; ++j) 
				{
					r = *it;
					d = *it2;
					G.new_edge(r,d);	//η δημουργία των ακμών.
					++it;
					++it2;
				}
		}


	//#########################################################

	node o,x;
	int w;
//δευτερη φάση ένωσης των γραφημάτων, επιλογή ενος τυχαίου κόμβου και ένωση με τους 
	//κόμβους του επόμενου επιπέδου.

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
		srand (seed);			//αρχικοποιηση της rand	
			w = rand() % m/4;	//προσθήκη της τιμής σε μια μεταβλητή
			it = L[0].begin();
			for (int i = 0; i < w; ++i) //iteration μεταξυ 0 και n/4 για να βρούμε ποιος κόμβος θα επιλεχθεί
			{
				++it;					//απο την θέση της λίστας που προκήπτει απο το w
			}
			o = *it;
edge q;									// L0
q = G.first_adj_edge(o);			//προσθήκη της τυχαίας ακμής στο node με τον iterator
	G.del_edge(q);
//επειδή δημιουργούνται παλι ακμες απο το i διάγραμμα στο i+1 			
//ο τυχαίος κόμβος έχει ήδη ακμή στο επόμενο επίδεδο οπότε οταν γίνει η δημιουργία
	//των ακμών θα προσθέσει διπλή ακμή με τον απογονο του,την διαγράφω για να είναι σωστό το διάγραμμα 
	//αν δεν γίνει η διαγραφή το γράφημα θα έχει 2k + 1 ακμές μεταξύ των επιπέδων που αυτό δεν συμφωνεί με την εκφώνηση

			for (it = L[1].begin(); it != L[1].end(); ++it) 
 			   {
    					x = *it;
   					 G.new_edge(o,x);	
	 			} 

//#########################################################
auto seed2 = chrono::high_resolution_clock::now().time_since_epoch().count();
			srand (seed2);
			w = rand() % m/4;
			it = L[1].begin();
			for (int i = 0; i < w; ++i)
			{
				++it;
			}											//random choose
			o = *it;
	q = G.first_adj_edge(o);			
	G.del_edge(q);

			for (it = L[2].begin(); it != L[2].end(); ++it) 
 			   {
    					x = *it;
   					 G.new_edge(o,x);	
	 			} 


//##################################################################

auto seed3 = chrono::high_resolution_clock::now().time_since_epoch().count();
			srand (seed3);
			w = rand() % m/4;
			it = L[2].begin();
			for (int i = 0; i < w; ++i)
			{
				++it;
			}
			o = *it;


q = G.first_adj_edge(o);			
	G.del_edge(q);


			for (it = L[3].begin(); it != L[3].end(); ++it) 
 			   {		x = *it;
    					
    					G.new_edge(o,x);	
	 			} 

//###############################################################
	//μέχρι εδώ ισχύουν τα σχόλια που έγιναν πριν
	//η δημιουργία πολλών seeds γίνεται γιατί με το ίδιο seed επιλέγονται οι ίδιοι απόγονοι
	//και το high resolution επειδή το αντικείμενο δημιουργείται σε πολύ μικρό χρόνο και έχει 
	//το ίδιο αποτέλεσμα 
	//####################################

	//δημιουργεία των επιπλέων 2 τυχαίων ακμών, η διαδηκασία είναι παρόμοια με τα παραπάνω
auto seed4 = chrono::high_resolution_clock::now().time_since_epoch().count();

				srand (seed4);
			w = rand() % m/4;
			it = L[0].begin();
			for (int i = 0; i < w; ++i)
			{
				++it;
			}
			o = *it;				//	L0 -> L2
auto seed5 = chrono::high_resolution_clock::now().time_since_epoch().count();
		srand (seed5);
			w = rand() % m/4;
			it = L[2].begin();
			for (int i = 0; i < w; ++i)
			{
				++it;
			}
			x = *it;

			G.new_edge(o,x);
//##########################################################################
	auto seed6 = chrono::high_resolution_clock::now().time_since_epoch().count();
		srand (seed6);
			w = rand() % m/4;
			it = L[1].begin();
			for (int i = 0; i < w; ++i)
			{
				++it;
			}
			o = *it;
auto seed7 = chrono::high_resolution_clock::now().time_since_epoch().count();
		srand (seed7);					//L1 -> L3
			w = rand() % m/4;
			it = L[3].begin();
			for (int i = 0; i < w; ++i)
			{
				++it;
			}
			x = *it;

			G.new_edge(o,x);
//#######################################################################################

G.insert_reverse_edges();

};