#include "../Includes/Cards.hpp"

Cards::Cards(CardData* Info,
             const sf::Color Color,
             const sf::Font& Font,
             float* DeltaTime,
             sf::Texture& Texture,
             sf::Vector2f Location)
{
    this->Info      = Info;
    this->DeltaTime = DeltaTime;
    this->Texture   = Texture;
    this->Location  = Location;

    this->Title.setFont(Font);
    
    this->LoadCard(Color);
}

Cards::~Cards(){}

void Cards::Update()
{

    this->UpdatePositionComponents();
}

void Cards::Render(sf::RenderWindow* Render)
{
    Render->draw(this->ImageBackground);
    Render->draw(this->ImageTitleBar);
    Render->draw(this->Title);
    Render->draw(this->ImageBar);
    Render->draw(this->ImageCharacter);
}

void Cards::LoadCard(sf::Color Color)
{
    this->UpdatePositionComponents();

    this->ImageBackground.setTexture(this->Texture);
    this->ImageBackground.setTextureRect(sf::IntRect(136.f, 0.f, 135.f, 171.f));
    this->ImageBackground.setColor(Color);

    this->ImageTitleBar.setTexture(this->Texture);
    this->ImageTitleBar.setTextureRect(sf::IntRect(272.f, 1.f, 129.f, 22.f));
                            
    this->Title.setCharacterSize(11.f);
    this->Title.setString(this->Info->Title);
    this->Title.setFillColor(sf::Color::White);
    this->Title.setStyle(sf::Text::Regular);

    this->ImageBar.setTexture(this->Texture);
    this->ImageBar.setTextureRect(sf::IntRect(272.f, 24.f, 128.f, 122.f));

    this->ImageCharacter.setTexture(this->Texture);
    this->ImageCharacter.setTextureRect(this->Info->ImageRect);
}

void Cards::UpdatePositionComponents()
{
    this->ImageBackground.setPosition(this->Location);
    this->ImageTitleBar.setPosition(Location.x + 4, Location.y + 6);
    this->Title.setPosition(this->ImageTitleBar.getPosition().x + 15,
                            this->ImageTitleBar.getPosition().y + 4);
    this->ImageBar.setPosition(this->Location.x + 4, Location.y + 32);
    this->ImageCharacter.setPosition(this->Location.x + 5, Location.y + 33);
}
