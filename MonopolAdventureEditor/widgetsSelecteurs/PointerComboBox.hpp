#ifndef POINTERCOMBOBOX_HPP
#define POINTERCOMBOBOX_HPP

#include <QComboBox>





/**
 * Classe template héritant de QComboBox qui permet d'associer un pointeur à chaque item de la liste.
 */
template <class T>
class PointerComboBox : public QComboBox
{
    private:
        QList<T*> m_listePointeurs;///< Liste des pointeurs.
        
        
        
    public:
        /**
         * Constructeur par défaut.
         */
        PointerComboBox() :
            QComboBox()
        {
            
        }
        
        
        
        /**
         * Retourne la liste des pointeurs.
         * @return Liste des pointeurs.
         */
        const QList<T*>& getListePointeurs() const
        {
            return m_listePointeurs;
        }
        
        
        
        /**
         * Retourne le pointeur de l'item sélectionné.
         * @return Pointeur de l'item sélectionné.
         */
        T* getCurrentPointeur() const
        {
            return m_listePointeurs.at(currentIndex());
        }
        
        
        
        /**
         * Sélectionne la ligne @a row.
         *
         * Cette surcharge est nécessaire, sinon, un appel de PointerComboBox::setCurrentIndex(0) appels la méthode PointerComboBox::setCurrentInedx(const T*).
         *
         * @param row Ligne.
         */
        void setCurrentIndex(const int row)
        {
            QComboBox::setCurrentIndex(row);
        }
        
        
        
        /**
         * Sélectionne la ligne représentée par le pointeur.
         * @param pointeur Pointeur représentant la ligne.
         */
        void setCurrentIndex(const T* pointeur)
        {
            QComboBox::setCurrentIndex(m_listePointeurs.indexOf((T*) pointeur));
        }
        
        
        
        /**
         * Ajoute un item à la QComboBox.
         * @param text Texte à afficher dans la liste.
         * @param pointeur Pointeur correspondant à l'item.
         */
        void addItem(const QString& text,
                     T* pointeur)
        {
            QComboBox::addItem(text);
            m_listePointeurs.append(pointeur);
        }
};

#endif // POINTERCOMBOBOX_HPP
