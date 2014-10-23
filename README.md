Components
==========
* Ktopic, node<ktopic>
* Ksubject, node<ksubject>
* Ktype, taxonomy_term<ktype>
* Kdata, eck_entity:kdata

Theme
=====
* Add page__node__ktopic, page__node__ksubject to 'theme_hook_suggestions' for corresponding node type.
* ktopic_logos

node<ktopic>
============
* ktypes property through hook_node_load(), add ktypes information to ktopic node.

Views
=====
* Views Relationship.
  - Utilize entity properties info to add kdata entity to node<ktopic> per bundle type.
  - Alter 'views_entity_node' to add relationship to join table and add context.
