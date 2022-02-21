"use strict";
/*--------------------------------------------------------------
 TABLE OF CONTENTS.
 ----------------------------------------------------------------
 # Vars.
 # Options.
 # Document Ready.

 # Functions.
 --------------------------------------------------------------*/



// =====================================================================================================================
// Vars.

if ( ish === null || typeof(ish) !== "object" ) {
	var ish = {}
}

var ishMacy;
var ishMacyActive = [];
var ishPortfolioTimer;
var ishBody = jQuery( 'body' );
var ishMenu = jQuery( '.ish-sidenav-menu' );
var ishNav = ishMenu.find( '.ish-sidenav-menu__icon' ).add( '.ish-resp-nav__icon--nav' );
var ishNavOpened = false;
var ishCurrentScreenTopPos = 0;
var ishHeaderHeight = 150;
var ishSearch = jQuery( '.ish-navigation__item--search-form' );
var ishFadedHeadline = false;
var ishPfloContainer = '.ish-portfolio.ish-macy';
var ishPreloaderTimer;

var ishFilterItem;
var ishPfloItems;
var ishPfloFirstItems;
var ishDel = 250;

var ishWindow = jQuery( window );
var ishPageHeight = ishWindow.height();
var ishPageLoaded = false;


// =====================================================================================================================
// Options.

var ishPortfolioTiltEffect = true;
var ishSmoothScroll = true;
var ishPreloader = true;


// =====================================================================================================================
// Document ready.

jQuery( document ).on( 'ready', function ( $ ) {

	ish.activateSmoothScrollPage();
	ish.activateStickyHeader();
	ish.activateRespBottomStickyNav();
	ish.activateBackToTop();
	ish.activateSearchForm();
	ish.activateLeadAnimation();
	ish.activateLeadHeadlinePosition();
	ish.activateMenuDropdown();
	ish.activatePortfolio();
	ish.activatePortfolioFilter();
	ish.activatePortfolioTilt();
	ish.activateBackToTopButton();
	ish.activateSidebar();
	ish.activateNavigation();
	ish.activateAccordion();
	ish.activateToggle();
	ish.activateTabs();
	ish.activateGallery();
	ish.activateLightBox();
	ish.activatePreloader();
	ish.activateSendForm();

	// Function ish.initMap() is called from html.

} );


// =====================================================================================================================
// Function exist.

function functionExists( name ) {
	return ( 'function' === eval( 'typeof ish.' + name ) );
}


// =====================================================================================================================
// Function element in view.

if ( !functionExists( 'activateElementInViewport' ) ) {
	ish.activateElementInViewport = function () {

		var contentEl = jQuery( '.ish-content' );
		var isElementInView = function ( thisEl ) {
			var pageTop = ishWindow.scrollTop();
			var pageBottom = pageTop + ishPageHeight;
			var elementTop = jQuery( thisEl ).offset().top;
			var elementTopMargin = parseInt( jQuery( thisEl ).css( 'margin-top' ), 10 );

			if ( ( elementTop - elementTopMargin / 2 ) <= pageBottom ) {
				return true;
			}
		};
		var checkElInViewport = function ( thisEl ) {
			if ( !thisEl.hasClass( 'ish-visible' ) ) {
				if ( ishPageLoaded ) {
					if ( isElementInView( thisEl ) ) {
						thisEl.addClass( 'ish-visible' );
					} else {
						thisEl.addClass( 'ish-no-delay' );
					}
				}
			}
		};

		checkElInViewport( contentEl );

		ishWindow.on( 'scroll', function () {
			checkElInViewport( contentEl );
		} );
	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Preloader.

if ( !functionExists( 'activatePreloader' ) ) {
	ish.activatePreloader = function () {

		var bodyEl = jQuery( 'body' );
		var addClassPageLoaded = function ( delay ) {

			clearTimeout( ishPreloaderTimer );

			ishPreloaderTimer = setTimeout( function () {
				ishPageLoaded = true;
				bodyEl.addClass( 'ish-page-loaded' );
				bodyEl.find( '.ish-preloader' ).remove();
				socialIconsAnimation();
				ish.activateElementInViewport();
			}, delay );

		};
		var socialIconsAnimation = function () {
			jQuery( '.ish-sidenav-socials__icon' ).each( function ( i ) {
				var thisEl = jQuery( this );
				setTimeout( function () {
					thisEl.addClass( 'animate' );
				}, 150 * i );
			} );
		};


		if ( ishPreloader ) {

			bodyEl.addClass( 'ish-page-ready' );
			bodyEl.find( '.ish-lead' ).prepend( '<div class="ish-preloader"></div>' );

			addClassPageLoaded( 5000 );

			// Window load.
			ishWindow.on( 'load', function () {
				addClassPageLoaded( 500 );
			} );

		} else {
			addClassPageLoaded( 0 );
		}

	};
}


// ---------------------------------------------------------------------------------------------------------------------
// SmoothScroll.

if ( !functionExists( 'activateSmoothScrollPage' ) ) {
	ish.activateSmoothScrollPage = function () {

		if ( ishSmoothScroll ) {
			SmoothScroll( {
				// Scrolling Core.
				animationTime: 400, // Value in ms ( 600 ).
				stepSize: 100 // Value in px ( 50 ).
			} );
		} else {
			SmoothScroll.destroy();
		}

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Sticky header smaller on scroll.

if ( !functionExists( 'activateStickyHeader' ) ) {
	ish.activateStickyHeader = function () {

		jQuery( document ).on( 'scroll', function () {

			var ishScreenTop = jQuery( document ).scrollTop();

			if ( ( ( ishCurrentScreenTopPos - ishHeaderHeight ) > ishScreenTop ) ||
				( ( ishCurrentScreenTopPos + ishHeaderHeight ) < ishScreenTop ) ) {
				ishBody.addClass( 'ish-nav--sticky' );
			}
			else {
				ishBody.removeClass( 'ish-nav--sticky' );
			}

		} );

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Responsive bottom sticky nav < 480px.

if ( !functionExists( 'activateRespBottomStickyNav' ) ) {
	ish.activateRespBottomStickyNav = function () {

		var ishPrevScroll = 0;
		var ishRespNav = jQuery( '.ish-resp-nav' );
		var ishDel = 1000;

		// Wait and then fire.
		setTimeout( function () {

			ishWindow.on( 'scroll', function () {

				var ishCurScroll = $( this ).scrollTop();

				// If I'm on top.
				if ( ishCurScroll === 0 ) {
					ishRespNav.addClass( 'ish-resp-nav--visible' );
				}

				// If scrolling down.
				if ( ishCurScroll > ishPrevScroll ) {
					ishRespNav.addClass( 'ish-resp-nav--hidden' );
				}
				// Scrolling up.
				else {
					ishRespNav.removeClass( 'ish-resp-nav--hidden' );
				}

				ishPrevScroll = ishCurScroll;
			} );

		}, ishDel );

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Back to top only on scroll.

if ( !functionExists( 'activateBackToTop' ) ) {
	ish.activateBackToTop = function () {

		jQuery( document ).on( 'scroll', function () {

			var ishScreenTop = jQuery( document ).scrollTop();

			if ( ( ( ishCurrentScreenTopPos - ishHeaderHeight ) > ishScreenTop ) ||
				( ( ishCurrentScreenTopPos + ishHeaderHeight ) < ishScreenTop ) ) {
				ishBody.addClass( 'ish--back-to-top' );
			}
			else {
				ishBody.removeClass( 'ish--back-to-top' );
			}

		} );

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Lead image animation effect.

if ( !functionExists( 'activateLeadAnimation' ) ) {
	ish.activateLeadAnimation = function () {

		var ishLeadImg = jQuery( '.ish-lead:not(.ish-blog-overview__post-lead) img' );
		if ( ishLeadImg.length > 0 ) {

			jQuery( document ).on( 'scroll', function () {

				var ishScreenTop = jQuery( document ).scrollTop();
				var ishLead = jQuery( '.ish-lead:not(.ish-blog-overview__post-lead)' );

				if ( ( ishCurrentScreenTopPos + ishHeaderHeight ) < ishScreenTop ) {

					var value = ( ishWindow.scrollTop() - ishHeaderHeight ) / ishLead.outerHeight();

					// Lead image.
					ishLead.addClass( 'ish-lead--animation-on' ).removeClass( 'ish-lead--animation-off' ).find( 'img' ).css( {
						'transform': 'scale(' + ( 1 + value * 0.4 ) + ')'
					} );

				}
				else {
					ishLead.addClass( 'ish-lead--animation-off' ).removeClass( 'ish-lead--animation-on' );
				}

			} );

		}

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Lead image headline position.

if ( !functionExists( 'activateLeadHeadlinePosition' ) ) {
	ish.activateLeadHeadlinePosition = function () {

		var ishLeadImg = jQuery( '.ish-lead:not(.ish-blog-overview__post-lead) img, .ish-lead #map' );

		// Has image or map.
		if ( ishLeadImg.length > 0 ) {

			ishLeadImg.imagesLoaded( function () {

				var ishLead = jQuery( '.ish-lead:not(.ish-blog-overview__post-lead)' );
				var ishLeadImgHeadline = ishLead.find( '.ish-lead__headline' );
				var ishLeadImgOverPosition = 30;
				var ishLeadImgHeight = ishLeadImg.height();
				var ishBrowserHeight = ishWindow.height();

				// Only if image is bigger than screen.
				if ( ( ishLeadImgHeight + ishHeaderHeight + ishLeadImgOverPosition ) > ishBrowserHeight ) {

					ishWindow.on( 'resize', function () {

						var ishLeadImgHeight = ishLeadImg.height();
						var ishBrowserHeight = ishWindow.height();

						// Change width when resize.
						ishLeadImgHeadline.css( {
							'width': ishLead.width()
						} );

						// On scroll - check if image is already whole visible.
						jQuery( document ).on( 'scroll', function () {

							var ishScreenTop = jQuery( document ).scrollTop();

							if ( ( ishCurrentScreenTopPos + ishHeaderHeight + ishLeadImgHeight + 60 ) < ( ishScreenTop + ishBrowserHeight ) ) {
								ishLead.removeClass( 'ish-lead--fixed-position' );
							}
							else {
								ishLead.addClass( 'ish-lead--fixed-position' );
							}

							if ( !ishFadedHeadline ) {
								ishLeadImgHeadline.hide().fadeIn();
								ishFadedHeadline = true;
							}

						} ).scroll();

					} ).resize();

				}
				else {
					ishLeadImgHeadline.hide().fadeIn();
					ishFadedHeadline = true;
				}

			} );

		}

		// Has no image, just title.
		else {
			jQuery( '.js .ish-lead__headline' ).fadeIn();
		}
	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Search opening in main menu.

if ( !functionExists( 'activateSearchForm' ) ) {
	ish.activateSearchForm = function () {

		if ( ishSearch.length > 0 ) {

			var ishOpenSearchBtn = jQuery( '.ish-navigation__item--search' ).find( 'a' );
			var ishSearchField = jQuery( '.ish-navigation__search-field' );
			var ishSearchClose = jQuery( '.ish-navigation__search-close' );

			// Click to open search form over menu.
			ishOpenSearchBtn.on( 'click', function () {
				ishSearch.parent().parent().addClass( 'ish-navigation--search-active' );

				setTimeout( function () {
					ishSearchField.focus();
				}, 100 );

				return false;
			} );

			// Click to close search only.
			ishSearchClose.on( 'click', function () {
				ishSearch.parent().parent().removeClass( 'ish-navigation--search-active' );
			} );

		}

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Lightbox - featherlight.

if ( !functionExists( 'activateLightBox' ) ) {
	ish.activateLightBox = function () {

		jQuery( 'body' ).lightGallery( {
			selector: '.ish-lightbox, .ish-sc-gallery a',
			speed: 250,
			download: false,
			thumbnail: false,
			autoplay: false,
			autoplayControls: false
		} );

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Menu dropdown active class & unhover.

if ( !functionExists( 'activateMenuDropdown' ) ) {
	ish.activateMenuDropdown = function () {

		var dropdown = jQuery( '.ish-navigation' );
		if ( dropdown.length > 0 ) {

			var rootItem = jQuery( '.ish-navigation__item' );

			rootItem.each( function () {
				var dis = jQuery( this ).find( '> a, > a+ul' );

				if ( !dis.parent().hasClass( 'ish-navigation__item--active' ) ) {
					dis.on( 'hover', function () {
						jQuery( this ).parent().addClass( 'ish-navigation__item--active' );
					}, function () {
						jQuery( this ).parent().removeClass( 'ish-navigation__item--active' );
					} );
				}
			} );

		}

		// Disable click on main parent items of navigation.
		jQuery( '.ish-navigation__menu' ).find( 'li' ).has( 'ul' ).children( 'a' ).on( 'click', function ( event ) {
			event.preventDefault();
		} );

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Portfolio.

if ( !functionExists( 'activatePortfolio' ) ) {
	ish.activatePortfolio = function () {

		var portfolio = jQuery( ishPfloContainer );

		if ( typeof ishMacyActive[ 'portfolio' ] === "undefined" ) {
			ishMacyActive[ 'portfolio' ] = false;
		}

		if ( portfolio.length > 0 ) {

			var checkPortfolio = function () {

				var windowWidth = window.innerWidth || document.body.clientWidth; // Including scrollbar width.
				var pfloWidth = portfolio.width();
				var resetActiveFilter = function () {
					var pfloFilterLinkEl = jQuery( '.ish-portfolio-filter__link' );
					if ( 0 < pfloFilterLinkEl.length ) {
						pfloFilterLinkEl.eq( 0 ).click();
					}
				};

				if ( windowWidth >= 768 ) {
					if ( !ishMacyActive[ 'portfolio' ] ) {
						var ishPfloSpace = pfloWidth * 0.09; // 9% of content width.

						Macy.init( {
							container: ishPfloContainer,
							columns: 2,
							margin: ishPfloSpace
						} );

						ishMacyActive[ 'portfolio' ] = true;

						resetActiveFilter();
					}
				} else {
					if ( ishMacyActive[ 'portfolio' ] ) {
						Macy.remove();

						ishMacyActive[ 'portfolio' ] = false;

						resetActiveFilter();

						// Reposition captions.
						var ishPortfolio = jQuery( '.ish-pflo-gal.ish-scroll-anim.ish-2col' );
						if ( ishPortfolio.length ) {
							ishPortfolio.find( '.ish-caption' ).attr( 'style', '' );
						}

					}
				}

			};

			checkPortfolio();

			ishWindow.on( 'resize', function () {

				clearTimeout( ishPortfolioTimer );
				ishPortfolioTimer = setTimeout( checkPortfolio, 300 );

			} );

		}

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Portfolio filter.

if ( !functionExists( 'activatePortfolioFilter' ) ) {
	ish.activatePortfolioFilter = function () {

		var ishPFilter = jQuery( '.ish-portfolio-filter' );
		var ishPFilterZigZag = jQuery( '.ish-portfolio-filter--zigzag' );
		var cat;
		var curSelectionClass;
		var curSelection = jQuery( '.ish-portfolio-item:not( .ish-portfolio-filter )' );
		var setContainerHeight = function ( curSelection ) {

			if ( curSelection ) {

				var elMaxTopPosition = 0;
				var elHeight = ishPFilter.height();
				var newPfloContainerHeight;

				curSelection.each( function () {
					var thisEl = jQuery( this );

					if ( elMaxTopPosition <= parseInt( thisEl.css( 'top' ), 10 ) ) {
						elMaxTopPosition = parseInt( thisEl.css( 'top' ), 10 );
						elHeight = thisEl.height();
					}
				} );

				newPfloContainerHeight = elMaxTopPosition + elHeight;
				newPfloContainerHeight = ( ishPFilter.height() > newPfloContainerHeight ) ? ishPFilter.height() : newPfloContainerHeight;

				jQuery( ishPfloContainer ).css( 'height', newPfloContainerHeight + 'px' );
			}
		};

		if ( 0 < ishPFilter.length ) {

			ishFilterItem = ishPFilter.find( 'a' );
			ishPfloItems = jQuery( '.ish-portfolio-item:not( .ish-portfolio-filter )' );
			ishPfloFirstItems = jQuery( '.ish-portfolio > *:not( .ish-portfolio-filter )' );

			ishFilterItem.on( 'click', function () {

				// Stop all portfolio animations.
				ishPfloItems.clearQueue().stop();

				cat = jQuery( this ).attr( 'href' );
				curSelectionClass = '.ish-portfolio-' + cat.replace( '#', '' );
				curSelection = jQuery( curSelectionClass );
				var portfolioContainer = jQuery( '.ish-content.ish-portfolio' );
				var portfolioContainerHeight = portfolioContainer.outerHeight( true );
				var rearangeZigZagItems = function ( thisEl, index, filterSelection ) {
					// Rearange zigzag portfolio elements.
					if ( 0 === index % 3 ) {
						thisEl.addClass( 'ish-portfolio-onecol ish-portfolio-item-indent ish-portfolio-item-trans' );
					} else if ( 1 === index % 3 ) {
						jQuery( filterSelection[ index ] ).addClass( 'ish-portfolio-twocol-left' );
						jQuery( filterSelection[ index + 1 ] ).addClass( 'ish-portfolio-twocol-right' );
						jQuery( filterSelection[ index - 1 ] ).nextUntil( filterSelection[ index + 2 ] ).wrapAll( "<div class='ish-portfolio-twocol ish-portfolio-item-indent ish-portfolio-item-trans'></div>" );
					}
				};
				var rearangeMacyItems = function ( selType, callback ) {
					// Rearrange the items.
					if ( ishMacyActive[ 'portfolio' ] ) {
						Macy.recalculate();

						// Set height of container.
						if ( 'curSelection' === selType ) {
							setContainerHeight( curSelection );
						}
					}

					callback();
				};
				var displayFilteredItems = function () {
					setTimeout( function () {

						// Set margin-top and transition for all items.
						ishPfloFirstItems.addClass( 'ish-portfolio-item-indent ish-portfolio-item-trans' );

						// Hide the items, remove opacity, fade them in.
						if ( '#all' === cat ) {
							// Show all.
							ishPfloItems.hide().css( 'opacity', '1' ).fadeIn( ishDel, function () {
								pfloContainerMinHeightAuto();
							} );
						} else {
							// Show just selected.
							curSelection.hide().css( 'opacity', '1' ).fadeIn( ishDel, function () {
								pfloContainerMinHeightAuto();
							} );
						}

						// Reset margin-top and transition for all items.
						jQuery( '.ish-portfolio-item, .ish-portfolio-onecol, .ish-portfolio-twocol' )
							.removeClass( 'ish-portfolio-item-indent' )
							.delay( 500 )
							.queue( function ( next ) {
								jQuery( this ).removeClass( 'ish-portfolio-item-trans' );
								if ( '#all' === cat ) {
									ishPfloItems.show();
								} else {
									curSelection.show();
								}
								next();
							} );

					}, 100 );
				};
				var pfloContainerMinHeightAuto = function () {
					portfolioContainer.css( 'min-height', 'auto' );
				};


				// Change active item of filter.
				jQuery( '.ish-portfolio-filter__link' ).removeClass( 'ish-portfolio-filter__link--active' );
				jQuery( this ).addClass( 'ish-portfolio-filter__link--active' );

				// Hide items & apply filter.
				jQuery.when(
					ishPfloItems.fadeOut( ishDel )
				).done( function () {

					// Set minimum height for container through rearranging items.
					portfolioContainer.css( 'min-height', portfolioContainerHeight );

					// Reset opacity on all items.
					ishPfloItems.hide().css( 'opacity', '0' );

					// Rearange zigzag portfolio elements.
					if ( 0 < ishPFilterZigZag.length ) {
						jQuery( ishPfloItems ).each( function ( index ) {
							var thisEl = jQuery( this );

							if ( thisEl.parent().hasClass( 'ish-portfolio-twocol' ) ) {
								thisEl.unwrap();
							} else if ( thisEl.hasClass( 'ish-portfolio-onecol' ) ) {
								thisEl.removeClass( 'ish-portfolio-onecol' );
							}
						} );
					}

					// Show the items but make them in.
					if ( '#all' === cat ) {

						// Show all.
						if ( 0 < ishPFilterZigZag.length ) {
							jQuery( ishPfloItems ).each( function ( index ) {
								rearangeZigZagItems( jQuery( this ), index, ishPfloItems );
							} );
						}

						jQuery.when(
							ishPfloItems.show()
						).done( function () {
							rearangeMacyItems( 'ishPfloItems', function callback() {
								displayFilteredItems();
							} );
						} );

					} else {

						// Show just selected.
						if ( 0 < ishPFilterZigZag.length ) {
							jQuery( curSelection ).each( function ( index ) {
								rearangeZigZagItems( jQuery( this ), index, curSelection );
							} );
						}

						jQuery.when(
							curSelection.show()
						).done( function () {
							rearangeMacyItems( 'curSelection', function callback() {
								displayFilteredItems();
							} );
						} );

						// Reset minimal height of container when 0 items is visible.
						if ( 0 === curSelection.length ) {
							pfloContainerMinHeightAuto();
						}

					}

				} );

				return false;
			} );

		}

		ishWindow.on( 'resize', function () {
			if ( ishMacyActive[ 'portfolio' ] && '#all' !== cat ) {
				setContainerHeight( curSelection );
			}
		} );

	}

}


// ---------------------------------------------------------------------------------------------------------------------
// Portfolio tilt.

if ( !functionExists( 'activatePortfolioTilt' ) ) {
	ish.activatePortfolioTilt = function () {

		var portfolioTilt = function () {

			var windowWidth = window.innerWidth || document.body.clientWidth; // Including scrollbar width.
			var pitem = jQuery( '.ish-portfolio-item:not(.ish-portfolio-filter)' );

			if ( ishPortfolioTiltEffect && ( 768 <= windowWidth ) ) {

				pitem.tilt( {
					maxTilt: 20,
					perspective: 500,
					easing: "cubic-bezier(.3,.98,.52,.99)",
					speed: 300,
					transition: true,
					reset: true
				} );

			} else {
				pitem.tilt.destroy.call( pitem );
			}
		};

		portfolioTilt();

		ishWindow.on( 'resize', function () {
			portfolioTilt();
		} );

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Back to top.

if ( !functionExists( 'activateBackToTopButton' ) ) {
	ish.activateBackToTopButton = function () {
		jQuery( '.ish-sidenav-btt__icon, .ish-resp-nav__icon--btt' ).on( 'click', function ( event ) {
			event.preventDefault();
			jQuery( 'html, body' ).animate( { scrollTop: 0 }, 500 );
		} )
	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Floated sidebar.

if ( !functionExists( 'activateSidebar' ) ) {
	ish.activateSidebar = function () {

		var sbar = jQuery( '.ish-sbar' );
		if ( sbar.length > 0 ) {

			var sbarBtn = jQuery( '.ish-sbar-btn, .ish-resp-nav__icon--sidebar' );
			var sbarOverlay = jQuery( '.ish-sbar-overlay' );
			var sbarOpened = false;

			// Open sidebar in click.
			sbarBtn.on( 'click', function () {
				if ( !sbarOpened ) {
					ishBody.removeClass( 'ish-sbar-closed' ).addClass( 'ish-sbar-opened' );
					sbarOpened = true;

					// Close navigation.
					if ( ishNavOpened )
						ish.closeNavigation();
				}
				return false;
			} );

			// Close by overlay.
			jQuery( '.ish-sbar-close-btn' ).add( sbarOverlay ).on( 'click', function () {
				if ( sbarOpened ) {
					ishBody.removeClass( 'ish-sbar-opened' ).addClass( 'ish-sbar-closed' );
					sbarOpened = false;
				}
				return false;
			} );

			jQuery( document ).on( 'keyup', function ( e ) {
				if ( e.keyCode == 27 ) {
					if ( sbarOpened ) {
						ishBody.removeClass( 'ish-sbar-opened' ).addClass( 'ish-sbar-closed' );
						sbarOpened = false;
					}
				}
			} );

		}
	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Navigation.

if ( !functionExists( 'activateNavigation' ) ) {
	ish.activateNavigation = function () {

		if ( ishMenu.length > 0 ) {

			// Open navigation.
			ishNav.on( 'click', function () {
				if ( !ishNavOpened ) {
					ish.openNavigation();
				}
				else {
					ish.closeNavigation();
				}
				return false;
			} );

			// Close with ESC if activated.
			jQuery( document ).on( 'keyup', function ( e ) {
				if ( e.keyCode == 27 ) {
					if ( jQuery( '.ish-navigation ' ).hasClass( 'ish-navigation--search-active' ) ) {
						jQuery( '.ish-navigation' ).removeClass( 'ish-navigation--search-active' );
					} else if ( ishNavOpened ) {
						ish.closeNavigation();
					}
				}
			} );

			// Use responsive X close btn.
			jQuery( '.ish-navigation__close-btn' ).on( 'click', function () {
				if ( ishNavOpened ) {
					ish.closeNavigation();
				}
				return false;
			} );

		}

	}
}


// Open nav.
if ( !functionExists( 'openNavigation' ) ) {
	ish.openNavigation = function () {

		ishBody.removeClass( 'ish-navigation--closed' ).addClass( 'ish-navigation--opened' );
		ishNav.find( 'div' ).addClass( 'open' );
		ishNavOpened = true;

	}
}

// Close nav.
if ( !functionExists( 'closeNavigation' ) ) {
	ish.closeNavigation = function () {

		ishBody.addClass( 'ish-navigation--closed' ).removeClass( 'ish-navigation--opened' );
		ishNav.find( 'div' ).removeClass( 'open' );

		ishSearch.parent().parent().removeClass( 'ish-navigation--search-active' );

		ishNavOpened = false;

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Accordion.

if ( !functionExists( 'activateAccordion' ) ) {
	ish.activateAccordion = function () {

		jQuery( '.ish-sc-accordion > dt > a' ).on( 'click', function () {
			var thisEl = jQuery( this ).parent();

			if ( thisEl.hasClass( 'ish-active-item' ) ) {
				thisEl.removeClass( 'ish-active-item' ).next().stop().slideUp();
			} else {
				thisEl.parent().find( '.ish-active-item' ).removeClass( 'ish-active-item' ).next().stop().slideUp();
				thisEl.next().stop().slideDown();
				thisEl.addClass( 'ish-active-item' );
			}

			return false;
		} );

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Toggle.

if ( !functionExists( 'activateToggle' ) ) {
	ish.activateToggle = function () {

		jQuery( '.ish-sc-toggle > dt > a' ).on( 'click', function () {
			var thisEl = jQuery( this ).parent();

			thisEl.toggleClass( 'ish-active-item' ).next().stop().slideToggle();

			return false;
		} );

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Tabs.

if ( !functionExists( 'activateTabs' ) ) {
	ish.activateTabs = function () {

		jQuery( '.ish-sc-tabs__menu a' ).on( 'click', function ( event ) {
			event.preventDefault();
			jQuery( this ).parent().addClass( 'ish-active-item' );
			jQuery( this ).parent().siblings().removeClass( 'ish-active-item' );
			var tab = jQuery( this ).attr( 'href' );
			jQuery( '.ish-sc-tabs__content-single' ).not( tab ).css( 'display', 'none' );
			jQuery( tab ).fadeIn();
		} );

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// "Jetpack" Gallery.

if ( !functionExists( 'activateGallery' ) ) {
	ish.activateGallery = function () {

		var galleries = jQuery( '.ish-sc-gallery' );
		if ( galleries.length ) {
			galleries.each( function () {
				var thisEl = jQuery( this );
				var rowHeight = ( thisEl.attr( 'data-rowHeight' ) ) ? thisEl.attr( 'data-rowHeight' ) : 110;
				var lastRow = ( thisEl.attr( 'data-lastRow' ) ) ? thisEl.attr( 'data-lastRow' ) : 'justify';
				var margins = ( thisEl.attr( 'data-margins' ) ) ? thisEl.attr( 'data-margins' ) : 1;

				thisEl.justifiedGallery( {
					rowHeight: rowHeight,
					lastRow: lastRow,
					margins: margins
				} );
			} );
		}

	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Google map.

if ( !functionExists( 'initMap' ) ) {
	ish.initMap = function () {

		// Load color from HTML.
		var themeMap = jQuery( '#map' );
		var mapColor = ( themeMap.attr( 'data-map-color' ) ) ? themeMap.attr( 'data-map-color' ) : '';
		var mapZoom = ( themeMap.attr( 'data-map-zoom' ) ) ? parseInt( themeMap.attr( 'data-map-zoom' ), 10 ) : 12;
		var markerColor = ( themeMap.attr( 'data-marker-color' ) ) ? themeMap.attr( 'data-marker-color' ) : '';
		var markerClickMove = ( themeMap.attr( 'data-marker-click-move' ) ) ? parseFloat( themeMap.attr( 'data-marker-click-move' ) ) : 0.02;

		// Specify features and elements to define styles.
		var myLat = ( themeMap.attr( 'data-map-lat' ) ) ? parseFloat( themeMap.attr( 'data-map-lat' ) ) : -33.9;
		var myLng = ( themeMap.attr( 'data-map-lng' ) ) ? parseFloat( themeMap.attr( 'data-map-lng' ) ) : 151.2;
		var myLatLng = { lat: myLat, lng: myLng };
		var styleArray = [
			{
				featureType: "all",
				stylers: [
					{ saturation: -100 }
				]
			}
		];

		// Create a map object and specify the DOM element for display.
		var map = new google.maps.Map( document.getElementById( 'map' ), {
			center: myLatLng,
			scrollwheel: false,
			// Apply the map style array to the map.
			styles: styleArray,
			zoom: mapZoom,
			mapTypeControl: true,
			mapTypeControlOptions: {
				style: google.maps.MapTypeControlStyle.HORIZONTAL_BAR,
				position: google.maps.ControlPosition.LEFT_TOP
			},
			zoomControl: true,
			zoomControlOptions: {
				position: google.maps.ControlPosition.RIGHT_TOP
			}
		} );

		// Create a marker and set its position.
		var ishMarker = {
			path: 'M0-48c-9.8 0-17.7 7.8-17.7 17.4 0 15.5 17.7 30.6 17.7 30.6s17.7-15.4 17.7-30.6c0-9.6-7.9-17.4-17.7-17.4 z M -8,-30 a 8,8 0 1,1 16,0 8,8 0 2,2 -16,0 z',
			fillRule: 'evenodd',
			fillColor: markerColor,
			fillOpacity: 0.9,
			scale: ( themeMap.attr( 'data-marker-scale' ) ) ? parseFloat( themeMap.attr( 'data-marker-scale' ) ) : 1.5,
			strokeWeight: 0
		};

		var mapMarkers = new Array();
		var infowindow = new google.maps.InfoWindow();
		var geocoder = new google.maps.Geocoder();
		var marker, i;

		// Set default map location.
		geocoder.geocode( { 'address': themeMap.attr( 'data-map-address' ) }, function ( results, status ) {
			if ( status == google.maps.GeocoderStatus.OK ) {
				map.setCenter( results[ 0 ].geometry.location );
			}
		} );

		// Fill array mapMarkers with data from HTML.
		themeMap.siblings( '.map-marker' ).each( function ( index ) {
			var markerValues = new Array();

			markerValues[ 'title' ] = $( this ).attr( 'data-title' );
			markerValues[ 'lat' ] = parseFloat( $( this ).attr( 'data-lat' ) );
			markerValues[ 'lng' ] = parseFloat( $( this ).attr( 'data-lng' ) );
			markerValues[ 'address' ] = $( this ).attr( 'data-address' );
			markerValues[ 'content' ] = $( this ).html();

			mapMarkers[ index ] = markerValues;
		} );

		for ( var i = 0; i < mapMarkers.length; i++ ) {
			geocodeAddress( mapMarkers[ i ] );
		}

		function geocodeAddress( location ) {
			geocoder.geocode( { 'address': location[ 'address' ] }, function ( results, status ) {
				if ( status == google.maps.GeocoderStatus.OK ) {
					createMarker( results[ 0 ].geometry.location, location[ 'content' ], location[ 'title' ] );
				}
				else {
					createMarker( {
						lat: location[ 'lat' ],
						lng: location[ 'lng' ]
					}, location[ 'content' ], location[ 'title' ] );
				}
			} );
		}

		function createMarker( latlng, markerHtml, markerTitle ) {
			var marker = new google.maps.Marker( {
				position: latlng,
				map: map,
				animation: google.maps.Animation.DROP,
				icon: ishMarker,
				title: markerTitle,
				html: markerHtml
			} );

			google.maps.event.addListener( marker, 'click', function () {
				var coef = Math.abs( mapZoom - map.getZoom() );
				var pow = Math.pow( 2, coef );
				var valMarkerMove = ( mapZoom > map.getZoom() ) ? ( markerClickMove * pow ) : ( markerClickMove / pow );

				if ( '' != markerHtml.trim() ) {
					infowindow.setContent( '<div class="ish-marker-info">' + markerHtml + '</div>' );
					map.panTo( { lat: this.getPosition().lat() + valMarkerMove, lng: this.getPosition().lng() } );
					infowindow.open( map, marker );
				} else {
					map.panTo( this.getPosition() );
					infowindow.close();
				}
			} );
		}
	}
}


// ---------------------------------------------------------------------------------------------------------------------
// Send Form - Contact Form.

if ( !functionExists( 'activateSendForm' ) ) {
	ish.activateSendForm = function () {

		jQuery( 'form input[type="submit"], form button[type="submit"]' ).on( 'click', function ( e ) {
			var thisForm = jQuery( this ).closest( 'form' );

			thisForm.on( 'submit', function ( event ) {

				if ( 'ish-contact-form' === thisForm.attr( 'id' ) ) {
					var url = "ajax.php";

					jQuery.ajax( {
						type: "POST",
						url: url,
						data: thisForm.serialize(), // Serializes the form's elements.
						success: function ( data ) {
							var obj = jQuery.parseJSON( data );

							console.log( obj );

							if ( 'success' === obj.message ) {
								alert( "Email has been sent." );
								location.reload();
							} else if ( 'error' === obj.message ) {
								alert( "ERROR! Something went wrong." );
							} else {
								location.reload();
							}

						},
						error: function () {
							alert( "ERROR! Something went wrong." );
						}
					} );

					return false;
				}

			} );

		} );
	}
}